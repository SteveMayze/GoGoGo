#ifndef INCLUDE_WHEEL_IRQ_DELEGATE_H_
#define INCLUDE_WHEEL_IRQ_DELEGATE_H_

#include "Wheel_IRQ.h"
#include "stdbool.h"

void Wheel_IRQ_Delegate_Reset(void);


void Wheel_IRQ_Delegate_SetLeftCounter(uint64_t count);
void Wheel_IRQ_Delegate_SetRightCounter(uint64_t count);

uint64_t Wheel_IRQ_Delegate_GetLeftCounter(void);
uint64_t Wheel_IRQ_Delegate_GetRightCounter(void);

void Wheel_IRQ_Delegate_SetStopLeft(bool flag);
void Wheel_IRQ_Delegate_SetStopRight(bool flag);

bool Wheel_IRQ_Delegate_GetStopLeft(void);
bool Wheel_IRQ_Delegate_GetStopRight(void);


void Wheel_IRQ_Delegate_SetLeftLimit(uint32_t count);
void Wheel_IRQ_Delegate_SetRightLimit(uint32_t count);

uint32_t Wheel_IRQ_Delegate_GetLeftLimit(void);
uint32_t Wheel_IRQ_Delegate_GetRightLimit(void);



#endif /* INCLUDE_WHEEL_IRQ_DELEGATE_H_ */
