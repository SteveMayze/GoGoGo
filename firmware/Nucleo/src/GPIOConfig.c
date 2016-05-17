

#include "GPIOConfig.h"
#include "cmsis_device.h"

void GPIOConfig_OutputPin(GPIO_TypeDef* port, uint16_t pin){
	if(port == GPIOA){
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	} else if(port == GPIOB){
		RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	} else	if(port == GPIOC){
		RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	} else {
		// TODO ?
	}

	GPIO_InitTypeDef GPIOInitStructure;

	GPIOInitStructure.GPIO_Pin = pin;
	GPIOInitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIOInitStructure.GPIO_OType = GPIO_OType_PP;
	GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(port, &GPIOInitStructure);
}


void GPIOConfig_InputPin(GPIO_TypeDef* port, uint16_t pin){
	GPIO_InitTypeDef GPIOInitStructure;

	GPIOInitStructure.GPIO_Pin = pin;
	GPIOInitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(port, &GPIOInitStructure);

}


void GPIOConfig_SetPWMPin(GPIO_TypeDef* port, uint16_t pin) {
	GPIO_InitTypeDef GPIOInitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitiStructure;

	GPIOInitStructure.GPIO_Pin = pin;
	GPIOInitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIOInitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIOInitStructure.GPIO_OType = GPIO_OType_PP;
	GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(port, &GPIOInitStructure);

	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = (SystemCoreClock / 1000) - 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_OCInitiStructure.TIM_Pulse = 0;
	TIM_OCInitiStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitiStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitiStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitiStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitiStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitiStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitiStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;

	// TODO Change this to my Left and Right PWM
	if( port == GPIOC) {
		if (pin == GPIO_PinSource7){
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);
			GPIO_PinAFConfig(port, pin, GPIO_AF_0);
			TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
			TIM_OC1Init(TIM3, &TIM_OCInitiStructure);

			TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
			TIM_SelectOnePulseMode(TIM3, TIM_OPMode_Repetitive);
			TIM_Cmd(TIM3, ENABLE);
			TIM_CtrlPWMOutputs(TIM3, ENABLE);
		}
	}
	if( port == GPIOB) {
		if (pin == GPIO_PinSource6){
			RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM16 , ENABLE);
			GPIO_PinAFConfig(port, pin, GPIO_AF_0);
			TIM_TimeBaseInit(TIM16, &TIM_TimeBaseStructure);
			TIM_OC1Init(TIM16, &TIM_OCInitiStructure);

			TIM_OC2PreloadConfig(TIM16, TIM_OCPreload_Enable);
			TIM_SelectOnePulseMode(TIM16, TIM_OPMode_Repetitive);
			TIM_Cmd(TIM16, ENABLE);
			TIM_CtrlPWMOutputs(TIM16, ENABLE);
		}
	}
}


void GPIOConfig_SetInterruptPin(GPIO_TypeDef* port, uint16_t pin) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	if (port == GPIOA) {
		SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource10);

		EXTI_InitStructure.EXTI_Line = EXTI_Line10;
	}

	if (port == GPIOB) {
		SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource3);

		EXTI_InitStructure.EXTI_Line = EXTI_Line10;
	}

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_15_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
