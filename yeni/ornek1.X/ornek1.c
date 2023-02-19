/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.50.33 (20-Dec-2022)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek1.c
 *
 * Code generated for Simulink model 'ornek1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Feb 16 16:51:45 2023
 */

#include "ornek1.h"
#include "ornek1_private.h"

/* Model step function */
void ornek1_step(void)
{
  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' incorporates:
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  LATBbits.LATB0 = PORTCbits.RC0;
}

/* Model initialize function */
void ornek1_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void ornek1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
