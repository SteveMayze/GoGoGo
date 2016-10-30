
#include "Wheel_IRQ_Delegate.h"

static uint64_t delegate_left_counter = 0;
static uint64_t delegate_right_counter = 0;
static bool delegate_stop_left = false;
static bool delegate_stop_right = false;
static uint32_t delegate_left_limit = 0;
static uint32_t delegate_right_limit = 0;


void Wheel_IRQ_Delegate_Reset(void){
  delegate_left_counter = 0;
  delegate_right_counter = 0;
  delegate_stop_left = false;
  delegate_stop_right = false;
  delegate_left_limit = 0;
  delegate_right_limit = 0;
}



void Wheel_IRQ_Delegate_SetLeftCounter(uint64_t count) {
  delegate_left_counter = count;
}
void Wheel_IRQ_Delegate_SetRightCounter(uint64_t count) {
  delegate_right_counter = count;
}


uint64_t Wheel_IRQ_Delegate_GetLeftCounter(void)
{
  printf("Called Wheel_IRQ_Delegate_GetLeftCounter %u\n", (int)delegate_left_counter);
  delegate_left_counter++;
  delegate_stop_left = delegate_left_counter > delegate_left_limit;
  return delegate_left_counter;
}

uint64_t Wheel_IRQ_Delegate_GetRightCounter(void) {
  printf("Called Wheel_IRQ_Delegate_GetRightCounter %u\n", (int)delegate_right_counter);
  delegate_right_counter++;
  delegate_stop_right = delegate_right_counter > delegate_right_limit;
  return delegate_right_counter;
}

void Wheel_IRQ_Delegate_SetStopLeft(bool flag) {
  delegate_stop_left = flag;
}
void Wheel_IRQ_Delegate_SetStopRight(bool flag) {
  delegate_stop_right = flag;
}

bool Wheel_IRQ_Delegate_GetStopLeft(void) {
  return delegate_stop_left;
}

bool Wheel_IRQ_Delegate_GetStopRight(void){
  return delegate_stop_right;
}


void Wheel_IRQ_Delegate_SetLeftLimit(uint32_t count){
  delegate_left_limit = count;
}
void Wheel_IRQ_Delegate_SetRightLimit(uint32_t count){
  delegate_right_limit = count;
}

uint32_t Wheel_IRQ_Delegate_GetLeftLimit(void) {
  return delegate_left_limit;
}
uint32_t Wheel_IRQ_Delegate_GetRightLimit(void) {
  return delegate_right_limit;
}
