#ifndef __OLED_H
#define __OLED_H 

//#include "sys.h"
//#include "stdlib.h"	
#include "pico/stdlib.h"

//-----------------OLED端口定义---------------- 
#define OLEDPIN_CL 2
#define OLEDPIN_DA 3
#define OLEDPIN_RST 9
#define OLEDPIN_DC 10
#define OLEDPIN_CS 11

//SCL
#define OLED_SCL_Clr() gpio_put(OLEDPIN_CL, 0)
#define OLED_SCL_Set() gpio_put(OLEDPIN_CL, 1)
//SDA
#define OLED_SDA_Clr() gpio_put(OLEDPIN_DA, 0)
#define OLED_SDA_Set() gpio_put(OLEDPIN_DA, 1)
//RES
#define OLED_RES_Clr() gpio_put(OLEDPIN_RST, 0)
#define OLED_RES_Set() gpio_put(OLEDPIN_RST, 1)
//DC
#define OLED_DC_Clr()  gpio_put(OLEDPIN_DC, 0)
#define OLED_DC_Set()  gpio_put(OLEDPIN_DC, 1)
//CS 		     
#define OLED_CS_Clr()  gpio_put(OLEDPIN_CS, 0)
#define OLED_CS_Set()  gpio_put(OLEDPIN_CS, 1)


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
void OLED_ShowChar6x8(u8 x,u8 y,u8 chr,u8 mode);
void OLED_ShowString(u8 x,u8 y,char *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
void OLED_Init(void);

#endif

