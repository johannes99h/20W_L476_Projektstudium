#include <receiver.h>

void transmitData(uint8_t *buffRx)
{
	HAL_UART_Transmit_IT(&huart4, (uint8_t *)buffRx, sizeof(buffRx));
}
