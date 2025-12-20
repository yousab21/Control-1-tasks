#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int desiredTemp = 40;
const int heaterPin = 7;

void turnOnHeater() {
  digitalWrite(heaterPin, HIGH);
}

void turnOffHeater() {
  digitalWrite(heaterPin, LOW);
}

int sensor() {
  int reading = analogRead(A0);
  float volts = (reading / 1023.0) * 5.0;
  int temp = volts * 100;
  return temp;
}

void setup() {
  pinMode(heaterPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  turnOffHeater();
}

void loop() {
  delay(250);

  int temperature = sensor();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C   ");

  if (temperature >= desiredTemp) {
    turnOffHeater();
  } else {
    turnOnHeater();
  }
}
