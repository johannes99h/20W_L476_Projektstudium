#include <receiver.h>

			uint8_t		RxCompleted = 0;
volatile	uint8_t 	buffRx[1] = { 0 };
			uint8_t 	buffMain[buffSize] = { 0 };
			uint8_t 	buffTx[frameSize] = { 0 };

void RxStuff()
{
	// "low budget" Ring-Buffer
	if(RxCompleted < buffSize)
	{
		buffMain[RxCompleted] = buffRx[0];
		RxCompleted++;
	}
	else
	{
		// Header finden
		// checkForHeader(buffMain);				// Problem: (noch) kein Newline-Zeichen im gesendeten Header!

		// CRC-/Checksum-Check
		// checkTheChecksum(buffTx);				// Problem: bisher CRC berechnet (und selbst das funktioniert nicht wirklich)

		// Trigger Transmit
		transmitData(buffMain);

		// Buffer zurücksetzen
		RxCompleted = 0;
		buffMain[RxCompleted] = buffRx[0];
		RxCompleted++;
	}

	// Interrupt freigeben
	HAL_UART_Receive_IT(&huart4, (uint8_t *)buffRx, sizeof(buffRx));
}

uint8_t* checkForHeader(uint8_t *buffMain)
{
	// kein Plan wie ich das am besten anstelle... vielleicht auch nicht Brute-Force verwenden?
	for(int i = 0; i < buffSize; i++)
	{
		// Check für Newline-Zeichen (entspricht ASCII-10, kein Plan ob das so funktioniert)
		if(buffMain[i] == 10)
		{
			break;
		}
		else
		{
			i++;
		}

		// Tx-Buffer füllen um vollständiges Frame auf einmal senden zu können
		for(int j = 0; j < frameSize; j++)
		{
			buffTx[j] = buffMain[i+j];
		}
	}

	return buffTx;
}

uint8_t* checkTheChecksum(uint8_t *buffTx)
{
	return buffTx;
}
