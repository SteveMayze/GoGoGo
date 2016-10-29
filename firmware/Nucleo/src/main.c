
#include "common.h"
#include "diag/Trace.h"

#include "GPIOConfig.h"
#include "GPIO.h"
#include "cmsis_device.h"
#include "Wheel.h"


void delay(void);


void delay(void) {
	uint32_t i = 12345689;
	while ((i != 0u)) {
		i--;
	}
}



#define MAIN_TEST_1
#ifdef MAIN_TEST_1
int main(void) {

	Wheel_Initialise();

	int cycles = 10;
	int cycle = 0;
	bool direction = false;

	uint32_t distance = 300;
	uint16_t fSpeed = 60;
	uint16_t rSpeed = 35;

	while (1) {
		if (cycles < 0 || cycle < cycles) {
			if (Wheel_IsRunning()) {
				delay();
				direction = !direction;

				if (direction) {
					Wheel_DoCommand( FORWARD, fSpeed, distance);
					Wheel_AllStop();
					delay();
				} else {
					Wheel_DoCommand( REVERSE, rSpeed, distance);
					Wheel_AllStop();
				}
				cycle++;
			}
		}
	}
}
#endif

#ifdef MAIN_TEST_2
int main(void) {

	setup();

	int cycles = 2;
	int cycle = 0;
	bool direction = false;

	uint32_t distance = 1000;
	uint16_t fSpeed = 80;
	uint16_t rSpeed = 50;

	while (1) {
		if (cycles < 0 || cycle < cycles) {
			if (!left_running && !right_running) {
				delay();
				direction = !direction;

				if (direction) {
					runCommand( FORWARD, fSpeed, distance);
					allStop();
					delay();
				} else {
					runCommand( REVERSE, rSpeed, distance);
					allStop();
				}
				cycle++;
			}
		}
	}
}
#endif

#ifdef MAIN_TEST_3
int main(void) {

	setup();

	int cycles = 2;
	int cycle = 0;
	bool direction = false;

	uint32_t distance = 100;
	uint16_t fSpeed = 60;
	uint16_t rSpeed = 35;

	while (1) {
		if (cycles < 0 || cycle < cycles) {
			if (!left_running && !right_running) {
				delay();
				direction = !direction;

				if (direction) {
//					leftWheel(direction, lSpeed, distance);
//					rightWheel(direction, rSpeed, distance);
					runCommand( FORWARD, fSpeed, distance / 2);
					delay();
					runCommand(LEFT_FWD, fSpeed, distance / 3);
					delay();
					runCommand( FORWARD, fSpeed, distance / 2);
					delay();
					runCommand(LEFT_FWD, fSpeed, distance / 3);
					delay();
					runCommand( FORWARD, fSpeed, distance / 2);
					delay();
					runCommand(LEFT_FWD, fSpeed, distance / 3);
					delay();
					runCommand( FORWARD, fSpeed, distance / 2);
					delay();
					allStop();
				} else {
//					leftWheel(direction, lSpeed / 2, distance);
//					rightWheel(direction, rSpeed / 2, distance);
					runCommand( REVERSE, rSpeed, distance);
					delay();
					runCommand(RIGHT_FWD, rSpeed, distance / 4);
					delay();
					runCommand( REVERSE, rSpeed, distance);
					delay();
					runCommand(RIGHT_FWD, rSpeed, distance / 4);
					delay();
					runCommand( REVERSE, rSpeed, distance);
					delay();
					runCommand(RIGHT_FWD, rSpeed, distance / 4);
					delay();
					runCommand( REVERSE, rSpeed, distance);
					delay();
					allStop();
				}
				cycle++;
			}
		}
	}
}
#endif

#pragma GCC diagnostic pop

