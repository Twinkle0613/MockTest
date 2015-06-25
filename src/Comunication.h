#ifndef Comunication_H
#define Comunication_H
#include "unity.h"
#include <stdint.h>

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
					setPinLow_Expect(CLK_PIN);						\
					setPinHigh_Expect(CLK_PIN);						\
					setPinOutPut_Expect(IO_PIN);					\
				}
				
#define ReadBit(x)													    \
				{																				\
					setPinLow_Expect(CLK_PIN);						\
					setPinHigh_Expect(CLK_PIN);						\
					getPin_ExpectAndReturn(IO_PIN,x);			\
				}

#define Command_Expect(x) SendCmd(x)
#define Addr_Expect(x) SendAddr(x)
#define Data_Expect(x)	SendData(x)
#define readBit_Expect(x) Read_Bit(x)

void writeData(uint8_t cmd,uint16_t address,uint8_t data);
uint8_t readData(uint8_t cmd, uint16_t address);
void sendBitHigh(int pinNo);
void sendBitLow(int pinNo);
void readTurnAroundIO(int pinNo);
void writeTurnAroundIO(int pinNo);
uint32_t readBit(int pinNo);
void SendCmd(int cmd);
#endif // Comunication_H
