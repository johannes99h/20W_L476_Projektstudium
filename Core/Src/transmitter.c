#include <receiver.h>

void transmitData(uint8_t *buffMain)
{
	HAL_UART_Transmit(&huart4, (uint8_t *)buffRx, sizeof(buffRx), 10);
	// mit Interrupt umsetzen & im Callback "Receive" starten?
	// Byte für Byte pipelinen?
}
