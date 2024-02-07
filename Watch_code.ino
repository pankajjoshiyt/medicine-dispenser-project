


//Include the library files
#include <Wire.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define BLYNK_TEMPLATE_ID "TMPL3jq1LGyx9"
#define BLYNK_TEMPLATE_NAME "medicine dispensor"
#define BLYNK_AUTH_TOKEN "2ojkf3OG9-t3IkOJP_2V1U7rXbH5Qsla"


char ssid[] = "IoT";              // Your WiFi credentials.    //type wifi name
char pass[] = "7878787878";                  // passward
char auth[] = BLYNK_AUTH_TOKEN;             // You should get Auth Token in the Blynk App.

int buzzer=D5;
int vibrator= D6;
int newTime=0;


BLYNK_WRITE(V1) {
  int Time = param.asInt();

newTime = Time *60*1000;
Serial.print (newTime);
 delay(newTime);
 
    digitalWrite(buzzer, HIGH);
     digitalWrite(vibrator, HIGH);
     delay (10000);
     digitalWrite(buzzer, LOW);
     digitalWrite(vibrator, LOW); 


} 
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);

pinMode (buzzer, OUTPUT);
pinMode(vibrator, OUTPUT);

}

void loop() 
{
  // put your main code here, to run repeatedly:
Blynk.run();//Run the Blynk library
   // Blynk.virtualWrite(V1, 0);
   // Blynk.virtualWrite(V1, 0);

}
