#ifndef MsTimer2_h
#define MsTimer2_h

#ifdef __AVR__
#include <avr/interrupt.h>
#elif defined(__arm__) && defined(TEENSYDUINO)
#include <Arduino.h>
#else
#error MsTimer2 library only works on AVR architecture
#endif

class MsTimer2
{
public:
	void set(unsigned long ms, void (*f)());
	void start();
	void stop();
	void _overflow();
	volatile unsigned int tcnt2;

private:
	unsigned long msecs;
	void (*func)();
	volatile unsigned long count;
	volatile char overflowing;
};

extern MsTimer2 mstimer2;

#endif /* MsTimer2_h */
