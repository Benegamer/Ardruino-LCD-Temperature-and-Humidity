/*
 *  Written from "Benegamer"
 *  Written on 28.October.2019
 *  
 *  This Code controlls an Adruino with an LCD Display (16 x 2)and the DHT11 Temperature and Humidity Sensor.
 *  Pins used for this project are :
 *                                  -Digital 7 for DHT11 Sensor
 *                                  -Analog 4 for SDA on LCD Display Controller
 *                                  -Analog 5 for SCL on LCD Display Controller
 *                                  -Ground(-) on DHT11 Sensor and GND on LCD Display Controller
 *                                  -5V on (+)DHT11 Sensor and VCC
 */

#include <LiquidCrystal_I2C.h>    
#include <dht.h>
#include <Wire.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

dht DHT;

#define DHT11_PIN 7 //Pin 7 for Data pin for DHT11. Change for different Pin!

void setup(){   //Used to Startup
  lcd.begin();  //Start the lcd Display
  lcd.setCursor(0,0); //Set the LCD Cursor on 0:0
  lcd.print("Startup"); //Print on the lCD Display "Startup"
}

void loop()
{
  double chk = DHT.read11(DHT11_PIN);
  if(DHT.temperature == -999){  //Check if Sensor has no Power
    lcd.begin();
    lcd.setCursor(0,0);
    lcd.print("Error"); //Print Error
  }else{
    lcd.begin();  //Screen setup
    lcd.setCursor(0,0); //Cursor on 0:0
    lcd.print("Temp="); 
    lcd.setCursor(6,0); //Cursor on 6:0
    lcd.print(DHT.temperature); //Temperatur print
    //Humidity
    lcd.setCursor(0,1); //Cursor on 0:1
    lcd.print("Hum= ");  //Print Hum
    lcd.setCursor(5,1); //Cursor on 5:1
    lcd.print(DHT.humidity);  //Humidity print
    delay(2000);    //Delay 
  }
}
