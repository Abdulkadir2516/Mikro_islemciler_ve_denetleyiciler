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
 * C/C++ source code generated on : Sat Feb 18 16:57:33 2023
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block signals and states (default storage) */
DW_untitled_T untitled_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_untitled_T untitled_Y;
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void untitled_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput_o1;
  real_T rtb_Switch1;
  real_T u;
  int16_T rowIdx;
  uint16_T rtb_Cast1;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_LogicalOperator1;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTAbits.RA9; /* Read pin A9 */

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator2'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rtb_LogicalOperator1 = (PORTAbits.RA10 || (untitled_DW.Memory_PreviousInput >= 100.0));

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Memory: '<S3>/Memory'
   */
  rowIdx = (int16_T)(((((uint16_T)rtb_DigitalInput_o1 << 1) + rtb_LogicalOperator1) << 1) +
                     untitled_DW.bitsForTID0.Memory_PreviousInput_l);
  rtb_Logic_idx_0 = untitled_ConstP.Logic_table[(uint16_T)rowIdx];

  /* Outport: '<Root>/Out1' incorporates:
   *  CombinatorialLogic: '<S3>/Logic'
   */
  untitled_Y.Out1 = untitled_ConstP.Logic_table[rowIdx + 8U];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Switch: '<Root>/Switch'
   */
  if (rtb_LogicalOperator1) {
    rtb_Switch1 = 0.0;
  } else if (rtb_Logic_idx_0) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Memory: '<Root>/Memory'
     *  Sum: '<Root>/Sum'
     */
    rtb_Switch1 = untitled_DW.Memory_PreviousInput + 0.01;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MultiPortSwitch: '<Root>/Index Vector1' incorporates:
   *  Gain: '<Root>/Multiply'
   *  Memory: '<Root>/Memory'
   *  Rounding: '<Root>/Fix'
   */
  u = 0.1 * untitled_DW.Memory_PreviousInput;
  if (u < 0.0) {
    u = ceil(u);
  } else {
    u = floor(u);
  }

  /* DataTypeConversion: '<Root>/Cast1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   */
  u = floor(untitled_ConstP.Constant4_Value[(int16_T)u]);
  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 65536.0);
  }

  rtb_Cast1 = u < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-u : (uint16_T)u;

  /* End of DataTypeConversion: '<Root>/Cast1' */

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATB = rtb_Cast1;                    /* No mask required : all pins defined as digital output are updated */

  /* DataTypeConversion: '<Root>/Cast' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Math: '<Root>/Mod'
   *  Memory: '<Root>/Memory'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  u = floor(untitled_ConstP.Constant4_Value[(int16_T)rt_modd_snf(untitled_DW.Memory_PreviousInput, 10.0)]);
  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 65536.0);
  }

  rtb_Cast1 = u < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-u : (uint16_T)u;

  /* End of DataTypeConversion: '<Root>/Cast' */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATC = rtb_Cast1;                    /* No mask required : all pins defined as digital output are updated */

  /* Update for Memory: '<Root>/Memory' */
  untitled_DW.Memory_PreviousInput = rtb_Switch1;

  /* Update for Memory: '<S3>/Memory' */
  untitled_DW.bitsForTID0.Memory_PreviousInput_l = rtb_Logic_idx_0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
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
