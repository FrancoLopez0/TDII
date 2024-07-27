/*
 * PWM.c
 *
 *  Created on: 3 jul. 2024
 *      Author: Franco A. López
 */

#include "PWM.h"

void INIT_PWM(t_pwm *PWM){

	assert(PWM->param.dutyCyclePercent <= MAX_DUTY_CYCLE);

	sctimer_config_t sctimerInfo;

	uint32_t sctimerClock;


	sctimerClock = SCTIMER_CLK_FREQ;

	SCTIMER_GetDefaultConfig(&sctimerInfo);

	/* Initialize SCTimer module */
	SCTIMER_Init(SCT0, &sctimerInfo);

	/* Configure first PWM with frequency 24kHZ from first output */


	if (SCTIMER_SetupPwm(SCT0, &(PWM->param), kSCTIMER_CenterAlignedPwm, 24000U, sctimerClock, &(PWM->event)) == kStatus_Fail)
	    {
	    	PRINTF ("Could not start SC Timer\n\r");
	    	return;
	    }

	/* Start the timer */
	SCTIMER_StartTimer(SCT0, kSCTIMER_Counter_U);

}

void UPDATE_PWM(t_pwm * pwm){
	SCTIMER_UpdatePwmDutycycle(SCT0, pwm->param.output, pwm->dutyCycle, pwm->event);
}

void PWM_DEFAULT_CONFIG(t_pwm * pwm){
	pwm->dutyCycle = INITIAL_DUTY_CYCLE;
	pwm->param.output = kSCTIMER_Out_1;
    pwm->param.level = kSCTIMER_HighTrue;
    pwm->param.dutyCyclePercent = pwm->dutyCycle;
}
/*
t_pwm pwm;
pwm.dutyCycle = INITIAL_DUTY_CYCLE;
pwm.param.output = kSCTIMER_Out_1;
pwm.param.level = kSCTIMER_HighTrue;
pwm.param.dutyCyclePercent = pwm.dutyCycle;
*/
