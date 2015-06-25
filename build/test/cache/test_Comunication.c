#include "mock_Signal.h"
#include "Comunication.h"
#include "unity.h"












void setUp(void){}

void tearDown(void){}















void test_sendBitHigh_give_xxxx_should_xxx(){



 { setPinHigh_CMockExpect(21, 4); setPinHigh_CMockExpect(21, 5); setPinLow_CMockExpect(21, 5); };

 sendBitHigh(4);



}



void test_sendBitLow_give_xxxx_should_xxx(){





 { setPinLow_CMockExpect(29, 4); setPinHigh_CMockExpect(29, 5); setPinLow_CMockExpect(29, 5); };

 sendBitLow(4);



}



void test_writeTurnAroundIO(void){



  { setPinHigh_CMockExpect(36, 4); setPinLow_CMockExpect(36, 5); setPinHigh_CMockExpect(36, 5); setPinOutPut_CMockExpect(36, 4); };

  writeTurnAroundIO(4);

}





void test_readTurnAroundIO(void){



  { setPinLow_CMockExpect(43, 4); setPinLow_CMockExpect(43, 5); setPinHigh_CMockExpect(43, 5); setPinInPut_CMockExpect(43, 4); };

  readTurnAroundIO(4);



 }



void test_readBit(void){

 { setPinLow_CMockExpect(49, 5); setPinHigh_CMockExpect(49, 5); getPin_CMockExpectAndReturn(49, 4, 1); };

 uint8_t bit;

 bit = readBit(4);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((bit)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

}

void test_writeData_given_0xCD_and_addr_0xDEAD_and_DATA_0xC0_should_send_0xCDDEADC0(void)

{

 { setPinHigh_CMockExpect(64, 4); setPinLow_CMockExpect(64, 5); setPinHigh_CMockExpect(64, 5); setPinOutPut_CMockExpect(64, 4); };

 SendData(0xC0);

 SendAddr(0xDEAD);

 SendCmd(0xCD);

 writeData(0xCD,0xDEAD,0xC0);

}

void test_readData_given_0xAB_and_addr_0xFACE_should_send_0xABFACE_and_turnaround_and_receive_0xBE(void)

{

 uint8_t receive;

 printf("-------------\n");

 { setPinHigh_CMockExpect(83, 4); setPinLow_CMockExpect(83, 5); setPinHigh_CMockExpect(83, 5); setPinOutPut_CMockExpect(83, 4); };

 SendAddr(0xFACE);

 SendCmd(0xAB);

 { setPinLow_CMockExpect(86, 4); setPinLow_CMockExpect(86, 5); setPinHigh_CMockExpect(86, 5); setPinInPut_CMockExpect(86, 4); };

 Read_Bit(0x11);

 receive = readData(0xAB,0xFACE);

}
