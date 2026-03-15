/**
 * eva Library - Slider and Joystick Examples
 *
 * This example demonstrates various initialization options for:
 * - Slider (analog input mapped to 0-255 range)
 * - Joystick (with trim adjustment and different center configurations)
 *
 * Hardware connections:
 * - Potentiometer on A0 (wiper) for slider
 * - Joystick X-axis on A1, Y-axis on A2
 * - Optional: second potentiometer on A3 for additional slider
 */

#include <evaTac.h>
#include <evaRepeatTimer.h>
#include <evaJoystick.h>
#include <evaSlider.h>

using namespace eva;

class App : public IHandler
{
private:
  // === SLIDER VARIANTS ===

  // Slider with restricted range (200-800 mapped to 0-255)
  // Useful when potentiometer doesn't use full range
  PinSlider<A3, INPUT, 200, 800> slider;

  // === JOYSTICK VARIANTS ===

  // Symmetric joystick (center automatically calculated as midpoint)
  PinSymmetricJoystick<A1, INPUT, 0, 1023> joystickX;
  PinSymmetricJoystick<A2, INPUT, 0, 1023> joystickY;

  // Joystick (center manually predefined as 400)
  PinJoystick<A4, INPUT, 0, 400, 1023> joystick3;

  // Timer for periodic reporting
  RepeatTimer reportTimer{1000, this};

public:
  App()
  {
    Serial.println("=== Slider and Joystick Demo ===");
    Serial.println("Slider on A0, A3 | Joystick X:A1 Y:A2");
    Serial.println("Format: Slider1|Slider2|JoyX|JoyY|TrimmedX|TrimmedY");

    // Set trim for trimmed joystick (example calibration)
    joystick3.setTrim(10); // Small positive trim
  }

  void invoke(void *sender, CallbackInfo info) override
  {
    if (sender == &reportTimer)
    {
      // Read all values
      signed char slider = slider.getValue();
      signed char joyX = joystickX.getValue();
      signed char joyY = joystickY.getValue();
      signed char trimX = joystick3.getValue();
      signed char trimY = joystick3.getValue(); // Same axis for demo

      // Print all values in CSV format
      Serial.print(slider);
      Serial.print('|');
      Serial.print(joyX);
      Serial.print('|');
      Serial.print(joyY);
      Serial.print('|');
      Serial.print(trimX);
      Serial.print('|');
      Serial.println(trimY);

      // Print joystick trim value
      Serial.print("Trim value: ");
      Serial.println(joystick3.getTrim());
    }
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
