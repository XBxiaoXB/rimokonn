#include "iodefine.h"
#include "timerA.h"
#include "led.h"
#include "machine.h"

void iniTimerA(void)
{
	TA.TMA.BYTE = 0x10;     //shiji 0.25s
	IRR1.BIT.IRRTA = 0;   //chushihua
	IENR1.BIT.IENTA = 0;  //jinzhizhongduan
}

