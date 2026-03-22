#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo horizontal; 
int servoh = 90; // Starting angle

Servo vertical; 
int servov = 45; // Starting angle

// LDR Pin Connections
int ldrlt = A0; // Top Left
int ldrrt = A1; // Top Right
int ldrld = A2; // Down Left
int ldrrd = A3; // Down Right

void setup() {
  horizontal.attach(9); 
  vertical.attach(10);
  horizontal.write(servoh);
  vertical.write(servov);
  delay(1000);
}

void loop() {
  int lt = analogRead(ldrlt);
  int rt = analogRead(ldrrt);
  int ld = analogRead(ldrld);
  int rd = analogRead(ldrrd);
  
  int avt = (lt + rt) / 2; // Average Top
  int avd = (ld + rd) / 2; // Average Down
  int avl = (lt + ld) / 2; // Average Left
  int avr = (rt + rd) / 2; // Average Right

  // Vertical movement logic
  if (avt > avd) {
    servov = ++servov;
    if (servov > 180) servov = 180;
  } else if (avt < avd) {
    servov= --servov;
    if (servov < 0) servov = 0;
  }
  vertical.write(servov);

  // Horizontal movement logic
  if (avl > avr) {
    servoh = --servoh;
    if (servoh < 0) servoh = 0;
  } else if (avl < avr) {
    servoh = ++servoh;
    if (servoh > 180) servoh = 180;
  }
  horizontal.write(servoh);
  
  delay(50); // Adjust for tracking speed
}
