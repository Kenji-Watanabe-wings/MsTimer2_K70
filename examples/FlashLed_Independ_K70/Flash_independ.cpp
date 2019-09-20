#include <Arduino.h>
#include <MsTimer2_K70.h>

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;	// 1.0 built in LED pin var
#else
const int led_pin = 13;			// default to pin 13
#endif

#define MSTIME (500)	// 500ms period	
static volatile bool mstimer2_callback_exc = false;

void flash()	/* 500ms */
{
	mstimer2_callback_exc = true;
}

void MsTimer2_K70_setup()
{
	pinMode(led_pin, OUTPUT);

	mstimer2.set(500, flash); // 500ms period
	mstimer2.start();
}

bool MsTimer2_K70_loop()
{
	if(mstimer2_callback_exc == true){
		static boolean output = HIGH;
		mstimer2_callback_exc = false;
		digitalWrite(led_pin, output);
		output = !output;
		return true;
	}
	return false;
}
