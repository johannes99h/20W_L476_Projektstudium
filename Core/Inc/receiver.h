#include "stdio.h"
#include "stdint.h"
#include "stm32l4xx_hal.h"
#include "string.h"
#include "transmitter.h"

#define 	buffSize 	1

extern 		UART_HandleTypeDef huart4;

volatile	uint8_t 	buff[buffSize];
