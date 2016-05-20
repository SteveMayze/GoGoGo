

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "diag/Trace.h"

#include "GPIOConfig.h"
#include "GPIO.h"
#include "cmsis_device.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

/*
 Arduino to Nucleo Mapping
 left_pwm =  9; // PWM ~9	= PC_7 TIM3_CH2
 left_stby = 5; // PD5		= PB_4
 left_inp1 = 13;			= PA_5
 left_inp2 = 12;			= PA_6
 left_encoderWheel = 2		= PA_10

 right_pwm = 10; // PWM ~10	= PB_6 TIM16_CH1N
 right_stby = 4; // PD4		= PB_5
 right_inp1 = 6;			= PB_10
 right_inp2 = 7;			= PA_8
 right_encoderWheel = 3		= PB_3

 Tentative re-mapping

 LEFT
 	 STBY   	PB0		OUPTUT
 	 IN1    	PB1		OUTPUT
 	 IN2    	PB2		OUTPUT
 	 PWM	D12	PC6	AF0:TIM3_CH1
 	 ENC    	PA0		INPUT/INTERRUPT

 RIGHT
 	 STBY   	PB3		OUTPUT
 	 IN1    	PB4		OUTPUT
 	 IN2    	PB5		OUTPUT
 	 PWM	D11	PC7	AF0:TIM3_CH2
 	 ENC    	PA1		INPUT/INTERRUPT

 */
#define LEFT_STBY GPIO_Pin_0 // Port B
#define LEFT_INP1 GPIO_Pin_1 // Port B
#define LEFT_INP2 GPIO_Pin_2 // Port B
#define LEFT_ENC GPIO_Pin_0 // Port A
#define LEFT_PWM GPIO_Pin_6 // Port C

#define RIGHT_STBY GPIO_Pin_3 // Port B
#define RIGHT_INP1 GPIO_Pin_4 // Port B
#define RIGHT_INP2 GPIO_Pin_5 // Port B
#define RIGHT_ENC GPIO_Pin_1 // Port A
#define RIGHT_PWM GPIO_Pin_7 // Port C


void setup(void);
void EXT0_1_IRQHandler(void);
void EXT2_3_IRQHandler(void);
void delay(void);

void leftWheel(bool forward, uint16_t velocity, uint32_t steps);
void rightWheel(bool forward, uint16_t velocity, uint32_t steps);
void allStop(void);
void leftStop(void);
void rightStop(void);


uint32_t left_counter = 0;
uint32_t right_counter = 0;


void setup(void){
	GPIOConfig_OutputPin(GPIOB, LEFT_STBY); // Left Standby
	GPIOConfig_OutputPin(GPIOB, LEFT_INP1); // Left Inp1
	GPIOConfig_OutputPin(GPIOB, LEFT_INP2); // Left Inp2

	GPIOConfig_InputPin(GPIOA, LEFT_ENC); // Left Encoder Pin
	GPIOConfig_SetInterruptPin(GPIOA, LEFT_ENC); // Left Encoder
	GPIOConfig_SetPWMPin(GPIOC, LEFT_PWM); // Left PWM



	GPIOConfig_OutputPin(GPIOB, RIGHT_STBY); // Right Standby
	GPIOConfig_OutputPin(GPIOB, RIGHT_INP1); // Right Inp1
	GPIOConfig_OutputPin(GPIOB, RIGHT_INP2); // Right Inp2

	GPIOConfig_InputPin(GPIOA, RIGHT_ENC); // Right Encoder Pin
	GPIOConfig_SetInterruptPin(GPIOA, RIGHT_ENC); // Right Encoder
	GPIOConfig_SetPWMPin(GPIOC, RIGHT_PWM); // Right PWM
}

/**
 * Interrupt handler for the LEFT encoder wheel
 */
void EXT0_1_IRQHandler(void) {
	if((EXTI->PR & EXTI_PR_PR0 ) != (uint32_t)0){
		EXTI->PR = EXTI_PR_PR0;
		left_counter++;
		NVIC_ClearPendingIRQ(EXTI0_1_IRQn);
	}
}

void EXT2_3_IRQHandler(void) {
	if((EXTI->PR & EXTI_PR_PR1 ) != (uint32_t)0){
		EXTI->PR = EXTI_PR_PR1;
		right_counter++;
		NVIC_ClearPendingIRQ(EXTI2_3_IRQn);
	}
}


void delay(void){
	uint32_t i = 123456;
	while((i != 0u)){
		i--;
	}
}

void leftWheel(bool forward, uint16_t velocity, uint32_t steps){
	// GPIO_AnalogWrite(GPIOC, LEFT_PWM, velocity);
	left_counter = 0;
	while(left_counter < steps){
		GPIO_DigitalWrite(GPIOB, LEFT_STBY, HIGH);
		if(forward) {
			GPIO_DigitalWrite(GPIOB, LEFT_INP1, HIGH);
			GPIO_DigitalWrite(GPIOB, LEFT_INP2, LOW);
		}
		else {
			GPIO_DigitalWrite(GPIOB, LEFT_INP1, LOW);
			GPIO_DigitalWrite(GPIOB, LEFT_INP2, HIGH);
		}
	}
	GPIO_DigitalWrite(GPIOB, LEFT_INP1, HIGH);
	GPIO_DigitalWrite(GPIOB, LEFT_INP2, HIGH);

}

void rightWheel(bool forward, uint16_t velocity, uint32_t steps) {
	// TODO Fix the Pins and ports!
	// GPIO_AnalogWrite(GPIOC, RIGHT_PWM, velocity);
	right_counter = 0;
	while(right_counter < steps){
		GPIO_DigitalWrite(GPIOB, RIGHT_STBY, HIGH);
		if(forward) {
			GPIO_DigitalWrite(GPIOB, RIGHT_INP1, HIGH);
			GPIO_DigitalWrite(GPIOB, RIGHT_INP2, LOW);
		}
		else {
			GPIO_DigitalWrite(GPIOB, RIGHT_INP1, LOW);
			GPIO_DigitalWrite(GPIOB, RIGHT_INP2, HIGH);
		}
	}
	GPIO_DigitalWrite(GPIOB, RIGHT_INP1, HIGH);
	GPIO_DigitalWrite(GPIOB, RIGHT_INP2, HIGH);

}

void allStop(void){
	leftStop();
	rightStop();

}

void leftStop(void) {
	GPIO_DigitalWrite(GPIOB, LEFT_INP1, LOW);
	GPIO_DigitalWrite(GPIOB, LEFT_INP2, LOW);
}

void rightStop(void) {
	GPIO_DigitalWrite(GPIOB, RIGHT_INP1, LOW);
	GPIO_DigitalWrite(GPIOB, RIGHT_INP2, LOW);
}


int main(int argc, char* argv[]) {

	// SystemInit();

	setup();

	while (1) {
		allStop();
		leftWheel(true, 80, 100);
		delay();
		leftWheel(false, 100, 10);
    }
}

#pragma GCC diagnostic pop

