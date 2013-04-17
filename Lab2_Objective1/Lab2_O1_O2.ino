#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int out1;
int LED=13;
boolean heatOnOff;


boolean heaterState(int setTemp){     //heater function takes an input set temperature value
  int curTemp = analogRead(A1);       //heater reads the current voltage (current temperature)
  int setTempConv = setTemp/.005;     //convert arduino bit units into celsius or voltage scale
  
  if (curTemp <= setTempConv){        //Turn heater if current temp is less than desired temp
    heatOnOff = HIGH;
    return heatOnOff;
  }
  if (curTemp > setTempConv){         //Turn heater off if current temp is greater than desired temp
    heatOnOff = LOW;
    return heatOnOff;
  }
  
  if (heatOnOff == HIGH && curTemp > 1.5){
    heatOnOff = LOW;
    return heatOnOff;
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("TOO HOT");
    lcd.setCursor(0,1);
    lcd.print("Turning Off");
  }

}

// The code below demonstrates the functionality of our function

void setup(){
 pinMode(LED,OUTPUT);
}

void loop(){
  heatOnOff= heaterState(1);
  digitalWrite(LED, heatOnOff);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(heatOnOff);
  delay(200);
  
} 




