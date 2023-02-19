/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.50.33 (20-Dec-2022)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: untitled_main.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sat Feb 18 16:57:33 2023
 */

/* Set Fuses Options */

#pragma config FNOSC = PRI
#pragma config POSCMD = HS, OSCIOFNC = ON, FCKSM = CSECMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

#define MCHP_isMainFile
#include "untitled.h"
#include "untitled_private.h"

volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */

/* Microchip Global Variables */
/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) ) ;/* Atomic bit-set: ContinueTimeStep |= 1U */
    _T1IF = 0;                         /* Re-enable interrupt */
  }
}

/* Solver mode : SingleTasking */
int main()
{
  /* Initialize model */

  /* Start Clock Switching */
  if ((OSCCONbits.COSC & 1) && !(OSCCONbits.COSC & 4))/* check not already in PLL mode (0?1) */
  {
    __builtin_write_OSCCONH(0);        /* Clock Switch to non PLL mode */
    __builtin_write_OSCCONL(0x01);     /* Start clock switching */
    __asm__ volatile("nop\n"
                     "nop");
    while (OSCCONbits.COSC != 0) ;
  }

  PLLFBD = 110;                        /* Oscillator PLL : PLLDIV */
  CLKDIV = 0x05;                       /* Oscillator PLL : FRCDIV ; PLLPOST ; PLLPRE */
  __builtin_write_OSCCONH(3);          /* Clock Switch to desired configuration */
  __builtin_write_OSCCONL(0x01);       /* Start clock switching */

  /* Configure Pins as Analog or Digital */
  AD1PCFGL = 0x01FC;

  /* Configure Remappables Pins */

  /* Configure Digitals I/O directions */
  TRISB = 0xFF00;
  TRISC = 0xFF00;

  /* Finish clock switching procedure */
  while (OSCCONbits.COSC != 3) ;       /* Wait for Oscillator Stabilisation */
  while (OSCCONbits.LOCK != 1) ;       /* Wait for PLL Stabilisation */

  /* Initialize model */
  untitled_initialize();

  /* Configure Timers */
  /* --- TIMER 1 --- This timer is enabled at end of configuration functions. */
  T1CON = 0;                           /* Stop Timer 1 and resets control register */
  _T1IP = 2;                           /* Set timer Interrupt Priority */
  _T1IF = 0;                           /* Reset pending Interrupt */
  _T1IE = 1;                           /* Enable Timer Interrupt. */
  PR1 = 0xC34F;                        /* Period */
  T1CON = 0x10;                        /* Set timer Prescaler ; internal clock source */

  /* Enable Time-step */
  TMR1 = 0xC34E;                       /* Initialize Timer Value */
  T1CONbits.TON = 1;                /* Start timer 1. Timer 1 is the source trigger for the model Time-step */

  /* Main Loop */
  for (;;) {
    while (!ContinueTimeStep) ;

    /* Disable Scheduler Interrupt */
    _IPL0 = 1;                         /* Disable Scheduler Interrupts. Rise IPL from 0 to 1 */
    __asm__ volatile ("BCLR.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) );/* Atomic bit-clear of ContinueTimeStep bit 1U */

    /* Call model Scheduler */
    /* Step the model for base rate */
    untitled_step();

    /* Get model outputs here */

    /* Remove conditional, and get model outputs here */
#if 0

    /* OutportID: 0, TaskID: 0 */
    your_variable = untitled_Y.Out1;

#endif

    /* Re-Enable Scheduler Interrupt */
    _IPL0 = 0;                         /* Enable Scheduler interrupt. Lower IPL from 1 to 0 */
  }                                    /* End for(;;) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
