#include <LiquidCrystal.h>

/*
=====================================================
Project: Non-Invasive Neonatal Bilirubin Estimation
Platform: Arduino / ESP32
Sensor: Optical Reflectance (Blue Channel Analysis)

Note:
This is a prototype-level biomedical diagnostic system
using optical reflectance mapping for bilirubin estimation.
=====================================================
*/

// LCD configuration
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);

// Sensor pins
#define S0 6
#define S1 7
#define S2 4
#define S3 3
#define sensorOut 5

#define statusLED 2

// Calibration constants (to be refined with clinical dataset)
#define FREQ_MIN 40
#define FREQ_MAX 120

// Global variable
float bilirubin_estimate = 0;

// ---------------- SENSOR READING ----------------
int readBlueFrequency() {
  long sum = 0;

  for (int i = 0; i < 10; i++) {
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    delay(20);
    sum += pulseIn(sensorOut, LOW);
  }

  return sum / 10;
}

// ---------------- CONVERSION MODEL ----------------
float convertToBilirubin(int freq) {
  float value = map(freq, FREQ_MIN, FREQ_MAX, 0, 300) / 100.0;

  if (value < 0) value = 0;
  if (value > 5) value = 5;

  return value;
}

// ---------------- DISPLAY FUNCTION ----------------
void displayData(float value) {
  lcd.setCursor(0, 0);
  lcd.print("Bili:");
  lcd.print(value);
  lcd.print(" mg/dL   ");

  lcd.setCursor(0, 1);

  if (value <= 1.2) {
    lcd.print("Normal        ");
    digitalWrite(statusLED, LOW);
  }
  else if (value <= 3.0) {
    lcd.print("Mild          ");
    digitalWrite(statusLED, HIGH);
  }
  else {
    lcd.print("High Risk     ");
    digitalWrite(statusLED, HIGH);
  }
}

// ---------------- SETUP ----------------
void setup() {

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(statusLED, OUTPUT);

  lcd.begin(16, 2);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW); // 20% scaling

  Serial.begin(9600);

  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

// ---------------- LOOP ----------------
void loop() {

  int blueFreq = readBlueFrequency();

  bilirubin_estimate = convertToBilirubin(blueFreq);

  Serial.print("Freq: ");
  Serial.print(blueFreq);
  Serial.print(" | Bili: ");
  Serial.println(bilirubin_estimate);

  displayData(bilirubin_estimate);

  delay(2000);
}
