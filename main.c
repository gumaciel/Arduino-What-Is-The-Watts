//What Is The Watts?
#include "EmonLib.h"
#include <LiquidCrystal.h>

EnergyMonitor emon1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int rede = 110.0;
int pino_sct = 1;

void setup(){
	lcd.begin(16, 2);
	lcd.clear();
	Serial.begin(9600);
	emon1.current(pino_sct, 29);
	lcd.setCursor(0,0);
	lcd.print("EaE – calc.Watts");
	lcd.setCursor(0,1);
	lcd.print("Watts:");
}

void loop(){
	double Irms = emon1.calcIrms(1480);
  
	Serial.print("Potencia: ");
	Serial.println(Irms*rede);
	lcd.setCursor(8,1);
	lcd.print(Irms*rede);
	delay(900); 	
}
