/*
 * Wheel.h
 *
 *  Created on: Oct 29, 2016
 *      Author: vagrant
 */

#ifndef INCLUDE_WHEEL_H_
#define INCLUDE_WHEEL_H_

#include "GPIOConfig.h"
#include "cmsis_device.h"
#include "stm32f0xx_gpio.h"

#include <stdbool.h>
#include <stdint.h>


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

#define LEFT_FWD ((uint16_t)0x0001)
#define LEFT_REV ((uint16_t)0x0002)
#define RIGHT_FWD ((uint16_t)0x0003)
#define RIGHT_REV ((uint16_t)0x0004)
#define FORWARD ((uint16_t)0x0100)
#define REVERSE ((uint16_t)0x0200)
#define ALL_STOP ((uint16_t)0x0300)

void Wheel_Initialise(void);

void Wheel_Straight(bool forward, uint16_t velocity, uint32_t steps);
void Wheel_TurnLeftWheel(bool forward, uint16_t velocity, uint32_t steps);
void Wheel_TurnRightWheel(bool forward, uint16_t velocity, uint32_t steps);
void Wheel_AllStop(void);
void Wheel_StopLeftWheel(void);
void Wheel_StopRightWheel(void);
void Wheel_DoCommand(uint16_t command, uint16_t speed, uint32_t distance);
bool Wheel_IsRunning(void);



#endif /* INCLUDE_WHEEL_H_ */
