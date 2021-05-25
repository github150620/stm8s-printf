// Depend on STM8S_StdPeriph_Lib
//
// Files:
//   stm8s.h
//   stm8s_uart1.c
//   stm8s_uart1.h
//

#include "stm8s.h"
#include <stdio.h>

char putchar(char c) {
	while(!UART1_GetFlagStatus(UART1_FLAG_TXE));
	UART1_SendData8(c);
	return c;
}

void main()
{
	UART1_DeInit();
	UART1_Init(115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TX_ENABLE|UART1_MODE_RX_DISABLE);

	printf("Hello\n");
	while (1) {
	}
}
