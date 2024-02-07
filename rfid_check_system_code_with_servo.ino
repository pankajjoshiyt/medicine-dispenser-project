//*******************************libraries********************************
//RFID-----------------------------
#include<Wire.h>
#include <ESP32Servo.h>

#include <SPI.h>
#include <MFRC522.h>

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>


//#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp32.h>


#define BLYNK_TEMPLATE_ID "TMPL3jq1LGyx9"
#define BLYNK_TEMPLATE_NAME "medicine dispensor"
#define BLYNK_AUTH_TOKEN "2ojkf3OG9-t3IkOJP_2V1U7rXbH5Qsla"


char ssid[] = "IoT";              // Your WiFi credentials.    //type wifi name
char pass[] = "7878787878";                  // passward
char auth[] = BLYNK_AUTH_TOKEN;             // You should get Auth Token in the Blynk App.


  


//************************************************************************
#define SS_PIN  5                                                                                                                             //D2
#define RST_PIN 2  //D0

//************************************************************************
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
//************************************************************************

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int pos = 0;
//int q;
const int trigPin = 21;
const int echoPin = 22;
long duration;
int distance;
int p = 0;
int state = 0;
int state2 = 0;
int led1 = 13;
int led2 = 14;
//int led3 =33;




int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int liquid1;
int liquid;


void setup() {

  Serial.begin(115200);
  //    WiFi.begin(ssid, pass);
  //Blynk.config(auth);

  SPI.begin();  // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite (led1, HIGH);
  digitalWrite (led2   , HIGH);
  //pinMode(q, OUTPUT);
  //digitalWrite (led3   , LOW);
  servo1.attach(33);

  servo2.attach(32);
  servo3.attach(26);
  servo4.attach(25);
  //Blynk.begin(auth, ssid, pass);
  blynk();
  delay(300);
int liquid1=200;
int liquid=200;
}



BLYNK_WRITE(V3) {
  liquid = param.asInt();
} 


BLYNK_WRITE(V7) {
  liquid1 = param.asInt();
} 



void blynk ()
{
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  delay (300);
}
void  dis()
{ //digitalWrite(q,HIGH);
  p = 0;
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2.000;
  p = distance;
  Serial.println(p);

}




void bly1()
{
  count2 = 1 + count2;
  Blynk.virtualWrite(V4, count2);
}

void bly2()
{
  count3 = 1 + count3;
  Blynk.virtualWrite(V6, count3);
}



void sero1()


{
  for (pos = 0; pos < 120 ; pos++)
  {
    servo1.write(pos);
    //servo2.write(pos);
    //servo3.write(pos);
    //servo4.write(pos);

    delay (10);
  }
  count1 = 1 + count1;
  Blynk.virtualWrite(V2, count1);

}



void sero2()


{
  for (pos = 45; pos < 120 ; pos++)
  {
    //servo1.write(pos);
    servo2.write(pos);
    //servo3.write(pos);
    //servo4.write(pos);

    delay (10);
  }


}

void sero3()


{
  for (pos = 0; pos < 120 ; pos++)
  {
    //servo1.write(pos);
    // servo2.write(pos);
    servo3.write(pos);
    // servo4.write(pos);
    delay (10);
  }




}

void sero4()


{
  for (pos = 110; pos > 0 ; pos--)
  {
    // servo1.write(pos);
    /// servo2.write(pos);
    //servo3.write(pos);
    servo4.write(pos);

    delay (10 );
  }
  count4 = 1 + count4;
  Blynk.virtualWrite(V5, count4);

}








void loop() {

  Blynk.run(); //Run the Blynk library
  ///Blynk.virtualWrite(V1, 0);
  /// Blynk.virtualWrite(V1, 0);



  dis();
  delay (100);
  if ( p <= 6 ) {

Serial.println(p);




    if ( ! mfrc522.PICC_IsNewCardPresent()) {
      return;//got to start of loop if there is no card present
    }
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) {
      return;//if read card serial(0) returns 1, the uid struct contians the ID of the read card.
    }
    String CardID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      CardID += mfrc522.uid.uidByte[i];
    }

    //String id= CardID;
    Serial.println(CardID);
//delay (3000); 
    if (CardID == "180234228150")

   {
      state = 1;
      Serial.println(state);

    }

  else if (CardID == "150862051")
   {
      state2 = 1;
      Serial.println(state2);

    }
    else
    {
      Serial.println("Enter Valid card");

    }


    if ( state == 1)
    {
     digitalWrite (led1, LOW);
      delay (liquid);
      digitalWrite (led1, HIGH);
      // digitalWrite (led3, HIGH);
      sero1();
      sero2();
      bly1();

      state = 0;

    }


    

    if ( state2 == 1)
    {

      Serial.println(p);
     digitalWrite (led2, LOW);
     delay (liquid1);
      digitalWrite (led2, HIGH);
      //  digitalWrite (led3, HIGH);
     sero3();
     sero4();
     bly2();
      state2 = 0;
    }
      
  }
}



//=======================================================================
