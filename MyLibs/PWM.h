/*
 * PWM.h
 *
 *  Created on: 3 jul. 2024
 *      Author: Franco A. López
 */

#ifndef PWM_H_
#define PWM_H_

#include "fsl_sctimer.h"
#include "fsl_swm_connections.h"
#include "fsl_debug_console.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define SCTIMER_CLK_FREQ CLOCK_GetFreq(kCLOCK_Fro)
#define DEMO_FIRST_SCTIMER_OUT kSCTIMER_Out_1
#define INITIAL_DUTY_CYCLE 60U
#define MAX_DUTY_CYCLE 100U
typedef struct {
	uint8_t dutyCycle;
	uint32_t event;
	sctimer_pwm_signal_param_t param;
}t_pwm;

/*******************************************************************************
 * API
 ******************************************************************************/

/**
 * @brief Init PWM channels
 *
 * @param pwmParam  pointer sctimer_pwm_signal_param_t
 * @param event 	pointer var use for storage sctimer event 
 *
 * @return void
 */
void INIT_PWM(t_pwm *);
/**
 * @brief Upate duty cycle
 *
 * @param pwm  pointer sctimer_pwm_signal_param_t
 *
 * @return void
 */
void UPDATE_PWM(t_pwm *);
/**
 * @brief Set default config
 *
 * @param pwm  pointer sctimer_pwm_signal_param_t
 *
 * @return void
 * 
 * @note If you use 2 channels, I should change the channel on the next line
 */
void PWM_DEFAULT_CONFIG(t_pwm *);

#endif /* PWM_H_ */
