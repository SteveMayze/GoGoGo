#include "Wheel_IRQ_Delegate.h"
#include "cmsis_device.h"
#include "mock_Wheel_IRQ.h"
#include "mock_GPIOConfig.h"
#include "mock_GPIO.h"
#include "Wheel.h"
#include "unity.h"












void test_whenWheelsAreInitialised_thenWeSetTheCorrectPins() {



   Wheel_Initialise();



   if ((0 < GPIOConfig_OutputPin_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(17)));};



}





void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForLeftWheel() {

    Wheel_Straight(1, 100, 6);









    if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(28)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(30)));};

    if ((((uint16_t)0x0200) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(31)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(32)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(34)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(35)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(36)));};

}





void test_whenWheelsGoForward_thenWeSetTheEnablePinForLeftWheel() {

     Wheel_Straight(1, 100, 6);



     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(43)));};

     if ((((uint16_t)0x0100) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(44)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(45)));};

}





void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheLeftWheel() {

   Wheel_Straight(1, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(54)));};

   if ((((uint16_t)0x0040) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(55)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(56)));};



}









void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForRightWheel() {

    Wheel_Straight(1, 100, 6);









    if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(69)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(71)));};

    if ((((uint16_t)0x1000) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(72)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(73)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(75)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(76)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(77)));};



}





void test_whenWheelsGoForward_thenWeSetTheEnablePinForRightWheel() {

     Wheel_Straight(1, 100, 6);







     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(87)));};

     if ((((uint16_t)0x0800) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(88)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(89)));};

}





void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheRightWheel() {

   Wheel_Straight(1, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(98)));};

   if ((((uint16_t)0x0080) == GPIO_AnalogWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(99)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(100)));};



}









void test_whenWheelsGoBackward_thenSetTheCorrectDirectionPinsForLeftWheel() {

  Wheel_Straight(0, 100, 6);









  if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(113)));};



  if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(115)));};

  if ((((uint16_t)0x0200) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(116)));};

  if ((0 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(117)));};



  if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(119)));};

  if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(120)));};

  if ((1 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(121)));};



}

void test_whenWheelsGoBackward_thenWeSetTheEnablePinForLeftWheel() {

     Wheel_Straight(0, 100, 6);



     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(127)));};

     if ((((uint16_t)0x0100) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(128)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(129)));};

}





void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheLeftWheel() {

   Wheel_Straight(0, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(138)));};

   if ((((uint16_t)0x0040) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(139)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(140)));};



}









void test_whenWheelsGoBackward_thenWeSetTheCorrectPinsForRightWheel() {

    Wheel_Straight(0, 100, 6);









    if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(153)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(155)));};

    if ((((uint16_t)0x1000) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(156)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(157)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(159)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(160)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(161)));};



}





void test_whenWheelsGoBackward_thenWeSetTheEnablePinForRightWheel() {

     Wheel_Straight(0, 100, 6);







     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(171)));};

     if ((((uint16_t)0x0800) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(172)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(173)));};

}





void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheRightWheel() {

   Wheel_Straight(0, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(182)));};

   if ((((uint16_t)0x0080) == GPIO_AnalogWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(183)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(184)));};



}







void test_whenDoCommandIsForward_thingsShouldEnd(){



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



   uint16_t count = 5;



   Wheel_DoCommand(((uint16_t)0x0100), 100, count);



   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((delegate_left_counter)), (((void *)0)), (_U_UINT)(212), UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((delegate_right_counter)), (((void *)0)), (_U_UINT)(213), UNITY_DISPLAY_STYLE_INT);









   UnityAssertEqualNumber((_U_SINT)((count + 1)), (_U_SINT)((Wheel_IRQ_GetStopLeft_fake.call_count)), (((void *)0)), (_U_UINT)(218), UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((count + 1)), (_U_SINT)((Wheel_IRQ_GetStopRight_fake.call_count)), (((void *)0)), (_U_UINT)(219), UNITY_DISPLAY_STYLE_INT);



}
