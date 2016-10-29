#include "unity.h"
#include "Wheel.h"
#include "stdbool.h"

#include "mock_GPIO.h"
#include "mock_GPIOConfig.h"
#include "mock_Wheel_IRQ.h"

#include "cmsis_device.h"


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


bool custom_GetStopLeft(void) {
  printf("Called custom_GetStopLeft\n");
  return true;
}

bool custom_GetStopRight(void) {
  printf("Called custom_GetStopRight\n");
  return true;
}

void test_whenDoCommandIsForward_thingsShouldEnd(){

   // Wheel_IRQ_GetLeftCounter_IgnoreAndReturn(11);
   // Wheel_IRQ_GetStopLeft_IgnoreAndReturn(true);

   Wheel_IRQ_GetStopLeft_fake.custom_fake = custom_GetStopLeft;
   Wheel_IRQ_GetStopRight_fake.custom_fake = custom_GetStopLeft;

   Wheel_DoCommand(FORWARD, 100, 10);

   TEST_ASSERT_TRUE(true);

}
