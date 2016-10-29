
#include "Wheel.h"

static volatile uint64_t left_counter = 0;
static volatile uint64_t right_counter = 0;
static volatile bool stop_left = false;
static volatile bool stop_right = false;
bool left_running = false;
bool right_running = false;
uint32_t left_limit = 0;
uint32_t right_limit = 0;

uint16_t compensation = 0;


bool Wheel_IsRunning(void){
	return !left_running && !right_running;
}


void Wheel_Initialise(void) {
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
	if ((EXTI->PR & EXTI_PR_PR0) != (uint32_t) 0) {
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
void EXTI4_15_IRQHandler(void) {
	if ((EXTI->PR & EXTI_PR_PR4) != (uint32_t) 0) {
		EXTI->PR = EXTI_PR_PR4;
		right_counter++;
		stop_right = right_counter > right_limit;
		NVIC_ClearPendingIRQ(EXTI4_15_IRQn);
	}
}


void Wheel_TurnLeftWheel(bool forward, uint16_t velocity, uint32_t steps) {
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

void Wheel_TurnRightWheel(bool forward, uint16_t velocity, uint32_t steps) {
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

void Wheel_AllStop(void) {
	Wheel_StopLeftWheel();
	Wheel_StopRightWheel();

}

void Wheel_StopLeftWheel(void) {
	GPIO_DigitalWrite(GPIOB, LEFT_INP1, LOW);
	GPIO_DigitalWrite(GPIOB, LEFT_INP2, LOW);
	GPIO_DigitalWrite(GPIOB, LEFT_STBY, LOW);
	left_counter = 0;
	left_limit = 0;
	left_running = false;
}

void Wheel_StopRightWheel(void) {
	GPIO_DigitalWrite(GPIOB, RIGHT_INP1, LOW);
	GPIO_DigitalWrite(GPIOB, RIGHT_INP2, LOW);
	GPIO_DigitalWrite(GPIOB, RIGHT_STBY, LOW);
	right_counter = 0;
	right_limit = 0;
	right_running = false;
}

void Wheel_DoCommand(uint16_t command, uint16_t speed, uint32_t distance) {
	bool running = true;
	bool newcmd = true;
	compensation = speed;
	while (running) {
		if (newcmd) {
			newcmd = false;
			switch (command) {
			case FORWARD:
				Wheel_TurnLeftWheel(true, speed, distance);
				Wheel_TurnRightWheel(true, speed, distance);
				break;
			case REVERSE:
				Wheel_TurnLeftWheel(false, speed, distance);
				Wheel_TurnRightWheel(false, speed, distance);
				break;
			case LEFT_FWD:
				Wheel_StopRightWheel();
				Wheel_TurnLeftWheel(true, speed, distance);
				break;
			case LEFT_REV:
				Wheel_StopRightWheel();
				Wheel_TurnLeftWheel(false, speed, distance);
				break;
			case RIGHT_FWD:
				Wheel_StopLeftWheel();
				Wheel_TurnRightWheel(true, speed, distance);
				break;
			case RIGHT_REV:
				Wheel_StopLeftWheel();
				Wheel_TurnRightWheel(false, speed, distance);
				break;
			case ALL_STOP:
				Wheel_AllStop();
				break;
			default:
				break;
			}
		}
		running = left_running || right_running;
		if (running) {

			if (command == FORWARD || command == REVERSE) {
				if (right_counter > left_counter) {
					// Right wheel is faster
					GPIO_AnalogWrite(GPIOC, RIGHT_PWM, compensation - 1);
					GPIO_AnalogWrite(GPIOC, LEFT_PWM, compensation + 1);

				}
				if (left_counter > right_counter) {
					// Right wheel is slower
					GPIO_AnalogWrite(GPIOC, RIGHT_PWM, compensation + 1);
					GPIO_AnalogWrite(GPIOC, LEFT_PWM, compensation - 1);
				}
				if (left_counter == right_counter) {
					compensation = speed;
					GPIO_AnalogWrite(GPIOC, RIGHT_PWM, compensation);
					GPIO_AnalogWrite(GPIOC, LEFT_PWM, compensation);
				}
			}

			if (stop_left && left_running) {
				Wheel_StopLeftWheel();
			}

			if (stop_right && right_running) {
				Wheel_StopRightWheel();
			}
		}
	}
}

