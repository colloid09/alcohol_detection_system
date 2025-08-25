#define MQ3pin 0
float sensorValue; //variable to store sensor value
const int buzzer = 8;
int leb = 4;
void setup() {
 Serial.begin(9600); // sets the serial port to 9600
 Serial.println("MQ3 warming up!");
 pinMode(leb, OUTPUT);
 pinMode(buzzer, OUTPUT);
 delay(20000); // allow the MQ3 to warm up
}

void loop() {
 sensorValue = analogRead(MQ3pin); // read analog input pin 0
  
 Serial.print("Sensor Value: ");
 Serial.println(sensorValue);
 if(sensorValue>100){
   Serial.print("Alcohol Detected ");
   digitalWrite(leb,HIGH);
     tone(buzzer, 1000); // Send 1KHz sound signal...
 delay(1000); // ...for 1 sec
 noTone(buzzer);
    // Stop sound...
   digitalWrite(leb,LOW);
 delay(1000); 
 }
 delay(2000); // wait 2s for next reading
}
