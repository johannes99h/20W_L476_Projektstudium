#include <receiver.h>

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	// Interrupt freigeben
	HAL_UART_Receive_IT(&huart4, (uint8_t *)buff, sizeof(buff));
}

void transmitData(uint8_t *buff)
{
	HAL_UART_Transmit_IT(&huart2, (uint8_t *)buff, sizeof(buff));
}
