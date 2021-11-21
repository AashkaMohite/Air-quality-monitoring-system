#include <LiquidCrystal_I2C.h>
#include "MQ135.h"
#define ANALOGPIN A2    //  Define Analog PIN on Arduino Board
#define RZERO 206.85    //  Define RZERO Calibration Value
MQ135 gasSensor = MQ135(ANALOGPIN);
LiquidCrystal_I2C lcd(0x27, 16,2);
void setup()
{ 

  lcd.init(); 
  lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();
  Serial.begin(9600);
  float rzero = gasSensor.getRZero();
  delay(3000);
  Serial.print("MQ135 RZERO Calibration Value : ");
  Serial.println(rzero);
}

void loop() {
  float ppm = gasSensor.getPPM();
  delay(1000);
  Serial.print("CO2 ppm value : ");
  Serial.println(ppm);
  lcd.setCursor(0,0);
  lcd.print("   Tech Maker   ");
  lcd.setCursor(0,1);
  lcd.print("CO2 : ");
  lcd.print(ppm);
  lcd.print("PPM");
  
}
