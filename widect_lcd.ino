#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// WiFi
const char* ssid = //enter the wifi name;
const char* password = //enter the passoword;

// Pins
int wifiLED = D5;
int buzzer  = D3;   // NEW

// Detection variables
long baselineRSSI;
int threshold = 5;

// Get average RSSI
long getRSSI(int samples) {
  long total = 0;
  for (int i = 0; i < samples; i++) {
    total += WiFi.RSSI();
    delay(10);
  }
  return total / samples;
}

void setup() {

  pinMode(wifiLED, OUTPUT);
  pinMode(buzzer, OUTPUT);   // NEW

  digitalWrite(wifiLED, LOW);
  digitalWrite(buzzer, LOW);

  // I2C
  Wire.begin(D6, D7);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Connecting...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
  }

  digitalWrite(wifiLED, HIGH);  // WiFi LED ON

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WiFi Connected");

  delay(1000);

  // Calibration
  baselineRSSI = getRSSI(30);
}

void loop() {

  long rssi = getRSSI(5);
  int diff = abs(rssi - baselineRSSI);

  // Line 1 → RSSI
  lcd.setCursor(0,0);
  lcd.print("RSSI:");
  lcd.print(rssi);
  lcd.print("   ");

  // Line 2 → Detection
  lcd.setCursor(0,1);

  if (diff > threshold) {

    lcd.print("Human Detected ");

    digitalWrite(buzzer, HIGH);   // 🔊 BUZZER ON

  } else {

    lcd.print("No Disturbance ");

    digitalWrite(buzzer, LOW);    // 🔇 BUZZER OFF
  }
}