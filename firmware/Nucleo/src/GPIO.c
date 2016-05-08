

#include "GPIO.h"
#include "GPIOConfig.h"
#include "cmsis_device.h"
#include "stm32f0xx_gpio.h"

void GPIO_DigitalWrite(GPIO_TypeDef *port, uint16_t pin, uint16_t value){
	if( value == HIGH ){
		GPIO_setBits(port, pin);
	}
	if( value == LOW ) {
		GPIO_ResetBits(port, pin);
	}
}



void GPIO_AnalogWrite(GPIO_TypeDef *port, uint16_t pin, uint16_t value){
	uint16_t pwmPeriod = (SystemCoreClock / 1000) -1;
	uint16_t channelPulse = (uint16_t)(((uint32_t)value*(pwmPeriod -1)) / 100);

	// TODO - Hard coded the PWM stuff for the moment as per Eric.
	if( port == GPIOC){
		if ( pin == GPIO_PinSource7) {
			TIM3->CCR1 = channelPulse;
		}
	}
	if( port == GPIOB){
		if ( pin == GPIO_PinSource6) {
			TIM3->CCR1 = channelPulse;
		}
	}
}
