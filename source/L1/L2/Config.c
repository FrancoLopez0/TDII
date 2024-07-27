
#include "Config.h"

t_pwm PWM1;
t_pwm PWM2;

bool PSC = 0;

void SUCCESS(void){
    delay_ms(BLINK_DELAY);
    LED_GREEN_TOGGLE();
    delay_ms(BLINK_DELAY);
    LED_GREEN_TOGGLE();
}

void LED_INIT(void){
    const gpio_pin_config_t config_out = {kGPIO_DigitalOutput,0};

 	GPIO_PortInit(GPIO, PORT_1);

	GPIO_PinInit(GPIO, PORT_1, LED_GREEN, &config_out); 
}

void MOTOR_GPIO_INIT(void){
    const gpio_pin_config_t config_out = {kGPIO_DigitalOutput,0};

 	GPIO_PortInit(GPIO, PORT_0);

	GPIO_PinInit(GPIO, PORT_0, IN0, &config_out);
    GPIO_PinInit(GPIO, PORT_0, IN1, &config_out);
    GPIO_PinInit(GPIO, PORT_0, IN2, &config_out);
    GPIO_PinInit(GPIO, PORT_0, IN3, &config_out);
     
}

void GPIO_CONFIG(void){
    
    LED_INIT();

    MOTOR_GPIO_INIT();

	SUCCESS();
}

#ifdef INIT_CONSOLE
void CONSOLE_ON(void){
    BOARD_InitDEBUG_UARTPins();
    BOARD_InitDebugConsole();
    PRINTF("CONSOLE ON....\r\n");
}
#endif

void CLOCKS_CONFIG(void){
    BOARD_BootClockFRO18M();
    SYSTICK_INIT();
}

void CONFIG_PINS(void){
    
    #ifdef INIT_CONSOLE
        CONSOLE_ON();
    #endif

    SWM_CONFIG();
    GPIO_CONFIG();

    #ifdef INIT_CONSOLE
        PRINTF("Pins Successfully Configured! :D");
    #endif
    PSC = true;// Pins Successfully Configured (PSC)
}

void CONFIG_PWM(void){

    PWM_DEFAULT_CONFIG(&PWM1);
    PWM_DEFAULT_CONFIG(&PWM2);

    PWM2.param.output = kSCTIMER_Out_2;
    assert(PWM1.param.output != PWM2.param.output);
    //TODO: PWM Update not found
//    PWM2.dutyCycle = 20;
//    UPDATE_PWM(&PWM2);
}

void INIT_PWM_PINS(void){
    INIT_PWM(&PWM1);
    INIT_PWM(&PWM2);
}

void CONFIG_PHERIPERALS(void){
    CONFIG_PWM();
    INIT_PWM_PINS();
}

void CONFIG(void){
    CLOCKS_CONFIG();
    CONFIG_PINS();
    CONFIG_PHERIPERALS();
}