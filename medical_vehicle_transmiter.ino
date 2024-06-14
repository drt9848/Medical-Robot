//wheel chair nsic transmitter
//transmitter code
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(PB0,PA4); // CE, CSN

//--------------------------------------------------------------
#define xPin PA0
#define yPin PA1
#define zPin PA3
//--------------------------------------------------------------
// Take multiple samples to reduce noise
const int samples = 10;
const uint64_t address = 0xF0F0F0F0E1LL;
int counter = 0;
void setup() {
  Serial.begin(115200);
  radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data

radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();  



}

void loop() {

  char text[50];
  
 int xRaw=0,yRaw=0,zRaw=0;
  for(int i=0;i<samples;i++)
  {
    xRaw+=analogRead(xPin);
    yRaw+=analogRead(yPin);
    zRaw+=analogRead(zPin);
  }
  xRaw/=samples;
  yRaw/=samples;
  zRaw/=samples;
  //--------------------------------------------------------------
  Serial.print(xRaw);
  Serial.print("\t");
  Serial.print(yRaw);
  Serial.print("\t");
  Serial.print(zRaw);
  Serial.println();





  // Serial.println("=====================================");

   strcpy(text, "=");
  strcat(text, String(xRaw).c_str());
  strcat(text, "=");
  strcat(text, String(yRaw).c_str());
  strcat(text, "=");
  strcat(text, String(zRaw).c_str());
  strcat(text, "=");
  strcat(text, String(1).c_str());
  strcat(text, "=");
  strcat(text, String(2).c_str());
  strcat(text, "=");
  strcat(text, String(3).c_str());
  strcat(text, "=");
  strcat(text, String(4).c_str());
  
  radio.write(&text, sizeof(text));
}