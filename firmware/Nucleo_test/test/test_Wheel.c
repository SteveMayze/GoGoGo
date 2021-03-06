#include "unity.h"
#include "Wheel.h"
#include "stdbool.h"

#include "mock_GPIO.h"
#include "mock_GPIOConfig.h"
#include "mock_Wheel_IRQ.h"

#include "cmsis_device.h"
#include "Wheel_IRQ_Delegate.h"


void setUp(void) {

  printf("setUp: preparing...");
  Wheel_IRQ_Delegate_Reset();

  Wheel_IRQ_GetLeftCounter_fake.custom_fake = Wheel_IRQ_Delegate_GetLeftCounter;
  Wheel_IRQ_GetRightCounter_fake.custom_fake = Wheel_IRQ_Delegate_GetRightCounter;
  Wheel_IRQ_GetStopLeft_fake.custom_fake = Wheel_IRQ_Delegate_GetStopLeft;
  Wheel_IRQ_GetStopRight_fake.custom_fake = Wheel_IRQ_Delegate_GetStopRight;
  Wheel_IRQ_GetLeftLimit_fake.custom_fake = Wheel_IRQ_Delegate_GetLeftLimit;
  Wheel_IRQ_GetRightLimit_fake.custom_fake = Wheel_IRQ_Delegate_GetRightLimit;

  Wheel_IRQ_SetLeftCounter_fake.custom_fake = Wheel_IRQ_Delegate_SetLeftCounter;
  Wheel_IRQ_SetRightCounter_fake.custom_fake = Wheel_IRQ_Delegate_SetRightCounter;
  Wheel_IRQ_SetStopLeft_fake.custom_fake = Wheel_IRQ_Delegate_SetStopLeft;
  Wheel_IRQ_SetStopRight_fake.custom_fake = Wheel_IRQ_Delegate_SetStopRight;
  Wheel_IRQ_SetLeftLLimit_fake.custom_fake = Wheel_IRQ_Delegate_SetLeftLimit;
  Wheel_IRQ_SetRightLimit_fake.custom_fake = Wheel_IRQ_Delegate_SetRightLimit;
  FFF_RESET_HISTORY();
}
void test_whenWheelsAreInitialised_thenWeSetTheCorrectPins() {

   Wheel_Initialise();

   TEST_ASSERT_TRUE(0 < GPIOConfig_OutputPin_fake.call_count);

}


void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForLeftWheel() {
    Wheel_Straight(true, 100, 6);

    // GPIO_DigitalWrite(GPIOB, LEFT_INP1, HIGH);
		// GPIO_DigitalWrite(GPIOB, LEFT_INP2, LOW);

    TEST_ASSERT_TRUE(GPIO_DigitalWrite_fake.call_count >= 2);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[0]);
    TEST_ASSERT_TRUE(LEFT_INP1 == GPIO_DigitalWrite_fake.arg1_history[0]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[0]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[1]);
    TEST_ASSERT_TRUE(LEFT_INP2 == GPIO_DigitalWrite_fake.arg1_history[1]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[1]);
}


void test_whenWheelsGoForward_thenWeSetTheEnablePinForLeftWheel() {
     Wheel_Straight(true, 100, 6);
     // GPIO_DigitalWrite(GPIOB, LEFT_STBY, HIGH);
     TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
     TEST_ASSERT_TRUE(LEFT_STBY == GPIO_DigitalWrite_fake.arg1_history[2]);
     TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[2]);
}


void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheLeftWheel() {
   Wheel_Straight(true, 100, 6);

   // GPIO_AnalogWrite(GPIOC, LEFT_PWM, velocity);

   TEST_ASSERT_TRUE(GPIOC == GPIO_AnalogWrite_fake.arg0_history[0]);
   TEST_ASSERT_TRUE(LEFT_PWM == GPIO_AnalogWrite_fake.arg1_history[0]);
   TEST_ASSERT_TRUE(100 == GPIO_AnalogWrite_fake.arg2_history[0]);

}


/** Right Wheel Tests */

void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForRightWheel() {
    Wheel_Straight(true, 100, 6);

    // GPIO_DigitalWrite(GPIOB, RIGHT_INP1, LOW);
		// GPIO_DigitalWrite(GPIOB, RIGHT_INP2, HIGH);

    TEST_ASSERT_TRUE(GPIO_DigitalWrite_fake.call_count >= 2);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[3]);
    TEST_ASSERT_TRUE(RIGHT_INP1 == GPIO_DigitalWrite_fake.arg1_history[3]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[3]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[4]);
    TEST_ASSERT_TRUE(RIGHT_INP2 == GPIO_DigitalWrite_fake.arg1_history[4]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[4]);

}


void test_whenWheelsGoForward_thenWeSetTheEnablePinForRightWheel() {
     Wheel_Straight(true, 100, 6);

     //  GPIO_DigitalWrite(GPIOB, RIGHT_STBY, HIGH);

     TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[5]);
     TEST_ASSERT_TRUE(RIGHT_STBY == GPIO_DigitalWrite_fake.arg1_history[5]);
     TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[5]);
}


void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheRightWheel() {
   Wheel_Straight(true, 100, 6);

   // GPIO_AnalogWrite(GPIOC, RIGHT_PWM, velocity);

   TEST_ASSERT_TRUE(GPIOC == GPIO_AnalogWrite_fake.arg0_history[1]);
   TEST_ASSERT_TRUE(RIGHT_PWM == GPIO_AnalogWrite_fake.arg1_history[1]);
   TEST_ASSERT_TRUE(100 == GPIO_AnalogWrite_fake.arg2_history[1]);

}


/** Reverse Tests LEFT */

void test_whenWheelsGoBackward_thenSetTheCorrectDirectionPinsForLeftWheel() {
  Wheel_Straight(false, 100, 6);

  // GPIO_DigitalWrite(GPIOB, LEFT_INP1, HIGH);
  // GPIO_DigitalWrite(GPIOB, LEFT_INP2, LOW);

  TEST_ASSERT_TRUE(GPIO_DigitalWrite_fake.call_count >= 2);

  TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[0]);
  TEST_ASSERT_TRUE(LEFT_INP1 == GPIO_DigitalWrite_fake.arg1_history[0]);
  TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[0]);

  TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[1]);
  TEST_ASSERT_TRUE(LEFT_INP2 == GPIO_DigitalWrite_fake.arg1_history[1]);
  TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[1]);

}
void test_whenWheelsGoBackward_thenWeSetTheEnablePinForLeftWheel() {
     Wheel_Straight(false, 100, 6);
     // GPIO_DigitalWrite(GPIOB, LEFT_STBY, HIGH);
     TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[2]);
     TEST_ASSERT_TRUE(LEFT_STBY == GPIO_DigitalWrite_fake.arg1_history[2]);
     TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[2]);
}


void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheLeftWheel() {
   Wheel_Straight(false, 100, 6);

   // GPIO_AnalogWrite(GPIOC, LEFT_PWM, velocity);

   TEST_ASSERT_TRUE(GPIOC == GPIO_AnalogWrite_fake.arg0_history[0]);
   TEST_ASSERT_TRUE(LEFT_PWM == GPIO_AnalogWrite_fake.arg1_history[0]);
   TEST_ASSERT_TRUE(100 == GPIO_AnalogWrite_fake.arg2_history[0]);

}


/** Right Wheel Tests */

void test_whenWheelsGoBackward_thenWeSetTheCorrectPinsForRightWheel() {
    Wheel_Straight(false, 100, 6);

    // GPIO_DigitalWrite(GPIOB, RIGHT_INP1, LOW);
		// GPIO_DigitalWrite(GPIOB, RIGHT_INP2, HIGH);

    TEST_ASSERT_TRUE(GPIO_DigitalWrite_fake.call_count >= 2);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[3]);
    TEST_ASSERT_TRUE(RIGHT_INP1 == GPIO_DigitalWrite_fake.arg1_history[3]);
    TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[3]);

    TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[4]);
    TEST_ASSERT_TRUE(RIGHT_INP2 == GPIO_DigitalWrite_fake.arg1_history[4]);
    TEST_ASSERT_TRUE(LOW == GPIO_DigitalWrite_fake.arg2_history[4]);

}


void test_whenWheelsGoBackward_thenWeSetTheEnablePinForRightWheel() {
     Wheel_Straight(false, 100, 6);

     //  GPIO_DigitalWrite(GPIOB, RIGHT_STBY, HIGH);

     TEST_ASSERT_TRUE(GPIOB == GPIO_DigitalWrite_fake.arg0_history[5]);
     TEST_ASSERT_TRUE(RIGHT_STBY == GPIO_DigitalWrite_fake.arg1_history[5]);
     TEST_ASSERT_TRUE(HIGH == GPIO_DigitalWrite_fake.arg2_history[5]);
}


void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheRightWheel() {
   Wheel_Straight(false, 100, 6);

   // GPIO_AnalogWrite(GPIOC, RIGHT_PWM, velocity);

   TEST_ASSERT_TRUE(GPIOC == GPIO_AnalogWrite_fake.arg0_history[1]);
   TEST_ASSERT_TRUE(RIGHT_PWM == GPIO_AnalogWrite_fake.arg1_history[1]);
   TEST_ASSERT_TRUE(100 == GPIO_AnalogWrite_fake.arg2_history[1]);

}



void test_whenDoCommandIsForward_thenExitAfterLastCount(){

   uint16_t count = 15;

   Wheel_DoCommand(FORWARD, 100, count);
   // After stopping, the counter is reset to 0
   TEST_ASSERT_EQUAL_INT(0, delegate_left_counter);
   TEST_ASSERT_EQUAL_INT(0,  delegate_right_counter);

   TEST_ASSERT_EQUAL_INT(count + 1, Wheel_IRQ_GetStopLeft_fake.call_count);
   TEST_ASSERT_EQUAL_INT(count + 1, Wheel_IRQ_GetStopRight_fake.call_count);

}
