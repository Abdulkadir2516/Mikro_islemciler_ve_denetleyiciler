/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.50.33 (20-Dec-2022)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: ornek1.h
 *
 * Code generated for Simulink model 'ornek1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Feb 16 16:51:45 2023
 */

#ifndef RTW_HEADER_ornek1_h_
#define RTW_HEADER_ornek1_h_
#ifndef ornek1_COMMON_INCLUDES_
#define ornek1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ornek1_COMMON_INCLUDES_ */

#include "ornek1_types.h"
#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */

/* Macros for accessing real-time model data structure */

/* Model entry point functions */
extern void ornek1_initialize(void);
extern void ornek1_step(void);
extern void ornek1_terminate(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ornek1'
 * '<S1>'   : 'ornek1/Digital Output'
 */
#endif                                 /* RTW_HEADER_ornek1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
