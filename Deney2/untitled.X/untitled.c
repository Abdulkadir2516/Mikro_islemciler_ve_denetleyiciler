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
 * Model version                  : 1.1
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sat Feb 18 15:17:29 2023
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block signals and states (default storage) */
DW_untitled_T untitled_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_untitled_T untitled_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_untitled_T untitled_Y;

/* Model step function */
void untitled_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput;
  real_T rtb_Switch;
  int16_T rowIdx;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_LogicalOperator;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTCbits.RC0;    /* Read pin C0 */

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  rtb_LogicalOperator = ((untitled_DW.Memory_PreviousInput > 0.0) && (untitled_DW.Memory_PreviousInput <= 3.0));

  /* CombinatorialLogic: '<S2>/Logic' incorporates:
   *  Memory: '<S2>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_DigitalInput << 1) + untitled_DW.invariantBits.In1) << 1) +
                     untitled_DW.bitsForTID0.Memory_PreviousInput_l);
  rtb_Logic_idx_0 = untitled_ConstP.Logic_table[(uint16_T)rowIdx];

  /* Outport: '<Root>/Out1' incorporates:
   *  CombinatorialLogic: '<S2>/Logic'
   */
  untitled_Y.Out1 = untitled_ConstP.Logic_table[rowIdx + 8U];

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Memory: '<Root>/Memory'
   *  Sum: '<Root>/Sum'
   */
  if (rtb_Logic_idx_0) {
    rtb_Switch = untitled_DW.Memory_PreviousInput + 0.1;
  } else {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATBbits.LATB0 = rtb_LogicalOperator;

  /* Update for Memory: '<S2>/Memory' */
  untitled_DW.bitsForTID0.Memory_PreviousInput_l = rtb_Logic_idx_0;

  /* Update for Memory: '<Root>/Memory' */
  untitled_DW.Memory_PreviousInput = rtb_Switch;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
  untitled_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
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
