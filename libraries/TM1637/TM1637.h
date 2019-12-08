		//	Author:Fred.Chu
	//	Date:9 April,2013
	//
	//	Applicable Module:
	//		  4-Digit Display by catalex
	//		  4-Digit Display (D4056A) by catalex
	//   Store: http://www.aliexpress.com/store/1199788
	//
	//	This library is free software; you can redistribute it and/or
	//	modify it under the terms of the GNU Lesser General Public
	//	License as published by the Free Software Foundation; either
	//	version 2.1 of the License, or (at your option) any later version.
	//
	//	This library is distributed in the hope that it will be useful,
	//	but WITHOUT ANY WARRANTY; without even the implied warranty of
	//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	//	Lesser General Public License for more details.
	//
	//	You should have received a copy of the GNU Lesser General Public
	//	License along with this library; if not, write to the Free Software
	//	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
	//
	//	Modified record:
	//      Author: Nicu FLORICA (niq_ro) - http://www.tehnic.go.ro & http://www.arduinotehniq.com
      //      Date: 25 november, 2015
      //      Note: put sign for degree, letter 'r' & 'h'
      //      Date: 10 march, 2016
      //      Note: put sign for degree, letter 'r', 'h' & 'n'
      //  Date: 21 september, 2016
      //  Note: put letter 't', "u up and _ bottom" & "u bottom and - up" 
	/*******************************************************************************/
	
#ifndef TM1637_h
#define TM1637_h
#include <inttypes.h>
#include <Arduino.h>
	//************definitions for TM1637*********************
#define ADDR_AUTO  0x40
#define ADDR_FIXED 0x44
	
#define STARTADDR  0xc0 
	/**** definitions for the clock point of the 4-Digit Display *******/
#define POINT_ON   1
#define POINT_OFF  0
	/**************definitions for brightness***********************/
#define  BRIGHT_DARKEST 0
#define  BRIGHT_TYPICAL 2
#define  BRIGHTEST      7
//--------------------------------------------------------//
//Special characters index of tube table
#define INDEX_NEGATIVE_SIGN	16
#define INDEX_BLANK			17
/************definitions for type of the 4-Digit Display*********************/
#define D4036B 0
#define D4056A 1

#define _0 0x3f //0
#define _1 0x06 //1
#define _2 0x5b //2
#define _3 0x4f //3
#define _4 0x66 //4
#define _5 0x6d //5
#define _6 0x7d //6
#define _7 0x07 //7
#define _8 0x7f //8
#define _9 0x6f //9
#define _A 0x77, //A 10
#define _B 0x7c, //B 11
#define _C 0x39, //C 12
#define _D 0x5e, //d 13
#define _E 0x79, //E 14
#define _F 0x71, //F 15
#define _G 0x3d, //G 16
#define _H 0x76, //H 17
#define _h 0x74, //h 18
#define _I 0x30, //I 19
#define _i 0x10, //i 20
#define _J 0x1e, //J 21
#define _j 0x0c, //j 22
#define _L 0x38, //L 23
#define _l 0x18, //l 24
#define _M 0x37, //M 25
#define _n 0x54, //n 26
#define _o 0x5c, //o 27
#define _P 0x73, //P 28
#define _r 0x50, //r 29
#define _t 0x78, //t 30
#define _U 0x3e, //U 31
#define _u 0x1c, //u 32
#define _Y 0x6E, //Y 33
#define _- 0x40, // "-"    34    
#define _degree 0x63, // градус 36
#define _under 0x08, // "_"	    37
#define _empty 0x00 //пробел

	class TM1637
	{
	  public:
		uint8_t Cmd_SetData;
		uint8_t Cmd_SetAddr;
		uint8_t Cmd_DispCtrl;
		boolean _PointFlag; 	//_PointFlag=1:the clock point on
		uint8_t _DispType;
		TM1637(uint8_t, uint8_t);
		void init(uint8_t = D4036B);
		void writeByte(int8_t wr_data);//write 8bit data to tm1637
		void start(void);//send start bits
		void stop(void); //send stop bits
		void display(int8_t DispData[]);
		void display(uint8_t BitAddr,int8_t DispData);
		void display(double Decimal);
		
		void runningString(int8_t DispData[], byte amount, int delayMs);
		void displayByte(uint8_t bit0, uint8_t bit1, uint8_t bit2, uint8_t bit3);// если лень создавать массив, выводит байты в ячейки
		void displayByte(uint8_t DispData[]);					// выводит байт вида 0xe6 и буквы-константы вида _a , _b .... массивом
		
		void display(int16_t Decimal);
		void clearDisplay(void);
		void set(uint8_t = BRIGHT_TYPICAL,uint8_t = 0x40,uint8_t = 0xc0);//To take effect the next time it displays.
		void point(boolean PointFlag);//whether to light the clock point ":".To take effect the next time it displays.
		void coding(int8_t DispData[]); 
		int8_t coding(int8_t DispData); 
	  
	  private:
		uint8_t lastData[4];
		uint8_t PointData;
		void sendByte(uint8_t BitAddr, int8_t sendData);
		void sendArray(uint8_t sendData[]);
		
		uint8_t Clkpin;
		uint8_t Datapin;
		uint8_t DecPoint;
		boolean BlankingFlag;
		
	};
#endif
