#include <Servo.h>
#include <avr/interrupt.h>

Servo servo1;
Servo servo2;

volatile bool motionDetected = false;
volatile bool timerFlag = false;

const int pirPin = 6;   // Датчик движения на D6
const int servoPin1 = 7; // Серво 1 на D7
const int servoPin2 = 8; // Серво 2 на D8

void func(){
  Serial.print("Inter  ");
  motionDetected = true;
}


void setup() {
  Serial.begin(9600);

  // Подключаем сервы
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo1.write(90);
  servo2.write(90);

  // Настройка пина для датчика движения
  pinMode(pirPin, INPUT_PULLUP);

  attachInterrupt(0, func, FALLING);
}

void loop() {
  if (motionDetected) {

    Serial.println("Motion detected!");

    for (int pos = 90; pos <= 180; pos++) {
      servo1.write(180 - pos);
      servo2.write(pos);
      delay(15);
    }
    for (int pos = 180; pos >= 90; pos--) {
      servo1.write(180 - pos);
      servo2.write(pos);
      delay(15);
    }
    for (int pos = 90; pos <= 180; pos++) {
      servo1.write(180 - pos);
      delay(15);
    }
    for (int pos = 180; pos >= 110; pos--) {
      servo1.write(180 - pos);
      delay(15);
    }
    for (int pos = 110; pos <= 180; pos++) {
      servo1.write(180 - pos);
      delay(15);
    }
    for (int pos = 180; pos >= 90; pos--) {
      servo1.write(180 - pos);
      delay(15);
    }
    motionDetected = false;
  }
}

