#include "Comunication.h"
#include "Signal.h"

void readTurnAroundIO(int pinNO){
		setPinLow(IO_PIN);
		setPinLow(CLK_PIN);
		setPinHigh(CLK_PIN);
		setPinOutPut(IO_PIN);
}

void writeTurnAroundIO(int pinNo){
	setPinHigh(IO_PIN);
	setPinHigh(CLK_PIN);
	setPinLow(CLK_PIN);
	setPinOutPut(IO_PIN);
}
void sendBitHigh(int pinNo){
	setPinHigh(IO_PIN);
	setPinHigh(CLK_PIN);
	setPinLow(CLK_PIN);
}
void sendBitLow(int pinNo){
	setPinLow(IO_PIN);
	setPinHigh(CLK_PIN);
	setPinLow(CLK_PIN);
}

uint32_t readBit(int pinNo){
	setPinLow(CLK_PIN);
	setPinHigh(CLK_PIN);
	uint32_t Bit = getPin(pinNo);
	return Bit;
}



// IO_PIN  4
// CLK_PIN  5
// AB = "00101011"
             //output        output           output 
						 //0xCD         ,0xDEAD           ,0xC0
void writeData(uint8_t cmd, uint16_t address,uint8_t data){
		// setPinInPut(CLK_PIN);
	 //writeTurnAroundIO(IO_PIN);

	char storage;
	int i;
	
	 //0xC0 -> Data
		for (i = 0; i<8 ; i++){
		
		storage = data & 0x01;
		data = data >> 1;
		printf("storage = %d\n", storage);
	 // if (storage == HIGH)
		// {
		 // sendBitHigh(IO_PIN);
		// }
		 // sendBitLow(IO_PIN);
		 }
		
	//0xDEAD -> write Address
		for (i = 0; i<16 ; i++){
		
		storage = address & 0x01;
		address = address >> 1;
		printf("storage = %d\n", storage);
		// if (storage == HIGH)
	 // {
		 // sendBitHigh(IO_PIN);
	 // }
		 // sendBitLow(IO_PIN);
	 }
		
	//0xCD -> write Memory
		for (i = 0; i<8 ; i++){
		
		storage = cmd & 0x01;
		cmd = cmd >> 1;
		printf("storage = %d\n", storage);
	 // if (storage == HIGH)
	 // {
		 // sendBitHigh(IO_PIN);
	 // }
		 // sendBitLow(IO_PIN);
	 }
	
}
/*
uint8_t readData(uint8_t cmd, uint16_t address){
	
	
		//writeTurnAroundIO(IO_PIN);
		//setPinOutPut(IO_PIN);
		// setPinInPut(CLK_PIN);
	
		//0xFACE -> write Address
		int i;
		char storage;
		for (i = 0; i<16 ; i++){
		
		storage = address & 0x01;
		address = address >> 1;
		printf("storage = %d\n", storage);
		// if (storage == HIGH)
	 // {
		 // sendBitHigh(IO_PIN);
	 // }
		 // sendBitLow(IO_PIN);
	 }

	//0xAB -> write Memory
		for (i = 0; i<8 ; i++){
		
		storage = cmd & 0x01;
		cmd = cmd >> 1;
		printf("storage = %d\n", storage);
	 // if (storage == HIGH)
	 // {
		 // sendBitHigh(IO_PIN);
	 // }
		 // sendBitLow(IO_PIN);
	 }
	 
		//readTurnAroundIO(IO_PIN);
		//setPinInPut(IO_PIN);
		
			uint8_t bit = 0x00, receive = 0x00;
			
			for( i=0 ; i<8 ; i++){
			
			bit = readBit(IO_PIN);
			receive = receive | (bit>>i); 
			}
			return receive;
	} 
	
	
	*/
	