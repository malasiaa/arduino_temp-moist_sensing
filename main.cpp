#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// moisture sensor
const int moisture_sensor_input = A2; // Connect sensor at analog pin A2
int moisture_sensor_value; // variable to store sensor value

// temperature sensor
#define ONE_WIRE_BUS 2 // Connect sensor at digital pin 2
OneWire oneWire(ONE_WIRE_BUS); // Initialize OneWire instance
DallasTemperature sensors(&oneWire); // Pass OneWire instance to DallasTemperature
float Celsius = 0;

// Red LED Pin
const int LED_PIN = 7; // Connect sensor at digital pin 7

void setup()
{
  sensors.begin(); // Initialize the temperature sensor
  Serial.begin(2400); // Initialize serial communication with a baud rate of 2400
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  // Read sensor data
  moisture_sensor_value = analogRead(moisture_sensor_input);
  sensors.requestTemperatures(); // Send command to get temperatures
  Celsius = sensors.getTempCByIndex(0); // Read temperature in Celsius

  // Print information on serial monitor
  Serial.print("Moisture value: ");
  Serial.print(moisture_sensor_value);
  Serial.print(" Temp value: ");
  Serial.print(Celsius);
  Serial.println(" C;");

  // Control LED based on moisture value
  // This condition is an example of what can be done to automate the plant watering
  if (moisture_sensor_value > 600) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  delay(2000); // Delay 1 second
}
