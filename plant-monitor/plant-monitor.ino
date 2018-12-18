#include <CapacitiveSensor.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHTTYPE DHT11


// configure sensor pins
const int lightSensor = A0;
const int moistureSensor = A1;
CapacitiveSensor touchSensor = CapacitiveSensor(2, 4);
DHT dht(8, DHTTYPE);



// values that will change throughout the loop
int lightValue = 0;
int touchValue = 0;
int moistureValue = 0;
int humidityValue = 0;
int temperatureValue = 0;


// initial setup
void setup() {
  pinMode(lightSensor, INPUT);
  pinMode(moistureSensor, INPUT);
  dht.begin();
  Serial.begin(9600);
}

void loop() {

  // read sensor values
  lightValue = analogRead(lightSensor);
  touchValue = touchSensor.capacitiveSensor(30);
  moistureValue = analogRead(moistureSensor);
  humidityValue = dht.readHumidity();
  temperatureValue = dht.readTemperature();

  //  print values to Serial
  Serial.print("moisture: ");
  Serial.print(moistureValue);
  Serial.print("\t"); // spacing
  
  Serial.print("temperature: ");
  Serial.print(temperatureValue);
  Serial.print("\t"); // spacing
  
  Serial.print("humidity: ");
  Serial.print(humidityValue);
  Serial.print("\t"); // spacing

  Serial.print("light: ");
  Serial.print(lightValue);
  Serial.print("\t"); // spacing
  
  Serial.print("touch: ");
  Serial.print(touchValue);
  Serial.print("\t"); // spacing
  
  Serial.print("\n"); // new line

  // delay of 1s
  delay(1000);

}
