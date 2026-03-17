/**
 * eva Library - Button Initialization Variants
 *
 * This example demonstrates all button initialization options:
 * - Pull-up buttons (most common)
 * - Active HIGH buttons
 * - Multi-buttons on single ADC pin (resistor ladder)
 * - Buttons with custom debounce timing
 */

#include <evaTac.h>
#include <evaRepeatTimer.h>
#include <evaButton.h>

using namespace eva;

class App : public IHandler
{
private:
  // === BUTTON VARIANT 1: Pull-up button (most common) ===
  // Active LOW, internal pull-up, debounced, click detection
  PullUpButton<2> pullupButton;

  // === BUTTON VARIANT 2: Another pull-up button ===
  // Will demonstrate multiple buttons
  PullUpButton<3> pullupButton2;

  // === BUTTON VARIANT 3: Active HIGH button ===
  // Requires external pull-down resistor
  PinButton<4, INPUT, HIGH> activeHighButton;

  // === BUTTON VARIANT 4: Multi-button on one ADC pin ===
  // 3 buttons on A0 with resistor ladder
  // Expected ADC thresholds for each button press
  PinMultiButton<A0, INPUT, 900, 700, 500> multiButton;

  // === BUTTON VARIANT 5: Button with custom reader (threshold-based) ===
  // Button using analog threshold (e.g., touch sensor, light sensor)
  Button<
      BinarizeLtDecor<
          StabilizeDecor<
              AnalogPinReader<A1, INPUT>>,
          512 // Threshold value
          >>
      analogThresholdButton;

  RepeatTimer reportTimer{5000, this};

  // Track button press counts for demo
  unsigned short clickCounts[5] = {0};

public:
  App()
  {
    // Set up listeners with different event masks
    pullupButton.setListener(this, ON_PRESS | ON_RELEASE | ON_SHORTCLICK | ON_LONGCLICK | ON_LONGPRESS);
    pullupButton2.setListener(this, ON_SHORTCLICK); // Only care about short clicks
    activeHighButton.setListener(this, ON_PRESS | ON_RELEASE);
    multiButton.setListener(this, ON_PRESS | ON_SHORTCLICK | ON_LONGCLICK);
    analogThresholdButton.setListener(this, ON_CHANGE | ON_PRESS | ON_RELEASE);

    Serial.println("=== Button Variants Demo ===");
    Serial.println("Try pressing buttons in different ways:");
    Serial.println("- Short press (<750ms)");
    Serial.println("- Long press (>750ms) and hold");
    Serial.println("- Long press then release");
    Serial.println();
    printButtonConfig();
  }

  void printButtonConfig()
  {
    Serial.println("Button Configuration:");
    Serial.println("1. PullUpButton<2> - Full event detection");
    Serial.println("2. PullUpButton<3> - Short clicks only");
    Serial.println("3. PinButton<4,INPUT,HIGH> - Active HIGH");
    Serial.println("4. PinMultiButton<A0> - 3 buttons on one pin");
    Serial.println("5. Analog threshold button on A1");
    Serial.println();
  }

  void invoke(void *sender, CallbackInfo info) override
  {
    unsigned char buttonId = 0;
    const char *buttonName = "";

    // Identify which button
    if (sender == &pullupButton)
    {
      buttonId = 1;
      buttonName = "Button1 (pin2)";
    }
    else if (sender == &pullupButton2)
    {
      buttonId = 2;
      buttonName = "Button2 (pin3)";
    }
    else if (sender == &activeHighButton)
    {
      buttonId = 3;
      buttonName = "Button3 (pin4)";
    }
    else if (sender == &multiButton)
    {
      buttonId = 4 + info.eventArg; // Buttons 4,5,6
      buttonName = "MultiButton";
    }
    else if (sender == &analogThresholdButton)
    {
      buttonId = 7;
      buttonName = "AnalogBtn (A1)";
    }
    else if (sender == &reportTimer)
    {
      printSummary();
      return;
    }

    // Track clicks for summary
    if (info.eventType == ON_SHORTCLICK || info.eventType == ON_LONGCLICK)
    {
      clickCounts[buttonId - 1]++;
    }

    // Print event with nice formatting
    Serial.print('[');
    Serial.print(buttonName);
    if (info.eventArg > 0 && buttonId >= 4 && buttonId <= 6)
    {
      Serial.print(" #");
      Serial.print(info.eventArg);
    }
    Serial.print("] ");

    switch (info.eventType)
    {
    case ON_PRESS:
      Serial.println("PRESSED");
      break;
    case ON_RELEASE:
      Serial.println("RELEASED");
      break;
    case ON_SHORTCLICK:
      Serial.println("SHORT CLICK");
      break;
    case ON_LONGCLICK:
      Serial.println("LONG CLICK");
      break;
    case ON_LONGPRESS:
      Serial.println("LONG PRESS (holding)");
      break;
    default:
      Serial.println("UNKNOWN");
      break;
    }
  }

  void printSummary()
  {
    Serial.println("\n=== Button Activity Summary ===");
    Serial.print("Button1 clicks: ");
    Serial.println(clickCounts[0]);
    Serial.print("Button2 clicks: ");
    Serial.println(clickCounts[1]);
    Serial.print("Button3 clicks: ");
    Serial.println(clickCounts[2]);
    Serial.print("MultiBtn clicks: ");
    Serial.println(clickCounts[3] + clickCounts[4] + clickCounts[5]);
    Serial.print("AnalogBtn clicks: ");
    Serial.println(clickCounts[6]);
    Serial.println("==============================\n");
  }
};

void setup()
{
  Serial.begin(9600);
  static App app;
}

void loop()
{
  eva::tac();
}
