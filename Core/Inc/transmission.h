#include "stdio.h"
#include "stdint.h"
#include "stm32l4xx_hal.h"

uint8_t RxInProgress;
uint8_t RxCompleted;
uint8_t buffRx[100];
uint8_t buffTx[100];

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart4;
extern DMA_HandleTypeDef hdma_usart4_rx;

void HAL_UART_RxHalfCptlCallback(UART_HandleTypeDef *huart4);
void HAL_UART_RxCptlCallback(UART_HandleTypeDef *huart4);

void 		setup();
uint8_t 	*clearRxBuff();
void 		tx(uint8_t *buffTx, uint8_t RxInProgress, uint8_t RxCompleted);
