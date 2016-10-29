#include <string.h>
#include "fff.h"
#include "mock_Wheel_IRQ.h"

DEFINE_FAKE_VOID_FUNC0(EXT0_1_IRQHandler);
DEFINE_FAKE_VOID_FUNC0(EXTI4_15_IRQHandler);
DEFINE_FAKE_VOID_FUNC1(Wheel_IRQ_SetLeftCounter, uint64_t);
DEFINE_FAKE_VOID_FUNC1(Wheel_IRQ_SetRightCounter, uint64_t);
DEFINE_FAKE_VALUE_FUNC0(uint64_t, Wheel_IRQ_GetLeftCounter);
DEFINE_FAKE_VALUE_FUNC0(uint64_t, Wheel_IRQ_GetRightCounter);
DEFINE_FAKE_VOID_FUNC1(Wheel_IRQ_SetStopLeft, _Bool);
DEFINE_FAKE_VOID_FUNC1(Wheel_IRQ_SetStopRight, _Bool);
DEFINE_FAKE_VALUE_FUNC0(_Bool, Wheel_IRQ_GetStopLeft);
DEFINE_FAKE_VALUE_FUNC0(_Bool, Wheel_IRQ_GetStopRight);
DEFINE_FAKE_VOID_FUNC1(Wheel_IRQ_SetLeftLLimit, uint32_t);
DEFINE_FAKE_VOID_FUNC1(Wheel_IRQ_SetRightLimit, uint32_t);
DEFINE_FAKE_VALUE_FUNC0(uint32_t, Wheel_IRQ_GetLeftLimit);
DEFINE_FAKE_VALUE_FUNC0(uint32_t, Wheel_IRQ_GetRightLimit);

void mock_Wheel_IRQ_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(EXT0_1_IRQHandler)
    RESET_FAKE(EXTI4_15_IRQHandler)
    RESET_FAKE(Wheel_IRQ_SetLeftCounter)
    RESET_FAKE(Wheel_IRQ_SetRightCounter)
    RESET_FAKE(Wheel_IRQ_GetLeftCounter)
    RESET_FAKE(Wheel_IRQ_GetRightCounter)
    RESET_FAKE(Wheel_IRQ_SetStopLeft)
    RESET_FAKE(Wheel_IRQ_SetStopRight)
    RESET_FAKE(Wheel_IRQ_GetStopLeft)
    RESET_FAKE(Wheel_IRQ_GetStopRight)
    RESET_FAKE(Wheel_IRQ_SetLeftLLimit)
    RESET_FAKE(Wheel_IRQ_SetRightLimit)
    RESET_FAKE(Wheel_IRQ_GetLeftLimit)
    RESET_FAKE(Wheel_IRQ_GetRightLimit)
}
void mock_Wheel_IRQ_Verify(void)
{
}
void mock_Wheel_IRQ_Destroy(void)
{
}
