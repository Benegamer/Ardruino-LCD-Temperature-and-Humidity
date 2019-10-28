#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
}

void loop()
{
 Sensor();
}


void Sensor(){
  int chk = DHT.read11(DHT11_PIN);
  if(DHT.temperature == -999){
    Serial.println("Error");
  }else{
  Serial.print("Temperature = " + DHT.temperature);
  }
  if(DHT.humidity == -999){
    
  }else{
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
  }
  delay(10000);
}
