

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
// NUCLEO Defines
//#define LEFT_STBY GPIO_Pin_0 // Port B
//#define LEFT_INP1 GPIO_Pin_1 // Port B
//#define LEFT_INP2 GPIO_Pin_2 // Port B
//#define LEFT_ENC GPIO_Pin_0 // Port A EXTI0_1
//#define LEFT_PWM GPIO_Pin_6 // Port C
//
//#define RIGHT_STBY GPIO_Pin_3 // Port B
//#define RIGHT_INP1 GPIO_Pin_4 // Port B (Swapped from 4)
//#define RIGHT_INP2 GPIO_Pin_5 // Port B (Swapped from 5)
//#define RIGHT_ENC GPIO_Pin_4 // Port A EXTI2_3 - Formally Pin_0
//#define RIGHT_PWM GPIO_Pin_7 // Port C

#define LEFT_STBY GPIO_Pin_8 // Port B
#define LEFT_INP1 GPIO_Pin_9 // Port B
#define LEFT_INP2 GPIO_Pin_10 // Port B
#define LEFT_ENC GPIO_Pin_0 // Port A EXTI0_1
#define LEFT_PWM GPIO_Pin_6 // Port A

#define RIGHT_STBY GPIO_Pin_11 // Port B
#define RIGHT_INP1 GPIO_Pin_12 // Port B (Swapped from 4)
#define RIGHT_INP2 GPIO_Pin_13 // Port B (Swapped from 5)
#define RIGHT_ENC GPIO_Pin_4 // Port A EXTI2_3 - Formally Pin_0
#define RIGHT_PWM GPIO_Pin_7 // Port A


void setup(void);
void EXT0_1_IRQHandler(void);
void EXTI4_15_IRQHandler (void);

void delay(void);

void leftWheel(bool forward, uint16_t velocity, uint32_t steps);
void rightWheel(bool forward, uint16_t velocity, uint32_t steps);
void allStop(void);
void leftStop(void);
void rightStop(void);


uint32_t left_counter = 0;
uint32_t right_counter = 0;
bool stop_left = false;
bool stop_right = false;
bool left_running = false;
bool right_running = false;
uint32_t left_limit = 0;
uint32_t right_limit = 0;

void setup(void){
	GPIOConfig_OutputPin(GPIOB, LEFT_STBY); // Left Standby
	GPIOConfig_OutputPin(GPIOB, LEFT_INP1); // Left Inp1
	GPIOConfig_OutputPin(GPIOB, LEFT_INP2); // Left Inp2

	GPIOConfig_InputPin(GPIOA, LEFT_ENC); // Left Encoder Pin
	GPIOConfig_SetInterruptPin(GPIOA, LEFT_ENC); // Left Encoder
	GPIOConfig_SetPWMPin(GPIOA, LEFT_PWM); // Left PWM



	 GPIOConfig_OutputPin(GPIOB, RIGHT_STBY); // Right Standby
	 GPIOConfig_OutputPin(GPIOB, RIGHT_INP1); // Right Inp1
	 GPIOConfig_OutputPin(GPIOB, RIGHT_INP2); // Right Inp2

	 GPIOConfig_InputPin(GPIOA, RIGHT_ENC); // Right Encoder Pin
	 GPIOConfig_SetInterruptPin(GPIOA, RIGHT_ENC); // Right Encoder
	 GPIOConfig_SetPWMPin(GPIOA, RIGHT_PWM); // Right PWM
}

/**
 * Interrupt handler for the LEFT encoder wheel
 */
void EXTI0_1_IRQHandler(void) {
	if((EXTI->PR & EXTI_PR_PR0 ) != (uint32_t)0){
		EXTI->PR = EXTI_PR_PR0;
		left_counter++;
		stop_left = left_counter > left_limit;
		NVIC_ClearPendingIRQ(EXTI0_1_IRQn);
	}
}

/**
 * Interrupt handler for the RIGHT encoder wheel
 */
// Formerly EXTI2_3_IRQHandler
void EXTI4_15_IRQHandler (void) {
	if((EXTI->PR & EXTI_PR_PR4 ) != (uint32_t)0){
		EXTI->PR = EXTI_PR_PR4;
		right_counter++;
		stop_right = right_counter > right_limit;
		NVIC_ClearPendingIRQ(EXTI4_15_IRQn);
	}
}


void delay(void){
	uint32_t i = 12345689;
	while((i != 0u)){
		i--;
	}
}

void leftWheel(bool forward, uint16_t velocity, uint32_t steps) {
	GPIO_AnalogWrite(GPIOC, LEFT_PWM, velocity);
	left_counter = 0;
	left_limit = steps;
	GPIO_DigitalWrite(GPIOB, LEFT_STBY, HIGH);
	if (forward) {
		GPIO_DigitalWrite(GPIOB, LEFT_INP1, HIGH);
		GPIO_DigitalWrite(GPIOB, LEFT_INP2, LOW);
	} else {
		GPIO_DigitalWrite(GPIOB, LEFT_INP1, LOW);
		GPIO_DigitalWrite(GPIOB, LEFT_INP2, HIGH);
	}
	left_running = true;
	stop_left = false;

}

void rightWheel(bool forward, uint16_t velocity, uint32_t steps) {
	GPIO_AnalogWrite(GPIOC, RIGHT_PWM, velocity);
	right_counter = 0;
	right_limit = steps;
	GPIO_DigitalWrite(GPIOB, RIGHT_STBY, HIGH);
	if (forward) {
		GPIO_DigitalWrite(GPIOB, RIGHT_INP1, LOW);
		GPIO_DigitalWrite(GPIOB, RIGHT_INP2, HIGH);
	} else {
		GPIO_DigitalWrite(GPIOB, RIGHT_INP1, HIGH);
		GPIO_DigitalWrite(GPIOB, RIGHT_INP2, LOW);
	}
	right_running = true;
	stop_right = false;

}

void allStop(void){
	leftStop();
	rightStop();

}

void leftStop(void) {
	GPIO_DigitalWrite(GPIOB, LEFT_INP1, LOW);
	GPIO_DigitalWrite(GPIOB, LEFT_INP2, LOW);
	GPIO_DigitalWrite(GPIOB, LEFT_STBY, LOW);
	left_counter = 0;
	left_limit = 0;
	left_running = false;
}

void rightStop(void) {
	GPIO_DigitalWrite(GPIOB, RIGHT_INP1, LOW);
	GPIO_DigitalWrite(GPIOB, RIGHT_INP2, LOW);
	GPIO_DigitalWrite(GPIOB, RIGHT_STBY, LOW);
	right_counter = 0;
	right_limit = 0;
	right_running = false;
}


int main(int argc, char* argv[]) {

	setup();

	int cycles = 2;
	int cycle = 0;
	bool direction = false;

	int distance = 1000;
	int lSpeed = 70;
	int rSpeed = 70;

	while (1) {
		if (cycles < 0 || cycle < cycles) {
			if (!left_running && !right_running) {
				delay();
				direction = !direction;


				if (direction) {
					leftWheel(direction, lSpeed, distance);
					rightWheel(direction, rSpeed, distance);

				} else {
					leftWheel(direction, lSpeed / 2, distance);
					rightWheel(direction, rSpeed / 2, distance);

				}
				cycle++;
			}
		}
		if (left_running || right_running) {

			if (stop_left && left_running) {
				leftStop();
			}

			if (stop_right && right_running) {
				rightStop();
			}
		}
	}
}

#pragma GCC diagnostic pop

