/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_arduino_4_mahdy_f.c
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

#include "controller_arduino_4_mahdy_f.h"
#include "rtwtypes.h"
#include "controller_arduino_4_mahdy_f_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "controller_arduino_4_mahdy_f_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define control_IN_Regenerative_Braking ((uint8_T)2U)
#define controller_a_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define controller_ardu_IN_Acceleration ((uint8_T)1U)
#define controller_arduino_4_IN_Neutral ((uint8_T)3U)
#define controller_arduino_4_IN_Reverse ((uint8_T)5U)
#define controller_arduino_4_m_IN_Bmode ((uint8_T)1U)
#define controller_arduino_4_m_IN_Drive ((uint8_T)2U)
#define controller_arduino_4_ma_IN_Park ((uint8_T)4U)
#define controller_arduino_4_ma_IN_Stop ((uint8_T)3U)

/* Named constants for Chart: '<Root>/Chart2' */
#define cont_IN_Input_transmissionState ((uint8_T)3U)
#define controller_ardu_IN_NeutralState ((uint8_T)4U)
#define controller_ardu_IN_ReverseState ((uint8_T)6U)
#define controller_arduin_IN_BrakeState ((uint8_T)1U)
#define controller_arduin_IN_DriveState ((uint8_T)2U)
#define controller_arduino_IN_ParkState ((uint8_T)5U)

/* Block signals (default storage) */
B_controller_arduino_4_mahdy__T controller_arduino_4_mahdy_f_B;

/* Block states (default storage) */
DW_controller_arduino_4_mahdy_T controller_arduino_4_mahdy_f_DW;

/* Real-time model */
static RT_MODEL_controller_arduino_4_T controller_arduino_4_mahdy_f_M_;
RT_MODEL_controller_arduino_4_T *const controller_arduino_4_mahdy_f_M =
  &controller_arduino_4_mahdy_f_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void controller_arduino_4_mahdy_f_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(controller_arduino_4_mahdy_f_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (controller_arduino_4_mahdy_f_M->Timing.TaskCounters.TID[1])++;
  if ((controller_arduino_4_mahdy_f_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    controller_arduino_4_mahdy_f_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void controller_arduino_4_mahdy_f_step0(void) /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Logic: '<Root>/NOT' incorporates:
   *  Delay: '<Root>/Delay'
   */
  controller_arduino_4_mahdy_f_DW.Delay_DSTATE =
    !controller_arduino_4_mahdy_f_DW.Delay_DSTATE;

  /* MATLABSystem: '<Root>/Digital Output7' incorporates:
   *  Delay: '<Root>/Delay'
   */
  writeDigitalPin(13, (uint8_T)controller_arduino_4_mahdy_f_DW.Delay_DSTATE);
}

/* Model step function for TID1 */
void controller_arduino_4_mahdy_f_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Sum2;
  real_T rtb_Switch2;
  real_T tmp;
  real32_T rtb_Gain;
  real32_T rtb_Sum;
  int16_T rtb_Negative_Torque;
  int16_T rtb_PedalFailure;
  uint16_T b_varargout_1;
  uint8_T tmp_0;
  boolean_T c_value;
  TransmissionState rtb_AutomaticTransmissionState;
  TransmissionState rtb_DataTypeConversion1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (controller_arduino_4_mahdy_f_DW.obj_g.SampleTime !=
      controller_arduino_4_mahdy_f_P.AnalogInput_SampleTime) {
    controller_arduino_4_mahdy_f_DW.obj_g.SampleTime =
      controller_arduino_4_mahdy_f_P.AnalogInput_SampleTime;
  }

  controller_arduino_4_mahdy_f_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(16UL);
  MW_AnalogInSingle_ReadResult
    (controller_arduino_4_mahdy_f_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Gain' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  rtb_Gain = controller_arduino_4_mahdy_f_P.Gain_Gain * (real32_T)b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input3' */
  if (controller_arduino_4_mahdy_f_DW.obj.SampleTime !=
      controller_arduino_4_mahdy_f_P.AnalogInput3_SampleTime) {
    controller_arduino_4_mahdy_f_DW.obj.SampleTime =
      controller_arduino_4_mahdy_f_P.AnalogInput3_SampleTime;
  }

  controller_arduino_4_mahdy_f_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(19UL);
  MW_AnalogInSingle_ReadResult
    (controller_arduino_4_mahdy_f_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Chart: '<Root>/Chart1' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double3'
   *  Gain: '<Root>/Gain4'
   *  MATLABSystem: '<Root>/Analog Input3'
   * */
  if ((rtb_Gain - controller_arduino_4_mahdy_f_P.Gain4_Gain * (real32_T)
       b_varargout_1 >= 0.05) || (controller_arduino_4_mahdy_f_DW.error == 1.0))
  {
    rtb_PedalFailure = 1;
    controller_arduino_4_mahdy_f_DW.error = 1.0;
  } else {
    rtb_PedalFailure = 0;
    controller_arduino_4_mahdy_f_DW.error = 0.0;
  }

  /* End of Chart: '<Root>/Chart1' */

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (controller_arduino_4_mahdy_f_DW.obj_j.SampleTime !=
      controller_arduino_4_mahdy_f_P.DigitalInput1_SampleTime) {
    controller_arduino_4_mahdy_f_DW.obj_j.SampleTime =
      controller_arduino_4_mahdy_f_P.DigitalInput1_SampleTime;
  }

  c_value = readDigitalPin(10);

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  MATLABSystem: '<Root>/Digital Input1'
   * */
  if (c_value) {
    rtb_Switch2 = controller_arduino_4_mahdy_f_P.Constant3_Value;
  } else {
    rtb_Switch2 = controller_arduino_4_mahdy_f_P.Constant4_Value;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Sum: '<Root>/Sum2' */
  rtb_Sum2 = (real_T)rtb_PedalFailure + rtb_Switch2;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (controller_arduino_4_mahdy_f_DW.obj_jv.SampleTime !=
      controller_arduino_4_mahdy_f_P.DigitalInput_SampleTime) {
    controller_arduino_4_mahdy_f_DW.obj_jv.SampleTime =
      controller_arduino_4_mahdy_f_P.DigitalInput_SampleTime;
  }

  c_value = readDigitalPin(8);

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (controller_arduino_4_mahdy_f_DW.obj_h5.SampleTime !=
      controller_arduino_4_mahdy_f_P.AnalogInput1_SampleTime) {
    controller_arduino_4_mahdy_f_DW.obj_h5.SampleTime =
      controller_arduino_4_mahdy_f_P.AnalogInput1_SampleTime;
  }

  controller_arduino_4_mahdy_f_DW.obj_h5.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(17UL);
  MW_AnalogInSingle_ReadResult
    (controller_arduino_4_mahdy_f_DW.obj_h5.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double1'
   *  Gain: '<Root>/Gain1'
   *  MATLABSystem: '<Root>/Analog Input1'
   *  Rounding: '<Root>/Floor1'
   * */
  rtb_Sum = rt_roundf_snf(controller_arduino_4_mahdy_f_P.Gain1_Gain * (real32_T)
    b_varargout_1);
  if (rtIsNaNF(rtb_Sum) || rtIsInfF(rtb_Sum)) {
    rtb_Sum = 0.0F;
  } else {
    rtb_Sum = (real32_T)fmod(rtb_Sum, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  rtb_DataTypeConversion1 = (TransmissionState)(rtb_Sum < 0.0F ? -(int32_T)
    (uint32_T)-rtb_Sum : (int32_T)(uint32_T)rtb_Sum);

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (controller_arduino_4_mahdy_f_DW.obj_h.SampleTime !=
      controller_arduino_4_mahdy_f_P.AnalogInput2_SampleTime) {
    controller_arduino_4_mahdy_f_DW.obj_h.SampleTime =
      controller_arduino_4_mahdy_f_P.AnalogInput2_SampleTime;
  }

  controller_arduino_4_mahdy_f_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(18UL);
  MW_AnalogInSingle_ReadResult
    (controller_arduino_4_mahdy_f_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<Root>/Cast To Double2'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   *  MATLABSystem: '<Root>/Analog Input2'
   * */
  rtb_Sum = controller_arduino_4_mahdy_f_P.Gain2_Gain * (real32_T)b_varargout_1 *
    controller_arduino_4_mahdy_f_P.Gain3_Gain +
    controller_arduino_4_mahdy_f_P.Constant_Value;

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<Root>/Digital Input'
   * */
  if (controller_arduino_4_mahdy_f_DW.is_active_c3_controller_arduino == 0U) {
    controller_arduino_4_mahdy_f_DW.is_active_c3_controller_arduino = 1U;
    controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd =
      controller_arduino_4_ma_IN_Park;
    rtb_AutomaticTransmissionState = Park;
    controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = 0.0F;
  } else {
    switch (controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd) {
     case controller_arduino_4_m_IN_Bmode:
      rtb_AutomaticTransmissionState = Brake;
      if ((rtb_DataTypeConversion1 == Drive) || (rtb_DataTypeConversion1 ==
           Neutral) || (rtb_DataTypeConversion1 == Reverse) ||
          (rtb_DataTypeConversion1 == Park)) {
        controller_arduino_4_mahdy_f_DW.is_Bmode =
          controller_a_IN_NO_ACTIVE_CHILD;
        controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd =
          controller_arduino_4_m_IN_Drive;
        rtb_AutomaticTransmissionState = Drive;
      } else {
        switch (controller_arduino_4_mahdy_f_DW.is_Bmode) {
         case controller_ardu_IN_Acceleration:
          if (rtb_Gain <= 0.33333333333333331) {
            controller_arduino_4_mahdy_f_DW.is_Bmode =
              control_IN_Regenerative_Braking;
          } else {
            controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = (rtb_Gain -
              0.333333343F) * (real32_T)
              controller_arduino_4_mahdy_f_DW.MAX_TORQUE * 3.0F / 2.0F;
          }
          break;

         case control_IN_Regenerative_Braking:
          if (rtb_Gain > 0.33333333333333331) {
            controller_arduino_4_mahdy_f_DW.is_Bmode =
              controller_ardu_IN_Acceleration;
          } else if (((rtb_Gain > 0.0F) <= 0.33333333333333331) && (rtb_Sum <=
                      0.05)) {
            controller_arduino_4_mahdy_f_DW.is_Bmode =
              controller_arduino_4_ma_IN_Stop;
            controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = 0.0F;
          } else {
            controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = (1.0F - 3.0F *
              rtb_Gain) * (real32_T)-controller_arduino_4_mahdy_f_DW.MAX_TORQUE;
          }
          break;

         default:
          /* case IN_Stop: */
          if (rtb_Gain > 0.33333333333333331) {
            controller_arduino_4_mahdy_f_DW.is_Bmode =
              controller_ardu_IN_Acceleration;
          }
          break;
        }
      }
      break;

     case controller_arduino_4_m_IN_Drive:
      rtb_AutomaticTransmissionState = Drive;
      if ((rtb_DataTypeConversion1 == Neutral) || (rtb_DataTypeConversion1 ==
           Reverse) || (rtb_DataTypeConversion1 == Park)) {
        controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd =
          controller_arduino_4_IN_Neutral;
        rtb_AutomaticTransmissionState = Neutral;
        controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = 0.0F;
      } else if (rtb_DataTypeConversion1 == Brake) {
        controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd =
          controller_arduino_4_m_IN_Bmode;
        rtb_AutomaticTransmissionState = Brake;
        controller_arduino_4_mahdy_f_DW.is_Bmode =
          controller_ardu_IN_Acceleration;
      } else {
        controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = rtb_Gain * (real32_T)
          controller_arduino_4_mahdy_f_DW.MAX_TORQUE;
      }
      break;

     case controller_arduino_4_IN_Neutral:
      rtb_AutomaticTransmissionState = Neutral;
      if ((c_value && (rtb_Sum > -5.0F) && (rtb_DataTypeConversion1 == Drive)) ||
          (rtb_DataTypeConversion1 == Brake)) {
        controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd =
          controller_arduino_4_m_IN_Drive;
        rtb_AutomaticTransmissionState = Drive;
      } else if (c_value && (((real32_T)fabs(rtb_Sum) < 5.0F) &&
                             (rtb_DataTypeConversion1 == Park))) {
        controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd =
          controller_arduino_4_ma_IN_Park;
        rtb_AutomaticTransmissionState = Park;
        controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = 0.0F;
      } else if ((rtb_Sum < 5.0F) && (rtb_DataTypeConversion1 == Reverse) &&
                 c_value) {
        controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd =
          controller_arduino_4_IN_Reverse;
        rtb_AutomaticTransmissionState = Reverse;
      }
      break;

     case controller_arduino_4_ma_IN_Park:
      rtb_AutomaticTransmissionState = Park;
      if (c_value && ((rtb_DataTypeConversion1 == Reverse) ||
                      (rtb_DataTypeConversion1 == Neutral) ||
                      (rtb_DataTypeConversion1 == Brake) ||
                      (rtb_DataTypeConversion1 == Drive))) {
        controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd =
          controller_arduino_4_IN_Neutral;
        rtb_AutomaticTransmissionState = Neutral;
        controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = 0.0F;
      }
      break;

     default:
      /* case IN_Reverse: */
      rtb_AutomaticTransmissionState = Reverse;
      if ((rtb_DataTypeConversion1 == Neutral) || (rtb_DataTypeConversion1 ==
           Drive) || (rtb_DataTypeConversion1 == Brake) ||
          (rtb_DataTypeConversion1 == Park)) {
        controller_arduino_4_mahdy_f_DW.is_c3_controller_arduino_4_mahd =
          controller_arduino_4_IN_Neutral;
        rtb_AutomaticTransmissionState = Neutral;
        controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = 0.0F;
      } else {
        controller_arduino_4_mahdy_f_B.TorqueRequest_Nm = -rtb_Gain * (real32_T)
          controller_arduino_4_mahdy_f_DW.MAX_TORQUE_REVERSE;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Switch: '<Root>/Switch' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  if (rtb_Sum2 > controller_arduino_4_mahdy_f_P.Switch_Threshold) {
    /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Rounding: '<Root>/Floor'
     */
    tmp = rt_roundd_snf(controller_arduino_4_mahdy_f_P.Constant1_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    rtb_AutomaticTransmissionState = (TransmissionState)(tmp < 0.0 ? -(int32_T)
      (uint32_T)-tmp : (int32_T)(uint32_T)tmp);
  }

  /* End of Switch: '<Root>/Switch' */

  /* Chart: '<Root>/Chart2' */
  if (controller_arduino_4_mahdy_f_DW.is_active_c2_controller_arduino == 0U) {
    controller_arduino_4_mahdy_f_DW.is_active_c2_controller_arduino = 1U;
    controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
      cont_IN_Input_transmissionState;
  } else {
    switch (controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd) {
     case controller_arduin_IN_BrakeState:
      if (rtb_AutomaticTransmissionState != Brake) {
        controller_arduino_4_mahdy_f_B.Brake_k = 0.0;
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          cont_IN_Input_transmissionState;
      }
      break;

     case controller_arduin_IN_DriveState:
      if (rtb_AutomaticTransmissionState != Drive) {
        controller_arduino_4_mahdy_f_B.Drive_f = 0.0;
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          cont_IN_Input_transmissionState;
      }
      break;

     case cont_IN_Input_transmissionState:
      switch (rtb_AutomaticTransmissionState) {
       case Reverse:
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          controller_ardu_IN_ReverseState;
        controller_arduino_4_mahdy_f_B.Reverse_l = 1.0;
        break;

       case Park:
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          controller_arduino_IN_ParkState;
        controller_arduino_4_mahdy_f_B.Park_b = 1.0;
        break;

       case Neutral:
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          controller_ardu_IN_NeutralState;
        controller_arduino_4_mahdy_f_B.Neutral_m = 1.0;
        break;

       case Drive:
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          controller_arduin_IN_DriveState;
        controller_arduino_4_mahdy_f_B.Drive_f = 1.0;
        break;

       case Brake:
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          controller_arduin_IN_BrakeState;
        controller_arduino_4_mahdy_f_B.Brake_k = 1.0;
        break;
      }
      break;

     case controller_ardu_IN_NeutralState:
      if (rtb_AutomaticTransmissionState != Neutral) {
        controller_arduino_4_mahdy_f_B.Neutral_m = 0.0;
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          cont_IN_Input_transmissionState;
      }
      break;

     case controller_arduino_IN_ParkState:
      if (rtb_AutomaticTransmissionState != Park) {
        controller_arduino_4_mahdy_f_B.Park_b = 0.0;
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          cont_IN_Input_transmissionState;
      }
      break;

     default:
      /* case IN_ReverseState: */
      if (rtb_AutomaticTransmissionState != Reverse) {
        controller_arduino_4_mahdy_f_B.Reverse_l = 0.0;
        controller_arduino_4_mahdy_f_DW.is_c2_controller_arduino_4_mahd =
          cont_IN_Input_transmissionState;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart2' */

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp = rt_roundd_snf(controller_arduino_4_mahdy_f_B.Reverse_l);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* MATLABSystem: '<Root>/Digital Output1' */
  tmp = rt_roundd_snf(controller_arduino_4_mahdy_f_B.Park_b);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(3, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/Digital Output2' */
  tmp = rt_roundd_snf(controller_arduino_4_mahdy_f_B.Neutral_m);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(4, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output2' */

  /* MATLABSystem: '<Root>/Digital Output3' */
  tmp = rt_roundd_snf(controller_arduino_4_mahdy_f_B.Drive_f);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(5, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output3' */

  /* MATLABSystem: '<Root>/Digital Output4' */
  tmp = rt_roundd_snf(controller_arduino_4_mahdy_f_B.Brake_k);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(6, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output4' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (rtb_Sum2 > controller_arduino_4_mahdy_f_P.Switch1_Threshold) {
    tmp = controller_arduino_4_mahdy_f_P.Constant2_Value;
  } else {
    tmp = controller_arduino_4_mahdy_f_B.TorqueRequest_Nm;
  }

  /* Chart: '<Root>/Chart3' incorporates:
   *  Switch: '<Root>/Switch1'
   */
  if (tmp >= 0.0) {
    rtb_PedalFailure = 1;
    rtb_Negative_Torque = 0;
  } else {
    rtb_PedalFailure = 0;
    rtb_Negative_Torque = 1;
  }

  /* End of Chart: '<Root>/Chart3' */

  /* MATLABSystem: '<Root>/Digital Output5' */
  writeDigitalPin(7, (uint8_T)rtb_PedalFailure);

  /* MATLABSystem: '<Root>/Digital Output8' */
  writeDigitalPin(9, (uint8_T)rtb_Negative_Torque);

  /* MATLABSystem: '<Root>/Digital Output6' */
  tmp = rt_roundd_snf(rtb_Switch2);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(12, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output6' */
}

/* Model initialize function */
void controller_arduino_4_mahdy_f_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for Delay: '<Root>/Delay' */
  controller_arduino_4_mahdy_f_DW.Delay_DSTATE =
    controller_arduino_4_mahdy_f_P.Delay_InitialCondition;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  controller_arduino_4_mahdy_f_DW.MAX_TORQUE_REVERSE = 40.0;
  controller_arduino_4_mahdy_f_DW.MAX_TORQUE = 80.0;

  /* Start for MATLABSystem: '<Root>/Digital Output7' */
  controller_arduino_4_mahdy_f_DW.obj_jw.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_jw.isInitialized = 1L;
  digitalIOSetup(13, 1);
  controller_arduino_4_mahdy_f_DW.obj_jw.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  controller_arduino_4_mahdy_f_DW.obj_g.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_g.SampleTime =
    controller_arduino_4_mahdy_f_P.AnalogInput_SampleTime;
  controller_arduino_4_mahdy_f_DW.obj_g.isInitialized = 1L;
  controller_arduino_4_mahdy_f_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(16UL);
  controller_arduino_4_mahdy_f_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input3' */
  controller_arduino_4_mahdy_f_DW.obj.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj.SampleTime =
    controller_arduino_4_mahdy_f_P.AnalogInput3_SampleTime;
  controller_arduino_4_mahdy_f_DW.obj.isInitialized = 1L;
  controller_arduino_4_mahdy_f_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(19UL);
  controller_arduino_4_mahdy_f_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  controller_arduino_4_mahdy_f_DW.obj_j.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_j.SampleTime =
    controller_arduino_4_mahdy_f_P.DigitalInput1_SampleTime;
  controller_arduino_4_mahdy_f_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(10, 0);
  controller_arduino_4_mahdy_f_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  controller_arduino_4_mahdy_f_DW.obj_jv.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_jv.SampleTime =
    controller_arduino_4_mahdy_f_P.DigitalInput_SampleTime;
  controller_arduino_4_mahdy_f_DW.obj_jv.isInitialized = 1L;
  digitalIOSetup(8, 0);
  controller_arduino_4_mahdy_f_DW.obj_jv.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  controller_arduino_4_mahdy_f_DW.obj_h5.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_h5.SampleTime =
    controller_arduino_4_mahdy_f_P.AnalogInput1_SampleTime;
  controller_arduino_4_mahdy_f_DW.obj_h5.isInitialized = 1L;
  controller_arduino_4_mahdy_f_DW.obj_h5.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(17UL);
  controller_arduino_4_mahdy_f_DW.obj_h5.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input2' */
  controller_arduino_4_mahdy_f_DW.obj_h.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_h.SampleTime =
    controller_arduino_4_mahdy_f_P.AnalogInput2_SampleTime;
  controller_arduino_4_mahdy_f_DW.obj_h.isInitialized = 1L;
  controller_arduino_4_mahdy_f_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(18UL);
  controller_arduino_4_mahdy_f_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  controller_arduino_4_mahdy_f_DW.obj_ds.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_ds.isInitialized = 1L;
  digitalIOSetup(2, 1);
  controller_arduino_4_mahdy_f_DW.obj_ds.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  controller_arduino_4_mahdy_f_DW.obj_o.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(3, 1);
  controller_arduino_4_mahdy_f_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  controller_arduino_4_mahdy_f_DW.obj_d.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(4, 1);
  controller_arduino_4_mahdy_f_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output3' */
  controller_arduino_4_mahdy_f_DW.obj_l.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(5, 1);
  controller_arduino_4_mahdy_f_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  controller_arduino_4_mahdy_f_DW.obj_nb.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_nb.isInitialized = 1L;
  digitalIOSetup(6, 1);
  controller_arduino_4_mahdy_f_DW.obj_nb.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output5' */
  controller_arduino_4_mahdy_f_DW.obj_nl.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_nl.isInitialized = 1L;
  digitalIOSetup(7, 1);
  controller_arduino_4_mahdy_f_DW.obj_nl.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output8' */
  controller_arduino_4_mahdy_f_DW.obj_n.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(9, 1);
  controller_arduino_4_mahdy_f_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output6' */
  controller_arduino_4_mahdy_f_DW.obj_f.matlabCodegenIsDeleted = false;
  controller_arduino_4_mahdy_f_DW.obj_f.isInitialized = 1L;
  digitalIOSetup(12, 1);
  controller_arduino_4_mahdy_f_DW.obj_f.isSetupComplete = true;
}

/* Model terminate function */
void controller_arduino_4_mahdy_f_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output7' */
  if (!controller_arduino_4_mahdy_f_DW.obj_jw.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_jw.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output7' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!controller_arduino_4_mahdy_f_DW.obj_g.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((controller_arduino_4_mahdy_f_DW.obj_g.isInitialized == 1L) &&
        controller_arduino_4_mahdy_f_DW.obj_g.isSetupComplete) {
      controller_arduino_4_mahdy_f_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close
        (controller_arduino_4_mahdy_f_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input3' */
  if (!controller_arduino_4_mahdy_f_DW.obj.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_arduino_4_mahdy_f_DW.obj.isInitialized == 1L) &&
        controller_arduino_4_mahdy_f_DW.obj.isSetupComplete) {
      controller_arduino_4_mahdy_f_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close
        (controller_arduino_4_mahdy_f_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!controller_arduino_4_mahdy_f_DW.obj_j.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!controller_arduino_4_mahdy_f_DW.obj_jv.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_jv.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!controller_arduino_4_mahdy_f_DW.obj_h5.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((controller_arduino_4_mahdy_f_DW.obj_h5.isInitialized == 1L) &&
        controller_arduino_4_mahdy_f_DW.obj_h5.isSetupComplete) {
      controller_arduino_4_mahdy_f_DW.obj_h5.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(17UL);
      MW_AnalogIn_Close
        (controller_arduino_4_mahdy_f_DW.obj_h5.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  if (!controller_arduino_4_mahdy_f_DW.obj_h.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((controller_arduino_4_mahdy_f_DW.obj_h.isInitialized == 1L) &&
        controller_arduino_4_mahdy_f_DW.obj_h.isSetupComplete) {
      controller_arduino_4_mahdy_f_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close
        (controller_arduino_4_mahdy_f_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!controller_arduino_4_mahdy_f_DW.obj_ds.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_ds.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!controller_arduino_4_mahdy_f_DW.obj_o.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!controller_arduino_4_mahdy_f_DW.obj_d.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!controller_arduino_4_mahdy_f_DW.obj_l.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!controller_arduino_4_mahdy_f_DW.obj_nb.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_nb.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output5' */
  if (!controller_arduino_4_mahdy_f_DW.obj_nl.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_nl.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output8' */
  if (!controller_arduino_4_mahdy_f_DW.obj_n.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output6' */
  if (!controller_arduino_4_mahdy_f_DW.obj_f.matlabCodegenIsDeleted) {
    controller_arduino_4_mahdy_f_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output6' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
