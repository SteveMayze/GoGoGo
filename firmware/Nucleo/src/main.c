

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "GPIOConfig.h"
#include "cmsis_device.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

/*
 Arduino to Nucleo Mapping
 left_pwm = 9; // PWM ~9	= PC_7 TIM3_CH2
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
 	 STBY
 	 IN1
 	 IN2
 	 PWM	D5	PB4		AF1:TIM3_CH1
 	 ENC

 RIGHT
 	 STBY
 	 IN1
 	 IN2
 	 PWM	D6	PB10	TIM17_CH1
 	 ENC

 */


void setup(void);


void setup(void){
	GPIOConfig_OutputPin(GPIOB, GPIO_Pin_4); // Left Standby
	GPIOConfig_OutputPin(GPIOA, GPIO_Pin_5); // Left Inp1
	GPIOConfig_OutputPin(GPIOA, GPIO_Pin_6); // Left Inp2
	//TODO - Correct the PINs etc.
	GPIOConfig_InputPin(GPIOA, GPIO_Pin_10); // Left Decoder Pin
	GPIOConfig_SetPWMPin(GPIOB, GPIO_Pin_4); // Left PWM
	GPIOConfig_SetInterruptPin(GPIOA, GPIO_Pin_10); // Left Encoder



	GPIOConfig_OutputPin(GPIOB, GPIO_Pin_5); // Right Standby
	GPIOConfig_OutputPin(GPIOB, GPIO_Pin_10); // Right Inp1
	GPIOConfig_OutputPin(GPIOA, GPIO_Pin_8); // Right Inp2
	//TODO - Correct the PINs etc.
	GPIOConfig_InputPin(GPIOA, GPIO_Pin_10); // Right Decoder Pin
	GPIOConfig_SetPWMPin(GPIOB, GPIO_Pin_4); // Right PWM
	GPIOConfig_SetInterruptPin(GPIOA, GPIO_Pin_10); // Right Encoder
}

int main(int argc, char* argv[]) {

	while (1) {
		// Add your code here.
    }
}

#pragma GCC diagnostic pop

