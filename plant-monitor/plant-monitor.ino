// constants
const int photosensor = A0;


// values that will change throughout the loop
int photosensorValue = 0;


// initial setup
void setup() {
  pinMode(photosensor, INPUT);
  Serial.begin(9600);
}

void loop() {

  // read the potenciometer value
  photosensorValue = analogRead(photosensor);


  // print photosensor values to Serial
  Serial.print("photosensor = ");
  Serial.print(photosensorValue);
  Serial.println("");

  delay(100);

}
