#include <evaTac.h>
#include <evaDelayTimer.h>
#include <evaButton.h>
#include <evaIndicator.h>
#include <evaCountdownIndicator.h>

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
  CountdownIndicator GreenIndicator;

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
    mTimer.stop();
    if (mContext->mIsAuto)
      mTimer.start(10000);
    mContext->RedIndicator.on();
    mContext->YellowIndicator.off();
    mContext->GreenIndicator.off();
  }

  virtual void ChangeSignal() override {
    mNext = mContext->RedYellowStateInstance;
  }

  void OnTimeOut(void *aSender, unsigned char aEventType, signed short aEventArgs) {
    mTimer.stop();
    mNext = mContext->RedYellowStateInstance;
  }
private:
  Context *mContext;
  DelayTimer mTimer = {new Handler<RedState>(this, &OnTimeOut)};

};

class RedYellowState : public IState {
  Context *mContext;
  DelayTimer mTimer = {new Handler<RedYellowState>(this, &OnTimeOut)};

public:
  RedYellowState(Context *c)
    : mContext(c) {}

  virtual void Start() override {
    mNext = 0;
    mTimer.start(3000);
    mContext->RedIndicator.on();
    mContext->YellowIndicator.on();
    mContext->GreenIndicator.off();
  }

  void OnTimeOut(void *aSender, unsigned char aEventType, signed short aEventArgs) {
    mNext = mContext->GreenStateInstance;
  }

  virtual void ChangeSignal() override {
    mTimer.stop();
    mNext = mContext->RedStateInstance;
  }
};

class GreenState : public IState {
  Context *mContext;
  DelayTimer mTimer = {new Handler<GreenState>(this, &OnTimeOut)};

public:
  GreenState(Context *c)
    : mContext(c) {}

  virtual void Start() override {
    mNext = 0;
    mTimer.stop();
    if (mContext->mIsAuto)
      mTimer.start(10000);
    mContext->RedIndicator.off();
    mContext->YellowIndicator.off();
    mContext->GreenIndicator.on();
  }

  void OnTimeOut(void *aSender, unsigned char aEventType, signed short aEventArgs) {
    mNext = mContext->BlinkingGreenStateInstance;
  }

  virtual void ChangeSignal() override {
    mTimer.stop();
    mNext = mContext->BlinkingGreenStateInstance;
  }
};

class BlinkingGreenState : public IState {
  Context *mContext;
  DelayTimer mTimer = {new Handler<BlinkingGreenState>(this, &OnTimeOut)};

public:
  BlinkingGreenState(Context *c)
    : mContext(c) {}

  virtual void Start() override {
    mNext = 0;
    mContext->RedIndicator.off();
    mContext->YellowIndicator.off();
    mContext->GreenIndicator.on(500, 506, 6);
    mTimer.start(3000);
  }

  void OnTimeOut(void *aSender, unsigned char aEventType, signed short aEventArgs) {
    mNext = mContext->YellowStateInstance;
  }

  virtual void ChangeSignal() override {
    mTimer.stop();
    mNext = mContext->GreenStateInstance;
  }
};

class YellowState : public IState {
  Context *mContext;
  DelayTimer mTimer = {new Handler<YellowState>(this, &OnTimeOut)};

public:
  YellowState(Context *c)
    : mContext(c) {
  }

  virtual void Start() override {
    mNext = 0;
    mContext->RedIndicator.off();
    mContext->YellowIndicator.on();
    mContext->GreenIndicator.off();
    mTimer.start(3000);
  }

  void OnTimeOut(void *aSender, unsigned char aEventType, signed short aEventArgs) {
    mNext = mContext->RedStateInstance;
  }

  virtual void ChangeSignal() override {
    mTimer.start(3000);
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
    RedIndicator.off();
    YellowIndicator.off();
    GreenIndicator.off();
    for (int i = 0; i < 5; i++) {
      YellowIndicator.on();
      delay(50);
      YellowIndicator.off();
      delay(50);
    }
    mState->Start();
  }

  void ChangeSignal() {
    mIsAuto = false;
    mState->ChangeSignal();
  }

  void tick() override{
    if (mState->Next() and mState->Next() != mState) {
      mState = mState->Next();
      mState->Start();
    }
  }
};

class AppSemaphore {
  StateChart mStates;
  PinButton<6, INPUT_PULLUP, LOW> mButton = {new Handler<AppSemaphore>(this, &OnChangeSignal), ON_SHORTCLICK | ON_LONGCLICK};

public:

  void OnChangeSignal(void *aSender, unsigned char aEventType, signed short aEventArgs) {
    if (aEventArgs & ON_LONGCLICK)
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
  tac();
}