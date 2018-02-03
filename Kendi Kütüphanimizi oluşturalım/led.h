#ifndef led_H
#define led_H

#include <Arduino.h>

class led { 
public:
	led();
	~led();
    void led_yak();
	void led_sondur();
	void led_flipflop(int sure);
};

#endif