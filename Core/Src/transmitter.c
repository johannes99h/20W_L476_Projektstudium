#include <receiver.h>

/*	nicht mehr notwendig nach letztem Bugfix
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	// Interrupt freigeben
	HAL_UART_Receive_IT(&huart4, (uint8_t *)buffRx, buffSize);
}
*/

void transmitData(uint8_t *buffTx)
{
	/*	Bugfix: je nach Größe von buffSize wurden bei der Übertragung Bytes ausgelassen
	 * 	(z.B. buffSize = 1 -> jedes zweite Byte "leer" bzw. verschwunden)
	 */

	// HAL_UART_Transmit_IT(&huart4, (uint8_t *)buffTx, buffSize);
	HAL_UART_Transmit(&huart4, (uint8_t *)buffTx, buffSize, 10);
}
