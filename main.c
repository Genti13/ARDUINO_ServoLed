#include <Servo.h>

Servo myServo;

int PIN_POTEN = A0;
int PIN_SERVO = 10;
int LED_PIN_R = 6;
int LED_PIN_G = 5;
int LED_PIN_B = 3;
int poten_value = 0;
int angle = 0;

void setup() {
  pinMode(PIN_POTEN, INPUT);
  pinMode(PIN_SERVO, OUTPUT);
  myServo.attach(PIN_SERVO);
}

void loop() {
  
  poten_value = analogRead(PIN_POTEN);
  angle = map(poten_value, 0, 1023, 0, 180);
  myServo.write(angle);

  if(poten_value <= 314){
    analogWrite(LED_PIN_R, 255);  // Rojo al máximo
    analogWrite(LED_PIN_G, 0);   // Verde apagado
    analogWrite(LED_PIN_B, 0);    // Azul apagado
  }else{
    if(poten_value > 314 && poten_value >= 628){
    analogWrite(LED_PIN_R, 0);  // Rojo al máximo
    analogWrite(LED_PIN_G, 255);   // Verde apagado
    analogWrite(LED_PIN_B, 0);    // Azul apagado
    }else{
      analogWrite(LED_PIN_R, 0);  // Rojo al máximo
      analogWrite(LED_PIN_G, 0);   // Verde apagado
      analogWrite(LED_PIN_B, 255);    // Azul apagado
    }
  }

  delay(15);
}
