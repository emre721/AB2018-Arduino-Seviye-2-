#include <Servo.h> 
#include <SPI.h>
#include "RF24.h"
Servo myservo; 
//SCK -> 13//MISO -> 12//MOSI -> 11//CSN -> 7//CE -> 8
RF24 radio(8,7);
const uint64_t pipe = 0xE8E8F0F0E1LL; 
int msg[1];
void setup() 
{ 
myservo.attach(9); 
radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening(); 
} 
void loop() 
{ 
if (radio.available()){
bool done = false;
while (!done){
done = radio.read(msg, 1); 
myservo.write (msg[0]);
 
}
}
}
