//medical vehicle 
//transmitter code
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(PB0,PA4); // CE, CSN

//Reset each channel value
int ch1 = 127;
int ch2 = 127;
int ch3 = 127;
int ch4 = 127;
int ch5 = 0;
int ch6 = 0;
int ch7 = 0;

const uint64_t address = 0xF0F0F0F0E1LL;
int counter = 0;
void setup() {
  Serial.begin(9600);
  radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();  

  ch1 = 127;
  ch2 = 127;
  ch3 = 127;
  ch4 = 127;
  ch5 = 0;
  ch6 = 0;
  ch7 = 0;

}

void loop() {

  char text[50];
  
  ch1 = map( analogRead(PA0), 0, 1024, 0, 255);
  ch2 = map( analogRead(PA1), 0, 1024, 0, 255);
  // ch3 = map( analogRead(A2), 0, 1024, 0, 255);
  // ch4 = map( analogRead(A3), 0, 1024, 0, 255);
  // ch5 = digitalRead(2);
  // ch6 = digitalRead(3);
  // ch7 = map( analogRead(A4), 0, 1024, 0, 255);

    Serial.print("channel1: ");
  Serial.println(ch1);
// delay(1000);
  Serial.print("channel2: ");
  Serial.println(ch2);

  
  Serial.print("channel3: ");
  Serial.println(ch3);

  
  Serial.print("channel4: ");
  Serial.println(ch4);


  Serial.println("=====================================");

   strcpy(text, "=");
  strcat(text, String(ch1).c_str());
  strcat(text, "=");
  strcat(text, String(ch2).c_str());
  strcat(text, "=");
  strcat(text, String(ch3).c_str());
  strcat(text, "=");
  strcat(text, String(ch4).c_str());
  strcat(text, "=");
  strcat(text, String(ch5).c_str());
  strcat(text, "=");
  strcat(text, String(ch6).c_str());
  strcat(text, "=");
  strcat(text, String(ch7).c_str());
  
  radio.write(&text, sizeof(text));
}