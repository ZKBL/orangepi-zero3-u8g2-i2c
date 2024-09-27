#include "u8g2.h"
#include "linux-i2c.h"
#define SSD1306_ADDR  0x3c

u8g2_t u8g2;

int main (void)
{
        u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_linux_i2c, u8x8_linux_i2c_delay);

        u8g2_SetI2CAddress(&u8g2, SSD1306_ADDR);

        u8g2_InitDisplay(&u8g2);

        u8g2_SetPowerSave(&u8g2, 0);

        u8g2_ClearBuffer(&u8g2);

        //u8g2_SetFont(&u8g2, u8g2_font_smart_patrol_nbp_tr);
        u8g2_SetFont(&u8g2, u8g2_font_wqy16_t_gb2312);


        u8g2_SetFontRefHeightText(&u8g2);

        u8g2_SetFontPosTop(&u8g2);
        int i =0;
        int y =0;
        while(1){
                u8g2_ClearBuffer(&u8g2);
                if (i+16>64){
                        i=0;
                        y=0;
                }
                u8g2_DrawUTF8(&u8g2, y, i, "你好，世界!");
                u8g2_SendBuffer(&u8g2);
                sleep(1);
                i+=16;
                y+=16;
        }

}

