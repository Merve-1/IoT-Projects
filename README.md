# Pharmaceutical Cargo Monitoring System

## Sender Circuit

### Components:
- **Arduino Mega:** Central control unit.
- **GPS Neo6 Module:** Determines accurate location data.
- **DHT22 Sensor:** Measures temperature and humidity.
- **SIM800L Module:** GSM/GPRS modem for sending SMS messages.

### Key Functions:
- `setup()`: Initializes serial communication and modules.
- `loop()`: Collects temperature, humidity, and location data. Sends SMS every 10 seconds.
- `updateSerial()`: Forwards data between Arduino's hardware serial and software serial.
- `send_SMS()`: Initializes SIM800L module, configures text mode, and sends SMS with data.

### DHT22 Sensor and Neo6 GPS Handling:
- Temperature and humidity obtained using `get_temp()` from DHT22 sensor.
- Location data (latitude and longitude) obtained using `get_location()` and `displayInfo()` from Neo6 GPS module.

## Receiver Circuit

### Components:
- **ESP8266 Module:** Equipped with Wi-Fi capabilities.
- **SIM800L Module:** Connected to ESP8266 for receiving SMS messages.

### Key Functions:
- `setup()`: Connects to Wi-Fi, initializes serial communication, and configures SIM800L module.
- `loop()`: Forwards data between Arduino and SIM800L module.

### Functions:
- `updateSerial()`: Forwards data between Arduino and SIM800L module. Parses received SMS data.
- SMS Data Parsing: Extracts temperature, humidity, latitude, and longitude values.

### Overall Purpose:
- Sender: Collects and sends pharmaceutical cargo data via SMS (temperature, humidity, location).
- Receiver: Receives SMS, extracts data, and transmits it over Wi-Fi for further processing.

### Instructions:
1. **Sender Circuit:**
   - Connect Arduino Mega to GPS Neo6, DHT22, and SIM800L modules.
   - Power the circuit with two batteries.
   - Ensure correct wiring and connections.

2. **Receiver Circuit:**
   - Connect ESP8266 to SIM800L module.
   - Power the circuit with two batteries.
   - Set correct Wi-Fi credentials (SSID and password).
   - Confirm proper wiring.

3. **Operation:**
   - Deploy sender and receiver circuits in cargo transport.
   - Monitor received data through the Wi-Fi connection of the receiver.

4. **Additional Notes:**
   - Customize SMS recipient number in the `send_SMS()` function.
   - Ensure strong network signals for reliable SMS transmission.

### Troubleshooting:
- Check Wi-Fi network credentials in the receiver circuit.
- Confirm proper power supply to all modules.
- Verify correct wiring and connections.
- Monitor Serial Monitor outputs for debugging.
