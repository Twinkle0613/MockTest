#ifndef Signal_H
#define Signal_H
#define HIGH 1
#define LOW 0
#define IO_PIN  4
#define CLK_PIN  5
/**
* @brief Set pin to high
* @param pinNo is the pin to set high
*
*/

void setPinHigh(int pinNO);

/**
* @brief Set pin to Low
* @param pinNo is the pin to set Low
*
*/
void setPinLow(int pinNO);

/**
* @brief Read pin state
* @param pinNo is the pin to read from
* @return 1 if pin is high, otherwise 0
*/
int getPin(int pinNO);

/**
* @brief set pin as Output
* @param pinNo is the pin set as output
*/

void setPinOutPut(int pinNo);

/**
* @brief set pin as Input
* @param pinNo is the pin set as Input
*/

void setPinInPut(int pinNo);


#endif // Signal_H
