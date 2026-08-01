const int ENABLE_1 = 5;
const int INPUT_1 = 7;
const int INPUT_2 = 8;
const int JOYSTICK = A0;

void setup() {
  Serial.begin(9600);
  pinMode(INPUT_1, OUTPUT);
  pinMode(INPUT_2, OUTPUT);
  pinMode(ENABLE_1, OUTPUT);
  digitalWrite(INPUT_1, LOW);
  digitalWrite(INPUT_2, LOW);
}

void loop() {
  int val_joystick = analogRead(JOYSTICK);
  
  int speed;
  
  if (val_joystick < 480) {     // Marche arrière
  	speed = map(val_joystick, 480, 0, 0, 255);
    digitalWrite(INPUT_1, HIGH);
    digitalWrite(INPUT_2, LOW);
    analogWrite(ENABLE_1, speed);
  }
  else if (val_joystick > 540) { // Marche avant
  	speed = map(val_joystick, 540, 1023, 0, 255);
    digitalWrite(INPUT_1, LOW);
    digitalWrite(INPUT_2, HIGH);
    analogWrite(ENABLE_1, speed);
  }
  else {                        // Arrêt
    speed = 0;
    digitalWrite(INPUT_1, LOW);
    digitalWrite(INPUT_2, LOW);
    analogWrite(ENABLE_1, speed);
  }
  Serial.println(val_joystick);
  Serial.println(speed);
  delay(100);
}
