#include "Comunication.h"
#include "Signal.h"
#include "mock_Signal.h"

void SendCmd(int temp3 ){
	int i;
	char storage;
		for (i = 0; i<8 ; i++){
			storage = temp3 & 0x01;
			temp3 = temp3 >> 1;
			if (storage == HIGH)
			{
				SendHIGH;
			}
			else{
				SendLOW;
			}
		}
}

void 	SendAddr(int temp2){
		int i;
		char storage;
		for (i = 0; i<16 ; i++){
			storage = temp2 & 0x01;
			temp2 = temp2 >> 1;
		if (storage == HIGH)
			{
				SendHIGH;
			}else{
				SendLOW;
			}
		}
}

void SendData(int temp1){
		int i;
		char storage;
		for (i = 0; i<8 ; i++){
			storage = temp1 & 0x01;
			temp1 = temp1 >> 1;
	  if (storage == HIGH)
			{
				SendHIGH;
			}else{
				SendLOW;
			}
		}
}

 void Read_Bit(int temp4){
	
	 int i;
	 char storage;
	 for( i=0 ; i<8 ; i++){
			 storage = temp4 & 0x01;
			 temp4 = temp4 >> 1;
			 	setPinLow_Expect(CLK_PIN);						
				setPinHigh_Expect(CLK_PIN);
				getPin_ExpectAndReturn(IO_PIN,storage);	
			 }

}

uint32_t readBit(int pinNo){
	setPinLow(CLK_PIN);
	setPinHigh(CLK_PIN);
	uint32_t Bit = getPin(pinNo);
	return Bit;
}

void readTurnAroundIO(int pinNO){
		setPinLow(IO_PIN);
		setPinLow(CLK_PIN);
		setPinHigh(CLK_PIN);
		setPinInPut(IO_PIN);
}

void writeTurnAroundIO(int pinNo){
	setPinHigh(IO_PIN);
	setPinLow(CLK_PIN);
	setPinHigh(CLK_PIN);
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


// IO_PIN  4
// CLK_PIN  5
// AB = "00101011"
             //output        output           output 
						 //0xCD         ,0xDEAD           ,0xC0
void writeData(uint8_t cmd, uint16_t address,uint8_t data){

	uint16_t temp2 = address;
	uint8_t temp1 = cmd;
	uint8_t temp3 = data;
	char storage;
	int i;
		 writeTurnAroundIO(IO_PIN);

	 //0xC0 -> Data
		for (i = 0; i<8 ; i++){
		
		storage = temp3 & 0x01;
		temp3 = temp3 >> 1;
		printf("Send = %d\n", storage);
	 if (storage == HIGH)
		 {
		  sendBitHigh(IO_PIN);
		 }
	else{
		  sendBitLow(IO_PIN);
		 }
		}
	//0xDEAD -> write Address
		for (i = 0; i<16 ; i++){
		
		storage = temp2 & 0x01;
		temp2 = temp2 >> 1;
		printf("Send = %d\n", storage);
		 if (storage == HIGH)
	  {
		  sendBitHigh(IO_PIN);
	  }else{
		  sendBitLow(IO_PIN);
		}
		}
		
	//0xCD -> write Memory
		for (i = 0; i<8 ; i++){
		
		storage = temp1 & 0x01;
		temp1 = temp1 >> 1;
		printf("Send = %d\n", storage);
	  if (storage == HIGH)
	  {
		  sendBitHigh(IO_PIN);
	  }else{
		  sendBitLow(IO_PIN);
		}
	 }
	
}


uint8_t readData(uint8_t cmd, uint16_t address){
	
	
		writeTurnAroundIO(IO_PIN);
		
	
		//0xFACE -> write Address
		int i;
		char storage;
		for (i = 0; i<16 ; i++){
		storage = address & 0x01;
		address = address >> 1;
		printf("send = %d\n", storage);
		if (storage == HIGH)
	  {
		  sendBitHigh(IO_PIN);
	  }else{
		  sendBitLow(IO_PIN);
		}
	 }

	//0xAB -> write Memory
		for (i = 0; i<8 ; i++){
		
		storage = cmd & 0x01;
		cmd = cmd >> 1;
		printf("send = %d\n", storage);
	  if (storage == HIGH)
	  {
		  sendBitHigh(IO_PIN);
	  }else{
		  sendBitLow(IO_PIN);
		}
  	}
	 
		readTurnAroundIO(IO_PIN);

		
			uint8_t bit = 0x00, receive = 0x00;
			
			for( i=0 ; i<8 ; i++){
			
			bit = readBit(IO_PIN);
			printf("receivebit = %d\n",bit);
			receive = receive | (bit<<i); 
			printf("receive = %d\n", receive);
			
			}
			return receive;
	} 
	
	

	