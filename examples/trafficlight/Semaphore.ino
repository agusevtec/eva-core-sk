#include "src/evaTac.h"
#include "src/evaTimer.h"
#include "src/evaButton.h"
#include "src/evaIndicator.h"
using namespace eva;

class IState {
protected:
  IState *mNext;

public:
  virtual void Start();
  virtual void ChangeSignal();

  IState *Next() {
    return mNext;
  }
};

struct Context {
  bool mIsAuto = true;

  Indicator RedIndicator;
  Indicator YellowIndicator;
  Indicator GreenIndicator;

  IState *RedStateInstance, *RedYellowStateInstance, *GreenStateInstance, *BlinkingGreenStateInstance, *YellowStateInstance;

  Context()
    : RedIndicator(9, LOW), YellowIndicator(8, LOW), GreenIndicator(7, LOW) {
  }
};

class RedState : public IState {
public:
  RedState(Context *c)
    : mContext(c) {}

  virtual void Start() override {
    mNext = 0;
    mTimer.Stop();
    if (mContext->mIsAuto)
      mTimer.After(10000);
    mContext->RedIndicator.On();
    mContext->YellowIndicator.Off();
    mContext->GreenIndicator.Off();
  }

  virtual void ChangeSignal() override {
    mNext = mContext->RedYellowStateInstance;
  }

  void OnTimeOut(void *aSender, long aEventArgs) {
    mTimer.Stop();
    mNext = mContext->RedYellowStateInstance;
  }
private:
  Context *mContext;
  Timer mTimer = {new Delegate<RedState>(this, &OnTimeOut)};

};

class RedYellowState : public IState {
  Context *mContext;
  Timer mTimer = {new Delegate<RedYellowState>(this, &OnTimeOut)};

public:
  RedYellowState(Context *c)
    : mContext(c) {}

  virtual void Start() override {
    mNext = 0;
    mTimer.Stop();
    mTimer.After(3000);
    mContext->RedIndicator.On();
    mContext->YellowIndicator.On();
    mContext->GreenIndicator.Off();
  }

  void OnTimeOut(void *aSender, long aEventArgs) {
    mNext = mContext->GreenStateInstance;
  }

  virtual void ChangeSignal() override {
    mTimer.Stop();
    mNext = mContext->RedStateInstance;
  }
};

class GreenState : public IState {
  Context *mContext;
  Timer mTimer = {new Delegate<GreenState>(this, &OnTimeOut)};

public:
  GreenState(Context *c)
    : mContext(c) {}

  virtual void Start() override {
    mNext = 0;
    mTimer.Stop();
    if (mContext->mIsAuto)
      mTimer.After(10000);
    mContext->RedIndicator.Off();
    mContext->YellowIndicator.Off();
    mContext->GreenIndicator.On();
  }

  void OnTimeOut(void *aSender, long aEventArgs) {
    mNext = mContext->BlinkingGreenStateInstance;
  }

  virtual void ChangeSignal() override {
    mTimer.Stop();
    mNext = mContext->BlinkingGreenStateInstance;
  }
};

class BlinkingGreenState : public IState {
  Context *mContext;
  Timer mTimer = {new Delegate<BlinkingGreenState>(this, &OnTimeOut)};

public:
  BlinkingGreenState(Context *c)
    : mContext(c) {}

  virtual void Start() override {
    mNext = 0;
    mContext->RedIndicator.Off();
    mContext->YellowIndicator.Off();
    mContext->GreenIndicator.Repeat(6, 500, 250);
    mTimer.After(3000);
  }

  void OnTimeOut(void *aSender, long aEventArgs) {
    mNext = mContext->YellowStateInstance;
  }

  virtual void ChangeSignal() override {
    mTimer.Stop();
    mNext = mContext->GreenStateInstance;
  }
};

class YellowState : public IState {
  Context *mContext;
  Timer mTimer = {new Delegate<YellowState>(this, &OnTimeOut)};

public:
  YellowState(Context *c)
    : mContext(c) {
  }

  virtual void Start() override {
    mNext = 0;
    mContext->RedIndicator.Off();
    mContext->YellowIndicator.On();
    mContext->GreenIndicator.Off();
    mTimer.After(3000);
  }

  void OnTimeOut(void *aSender, long aEventArgs) {
    mNext = mContext->RedStateInstance;
  }

  virtual void ChangeSignal() override {
    mTimer.Stop();
    mNext = mContext->GreenStateInstance;
  }
};

class StateChart : public Context, Tickable {
  IState *mState;

public:
  StateChart() {
    RedStateInstance = new RedState(this);
    RedYellowStateInstance = new RedYellowState(this);
    GreenStateInstance = new GreenState(this);
    BlinkingGreenStateInstance = new BlinkingGreenState(this);
    YellowStateInstance = new YellowState(this);
    mState = GreenStateInstance;
    mState->Start();
  }

  void SetAutoMode() {
    mIsAuto = true;
    RedIndicator.Off();
    YellowIndicator.Off();
    GreenIndicator.Off();
    for (int i = 0; i < 5; i++) {
      YellowIndicator.On();
      delay(50);
      YellowIndicator.Off();
      delay(50);
    }
    mState->Start();
  }

  void ChangeSignal() {
    mIsAuto = false;
    mState->ChangeSignal();
  }

  void Tick() {
    if (mState->Next() and mState->Next() != mState) {
      mState = mState->Next();
      mState->Start();
    }
  }
};

class AppSemaphore {
  StateChart mStates;
  Button& mButton = Button::Create<6, INPUT_PULLUP, LOW>()
                      .SetListener(new Delegate<AppSemaphore>(this, &OnChangeSignal), Button::ON_SHORTCLICK | Button::ON_LONGCLICK);

public:

  void OnChangeSignal(void *aSender, long aEventArgs) {
    if (aEventArgs & Button::ON_LONGCLICK)
      mStates.SetAutoMode();
    else
      mStates.ChangeSignal();
  }
};

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  pinMode(A2, INPUT);
  static AppSemaphore app;
}

void loop() {
  Ticker::Tac();
}