#include "led.h" 
#include "Arduino.h"

int LED=13;

led::led(){
	
    pinMode(LED_PIN, OUTPUT); 
	
}

led::~led(){
}

void led :: led_yak(){
    digitalWrite(LED,HIGH);
}

void led :: led_sondur(){
	digitalWrite(LED,LOW);
}

void led :: led_flipflop(int sure){
	digitalWrite(LED,HIGH);
	delay(sure);
	digitalWrite(LED,LOW);
	delay(sure);
}