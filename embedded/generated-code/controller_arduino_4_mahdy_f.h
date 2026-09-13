/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_arduino_4_mahdy_f.h
 *
 * Code generated for Simulink model 'controller_arduino_4_mahdy_f'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Jun 14 15:21:02 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef controller_arduino_4_mahdy_f_h_
#define controller_arduino_4_mahdy_f_h_
#ifndef controller_arduino_4_mahdy_f_COMMON_INCLUDES_
#define controller_arduino_4_mahdy_f_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif                       /* controller_arduino_4_mahdy_f_COMMON_INCLUDES_ */

#include "controller_arduino_4_mahdy_f_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Reverse_l;                    /* '<Root>/Chart2' */
  real_T Park_b;                       /* '<Root>/Chart2' */
  real_T Neutral_m;                    /* '<Root>/Chart2' */
  real_T Drive_f;                      /* '<Root>/Chart2' */
  real_T Brake_k;                      /* '<Root>/Chart2' */
  real32_T TorqueRequest_Nm;           /* '<Root>/Chart' */
} B_controller_arduino_4_mahdy__T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_h;/* '<Root>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_h5;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_g;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_jv;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_e_T obj_n;/* '<Root>/Digital Output8' */
  codertarget_arduinobase_blo_e_T obj_jw;/* '<Root>/Digital Output7' */
  codertarget_arduinobase_blo_e_T obj_f;/* '<Root>/Digital Output6' */
  codertarget_arduinobase_blo_e_T obj_nl;/* '<Root>/Digital Output5' */
  codertarget_arduinobase_blo_e_T obj_nb;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_blo_e_T obj_l;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_blo_e_T obj_d;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_blo_e_T obj_o;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_blo_e_T obj_ds;/* '<Root>/Digital Output' */
  real_T error;                        /* '<Root>/Chart1' */
  real_T MAX_TORQUE_REVERSE;           /* '<Root>/Chart' */
  real_T MAX_TORQUE;                   /* '<Root>/Chart' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
  uint8_T is_active_c2_controller_arduino;/* '<Root>/Chart2' */
  uint8_T is_c2_controller_arduino_4_mahd;/* '<Root>/Chart2' */
  uint8_T is_active_c3_controller_arduino;/* '<Root>/Chart' */
  uint8_T is_c3_controller_arduino_4_mahd;/* '<Root>/Chart' */
  uint8_T is_Bmode;                    /* '<Root>/Chart' */
} DW_controller_arduino_4_mahdy_T;

/* Parameters (default storage) */
struct P_controller_arduino_4_mahdy__T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  real_T AnalogInput3_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input3'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_controller_arduino_4__T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_controller_arduino_4_mahdy__T controller_arduino_4_mahdy_f_P;

/* Block signals (default storage) */
extern B_controller_arduino_4_mahdy__T controller_arduino_4_mahdy_f_B;

/* Block states (default storage) */
extern DW_controller_arduino_4_mahdy_T controller_arduino_4_mahdy_f_DW;

/* External function called from main */
extern void controller_arduino_4_mahdy_f_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void controller_arduino_4_mahdy_f_initialize(void);
extern void controller_arduino_4_mahdy_f_step0(void);
extern void controller_arduino_4_mahdy_f_step1(void);
extern void controller_arduino_4_mahdy_f_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_arduino_4_T *const controller_arduino_4_mahdy_f_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Boolean1' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'controller_arduino_4_mahdy_f'
 * '<S1>'   : 'controller_arduino_4_mahdy_f/Chart'
 * '<S2>'   : 'controller_arduino_4_mahdy_f/Chart1'
 * '<S3>'   : 'controller_arduino_4_mahdy_f/Chart2'
 * '<S4>'   : 'controller_arduino_4_mahdy_f/Chart3'
 */
#endif                                 /* controller_arduino_4_mahdy_f_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
