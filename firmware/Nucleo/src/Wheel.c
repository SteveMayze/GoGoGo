
#include "Wheel.h"
#include "Wheel_IRQ.h"

bool left_running = false;
bool right_running = false;

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



void Wheel_Straight(bool forward, uint16_t velocity, uint32_t steps){
	Wheel_TurnLeftWheel(forward, velocity, steps);
	Wheel_TurnRightWheel(forward, velocity, steps);
}


void Wheel_TurnLeftWheel(bool forward, uint16_t velocity, uint32_t steps) {
	GPIO_AnalogWrite(GPIOC, LEFT_PWM, velocity);
	Wheel_IRQ_SetLeftCounter(0);
	Wheel_IRQ_SetLeftLLimit(steps);
	if (forward) {
		GPIO_DigitalWrite(GPIOB, LEFT_INP1, HIGH);
		GPIO_DigitalWrite(GPIOB, LEFT_INP2, LOW);
	} else {
		GPIO_DigitalWrite(GPIOB, LEFT_INP1, LOW);
		GPIO_DigitalWrite(GPIOB, LEFT_INP2, HIGH);
	}
	GPIO_DigitalWrite(GPIOB, LEFT_STBY, HIGH);
	left_running = true;
	Wheel_IRQ_SetStopLeft(false);

}

void Wheel_TurnRightWheel(bool forward, uint16_t velocity, uint32_t steps) {
	GPIO_AnalogWrite(GPIOC, RIGHT_PWM, velocity);
	Wheel_IRQ_SetRightCounter(0);
	Wheel_IRQ_SetRightLimit(steps);
	if (forward) {
		GPIO_DigitalWrite(GPIOB, RIGHT_INP1, LOW);
		GPIO_DigitalWrite(GPIOB, RIGHT_INP2, HIGH);
	} else {
		GPIO_DigitalWrite(GPIOB, RIGHT_INP1, HIGH);
		GPIO_DigitalWrite(GPIOB, RIGHT_INP2, LOW);
	}
	GPIO_DigitalWrite(GPIOB, RIGHT_STBY, HIGH);
	right_running = true;
	Wheel_IRQ_SetStopRight(false);

}

void Wheel_AllStop(void) {
	Wheel_StopLeftWheel();
	Wheel_StopRightWheel();

}

void Wheel_StopLeftWheel(void) {
	GPIO_DigitalWrite(GPIOB, LEFT_INP1, LOW);
	GPIO_DigitalWrite(GPIOB, LEFT_INP2, LOW);
	GPIO_DigitalWrite(GPIOB, LEFT_STBY, LOW);
	Wheel_IRQ_SetLeftCounter(0);
	Wheel_IRQ_SetLeftLLimit(0);
	left_running = false;
}

void Wheel_StopRightWheel(void) {
	GPIO_DigitalWrite(GPIOB, RIGHT_INP1, LOW);
	GPIO_DigitalWrite(GPIOB, RIGHT_INP2, LOW);
	GPIO_DigitalWrite(GPIOB, RIGHT_STBY, LOW);
	Wheel_IRQ_SetRightCounter(0);
	Wheel_IRQ_SetRightLimit(0);
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
				Wheel_Straight(true, speed, distance);
				break;
			case REVERSE:
				Wheel_Straight(false, speed, distance);
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
				if (Wheel_IRQ_GetRightCounter() > Wheel_IRQ_GetLeftCounter()) {
					// Right wheel is faster
					GPIO_AnalogWrite(GPIOC, RIGHT_PWM, compensation - 1);
					GPIO_AnalogWrite(GPIOC, LEFT_PWM, compensation + 1);

				}
				if (Wheel_IRQ_GetLeftCounter() > Wheel_IRQ_GetRightCounter()) {
					// Right wheel is slower
					GPIO_AnalogWrite(GPIOC, RIGHT_PWM, compensation + 1);
					GPIO_AnalogWrite(GPIOC, LEFT_PWM, compensation - 1);
				}
				if (Wheel_IRQ_GetLeftCounter() == Wheel_IRQ_GetRightCounter()) {
					compensation = speed;
					GPIO_AnalogWrite(GPIOC, RIGHT_PWM, compensation);
					GPIO_AnalogWrite(GPIOC, LEFT_PWM, compensation);
				}
			}

			if (Wheel_IRQ_GetStopLeft() && left_running) {
				Wheel_StopLeftWheel();
			}

			if (Wheel_IRQ_GetStopRight() && right_running) {
				Wheel_StopRightWheel();
			}
		}
	}
}

