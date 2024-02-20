


//Include the library files
#include <Wire.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
Servo myservo;  // create servo object to control a servo


#define BLYNK_TEMPLATE_ID "TMPL3X4caFjTm"
#define BLYNK_TEMPLATE_NAME "Medicine Dispenser Machine"
#define BLYNK_AUTH_TOKEN "1kLrDBq9swJRGsRHkLrdujIoRC3ffw2v"
 

char ssid[] = "AAA";              // Your WiFi credentials.    //type wifi name
char pass[] = "123456789";                  // passward
char auth[] = BLYNK_AUTH_TOKEN;             // You should get Auth Token in the Blynk App.

int buzzer = D5;
//int vibrator = D6;
int newTime = 0;
int pos=90;


BLYNK_WRITE(V1) {
  int Time = param.asInt();

  newTime = Time * 60 * 1000;
  Serial.print (newTime);
  delay(newTime);

  digitalWrite(buzzer, HIGH);
  // digitalWrite(vibrator, HIGH);
  delay (3000);
  digitalWrite (buzzer, LOW);
  myservo.write(pos);
  delay (100);
  digitalWrite(buzzer, LOW);
  delay (180000);



 digitalWrite(buzzer, HIGH);
  // digitalWrite(vibrator, HIGH);
  delay (3000);
  digitalWrite (buzzer, LOW);
  myservo.write(180);
  delay (100);
  digitalWrite(buzzer, LOW);
  delay (180000);



 digitalWrite(buzzer, HIGH);
  // digitalWrite(vibrator, HIGH);
  delay (3000);
  digitalWrite (buzzer, LOW);
  myservo.write(270);
  delay (100);
  digitalWrite(buzzer, LOW);
  delay (180000);




 digitalWrite(buzzer, HIGH);
  // digitalWrite(vibrator, HIGH);
  delay (3000);
  digitalWrite (buzzer, LOW);
  myservo.write(360);
  delay (100);
  digitalWrite(buzzer, LOW);
  delay (5000);






}
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  myservo.attach(D6);  // attaches the servo on GIO2 to the servo object
  myservo.write(0);
  Blynk.begin(auth, ssid, pass);

  pinMode (buzzer, OUTPUT);
  // pinMode(vibrator, OUTPUT);

}

void loop()
{
  // put your main code here, to run repeatedly:
  Blynk.run();//Run the Blynk library
  // Blynk.virtualWrite(V1, 0);
  // Blynk.virtualWrite(V1, 0);

}
