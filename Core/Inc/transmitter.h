#include "stdio.h"
#include "stdint.h"
#include "stm32l4xx_hal.h"
#include "string.h"

extern UART_HandleTypeDef huart2;

void transmitData(uint8_t *buff);
