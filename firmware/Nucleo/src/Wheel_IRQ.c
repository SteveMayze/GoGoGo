
#include "Wheel.h"
#include "Wheel_IRQ.h"

static volatile uint64_t left_counter = 0;
static volatile uint64_t right_counter = 0;
static volatile bool stop_left = false;
static volatile bool stop_right = false;

static volatile uint32_t left_limit = 0;
static volatile uint32_t right_limit = 0;

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


void Wheel_IRQ_SetLeftCounter(uint64_t count){
	left_counter = count;
}
void Wheel_IRQ_SetRightCounter(uint64_t count) {
	right_counter = count;
}

uint64_t Wheel_IRQ_GetLeftCounter(void) {
	return left_counter;
}
uint64_t Wheel_IRQ_GetRightCounter(void) {
	return right_counter;
}


void Wheel_IRQ_SetStopLeft(bool flag) {
	stop_left = flag;
}

void Wheel_IRQ_SetStopRight(bool flag) {
	stop_right = flag;
}

bool Wheel_IRQ_GetStopLeft(void) {
	return stop_left;
}

bool Wheel_IRQ_GetStopRight(void) {
	return stop_right;
}


void Wheel_IRQ_SetLeftLLimit(uint32_t count) {
	left_limit = count;
}

void Wheel_IRQ_SetRightLimit(uint32_t count) {
	right_limit = count;
}


uint32_t Wheel_IRQ_GetLeftLimit(void){
	return left_limit;
}

uint32_t Wheel_IRQ_GetRightLimit(void) {
	right_limit;
}


