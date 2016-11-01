/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  CMock_Init(); \
  UNITY_CLR_DETAILS(); \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
    CMock_Verify(); \
  } \
  CMock_Destroy(); \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "mock_GPIO.h"
#include "mock_GPIOConfig.h"
#include "mock_Wheel_IRQ.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_whenWheelsAreInitialised_thenWeSetTheCorrectPins();
extern void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForLeftWheel();
extern void test_whenWheelsGoForward_thenWeSetTheEnablePinForLeftWheel();
extern void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheLeftWheel();
extern void test_whenWheelsGoForward_thenWeSetTheCorrectPinsForRightWheel();
extern void test_whenWheelsGoForward_thenWeSetTheEnablePinForRightWheel();
extern void test_whenWheelsGoForward_thenWeSetTheVelocityOfTheRightWheel();
extern void test_whenWheelsGoBackward_thenSetTheCorrectDirectionPinsForLeftWheel();
extern void test_whenWheelsGoBackward_thenWeSetTheEnablePinForLeftWheel();
extern void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheLeftWheel();
extern void test_whenWheelsGoBackward_thenWeSetTheCorrectPinsForRightWheel();
extern void test_whenWheelsGoBackward_thenWeSetTheEnablePinForRightWheel();
extern void test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheRightWheel();
extern void test_whenDoCommandIsForward_thenExitAfterLastCount();


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_GPIO_Init();
  mock_GPIOConfig_Init();
  mock_Wheel_IRQ_Init();
}
static void CMock_Verify(void)
{
  mock_GPIO_Verify();
  mock_GPIOConfig_Verify();
  mock_Wheel_IRQ_Verify();
}
static void CMock_Destroy(void)
{
  mock_GPIO_Destroy();
  mock_GPIOConfig_Destroy();
  mock_Wheel_IRQ_Destroy();
}

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_Wheel.c");
  RUN_TEST(test_whenWheelsAreInitialised_thenWeSetTheCorrectPins, 33);
  RUN_TEST(test_whenWheelsGoForward_thenWeSetTheCorrectPinsForLeftWheel, 42);
  RUN_TEST(test_whenWheelsGoForward_thenWeSetTheEnablePinForLeftWheel, 60);
  RUN_TEST(test_whenWheelsGoForward_thenWeSetTheVelocityOfTheLeftWheel, 69);
  RUN_TEST(test_whenWheelsGoForward_thenWeSetTheCorrectPinsForRightWheel, 83);
  RUN_TEST(test_whenWheelsGoForward_thenWeSetTheEnablePinForRightWheel, 102);
  RUN_TEST(test_whenWheelsGoForward_thenWeSetTheVelocityOfTheRightWheel, 113);
  RUN_TEST(test_whenWheelsGoBackward_thenSetTheCorrectDirectionPinsForLeftWheel, 127);
  RUN_TEST(test_whenWheelsGoBackward_thenWeSetTheEnablePinForLeftWheel, 144);
  RUN_TEST(test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheLeftWheel, 153);
  RUN_TEST(test_whenWheelsGoBackward_thenWeSetTheCorrectPinsForRightWheel, 167);
  RUN_TEST(test_whenWheelsGoBackward_thenWeSetTheEnablePinForRightWheel, 186);
  RUN_TEST(test_whenWheelsGoBackward_thenWeSetTheVelocityOfTheRightWheel, 197);
  RUN_TEST(test_whenDoCommandIsForward_thenExitAfterLastCount, 210);

  CMock_Guts_MemFreeFinal();
  return (UnityEnd());
}

//=======Defintions of FFF variables=====
#include "fff.h"
DEFINE_FFF_GLOBALS;
