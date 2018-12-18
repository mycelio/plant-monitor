#include <CapacitiveSensor.h>

// configure sensor pins
const int photosensor = A0;
CapacitiveSensor capsensor = CapacitiveSensor(2, 4); // 1M resistor between pins 2 and 4



// values that will change throughout the loop
int photosensorValue = 0;
int capsensorValue = 0;


// initial setup
void setup() {
  pinMode(photosensor, INPUT);
  Serial.begin(9600);
}

void loop() {

  // read photsensor values
  photosensorValue = analogRead(photosensor);
  
  // print photosensor values to Serial
  Serial.print("photosensor = ");
  Serial.print(photosensorValue);
  Serial.println("");



  // read capacitor values
  capsensorValue = capsensor.capacitiveSensor(30);

  // print capacitor values to Serial
  Serial.print("capsensor = ");
  Serial.print(capsensorValue);
  Serial.println("");
  
  delay(500);

}
