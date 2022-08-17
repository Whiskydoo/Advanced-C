/*
 * File:   Source_Buoi8.c
 * Author: dogiaquocviet
 *
 * Created on August 17, 2022, 11:58 AM
 * Chương trình ban đầu nhấp nháy 20 lần tất cả các led,
 * sau đó chuyển sang chế độ led đuổi 5 lần và lại chuyển chế độ nhấp nháy 20 lần
 * và cứ như thế.
 * 
 * Vận dụng kiến thức về câu lệnh goto ta viết được hàm delayAndCheck
 * để chuyển sang chế độ led bất kỳ ngay lập tức mà không bị delay hoặc
 * phải sử dụng interrupt.
 * 
 * Vì lệnh goto không sử dụng được ở 1 hàm khác nên em viết chung vào 1 hàm main luôn ạ :<<.
 * 
 * Chương trình được mô phỏng và thực hiện trên PIC16f877a.
 * 
 * Link demo chương trình: https://youtu.be/CTkjMTDm24M
 */


#include <xc.h>
#include <pic16f877a.h>
#include "Config_Buoi8.h"
#define _XTAL_FREQ 4000000
    
void main(void) {
    TRISD = 0x00;
    PORTD = 0x00;
    TRISB = 0x07;
    //Hàm chớp tắt tất cả các led 20 lần
BUTTON1:
    PORTD = 0x00;
    for(int B1 = 0; B1<20; B1++)
    {
        //Delay and Chek;
        for(int i = 0; i <100; i++)
        {
        __delay_ms(10);
        if(RB0 == 1)
        {
            goto BUTTON1;
        }
        if(RB1 == 1)
        {
            goto BUTTON2;
        }
        if(RB2 == 1)
        {
            goto BUTTON3;
        }
        }
        
        PORTD = 0xff;
        //Delay And Check;
        for(int i = 0; i <100; i++)
        {
        __delay_ms(10);
        if(RB0 == 1)
        {
            goto BUTTON1;
        }
        if(RB1 == 1)
        {
            goto BUTTON2;
        }
        if(RB2 == 1)
        {
            goto BUTTON3;
        }
        }

        PORTD = 0x00;
    }

//Hàm các led sáng đuổi 5 lần

BUTTON2:   
    for(int B2 = 0; B2<5; B2++)
    {
        PORTD = 0x01;
        for(int i = 1; i < 9; i++)
        {
            //Delay And Check;
            for(int i = 0; i <100; i++)
            {
                __delay_ms(10);
                if(RB0 == 1)
                {
                    goto BUTTON1;
                }
                if(RB1 == 1)
                {
                    goto BUTTON2;
                }
                if(RB2 == 1)
                {
                    goto BUTTON3;
                }
                }
                //Dịch trái led;
                PORTD = PORTD << 1;
        }
    }
    goto BUTTON1;
BUTTON3:
    goto BUTTON3;    
}
