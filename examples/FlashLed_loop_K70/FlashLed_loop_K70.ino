#include <MsTimer2_K70.h>�@/* ���C�u�����g�p��錾 */

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;	// 1.0 built in LED pin var
#else
const int led_pin = 13;			// default to pin 13
#endif

#define MSTIME (500)	// 500ms period	
bool mstimer2_callback_exc = false;

void flash()	/* 500ms���ƂɎ��s */
{
	mstimer2_callback_exc = true;
}

void setup()
{
	pinMode(led_pin, OUTPUT);

	mstimer2.set(500, flash); // 500ms period	/* MsTimer2�̏����� */
	mstimer2.start();	/* MsTimer2�̋N�� */
}

void loop()
{
	if(mstimer2_callback_exc == true){
		static boolean output = HIGH;
		mstimer2_callback_exc = false;
		digitalWrite(led_pin, output);
		output = !output;
	}
}