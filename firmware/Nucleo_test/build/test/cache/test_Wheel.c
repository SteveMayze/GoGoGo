#include "cmsis_device.h"
#include "mock_Wheel_IRQ.h"
#include "mock_GPIOConfig.h"
#include "mock_GPIO.h"
#include "Wheel.h"
#include "unity.h"












void test_whenWheelsAreInitialised_thenWeSetTheCorrectPins() {



   Wheel_Initialise();



   if ((0 < GPIOConfig_OutputPin_fake.call_count)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(16)));};



}





void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForLeftWheel() {

    Wheel_Straight(1, 100, 6);









    if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(27)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(29)));};

    if ((((uint16_t)0x0200) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(30)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(31)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(33)));};

    if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(34)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(35)));};

}





void test_whenWheelsGoForward_thenWeSetTheEnablePinForLeftWheel() {

     Wheel_Straight(1, 100, 6);



     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(42)));};

     if ((((uint16_t)0x0100) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(43)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(44)));};

}





void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheLeftWheel() {

   Wheel_Straight(1, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(53)));};

   if ((((uint16_t)0x0040) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(54)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(55)));};



}









void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForRightWheel() {

    Wheel_Straight(1, 100, 6);









    if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(68)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(70)));};

    if ((((uint16_t)0x1000) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(71)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(72)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(74)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(75)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(76)));};



}





void test_whenWheelsGoForward_thenWeSetTheEnablePinForRightWheel() {

     Wheel_Straight(1, 100, 6);







     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(86)));};

     if ((((uint16_t)0x0800) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(87)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(88)));};

}





void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheRightWheel() {

   Wheel_Straight(1, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(97)));};

   if ((((uint16_t)0x0080) == GPIO_AnalogWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(98)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(99)));};



}









void test_whenWheelsGoBackward_thenSetTheCorrectDirectionPinsForLeftWheel() {

  Wheel_Straight(0, 100, 6);









  if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(112)));};



  if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(114)));};

  if ((((uint16_t)0x0200) == GPIO_DigitalWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(115)));};

  if ((0 == GPIO_DigitalWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(116)));};



  if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(118)));};

  if ((((uint16_t)0x0400) == GPIO_DigitalWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(119)));};

  if ((1 == GPIO_DigitalWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(120)));};



}

void test_whenWheelsGoBackward_thenWeSetTheEnablePinForLeftWheel() {

     Wheel_Straight(0, 100, 6);



     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(126)));};

     if ((((uint16_t)0x0100) == GPIO_DigitalWrite_fake.arg1_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(127)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[2])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(128)));};

}





void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheLeftWheel() {

   Wheel_Straight(0, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(137)));};

   if ((((uint16_t)0x0040) == GPIO_AnalogWrite_fake.arg1_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(138)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[0])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(139)));};



}









void test_whenWheelsGoBackward_thenWeSetTheCorrectPinsForRightWheel() {

    Wheel_Straight(0, 100, 6);









    if ((GPIO_DigitalWrite_fake.call_count >= 2)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(152)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(154)));};

    if ((((uint16_t)0x1000) == GPIO_DigitalWrite_fake.arg1_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(155)));};

    if ((1 == GPIO_DigitalWrite_fake.arg2_history[3])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(156)));};



    if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(158)));};

    if ((((uint16_t)0x2000) == GPIO_DigitalWrite_fake.arg1_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(159)));};

    if ((0 == GPIO_DigitalWrite_fake.arg2_history[4])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(160)));};



}





void test_whenWheelsGoBackward_thenWeSetTheEnablePinForRightWheel() {

     Wheel_Straight(0, 100, 6);







     if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000400)) == GPIO_DigitalWrite_fake.arg0_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(170)));};

     if ((((uint16_t)0x0800) == GPIO_DigitalWrite_fake.arg1_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(171)));};

     if ((1 == GPIO_DigitalWrite_fake.arg2_history[5])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(172)));};

}





void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheRightWheel() {

   Wheel_Straight(0, 100, 6);







   if ((((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x08000000) + 0x00000800)) == GPIO_AnalogWrite_fake.arg0_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(181)));};

   if ((((uint16_t)0x0080) == GPIO_AnalogWrite_fake.arg1_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(182)));};

   if ((100 == GPIO_AnalogWrite_fake.arg2_history[1])) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(183)));};



}





_Bool custom_GetStopLeft(void) {

  printf("Called custom_GetStopLeft\n");

  return 1;

}



_Bool custom_GetStopRight(void) {

  printf("Called custom_GetStopRight\n");

  return 1;

}



void test_whenDoCommandIsForward_thingsShouldEnd(){









   Wheel_IRQ_GetStopLeft_fake.custom_fake = custom_GetStopLeft;

   Wheel_IRQ_GetStopRight_fake.custom_fake = custom_GetStopLeft;



   Wheel_DoCommand(((uint16_t)0x0100), 100, 10);



   if ((1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (_U_UINT)((_U_UINT)(208)));};



}
