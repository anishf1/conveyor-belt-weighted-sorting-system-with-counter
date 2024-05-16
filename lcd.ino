/* TITLE: Counter UP-DOWN
 * AUTHOR: Anish Patel
 * 
 * INFO:
 * Arduino Uno has two dedicated pins to handle interruptions. They are Pin 2 and 3.
 * There are two tactil switches. The first one connected in Pin 2 (UP Switch)
 * The second switch is connected in Pin 3 (Down Switch) 
 * Both inputs have a Pull-Up resistor of 10K each and both switches are connected between its respective input and ground.
 * Each active output is connected with a 300 Ohm resistor and an LED.
 * Avoid Use Pin 13 Because is the LED to show Serial Tx 
 
 The Atmega ADK intertups are: 
 
 Pin 2 (interrupt 0)
 Pin 3 (interrupt 1)
 
 Pin 21 (interrupt 2)
 Pin 20 (interrupt 3)
 Pin 19 (interrupt 4)
 Pin 18 (interrupt 5)
*/ 

#include <stdio.h>
#include <math.h>
#include <LiquidCrystal.h>
#include <stdlib.h>

#define LOWER_DIGITAL_PIN 21                // In this code the lower Digital output Pin is Number 22, therfore the constant must be 22 -1 = 21
#define MAX_DIGITAL_PIN_OUTPUT 32           // In this code the Maximum Digital Output Pin is 32 Therfore the constant must be 32 )
#define INTERRUPTION_TWO 2                  // Atmega ADK pin 21 is the Interruption Number 2
#define INTERRUPTION_THREE 3                // Atmega ADK pin 21 is the Interruption Number 3
#define PIN_INTERRUPTION_TWO 21             // Atmega ADK pin 21 is the Interruption Number 2
#define PIN_INTERRUPTION_THREE 20           // Atmega ADK pin 20 is the Interruption Number 3

int counter = LOWER_DIGITAL_PIN; 
int counter2 = 0;
int x1;
int prex1 = 1;
int preprex1 = 1;
int x2;
int prex2 = 1;
int preprex2 = 1;

char str[2];                             

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);




void setup() {
	
  Serial.begin(9600);

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
 
 	
 /* Define Outputs */
     
     	pinMode(PIN_INTERRUPTION_THREE,INPUT); 
	pinMode(PIN_INTERRUPTION_TWO,INPUT);
      
  for (int z = LOWER_DIGITAL_PIN + 1; z <= MAX_DIGITAL_PIN_OUTPUT; z ++)
  {
        pinMode(z,OUTPUT);
        
  }
	
	
/*  Set all outputs LOW */  

  for (int y = LOWER_DIGITAL_PIN + 1; y <= MAX_DIGITAL_PIN_OUTPUT; y ++)
  {
	 digitalWrite(y,LOW);
  }
	

 /* Define Interruptions */

  attachInterrupt(INTERRUPTION_TWO, updateX1,CHANGE);
  attachInterrupt(INTERRUPTION_THREE, updateX2,CHANGE);
}


void loop()
{
  
  
  }
   

/* Interruption UP */   

 void updateX1(){
	 
	x1 = digitalRead(PIN_INTERRUPTION_TWO); 
if ( x1 == 0 &&  counter < MAX_DIGITAL_PIN_OUTPUT && x1 != prex1 && x1 != preprex1 ) {
     digitalWrite(counter,0);
     counter ++;
     counter2 ++;
     digitalWrite(counter,1);
     
     sprintf(str, "%d", counter2);
     
     lcd.setCursor(10,0);
     
     if ( counter2 < 10 ){
       lcd.write(" ");
     }
       
       lcd.write(str);
    }
	
	prex1 = digitalRead(PIN_INTERRUPTION_TWO);

	
	preprex1 = digitalRead(PIN_INTERRUPTION_TWO);

 }


/* Interruption DOWN */   

 void updateX2(){
	
        
	x2 = digitalRead(PIN_INTERRUPTION_THREE); 
if ( x2 == 0 &&  counter > LOWER_DIGITAL_PIN  && x2 != prex2 && x2 != preprex2 ) { 
    digitalWrite(counter,0);
    counter --;
    counter2 --;
    digitalWrite(counter,1);
    
    sprintf(str, "%d", counter2);
    
    lcd.setCursor(10,0);
    
      if ( counter2 < 10 ){
       lcd.write(" ");
     }
    
    
    lcd.write(str);
    
    
    }
	
	prex2 = digitalRead(PIN_INTERRUPTION_THREE);

	
	preprex2 = digitalRead(PIN_INTERRUPTION_THREE);

 }
