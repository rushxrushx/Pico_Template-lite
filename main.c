/****************************************************************************
*  Copyright 2021 Gorgon Meducer (Email:embedded_zhuoran@hotmail.com)       *
*                                                                           *
*  Licensed under the Apache License, Version 2.0 (the "License");          *
*  you may not use this file except in compliance with the License.         *
*  You may obtain a copy of the License at                                  *
*                                                                           *
*     http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                           *
*  Unless required by applicable law or agreed to in writing, software      *
*  distributed under the License is distributed on an "AS IS" BASIS,        *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
*  See the License for the specific language governing permissions and      *
*  limitations under the License.                                           *
*                                                                           *
****************************************************************************/
/*============================ INCLUDES ======================================*/
#include "pico/stdlib.h"
#include <stdio.h>

/*============================ MACROS ========================================*/
#define TOP         (0x1FFF)

/*============================ MACROFIED FUNCTIONS ===========================*/
#define ABS(__N)    ((__N) < 0 ? -(__N) : (__N))
#define _BV(__N)    ((uint32_t)1<<(__N))



/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
/*============================ IMPLEMENTATION ================================*/

void SysTick_Handler(void)
{

}

/*! \brief set the 16-level led gradation
 *! \param hwLevel gradation
 *! \return none
 */
static void set_led_gradation(uint16_t hwLevel)
{
    static uint16_t s_hwCounter = 0;
    
    if (hwLevel >= s_hwCounter) {
        gpio_put(PICO_DEFAULT_LED_PIN, 1);
    } else {
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
    }
    
    s_hwCounter++;
    s_hwCounter &= TOP;
}

static void breath_led(void)
{
    static uint16_t s_hwCounter = 0;
    static int16_t s_nGray = (TOP >> 1);
    
    s_hwCounter++;
    if (!(s_hwCounter & (_BV(10)-1))) {
        s_nGray++; 
        if (s_nGray == TOP) {
            s_nGray = 0;
        }
    }
    
    set_led_gradation(ABS(s_nGray - (TOP >> 1)));
}

static void system_init(void)
{
    extern void SystemCoreClockUpdate();

    SystemCoreClockUpdate();
    /*! \note if you do want to use SysTick in your application, please use 
     *!       init_cycle_counter(true); 
     *!       instead of 
     *!       init_cycle_counter(false); 
     */
//    init_cycle_counter(false);


    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

}




#include "oled.h"
#include "bmp.h"
int main(void) 
{
    system_init();

    //printf("Hello Pico-Template\r\n");
    uint32_t n = 0;
	
	
    gpio_init(24);
    gpio_set_dir(24, GPIO_OUT);
	
	
		OLED_Init();
		OLED_ColorTurn(0);//0正常显示，1 反色显示
    
    while (true) {
        //breath_led();
        //gpio_put(PICO_DEFAULT_LED_PIN, 1);
        //sleep_ms(500);
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
        //sleep_ms(500);
        gpio_put(PICO_DEFAULT_LED_PIN, 1);
					
			if(n==0) {OLED_ColorTurn(0);n=1;}
			else 		{OLED_ColorTurn(1);n=0;}
			
		OLED_ShowPicture(0,0,128,32,BMP1,1);
		OLED_Refresh();
		sleep_ms(1000);
		OLED_Clear();
		OLED_ShowChinese(0,0,0,16,1);//中
		OLED_ShowChinese(18,0,1,16,1);//景
		OLED_ShowChinese(36,0,2,16,1);//园
		OLED_ShowChinese(54,0,3,16,1);//电
		OLED_ShowChinese(72,0,4,16,1);//子
		OLED_ShowChinese(90,0,5,16,1);//科
		OLED_ShowChinese(108,0,6,16,1);//技
		OLED_ShowString(8,16,"ZHONGJINGYUAN",16,1);
		OLED_Refresh();
		sleep_ms(1000);
//		OLED_Clear();
//		OLED_Refresh();
		sleep_ms(500);
		OLED_Clear();
		OLED_ShowChinese(0,0,0,16,1); //16*16 中
		OLED_ShowChinese(16,0,0,24,1);//24*24 中
		OLED_ShowChinese(40,0,0,32,1);//32*32 中
		OLED_Refresh();
	  sleep_ms(500);
  	OLED_Clear();
		OLED_ShowString(0,7,"A",8,1);
		OLED_ShowString(18,4,"B",12,1);
		OLED_ShowString(36,2,"C",16,1);
		OLED_ShowString(56,0,"D",24,1);
	  OLED_Refresh();
		sleep_ms(500);
//		OLED_ScrollDisplay(11,4,1);
			
    }
    //return 0;
}
