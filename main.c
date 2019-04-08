/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 04 March 2019, 19:24
 * 
1) Keep your pull requests small and digestible
2) Write a design doc before coding to save time and prevent spaghetti code
3) Keep your eye on the end goal (i.e. shipping products) and don't surf reddit at work ¯\_(?)_/¯
4) Lose the ego and arrogance, don't be afraid to ask questions, and don't try to write "clever" unintelligible code
5) Respect The Tech Lead, buy them coffee or they'll get you fired?
 */
/* Design document for Pong game
 * This version of pong is a one (human) player game (LHS) who plays against the PIC microcontroller (RHS). Whenever the puck is successfully returned, 
 * one point is scored. When the puck is missed and goes out of play behind the paddle, a point is deducted from that player. 
 * Whoever is the first player to reach 10 is the winner. If the puck is returned from the top or bottom of the paddle, the angle of the deflected ball is 45 deg.
 * If the puck is returned from the middle area of the paddle, the angle of the return is 180 deg. The puck can only rebound from the top or bo ttom walls, 
 * not from the wall at extreme left or right of the screen. The game starts whenever the human moves the paddle for the first time.
 */

#include "config.h"
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "lcdWrite.h"



void main(void) 
{
    uchar x, y, i, j, k;
uchar pad [8][1]= {    {0},
                      {0},
                      {1},
                      {1},
                      {1},
                      {1},
                      {0},
                      {0}};
    //bool pad [1][8] =  {{0,0,1,1,1,1,0,0}};
  // bool pad[8] = {0,0,1,1,1,1,0,0};                   
    setup_ports();
    init_spi();
    
    
    RST = LOW;
    __delay_ms(1);
    RST = HIGH;
    
    lcdWrite(FUNC_SET_EXTEND, LOW); // function set command LCD active, Horiz mode, extended instruction set
    lcdWrite(LCD_CONTRAST, LOW); // set LCD Vop contrast
    lcdWrite(LCD_TEMP_COEFF, LOW); // set temp coefficient
    lcdWrite(LCD_BIAS, LOW); // LCD bias mode
    lcdWrite(BASIC_IS, LOW); // LCD basic instruction set
    lcdWrite(NORMAL_MODE, LOW); // normal display mode
    
    for(j = 0x40; j < 0x46; j++)
    {
        for(k = 0x80; k < 0xd3;k++)
        {
        lcdWrite(0x00|j, LOW);    // y address = 1 (0x42)
        lcdWrite(0x00|k, LOW);    // x address = 0 (0x80)
        
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        
        }
        
    }
   
    
    /*for (x = 0; x<8 ;x++)
    {
        y = 0;
        lcdWrite(pad[x], HIGH);
    }*/
    j = 0x40;
    k = 0x80;
    for (j = 0x40; j < 0x46; j++)
    {
        lcdWrite(0x00|j, LOW);    // y address = 0 (0x40)
        lcdWrite(0x00|k, LOW);    // x address = 0 (0x80)
       
        lcdWrite(0xff, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        __delay_ms(100);
        
       
        lcdWrite(0x00|j, LOW);    // y address = 0 (0x40)
        lcdWrite(0x00|k, LOW);    // x address = 0 (0x80)
       
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        __delay_ms(100);
    
    }
    j = 0x40;
    k = 0x80;
    
    
   /* for(j = 0x40; j < 0x46; j++)
    {
        for(k = 0x80; k < 0xd3;k++)
        {
        lcdWrite(0x00|j, LOW);    // y address = 1 (0x42)
        lcdWrite(0x00|k, LOW);    // x address = 0 (0x80)
        
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x1c, HIGH);
        lcdWrite(0x1c, HIGH);
        lcdWrite(0x1c, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        __delay_ms(50);
        }
        __delay_ms(50);
    }
        */
     
    while(1)
    {
        /*GREEN_LED = HIGH;
        __delay_ms(100);
        GREEN_LED = LOW;
        __delay_ms(100);*/
        j = 0x40;
    k = 0x80;
    for (j = 0x40; j < 0x46; j++)
    {
        lcdWrite(0x00|j, LOW);    // y address = 0 (0x40)
        lcdWrite(0x00|k, LOW);    // x address = 0 (0x80)
       
        lcdWrite(0xff, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        __delay_ms(500);
        
       
        lcdWrite(0x00|j, LOW);    // y address = 0 (0x40)
        lcdWrite(0x00|k, LOW);    // x address = 0 (0x80)
       
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        __delay_ms(100);
    
    }
    for (j = 0x46; j < 0x40; j--)
    {
        lcdWrite(0x00|j, LOW);    // y address = 0 (0x40)
        lcdWrite(0x00|k, LOW);    // x address = 0 (0x80)
       
        lcdWrite(0xff, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        __delay_ms(500);
        
       
        lcdWrite(0x00|j, LOW);    // y address = 0 (0x40)
        lcdWrite(0x00|k, LOW);    // x address = 0 (0x80)
       
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        lcdWrite(0x00, HIGH);
        __delay_ms(100);
    
    }
    }
    
}



