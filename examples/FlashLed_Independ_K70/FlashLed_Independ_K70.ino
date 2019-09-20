#include <MsTimer2_K70.h>


void setup()
{
	MsTimer2_K70_setup();
}

void loop()
{
	bool chang_flag = MsTimer2_K70_loop();
	if(chang_flag == true){
		Serial.println("change led_pin");
	}
}
