#include "Wheel_IRQ_Delegate.h"
#include "cmsis_device.h"
#include "mock_Wheel_IRQ.h"
#include "mock_GPIOConfig.h"
#include "mock_GPIO.h"
#include "Wheel.h"
#include "unity.h"












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

  fff.call_history_idx = 0;;

}

void test_whenWheelsAreInitialised_thenWeSetTheCorrectPins() {



   Wheel_Initialise();



   if ((0 < GPIOConfig_OutputPin_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(37)));};



}





void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForLeftWheel() {

    Wheel_Straight(1, 100, 6);









    if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(48)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(50)));};

    if ((((uint16_t)0x0200) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(51)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(52)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(54)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(55)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(56)));};

}





void test_whenWheelsGoForward_thenWeSetTheEnablePinForLeftWheel() {

     Wheel_Straight(1, 100, 6);



     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(63)));};

     if ((((uint16_t)0x0100) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(64)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(65)));};

}





void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheLeftWheel() {

   Wheel_Straight(1, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(74)));};

   if ((((uint16_t)0x0040) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(75)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(76)));};



}









void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForRightWheel() {

    Wheel_Straight(1, 100, 6);









    if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(89)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(91)));};

    if ((((uint16_t)0x1000) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(92)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(93)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(95)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(96)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(97)));};



}





void test_whenWheelsGoForward_thenWeSetTheEnablePinForRightWheel() {

     Wheel_Straight(1, 100, 6);







     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(107)));};

     if ((((uint16_t)0x0800) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(108)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(109)));};

}





void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheRightWheel() {

   Wheel_Straight(1, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(118)));};

   if ((((uint16_t)0x0080) == GPIO_AnalogWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(119)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(120)));};



}









void test_whenWheelsGoBackward_thenSetTheCorrectDirectionPinsForLeftWheel() {

  Wheel_Straight(0, 100, 6);









  if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(133)));};



  if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(135)));};

  if ((((uint16_t)0x0200) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(136)));};

  if ((0 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(137)));};



  if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(139)));};

  if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(140)));};

  if ((1 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(141)));};



}

void test_whenWheelsGoBackward_thenWeSetTheEnablePinForLeftWheel() {

     Wheel_Straight(0, 100, 6);



     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(147)));};

     if ((((uint16_t)0x0100) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(148)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(149)));};

}





void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheLeftWheel() {

   Wheel_Straight(0, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(158)));};

   if ((((uint16_t)0x0040) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(159)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(160)));};



}









void test_whenWheelsGoBackward_thenWeSetTheCorrectPinsForRightWheel() {

    Wheel_Straight(0, 100, 6);









    if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(173)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(175)));};

    if ((((uint16_t)0x1000) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(176)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(177)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(179)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(180)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(181)));};



}





void test_whenWheelsGoBackward_thenWeSetTheEnablePinForRightWheel() {

     Wheel_Straight(0, 100, 6);







     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(191)));};

     if ((((uint16_t)0x0800) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(192)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(193)));};

}





void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheRightWheel() {

   Wheel_Straight(0, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(202)));};

   if ((((uint16_t)0x0080) == GPIO_AnalogWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(203)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(204)));};



}







void test_whenDoCommandIsForward_thenExitAfterLastCount(){



   uint16_t count = 15;



   Wheel_DoCommand(((uint16_t)0x0100), 100, count);



   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((delegate_left_counter)), (((void *)0)), (_U_UINT)(216), UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((delegate_right_counter)), (((void *)0)), (_U_UINT)(217), UNITY_DISPLAY_STYLE_INT);



   UnityAssertEqualNumber((_U_SINT)((count + 1)), (_U_SINT)((Wheel_IRQ_GetStopLeft_fake.call_count)), (((void *)0)), (_U_UINT)(219), UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((count + 1)), (_U_SINT)((Wheel_IRQ_GetStopRight_fake.call_count)), (((void *)0)), (_U_UINT)(220), UNITY_DISPLAY_STYLE_INT);



}
