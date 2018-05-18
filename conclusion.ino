const int trigger = A4;
const int echo = A3;
const int trigger1 = A0;
const int echo1 = A1;
int vcc = A5;
int gnd = A2;
int LED1 = 3;
int LED2 = 5;
int LED3 = 6;
int LED4 = 9;
int LED5 = 10;
int LED6 = 11;

long Time;
float distanceCM;
float distanceM;
float distance = 20; // set threshold distance in cm
int dim = 3; // adjust minimum brightness
int bright = 50; // adjust maximum brightness
float resultCM;
float resultM;
void setup()
{
pinMode(LED1,OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(trigger1, OUTPUT);
pinMode(echo1, INPUT);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
pinMode(vcc,OUTPUT);
pinMode(gnd,OUTPUT);
Serial.begin(9600);
}
void loop()
{
if(digitalRead(echo)==HIGH || digitalRead(echo)==LOW)
{digitalWrite(vcc,HIGH);
digitalWrite(gnd,LOW);
digitalWrite(trigger,LOW);
delay(10);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);
Time=pulseIn(echo,HIGH);
distanceCM=Time*0.034;
resultCM=distanceCM/2;
resultM=resultCM/100;
Serial.print("Distance in cm: ");
Serial.println(resultCM);
Serial.print("Distance in meter: ");
Serial.println(resultM);
Serial.println("------------------------------------------");
/*if(resultCM==5)
{
analogWrite(LED, bright);
analogWrite(LED1,bright);
delay(10);
}*/
if(resultCM<distance && resultCM>0)
{
analogWrite(LED1,bright);
analogWrite(LED2, bright);
analogWrite(LED3, bright);
//delay(10000);





}

else
{
analogWrite(LED1, dim);
analogWrite(LED2,dim);
analogWrite(LED3, dim);
delay(10);
}
}
if(digitalRead(echo1)==HIGH || digitalRead(echo1)==LOW)
{digitalWrite(vcc,HIGH);
digitalWrite(gnd,LOW);
digitalWrite(trigger1,LOW);
delay(10);
digitalWrite(trigger1,HIGH);
delayMicroseconds(10);
digitalWrite(trigger1,LOW);
Time=pulseIn(echo1,HIGH);
distanceCM=Time*0.034;
resultCM=distanceCM/2;
resultM=resultCM/100;
Serial.print("Distance in cm: ");
Serial.println(resultCM);
Serial.print("Distance in meter: ");
Serial.println(resultM);
Serial.println("------------------------------------------");
/*if(resultCM==5)
{
analogWrite(LED, bright);
analogWrite(LED1,bright);
delay(10);
}*/
if(resultCM<distance && resultCM>0)
{
analogWrite(LED4,bright);
analogWrite(LED5, bright);
analogWrite(LED6, bright);
//delay(10000);
}
else
{
analogWrite(LED4, dim);
analogWrite(LED5,dim);
analogWrite(LED6, dim);
delay(10);
}
}
}

