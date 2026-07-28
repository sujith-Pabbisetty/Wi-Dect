# WiDect

WiDect is an IoT-based Wi-Fi signal disturbance detection system built using the ESP8266 NodeMCU.

The system continuously monitors Wi-Fi RSSI (Received Signal Strength Indicator) values. Significant changes in RSSI indicate disturbances in the wireless path, allowing the system to detect the presence of a person or large obstacle.

When a disturbance is detected, the system:

- Displays the detection status on an I2C LCD
- Activates a buzzer
- Indicates Wi-Fi connection using an LED

---

## Features

- Wi-Fi RSSI monitoring
- Automatic baseline calibration
- Human/obstacle disturbance detection
- LCD status display
- Buzzer alert
- Wi-Fi status LED
- Low-cost hardware
- Standalone operation using power bank

---

## Hardware

- ESP8266 NodeMCU
- 16x2 I2C LCD
- Active buzzer
- LED
- 220Ω resistor
- Breadboard
- Jumper wires
- USB cable / Power bank

---

## Software

- Arduino IDE
- ESP8266 Board Package
- ESP8266WiFi Library
- LiquidCrystal_I2C
- Wire Library

---

## Working Principle

1. ESP8266 connects to Wi-Fi.
2. A baseline RSSI is recorded.
3. RSSI is continuously monitored.
4. If the RSSI deviation exceeds a threshold,
   - LCD displays "Human Detected"
   - Buzzer turns ON
5. Otherwise the system reports "No Disturbance."

---

## Applications

- Indoor intrusion awareness
- Presence detection
- Wireless sensing demonstrations
- Educational IoT projects
- Smart occupancy monitoring

---

## Limitations

- RSSI fluctuations depend on environmental conditions.
- The system detects signal disturbances; it does not identify or recognize specific objects.
- Performance varies with Wi-Fi interference and obstacle placement.

---

## Future Improvements

- ESP32-CAM integration
- Telegram notifications
- Mobile dashboard
- Data logging
- Machine-learning-based classification
