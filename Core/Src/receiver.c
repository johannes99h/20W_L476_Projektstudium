#include <receiver.h>

// volatile	uint8_t 	buff[buffSize] = { 0 };
volatile	uint8_t 	buffRx[buffSize] = { 0 };
			uint8_t 	buffTx[buffSize] = { 0 };

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	/*	unnötiger Performance-Hit laut Disassembly
	for(int i = 0; i < buffSize; i++)
	{
		buffTx[i] = buffRx[i];
	}
	*/

	// wirklich zwei Arrays notwendig?
	buffTx[0] = buffRx[0];

	transmitData(buffTx);
}
