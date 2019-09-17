#include <EspMQTTClient.h>
#include <SPI.h>
#include "DMD2.h"
#include "fonts/SystemFont5x7.h"
#include "fonts/Arial14.h"


EspMQTTClient client(
  "phoenix5",
  "g0d!$g0d",
  "m11.cloudmqtt.com",  // MQTT Broker server ip
  "lyhdpqlj",   // Can be omitted if not needed
  "4OCSTRT0DPlQ",   // Can be omitted if not needed
  "TestClient",     // Client name that uniquely identify your device
  12492              // The MQTT port, default to 1883. this line can be omitted
);



/*
  Scrolling alphabet demo, displays characters one at a time into a scrolling box.
 */

// Set Width to the number of displays wide you have
const int WIDTH = 1;
const uint8_t *FONT = SystemFont5x7;

// Message 
char message_buff[100];
String message = String("hello");


// ESP Pins - Using D0 -- Digital PINS mapping

static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;

/*
A D0
B D6
CLK D5
SCK D3
R D7
NOE D8
GND GND
*/
SoftDMD dmd(WIDTH,1);  // DMD controls the entire display
DMD_TextBox box(dmd, 0, 0, 32, 16, true);
unsigned long previousMillis = 0;   
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  dmd.setBrightness(255);
  dmd.selectFont(FONT);
  client.enableLastWillMessage("TestClient/lastwill", "I am going offline");  // You can activate the retain flag by setting the third parameter to true

  delay(10000);    //Wait for one second
  dmd.begin();
  
}

void ScanDMD()
{ 
 // dmd.begin();
 // dmd.end();
}

void onConnectionEstablished()
{
    // Subscribe to "mytopic/test" and display received message to Serial
    client.subscribe("mytopic/test", [](const String & payload) {
    message = payload;
    Serial.println("Recieved - connect --" + payload);
  });

}

void showMessage(){
  char marqueeString[256];
  int myTextLength = message.length();
  message.toCharArray(marqueeString, myTextLength+1);
  dmd.drawString(0,0,marqueeString);
}


//int phase = 0; // 0-3, 'phase' value determines direction

// the loop routine runs over and over again forever:
void loop() {
   client.loop();
    Serial.println(message);  //Just for debugging
    showMessage();
    delay(1000);    //Wait for one second
  }
