/*
 * Config.h
 *
 *  Created on: 27 jul. 2024
 *      Author: Franco A. López
 */


/**
 * @file    Config.h
 * @brief   Config Layer.
 */

#ifndef Config_H_
#define Config_H_

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC845.h"

/* TODO: insert other include files here. */
#include "../MyLibs/SWM_config.h"
#include "../MyLibs/DELAY.h"
#include "../MyLibs/PWM.h"
#include "fsl_gpio.h"

/* TODO: insert other definitions and declarations here. */
#define IN0 17
#define IN1 18  
#define IN2 19
#define IN3 20

#define LED_GREEN 0
#define PORT_1 1
#define PORT_0 0
#define LED_OFF 0
#define LED_ON 1

#define BLINK_DELAY 500

#define INIT_CONSOLE 

#ifdef INIT_CONSOLE
    #include "fsl_debug_console.h"
#endif

void SUCCESS(void);

void LED_INIT(void);

void MOTOR_GPIO_INIT(void);


void GPIO_CONFIG(void);

#ifdef INIT_CONSOLE
void CONSOLE_ON(void);
#endif

void CLOCKS_CONFIG(void);

void CONFIG_PINS(void);

void CONFIG_PWM(void);

void INIT_PWM_PINS(void);

void CONFIG_PHERIPERALS(void);

void CONFIG(void);

#endif /* Config_H_ */