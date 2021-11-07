#include "stdio.h"
#include "stdint.h"
#include "stm32l4xx_hal.h"
#include "string.h"
#include "transmitter.h"

#define 	buffSize 	1
// #define 	frameSize 	1

extern 		UART_HandleTypeDef huart4;

//			uint8_t		RxCompleted;
volatile	uint8_t 	buffRx[buffSize];
//			uint8_t 	buffMain[buffSize];
//			uint8_t 	buffTx[buffSize];

void 		RxStuff();
// uint8_t*		checkForHeader(uint8_t *buffMain);
// uint8_t* 	checkTheChecksum(uint8_t *buffTx);
