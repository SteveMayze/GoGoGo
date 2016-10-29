#ifndef mock_Wheel_IRQ_H
#define mock_Wheel_IRQ_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "Wheel_IRQ.h"


DECLARE_FAKE_VOID_FUNC0(EXT0_1_IRQHandler);
DECLARE_FAKE_VOID_FUNC0(EXTI4_15_IRQHandler);
DECLARE_FAKE_VOID_FUNC1(Wheel_IRQ_SetLeftCounter, uint64_t);
DECLARE_FAKE_VOID_FUNC1(Wheel_IRQ_SetRightCounter, uint64_t);
DECLARE_FAKE_VALUE_FUNC0(uint64_t, Wheel_IRQ_GetLeftCounter);
DECLARE_FAKE_VALUE_FUNC0(uint64_t, Wheel_IRQ_GetRightCounter);
DECLARE_FAKE_VOID_FUNC1(Wheel_IRQ_SetStopLeft, _Bool);
DECLARE_FAKE_VOID_FUNC1(Wheel_IRQ_SetStopRight, _Bool);
DECLARE_FAKE_VALUE_FUNC0(_Bool, Wheel_IRQ_GetStopLeft);
DECLARE_FAKE_VALUE_FUNC0(_Bool, Wheel_IRQ_GetStopRight);
DECLARE_FAKE_VOID_FUNC1(Wheel_IRQ_SetLeftLLimit, uint32_t);
DECLARE_FAKE_VOID_FUNC1(Wheel_IRQ_SetRightLimit, uint32_t);
DECLARE_FAKE_VALUE_FUNC0(uint32_t, Wheel_IRQ_GetLeftLimit);
DECLARE_FAKE_VALUE_FUNC0(uint32_t, Wheel_IRQ_GetRightLimit);

void mock_Wheel_IRQ_Init(void);
void mock_Wheel_IRQ_Verify(void);
void mock_Wheel_IRQ_Destroy(void);

#endif // mock_Wheel_IRQ_H
