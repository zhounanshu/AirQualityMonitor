int Led=13;                           //定义LED 接口
int buttonpin=3;                      //定义传感器D0接口
int AO = 8;
int DO = 9;
int val,ain,din;                              //定义数字变量val
void setup(){
      pinMode(Led,OUTPUT);                    //定义LED 为输出接口
      pinMode(buttonpin,INPUT);               //定义传感器D0为输出接口
      pinMode(ain,INPUT);
      pinMode(din,INPUT);
      Serial.begin(9600);
}
void loop(){
         ain = digitalRead(ain);
         din = digitalRead(din);
         Serial.print("AO:");
         Serial.print(ain);
         Serial.print("   ");
         Serial.print("DO:");
         Serial.print(din);
         Serial.println("");
        
       
//      val=digitalRead(buttonpin);     //将数字接口3的值读取赋给val
//      if(val==HIGH){                  //当声音检测模块检测有信号时，LED 闪烁
//          digitalWrite(Led,HIGH);
//      }
//      else{
//          digitalWrite(Led,LOW);
//      }
}

//
//int sensorPin = 5;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
//int sensorValue = 0;  // variable to store the value coming from the sensor
//
//void setup() {
// pinMode(ledPin, OUTPUT); 
//  Serial.begin(9600); 
//}
//
//void loop() {
// 
//  sensorValue = analogRead(sensorPin);    
//  digitalWrite(ledPin, HIGH);  
// delay(sensorValue);          
//  digitalWrite(ledPin, LOW);   
// delay(sensorValue);
// Serial.println(sensorValue, DEC);  
//}
//


