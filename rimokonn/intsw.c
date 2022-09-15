#include "iodefine.h"
#include "machine.h"
#include "intsw.h"
#include "led.h"
#include "lcd.h"


unsigned int TCA = 0x00; 

void initSWint(void)
{
	
	IO.PMR1.BIT.IRQ1=1;
	
	//IEGR1.BIT.NMIEG=1;
	IEGR1.BIT.IEG1=1;
	
	IRR1.BIT.IRRI1=0;
	
	IENR1.BIT.IEN1=1;
	
	IO.PCR1=0x00;
	IO.PDR8.BIT.B1=1;
	IO.PCR8=0x46;
	
}
#pragma section IntPRG
__interrupt(vect=15) void INT_IRQ1(void) {
	
	IRR1.BIT.IRRI1=0;
	
	IO.PDR8.BIT.B1=1;
	
    LcdXY(1,1);
	LcdPuts("‘æˆê‰ñ:");	
	putLCDNumber(4,(unsigned int)TCA);
		
	
	}

