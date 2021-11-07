#include <receiver.h>

volatile	uint8_t 	buff[buffSize] = { 0 };

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	transmitData(buff);
}
