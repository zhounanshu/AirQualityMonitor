//int Led=13;
//int buttonpin=3 ;
//int val;
//void setup(){
//    pinMode(Led,OUTPUT);
//    pinMode(buttonpin,INPUT);
//    Serial.begin(9600);
//}
//
//void loop()
//{
//    val=digitalRead(buttonpin);
//    Serial.println(val);
//    if(val==HIGH){
//        digitalWrite(Led,HIGH);
//     }
//    else{
//        digitalWrite(Led,LOW);}
//}
//



int sensorPin = A5; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
    sensorValue = analogRead(sensorPin);
    digitalWrite(ledPin, HIGH);
    delay(sensorValue);
    digitalWrite(ledPin, LOW);
    delay(sensorValue);
    Serial.println(sensorValue, DEC);
}
