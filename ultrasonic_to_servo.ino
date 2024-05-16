
#include <stdio.h>
#include <math.h>
#include <LiquidCrystal.h>
#include <stdlib.h>
#include<Servo.h>

  char str[2];                             
  LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
  int trig=8;
  int echo=9;
  int dt=10;
  int items=0;
  Servo servo;
  
void setup(){
  Serial.begin(9600);
  servo.attach(11);
  lcd.begin(2, 16);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TOT:");
  lcd.setCursor(4,0);
  lcd.print("00");
  lcd.setCursor(7,0);
  lcd.print("WEI:");
  lcd.setCursor(11,0);
  lcd.print("000g");
  lcd.setCursor(0,1);
  lcd.print("LIGHT:");
  lcd.setCursor(6,1);
  lcd.print("00"); 
  lcd.setCursor(9,1);
  lcd.print("HEAV:");
  lcd.setCursor(14,1);
  lcd.print("00"); 
 
//int distance,duration;
// put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}

void loop()
{
  if (calc_dis()<10)
{
    for (int i=0;i<=540;i++)
  {
      servo.write(i);
     delay(1);
  }
    delay(100);
     
     for (int i=540;i>=0;i--)
  {
      servo.write(i);
      delay(1);
  }
     delay(100);

      items= items+1;
      sprintf(str, "%d", items);
      lcd.setCursor(5,0);
      lcd.print(str);
      
      {
      while items<9;
      sprintf(str, "%d", items);
      lcd.setCursor(4,0);
      lcd.print(str);
      
}
}
}
 
//This code is written to calculate the DISTANCE using ULTRASONIC SENSOR

  int calc_dis()
{
  int duration,distance;
  digitalWrite(trig,HIGH);
  delay(dt);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}


