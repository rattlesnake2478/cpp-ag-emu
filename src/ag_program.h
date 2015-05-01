#ifndef __AG_PROGRAM_H
#define __AG_PROGRAM_H

#include "type.h"
#include <math.h>

//------------------------------------------------------------------------------
//			Macro definitions
//------------------------------------------------------------------------------

#define COLOR_BLACK          0x0000
#define COLOR_WHITE          0xFFFF

#define COLOR_BLUE           0x001F
#define COLOR_GREEN          0x07E0
#define COLOR_RED            0xF800

#define COLOR_YELLOW         0xFFE0
#define COLOR_NAVY           0x0010
#define COLOR_BROWN			 0x8000
#define COLOR_DARK_GREEN   	 0x0700
#define COLOR_GRAY			 0x8410
#define	COLOR_SNOW			 0xE79C

//Constants
#define AG_Radius	210
#define PitchCoef 	2.5
#define	PitchDeriv	2
#define ANGL		1
#define ENV			0

// Коэффициент для шарика. Максимальный ход шарика -25 ... + 25 градусов
#define BALL_COEF	25
// Добавка для давления. Можно добавить, можно отнять давление
#define PRESSURE_ADD	0

#define	BIGARROW_OUT_COLOR		COLOR_BLUE
#define	BIGARROW_IN_COLOR		COLOR_WHITE
#define SKY_COLOR				COLOR_BLUE
#define	HORIZ1_COLOR			0xC600
#define	HORIZ2_COLOR			COLOR_BROWN
#define HORIZ_NUMCOLOR1			COLOR_BLACK
#define HORIZ_NUMCOLOR2			COLOR_WHITE
#define	DANGER_RED				COLOR_RED
#define	OK_GREEN				COLOR_GREEN
#define MARK_COLOR				COLOR_DARK_GREEN
#define SCALE_COLOR				COLOR_GREEN
#define COMPASS_BACKCOLOR		COLOR_SNOW
#define	COMPASS_MARKCOLOR		COLOR_GREEN
#define COMPASS_COLOR			COLOR_BLACK
#define MENU_BACKCOLOR			0x97F2//COLOR_SNOW
#define	MENU_TEXTCOLOR			COLOR_BLACK
#define	MENU_ACTIVETEXTCOLOR    COLOR_RED
#define MENU_ACTIVEBACKCOLOR	COLOR_BLUE
#define VARIO_IN_COLOR			0x0300
#define VARIO_OUT_COLOR			COLOR_WHITE
#define VARIO_UP_COLOR			COLOR_YELLOW
#define	VARIO_DOWN_COLOR		COLOR_RED
#define BALL_COLOR				COLOR_BLACK
#define CLOCK_COLOR				COLOR_WHITE
#define TIMER_COLOR				0xF7EF

/*
#define COLOR_DARKCYAN       0x002323

#define COLOR_DARKBLUE       0x00008B
#define COLOR_DARKGREEN      0x006400

#define COLOR_CYAN           0x00FFFF
#define COLOR_TURQUOISE      0x40E0D0
#define COLOR_INDIGO         0x4B0082
#define COLOR_DARKRED        0x800000
#define COLOR_OLIVE          0x808000
#define COLOR_GRAY           0x808080
#define COLOR_SKYBLUE        0x87CEEB
#define COLOR_BLUEVIOLET     0x8A2BE2
#define COLOR_LIGHTGREEN     0x90EE90
#define COLOR_DARKVIOLET     0x9400D3
#define COLOR_YELLOWGREEN    0x9ACD32
#define COLOR_BROWN          0xA52A2A
#define COLOR_DARKGRAY       0xA9A9A9
#define COLOR_SIENNA         0xA0522D
#define COLOR_LIGHTBLUE      0xADD8E6
#define COLOR_GREENYELLOW    0xADFF2F
#define COLOR_SILVER         0xC0C0C0
#define COLOR_LIGHTGREY      0xD3D3D3
#define COLOR_LIGHTCYAN      0xE0FFFF
#define COLOR_VIOLET         0xEE82EE
#define COLOR_AZUR           0xF0FFFF
#define COLOR_BEIGE          0xF5F5DC
#define COLOR_MAGENTA        0xFF00FF
#define COLOR_TOMATO         0xFF6347
#define COLOR_GOLD           0xFFD700
#define COLOR_ORANGE         0xFFA500
#define COLOR_SNOW           0xFFFAFA
*/

#define	LEFT 		        0
#define CENTER 				1
#define	RIGHT 				2

#define DEG2RAD  			0.017453292519943295769236907684
#define RAD2DEG 			57.295779513082320876798154814105

void ag_program(void);

#endif
