#include <CapacitiveSensor.h>

// configure sensor pins
const int photosensor = A0;
const int moisturesensor = A1;
CapacitiveSensor capsensor = CapacitiveSensor(2, 4); // 1M resistor between pins 2 and 4



// values that will change throughout the loop
int photosensorValue = 0;
int capsensorValue = 0;
int moisturesensorValue = 0;


// initial setup
void setup() {
  pinMode(photosensor, INPUT);
  pinMode(moisturesensor, INPUT);
  Serial.begin(9600);
}

void loop() {

  // read photsensor value
  photosensorValue = analogRead(photosensor);
  
  // print photosensor value to Serial
  Serial.print("photosensor = ");
  Serial.print(photosensorValue);
  Serial.println("");



  // read capacitor value
  capsensorValue = capsensor.capacitiveSensor(30);

  // print capacitor value to Serial
  Serial.print("capsensor = ");
  Serial.print(capsensorValue);
  Serial.println("");



  // read moisture sensor value
  moisturesensorValue = analogRead(moisturesensor);

  // print moisture values to Serial
  Serial.print("moisture = ");
  Serial.print(moisturesensorValue);
  Serial.println("");
  
  delay(500);

}
