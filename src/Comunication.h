#ifndef Comunication_H
#define Comunication_H
#include "unity.h"


#include <stdint.h>
void writeData(uint8_t cmd,uint16_t address,uint8_t data);
uint8_t readData(uint8_t cmd, uint16_t address);
void sendBitHigh(int pinNo);
void sendBitLow(int pinNo);
void readTurnAroundIO(int pinNo);
void writeTurnAroundIO(int pinNo);
uint32_t readBit(int pinNo);
#endif // Comunication_H
