#ifndef __TYPE_H
#define __TYPE_H

#define KEY1                (1<<0)
#define KEY2                (1<<1)
#define KEY3                (1<<2)
#define KEY4                (1<<3)
#define KEY5                (1<<4)
#define KEY6                (1<<5)
#define KEY7                (1<<6)
#define KEY8                (1<<7)

typedef unsigned short 	color;
typedef unsigned char	align;
typedef unsigned int	glyph;

typedef unsigned short 	uint16;
typedef unsigned long   uint32;
typedef signed short 	int16;
typedef signed long   	int32;
typedef unsigned char   uint8;
typedef signed char	int8;

typedef struct
{
	uint16 	IsHorizon:1;
	uint16 	Altitude1000:1;
	uint16 	Altitude5000:1;
	uint16	Speed300:1;
	uint16 	HorizColor:1;
	uint16 	TimerOn:1;
	uint16 	TimerMode:1;
	uint16 	AltitudeMarkOn:1;
	uint16 	SpeedMarkOn:1;
	uint16 	Altitude100Rest:1;
	uint16	CompassLine:1;
	uint16	BlackNum:1;
	uint16	CorrOn:1;
	uint16	ClockDot:1;
	uint16  IsPitchCor:1;
	uint16  IsRollCor:1;
}ParamBit;

typedef struct
{
	uint16 		AltitudeMark;
	uint16		SpeedMark;
	uint8 		SpeedMin;
	uint8 		SpeedMax;
	uint8		Brightness;
	uint16 		Pressure;
	int16 		Temperature;
	int16		DeltaRoll;
	int16		DeltaPitch;
}ParamVal;

typedef struct
{
	float 		Pitch;
	float 		Roll;
	float 		Yaw;
	uint16 		Barspeed;
	float 		Altitude;
	float		Ball;
    float       N5g;
	uint8   	TimerHour;
	uint8		TimerMin;
	uint8		TimerSec;
	uint8		ClockHour;
	uint8		ClockMin;
	uint8		ClockSec;
	ParamBit 	PBit;
	ParamVal    PVal;

} FlyData;

#endif
