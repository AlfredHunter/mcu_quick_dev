/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "ledtest.h"

/* Library includes. */
#include "stm32f10x_lib.h"

#define partstMAX_OUTPUT_LED	( 1 )
#define partstFIRST_LED			GPIO_Pin_11

static unsigned short usOutputValue = 0;

/*-----------------------------------------------------------*/

void ledTestInitialise( void )
{
GPIO_InitTypeDef GPIO_InitStructure;

	/* Configure PC.06, PC.07, PC.08 and PC.09 as output push-pull */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOC, &GPIO_InitStructure );
}
/*-----------------------------------------------------------*/

void ledTestSetLED( unsigned long uxLED, signed long xValue )
{
unsigned short usBit;

	vTaskSuspendAll();
	{
		if( uxLED < partstMAX_OUTPUT_LED )
		{
			usBit = partstFIRST_LED << uxLED;

			if( xValue == pdFALSE )
			{
				usBit ^= ( unsigned short ) 0xffff;
				usOutputValue &= usBit;
			}
			else
			{
				usOutputValue |= usBit;
			}

			GPIO_Write( GPIOC, usOutputValue );
		}	
	}
	xTaskResumeAll();
}
/*-----------------------------------------------------------*/

void ledTestToggleLED( unsigned long uxLED )
{
unsigned short usBit;

	vTaskSuspendAll();
	{
		if( uxLED < partstMAX_OUTPUT_LED )
		{
			usBit = partstFIRST_LED << uxLED;

			if( usOutputValue & usBit )
			{
				usOutputValue &= ~usBit;
			}
			else
			{
				usOutputValue |= usBit;
			}

			GPIO_Write( GPIOC, usOutputValue );
		}
	}
	xTaskResumeAll();
}
/*-----------------------------------------------------------*/
