#include <receiver.h>

// uint8_t RxInProgress = 0;
// uint8_t RxCompleted = 0;
/*
uint8_t buffByte = 0;
uint8_t indexNumber = 0;
uint8_t buffRx[buffSize] = { 0 };
uint8_t buffMain[buffSize] = { 0 };
// uint8_t buffTx[buffSize] = { 0 };
*/
/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Adrians Tipp: Interrupt nach jedem empfangenem Byte
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */
/*
void setup()
{
	HAL_UART_Receive_IT(&huart4, buffByte, sizeof(buffByte));
}

void HAL_UART_RxCptlCallback(UART_HandleTypeDef *huart4)
{
	if(indexNumber < buffSize)
	{
		buffRx[indexNumber] = buffByte;
		indexNumber++;
	}
	else
	{
		indexNumber = 0;
		buffRx[indexNumber] = buffByte;
		indexNumber++;
	}

	HAL_UART_Receive_IT(&huart4, buffByte, sizeof(buffByte));
}
*/
/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * mein erster Versuch, vergessen was ich da eigentlich wollte
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */

/*
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
*/

/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * DMA, Ring Buffer & Idle-Line (nicht wirklich getestet, vmtl. nicht funktionsfähig
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */

/*

void setup()
{
  	HAL_UARTEx_ReceiveToIdle_DMA(&huart4, buffRx, sizeof(buffRx));	// empfängt Daten, bis sizeof(...) erreicht oder Idle-Line (-> Interrupt)
	__HAL_DMA_DISABLE_IT(&hdma_uart4_rx, DMA_IT_HT);					// deaktiviert den Half Transfer-IT
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance == UART4)
	{
		oldPos = newPos;

		if(oldPos + Size > buffSize)												// wird getriggered, wenn Main-Buffer überlaufen würde
		{
			uint16_t dataToCopy = buffSize - oldPos;								// Ermittlung des verbleibenden Speichers im Main-Buffer
			memcpy((uint8_t *)(buffMain+oldPos), (uint8_t *)buffRx, dataToCopy);		// verbleibenden Speicher im Main-Buffer auffüllen

			oldPos = 0;
			memcpy(buffMain, (buffRx + dataToCopy), (Size - dataToCopy));
			newPos = (Size - dataToCopy);

		}

		else														// wird getriggered, wenn Main-Buffer nicht überlaufen wird
		{
			memcpy((buffMain + oldPos), buffRx, Size);
			newPos = (Size + oldPos);
		}
	}

	// Neustart der DMA-Schnittstelle (da normaler statt zirkulärer DMA-Modus verwendet wird!)
	  HAL_UARTEx_ReceiveToIdle_DMA(&huart4, buffRx, sizeof(buffRx));	// empfängt Daten, bis sizeof(...) erreicht oder Idle-Line (-> Interrupt)
	  __HAL_DMA_DISABLE_IT(&hdma_uart4_rx, DMA_IT_HT);					// deaktiviert den Half Transfer-IT

	// Suche nach dem Beginn des Frames
	for(int i = 0; i < Size; i++)
	{
		if((buffRx[i] = '_') && (buffRx[i+1] == '_'))
		{
			newFrameDetected = 1;										// irgendeine Funktion aufrufen? wie hab ich mir das gedacht?
		}
	}
}

*/
