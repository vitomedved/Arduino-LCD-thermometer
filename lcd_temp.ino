#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float temp;
const char cel = 223;

void printText();
void readTemp();
void printTemp();

void setup() {
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  printText();
  readTemp();
  printTemp();
  delay(800);
}

void printText(){
  lcd.setCursor(0, 0);
  lcd.print("THERMOMETER");
}

void readTemp(){
    temp = (5.0 * analogRead(A0) * 100.0) / 1024;
}

void printTemp(){
  Serial.println(temp);
  
  lcd.setCursor(2, 1);
  lcd.print("Temp.: ");
  lcd.setCursor(9, 1);
  lcd.print(temp);
  lcd.print(cel);
  lcd.print("C");
}

