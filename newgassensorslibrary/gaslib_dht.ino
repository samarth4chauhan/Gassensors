#include "Gassensors.h"
#include "DHT.h"
#include<DHT_U.h>
#include<Adafruit_Sensor.h>


#define         DHTPIN                       (2)
#define         MQ2PIN                       (1)  //define which analog input channel you are going to use
#define         MQ6PIN                       (2)
#define         MQ7PIN                       (3)
#define         MQ8PIN                       (4)
#define         MQ135PIN                     (0)

#define         DHTTYPE                      DHT22   // DHT 22  (AM2302)    
int Gassensor_type[] = {MQ2,MQ3,MQ4,MQ5,MQ6,MQ7,MQ8,MQ9,MQ135};
float               Ro = 0, Pm25 = 0, Pm10 = 0;                    //Ro is initialized to 0 kilo ohms

DHT dht(DHTPIN, DHTTYPE);
Gassensors gs2(MQ2PIN,Gassensor_type[0]);
Gassensors gs6(MQ6PIN,Gassensor_type[4]);
Gassensors gs7(MQ7PIN,Gassensor_type[5]);
Gassensors gs8(MQ8PIN,Gassensor_type[6]);
//Gassensors gs9(MQ9PIN,Gassensor_type[7]);
Gassensors gs135(MQ135PIN,Gassensor_type[8]);

void setup() {
  Serial.begin(9600);                                   //UART setup, baudrate = 9600bps
  dht.begin();
}

void loop() {
 /* /*  //Serial.println(analogRead(MQ135PIN));
/*Serial.print("mq values");
  Serial.println(Gassensor_type[0]);
  Serial.println(Gassensor_type[1]);
  Serial.println(Gassensor_type[2]);
  Serial.println(Gassensor_type[3]);
   Serial.print("adc reading pin4: ");
  Serial.print(gs4.MQRead(MQ4PIN));
    delay(500);
  //Serial.print(Ro);
  
       Serial.print("rs/ro reading pin4: ");
       //gs4.rs_ro_ratio(MQ4PIN);
  Serial.print(gs4.rs_ro_ratio(MQ4PIN));
   //Serial.print("printed value: ");
    delay(500);
  //Serial.print(Ro);
  
   Serial.print("       adc reading pin2: ");
  Serial.print(gs2.MQRead(MQ2PIN)); 
  delay(500);
  //Serial.print(Ro);


   Serial.print("       rs/ro reading pin2: ");
  Serial.println(gs2.rs_ro_ratio(MQ2PIN)); 
  delay(500);
  //Serial.print(Ro);*/
//Serial.print(Gas_Name);
//delay(5000);

/****************** DHT22 Temperature sensor code ****************************************/

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  float hi = dht.computeHeatIndex(f, h);
  Serial.println(F("DHT22 sensor output "));
  Serial.print(F("Humidity:")); 
  Serial.print(h);
  Serial.print(F(" %\t"));
  Serial.print(F("  Temperature(Deg):")); 
  Serial.print(t);
  Serial.println(F(" *C\t "));

  
/****************** MQ Gas sensors code ****************************************/

 gs2.printallgases(Gassensor_type[0]);
  //delay(200);
 // gs3.printallgases(Gassensor_type[1]);
  //delay(200);
  //gs4.printallgases(Gassensor_type[2]);
  //delay(200);
  //gs5.printallgases(Gassensor_type[3]);
  //delay(200);
  gs6.printallgases(Gassensor_type[4]);
  //delay(200);
  gs7.printallgases(Gassensor_type[5]);
  //delay(200);
 s8.printallgases(Gassensor_type[6]);
  //delay(200);
  gs135.printallgases(Gassensor_type[8]);
  //delay(200);*/
}

