

#ifndef INCLUDE_WHEEL_IRQ_H_
#define INCLUDE_WHEEL_IRQ_H_
#include "Wheel.h"

void EXT0_1_IRQHandler(void);
void EXTI4_15_IRQHandler(void);


void Wheel_IRQ_SetLeftCounter(uint64_t count);
void Wheel_IRQ_SetRightCounter(uint64_t count);

uint64_t Wheel_IRQ_GetLeftCounter(void);
uint64_t Wheel_IRQ_GetRightCounter(void);

void Wheel_IRQ_SetStopLeft(bool flag);
void Wheel_IRQ_SetStopRight(bool flag);

bool Wheel_IRQ_GetStopLeft(void);
bool Wheel_IRQ_GetStopRight(void);


void Wheel_IRQ_SetLeftLLimit(uint32_t count);
void Wheel_IRQ_SetRightLimit(uint32_t count);

uint32_t Wheel_IRQ_GetLeftLimit(void);
uint32_t Wheel_IRQ_GetRightLimit(void);


#endif /* INCLUDE_WHEEL_IRQ_H_ */
