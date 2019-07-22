#include <LiquidCrystal.h>


int motorPin1 = 9;
int tempPin = 0;
int motorSpeed;
int temperature;
int rpm;
int motorSpeed_temp = 0;
int diodePin = 8;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

 	 pinMode(motorPin1, OUTPUT);
  	 pinMode(diodePin, OUTPUT);
 	
     motorSpeed = 0; 
	 temperature = 0;	
 	 rpm = 0;	
  	 motorSpeed_temp = 0;		
  
	 lcd.begin(16, 2); 
  	 lcd.print("LCD ON");
}

void loop() {
 
		
  
  int temp = analogRead(tempPin);  
 
 
  temperature = getTemperature(temp);
  
  if(temperature < 50)
    motorSpeed = 0;
  
  else if(temperature > 50 && temperature < 80)
    motorSpeed = 77;
    
	else if(temperature > 80 && temperature < 95)
         motorSpeed = 153;
    
    else if(temperature > 95 && temperature < 110)
    	motorSpeed = 200;
   
    else 
    	motorSpeed = 250;
   
    	
      analogWrite(motorPin1, motorSpeed); 
    
    	if(motorSpeed!=0)
    		digitalWrite(diodePin, HIGH);
   		else
    		digitalWrite(diodePin, LOW);
    
    rpm = motorSpeed*13.75;
    
    lcd.setCursor(0, 0);
   	
  	if(motorSpeed_temp !=motorSpeed)
    	lcd.clear();
    
    
    if(motorSpeed!=0)
  		lcd.print("FAN ON");
    	else
    	lcd.print("FAN OFF");
    
    lcd.setCursor(0,1);
    	lcd.print("SPEED:");
  		lcd.print(rpm);
  		lcd.print("RPM");
  	
  
  	motorSpeed_temp = motorSpeed;
  
   }


float getTemperature(int temp){
	
   float voltage = temp * 5.0;
 	voltage /= 1024.0; 
 	float temperatureC = (voltage - 0.5) * 100 ;
  
  return temperatureC;
  
}