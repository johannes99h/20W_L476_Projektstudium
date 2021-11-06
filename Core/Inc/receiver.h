#include "stdio.h"
#include "stdint.h"
#include "stm32l4xx_hal.h"
#include "string.h"

#define 	buffSize 	100
#define 	frameSize 	100

extern 		UART_HandleTypeDef huart4;

			uint8_t		RxCompleted;
volatile	uint8_t 	buffRx[1];
			uint8_t 	buffMain[buffSize];
			uint8_t 	buffTx[frameSize];

void 		RxStuff();
uint8_t*	checkForHeader(uint8_t *buffMain);
uint8_t* 	checkTheChecksum(uint8_t *buffTx);
