#include "unity.h"
#include "Comunication.h"
#include "mock_Signal.h"


#define SendHIGH                                \
        {                                       \
					setPinHigh_Expect(IO_PIN);						\
					setPinHigh_Expect(CLK_PIN);						\
					setPinLow_Expect(CLK_PIN);            \
				}  				
				
#define SendLOW                                 \
        {                                       \
					setPinLow_Expect(IO_PIN);							\
					setPinHigh_Expect(CLK_PIN);						\
					setPinLow_Expect(CLK_PIN);            \
				}  			
#define RTA_TO                                  \
        {                                       \
					setPinLow_Expect(IO_PIN);							\
					setPinLow_Expect(CLK_PIN);						\
					setPinHigh_Expect(CLK_PIN);						\
					setPinInPut_Expect(IO_PIN);           \
				}  			
					
#define WTA_TO																	\
				{																				\
					setPinHigh_Expect(IO_PIN);						\
					setPinHigh_Expect(CLK_PIN);						\
					setPinLow_Expect(CLK_PIN);						\
					setPinOutPut_Expect(IO_PIN);					\
				}
#define ReadBit																	\
				{																				\
					setPinLow_Expect(CLK_PIN);						\
					setPinHigh_Expect(CLK_PIN);						\
					getPin_ExpectAndReturn(IO_PIN,1);			\
				}



void setUp(void){}
void tearDown(void){}

/* void setPinHigh_Expect(int pinNO);
void setPinLow_Expect(int pinNO);
int getPin_ExpectAndReturn(int pinNO);
int setPinOutPut_ExpectAndReturn(int pinNo);
int setPinInPut_ExpectAndReturn(int pinNo); */

void test_sendBitHigh_give_xxxx_should_xxx(){
		
	setPinHigh_Expect(IO_PIN);
	setPinHigh_Expect(CLK_PIN);
	setPinLow_Expect(CLK_PIN);
	sendBitHigh(IO_PIN);
	
}

void test_sendBitLow_give_xxxx_should_xxx(){


	setPinLow_Expect(IO_PIN);
	setPinHigh_Expect(CLK_PIN);
	setPinLow_Expect(CLK_PIN);
	sendBitLow(IO_PIN);
	
}

void test_writeTurnAroundIO(void){
	
	WTA_TO;
	writeTurnAroundIO(IO_PIN);
}


void test_readTurnAroundIO(void){
		
		RTA_TO;
		readTurnAroundIO(IO_PIN);
		
	}
	
void test_readBit(void){
	setPinLow_Expect(CLK_PIN);
	setPinHigh_Expect(CLK_PIN);
	getPin_ExpectAndReturn(IO_PIN,1);
	uint8_t bit;
	bit = readBit(IO_PIN);
	TEST_ASSERT_EQUAL(1,bit);
}
	
	
//setPinHigh_ExpectAndReturn(pinNo,HIGH)

/*
Cmd :
	instruction of Write memory  = 0xCD
	address location = 0xDE 0XAD
	data from external device = 0xC0
*/

void test_writeData_given_0xCD_and_addr_0xDEAD_and_DATA_0xC0_should_send_0xCDDEADC0(void)
{	
	writeData(0xCD,0xDEAD,0xC0);
}


/*
Cmd :
	instruction of read memory = 0xAB
	address location = 0xFA 0XCE
	data from external device = 0xBE
*/

void test_readData_given_0xAB_and_addr_0xFACE_should_send_0xABFACE_and_turnaround_and_receive_0xBE(void)
{
	uint8_t receive;
	receive = readData(0xAB,0xFACE);
	
}
