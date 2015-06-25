#include "mock_Signal.h"
#include "Comunication.h"
#include "unity.h"
void setUp(void){}

void tearDown(void){}















void test_sendBitHigh_give_xxxx_should_xxx(){



 setPinHigh_CMockExpect(54, 4);

 setPinHigh_CMockExpect(55, 5);

 setPinLow_CMockExpect(56, 5);

 sendBitHigh(4);



}



void test_sendBitLow_give_xxxx_should_xxx(){





 setPinLow_CMockExpect(64, 4);

 setPinHigh_CMockExpect(65, 5);

 setPinLow_CMockExpect(66, 5);

 sendBitLow(4);



}



void test_writeTurnAroundIO(void){



 { setPinHigh_CMockExpect(73, 4); setPinHigh_CMockExpect(73, 5); setPinLow_CMockExpect(73, 5); setPinOutPut_CMockExpect(73, 4); };

 writeTurnAroundIO(4);

}





void test_readTurnAroundIO(void){



  { setPinLow_CMockExpect(80, 4); setPinLow_CMockExpect(80, 5); setPinHigh_CMockExpect(80, 5); setPinInPut_CMockExpect(80, 4); };

  readTurnAroundIO(4);



 }



void test_readBit(void){

 setPinLow_CMockExpect(86, 5);

 setPinHigh_CMockExpect(87, 5);

 getPin_CMockExpectAndReturn(88, 4, 1);

 uint8_t bit;

 bit = readBit(4);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((bit)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

}

void test_writeData_given_0xCD_and_addr_0xDEAD_and_DATA_0xC0_should_send_0xCDDEADC0(void)

{

 writeData(0xCD,0xDEAD,0xC0);

}

void test_readData_given_0xAB_and_addr_0xFACE_should_send_0xABFACE_and_turnaround_and_receive_0xBE(void)

{

 uint8_t receive;

 receive = readData(0xAB,0xFACE);



}
