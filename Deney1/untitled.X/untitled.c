/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.50.33 (20-Dec-2022)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Feb 17 22:53:16 2023
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block signals and states (default storage) */
DW_untitled_T untitled_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_untitled_T untitled_Y;

/* Model step function */
void untitled_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o4;
  int16_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_Logic_l[2];
  boolean_T rtb_Logic_p[2];
  boolean_T rtb_Memory;
  boolean_T rtb_Memory1;
  boolean_T rtb_Memory2;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o4 = PORTCbits.RC3; /* Read pin C3 */

  /* Memory: '<Root>/Memory2' */
  rtb_Memory2 = untitled_DW.bitsForTID0.Memory2_PreviousInput;

  /* Memory: '<Root>/Memory1' */
  rtb_Memory1 = untitled_DW.bitsForTID0.Memory1_PreviousInput;

  /* Switch: '<Root>/Switch5' incorporates:
   *  Constant: '<Root>/Constant3'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   *  Switch: '<Root>/Switch6'
   */
  if (rtb_Memory2) {
    rtb_Memory = false;
  } else {
    rtb_Memory = ((!rtb_Memory1) && PORTCbits.RC0);
  }

  /* End of Switch: '<Root>/Switch5' */

  /* CombinatorialLogic: '<S2>/Logic' incorporates:
   *  Memory: '<S2>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_Memory << 1) + rtb_DigitalInput_o4) << 1) +
                     untitled_DW.bitsForTID0.Memory_PreviousInput);
  rtb_Logic[0U] = untitled_ConstP.pooled3[(uint16_T)rowIdx];
  rtb_Logic[1U] = untitled_ConstP.pooled3[rowIdx + 8U];

  /* Outport: '<Root>/Out1' */
  untitled_Y.Out1 = rtb_Logic[1];

  /* Memory: '<Root>/Memory' */
  rtb_Memory = untitled_DW.bitsForTID0.Memory_PreviousInput_h;

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant4'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   *  Switch: '<Root>/Switch1'
   */
  if (rtb_Memory2) {
    rtb_Memory2 = false;
  } else {
    rtb_Memory2 = ((!rtb_Memory) && PORTCbits.RC1);
  }

  /* End of Switch: '<Root>/Switch3' */

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Memory: '<S3>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_Memory2 << 1) + rtb_DigitalInput_o4) << 1) +
                     untitled_DW.bitsForTID0.Memory_PreviousInput_o);
  rtb_Logic_p[0U] = untitled_ConstP.pooled3[(uint16_T)rowIdx];
  rtb_Logic_p[1U] = untitled_ConstP.pooled3[rowIdx + 8U];

  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<Root>/Constant5'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   *  Switch: '<Root>/Switch2'
   */
  if (rtb_Memory1) {
    rtb_Memory1 = false;
  } else {
    rtb_Memory1 = ((!rtb_Memory) && PORTCbits.RC2);
  }

  /* End of Switch: '<Root>/Switch4' */

  /* CombinatorialLogic: '<S4>/Logic' incorporates:
   *  Memory: '<S4>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_Memory1 << 1) + rtb_DigitalInput_o4) << 1) +
                     untitled_DW.bitsForTID0.Memory_PreviousInput_p);
  rtb_Logic_l[0U] = untitled_ConstP.pooled3[(uint16_T)rowIdx];
  rtb_Logic_l[1U] = untitled_ConstP.pooled3[rowIdx + 8U];

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_Logic[0];
  LATBbits.LATB1 = rtb_Logic_p[0];
  LATBbits.LATB2 = rtb_Logic_l[0];

  /* Outport: '<Root>/Out3' */
  untitled_Y.Out3 = rtb_Logic_l[1];

  /* Outport: '<Root>/Out2' */
  untitled_Y.Out2 = rtb_Logic_p[1];

  /* Update for Memory: '<Root>/Memory2' */
  untitled_DW.bitsForTID0.Memory2_PreviousInput = rtb_Logic_l[0];

  /* Update for Memory: '<Root>/Memory1' */
  untitled_DW.bitsForTID0.Memory1_PreviousInput = rtb_Logic_p[0];

  /* Update for Memory: '<S2>/Memory' */
  untitled_DW.bitsForTID0.Memory_PreviousInput = rtb_Logic[0];

  /* Update for Memory: '<Root>/Memory' */
  untitled_DW.bitsForTID0.Memory_PreviousInput_h = rtb_Logic[0];

  /* Update for Memory: '<S3>/Memory' */
  untitled_DW.bitsForTID0.Memory_PreviousInput_o = rtb_Logic_p[0];

  /* Update for Memory: '<S4>/Memory' */
  untitled_DW.bitsForTID0.Memory_PreviousInput_p = rtb_Logic_l[0];
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* InitializeConditions for Memory: '<S2>/Memory' */
  untitled_DW.bitsForTID0.Memory_PreviousInput = true;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  untitled_DW.bitsForTID0.Memory_PreviousInput_o = true;

  /* InitializeConditions for Memory: '<S4>/Memory' */
  untitled_DW.bitsForTID0.Memory_PreviousInput_p = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
