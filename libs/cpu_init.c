   //INIT FILE


#include "cpu_Init.h"


void cpuPllInit()
{
   
#ifdef USE_EXTERNAL_OSCILLATOR
   SCB_PDRUNCFG &= ~(SCB_PDRUNCFG_SYSOSC_MASK);
   
#if EXTERNAL_OSCILLATOR_FREQ > 18000000
   SCB_SYSOSCCTRL = (SCB_SYSOSCCTRL_BYPASS_DISABLED | SCB_SYSOSCCTRL_FREQRANGE_1TO20MHZ);
#else
   SCB_SYSOSCCTRL = (SCB_SYSOSCCTRL_BYPASS_DISABLED | SCB_SYSOSCCTRL_FREQRANGE_15TO25MHZ);
#endif
   
	for (i = 0; i < 200; i++)
  	{
    	__asm volatile ("NOP");
  	}
   
      // Configure PLL
  	SCB_PLLCLKSEL = SCB_CLKSEL_SOURCE_MAINOSC;    // Use the external crystal
#define M	SYS_CLOCK / EXTERNAL_OSCILLATOR_FREQ
#define P 	(238000000 / 2) / SYS_CLOCK
   
   
#else
   
   SCB_PDRUNCFG &= ~(SCB_PDRUNCFG_SYSOSC_MASK);
   
   
      // Configure PLL
  	SCB_PLLCLKSEL = SCB_CLKSEL_SOURCE_INTERNALOSC;    // Use the external crystal
#define M	SYS_CLOCK / INTERNAL_OSCILLATOR_FREQ
#define P 	(238000000 / 2) / SYS_CLOCK
   
   
   
#endif
   
   
  	SCB_PLLCLKUEN = SCB_PLLCLKUEN_UPDATE;         // Update clock source
  	SCB_PLLCLKUEN = SCB_PLLCLKUEN_DISABLE;        // Toggle update register once
  	SCB_PLLCLKUEN = SCB_PLLCLKUEN_UPDATE;         // Update clock source again
   
      // Wait until the clock is updated
  	while (!(SCB_PLLCLKUEN & SCB_PLLCLKUEN_UPDATE));
	
      // Set clock speed
   
   
   
#if P != 2
      //#error "BAD PLL VALUE"
#endif
	
      //SCB_PLLCTRL = 0x23;//( (M - 1) | (1 << SCB_PLLCTRL_DIV_BIT));
   SCB_PLLCTRL = ( (M - 1) | (1 << SCB_PLLCTRL_DIV_BIT));
   
      // Enable system PLL
  	SCB_PDRUNCFG &= ~(SCB_PDRUNCFG_SYSPLL_MASK);
   
      // Wait for PLL to lock
  	while (!(SCB_PLLSTAT & SCB_PLLSTAT_LOCK));
   
      // Setup main clock
  	SCB_MAINCLKSEL = SCB_MAINCLKSEL_SOURCE_SYSPLLCLKOUT;
  	SCB_MAINCLKUEN = SCB_MAINCLKUEN_UPDATE;       // Update clock source
  	SCB_MAINCLKUEN = SCB_MAINCLKUEN_DISABLE;      // Toggle update register once
  	SCB_MAINCLKUEN = SCB_MAINCLKUEN_UPDATE;
   
      // Wait until the clock is updated
  	while (!(SCB_MAINCLKUEN & SCB_MAINCLKUEN_UPDATE));
	
      // Set system AHB clock
  	SCB_SYSAHBCLKDIV = 1;//SCB_SYSAHBCLKDIV_DIV1;
   
      // Enabled IOCON clock for I/O related peripherals
  	SCB_SYSAHBCLKCTRL |= SCB_SYSAHBCLKCTRL_IOCON;
}




void cpuInit()
{
	cpuPllInit();
}







