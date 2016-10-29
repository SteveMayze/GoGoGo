

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

	if (port == GPIOA) {
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
		// Set up the Pin
		GPIOInitStructure.GPIO_Pin = pin;
		GPIOInitStructure.GPIO_OType = GPIO_OType_PP;
		GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIOInitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(port, &GPIOInitStructure);

		if (pin == GPIO_Pin_6) {
			GPIO_PinAFConfig(port, GPIO_PinSource6, GPIO_AF_1);
		}
		if (pin == GPIO_Pin_7) {
			GPIO_PinAFConfig(port, GPIO_PinSource7, GPIO_AF_1);
		}


		// Set up the timer
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		TIM_TimeBaseStructure.TIM_Prescaler = 0;
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseStructure.TIM_Period =  (SystemCoreClock / 1000) - 1;
		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 0;
		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
		TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
		TIM_Cmd(TIM3, ENABLE);

		// Configure the PWM
		TIM_OCInitiStructure.TIM_OCMode = TIM_OCMode_PWM2;
		TIM_OCInitiStructure.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitiStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
		TIM_OCInitiStructure.TIM_Pulse = 0;
		if (pin == GPIO_Pin_6) {  // Channel 1
			TIM_OC1Init(TIM3, &TIM_OCInitiStructure);
			TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
		}
		if (pin == GPIO_Pin_7) {  // Channel 2
			TIM_OC2Init(TIM3, &TIM_OCInitiStructure);
			TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
		}
	}
}

void GPIOConfig_SetTickCounters(GPIO_TypeDef *port) {

}

//////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
void GPIOConfig_SetInterruptPin(GPIO_TypeDef* port, uint16_t pin) {

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	if (port == GPIOA) {

		if( pin == GPIO_Pin_0) { // Left Wheel
			SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
			EXTI_InitStructure.EXTI_Line = EXTI_Line0;
			NVIC_InitStructure.NVIC_IRQChannel = EXTI0_1_IRQn;
		}
		if( pin == GPIO_Pin_4) { // Right Wheel
			SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource4);
			EXTI_InitStructure.EXTI_Line = EXTI_Line4;
			NVIC_InitStructure.NVIC_IRQChannel = EXTI4_15_IRQn;
		}

	}

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
