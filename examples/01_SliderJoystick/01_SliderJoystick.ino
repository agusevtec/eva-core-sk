/**
 * eva Library - Slider and Joystick Examples
 */

#include <evaTac.h>
#include <evaJoystick.h>
#include <evaSlider.h>
#include <evaHeartbeat.h>

using namespace eva;

class App : public Heartbeat
{
private:
  // === SLIDER VARIANTS ===

  // Slider with restricted range (200-800 mapped to 1000-2000)
  // Useful when potentiometer doesn't use full range
  PinSlider<A3, INPUT, 200, 800> slider;

  // === JOYSTICK VARIANTS ===

  // Symmetric joystick (center automatically calculated as midpoint)
  PinSymmetricJoystick<A1, INPUT, 0, 1023> joystickX;
  PinSymmetricJoystick<A2, INPUT, 0, 1023> joystickY;

  // Joystick (center manually predefined as 400)
  PinJoystick<A4, INPUT, 0, 400, 1023> joystick3;

public:
  App()
      : Heartbeat(1000)
  {
    joystick3.setTrim(10); // Small positive trim
  }

  void onHeartbeat() override
  {
    signed short sliderValue = slider.getValue();
    signed char joyX = joystickX.getValue();
    signed char joyY = joystickY.getValue();
    signed char trimX = joystick3.getValue();
    signed char trimY = joystick3.getValue();

    Serial.print(sliderValue);
    Serial.print('|');
    Serial.print(joyX);
    Serial.print('|');
    Serial.print(joyY);
    Serial.print('|');
    Serial.print(trimX);
    Serial.print('|');
    Serial.println(trimY);

    Serial.print("Trim value: ");
    Serial.println(joystick3.getTrim());
  }
};

void setup()
{
  Serial.begin(9600);
  Serial.println("=== Slider and Joystick Demo ===");
  static App app;
}

void loop()
{
  eva::tac();
}
