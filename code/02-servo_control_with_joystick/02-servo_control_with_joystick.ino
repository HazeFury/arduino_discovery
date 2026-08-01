#include <Servo.h>

Servo monServo; // instanciate a Servo object to control the servo motor

const int pinY = A0;      // X axis
const int pinServo = 9;   // Broche de signal du servo

void setup() {
  Serial.begin(9600);
  monServo.attach(pinServo); // Associate Servo to pin 9
}

void loop() {
  int valY = analogRead(pinY); // Read X axis (0 - 1023)

  // Convert joystick value (0-1023) in a angle for the servo (0-180)
  int angle = map(valY, 0, 1022, 0, 180);

  monServo.write(angle); // Update angle of the servo

  Serial.println("------------------");
  Serial.println(valY);
  Serial.println(angle);
  Serial.println("------------------");
  delay(100);
}
