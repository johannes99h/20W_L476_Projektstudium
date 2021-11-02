#include "transmission.h"

uint8_t RxInProgress = 0;
uint8_t RxCompleted = 0;

uint8_t buffRx[100] = { 0 };
uint8_t buffTx[100] = { 0 };


void setup()
{
    HAL_UART_Receive_DMA(&huart4, (uint8_t *)buffRx, sizeof(buffRx));
}


void HAL_UART_RxHalfCptlCallback(UART_HandleTypeDef *huart4)
{
	// Setzen eines Flags, da bei UART-DMA mglw. keine Info an MCU geht wenn schon ein Bit im Receive-Register fehlt!
	// RxInProgress = 1;
}


void HAL_UART_RxCptlCallback(UART_HandleTypeDef *huart4)
{
	// RxCompleted = 1;
	clearRxBuff(rxBuff);
	tx(buffTx, RxInProgress, RxCompleted);
}



uint8_t *clearRxBuff(uint8_t buffRx)
{
	for(int i = 0; i < sizeof(buffRx); i++)
	{
		buffRx[i] = buffTx[i];
		buffRx[i] = 0;
	}

	return buffTx;
}

// Idle-Line-Detection irgendwie einbauen!

void tx(uint8_t *buffRx, uint8_t RxInProgress, uint8_t RxCompleted)
{
	if(RxInProgress == 1 && RxCompleted == 1)
	{
		// Output an Logic Analyzer/FTDI triggern
		HAL_UART_Transmit(&huart2, buffRx, sizeof(buffRx), 20);

		// Zurücksetzen der "Flags"
	}
}
