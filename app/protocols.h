/** 
 * @defgroup infrared IR Protocols Driver Library
 * @code #include <drivers/ir/protocols.h> @endcode
 * 
 * @brief  
 *
 *
 * @author	Andreas Fritiofson, Anders Runeson
 * @date	2007
 */

/**@{*/


#ifndef IR_PROTOCOLS_H_
#define IR_PROTOCOLS_H_
#include <config.h>
#include <user_config.h>
#include <stdlib.h>

#include <SmingCore/SmingCore.h>

/* Protocol data structure */
typedef struct {
	uint8 protocol;
	uint64 data;
	uint16 timeout;		//Set to 0 to indicate burst protocol (only one pulse train is sent)
	uint8 repeats;
	uint16 modfreq;
	uint8 framecnt;
} Ir_Protocol_Data_t;


#define IR_PROTOCOL_RC5 0
#define IR_PROTOCOL_RC6 1
#define IR_PROTOCOL_RCMM 2
#define IR_PROTOCOL_SIRC 3
#define IR_PROTOCOL_SHARP 4
#define IR_PROTOCOL_NEC 5
#define IR_PROTOCOL_SAMSUNG 6
#define IR_PROTOCOL_MARANTZ 7
#define IR_PROTOCOL_PANASONIC 8
#define IR_PROTOCOL_SKY 9
#define IR_PROTOCOL_NEXA2 10
#define IR_PROTOCOL_NEXA 11
#define IR_PROTOCOL_VIKING 12
#define IR_PROTOCOL_VIKINGSTEAK 13
#define IR_PROTOCOL_RUBICSON 14
#define IR_PROTOCOL_IROBOT 15
#define IR_PROTOCOL_OREGONRAIN 16
#define IR_PROTOCOL_OREGONTEMPHUM 17
#define IR_PROTOCOL_OREGONWIND 18
#define IR_PROTOCOL_RUBICSONSTN 19
#define IR_PROTOCOL_UNKNOWN 255


/* Which protocols to use. These should perhaps be configuration options 
 * (config.inc). Only applies to receiver right now */
#ifndef IR_PROTOCOLS_USE_SIRC
# define IR_PROTOCOLS_USE_SIRC		1
#endif
#ifndef IR_PROTOCOLS_USE_RC5
# define IR_PROTOCOLS_USE_RC5		1
#endif
#ifndef IR_PROTOCOLS_USE_SHARP
# define IR_PROTOCOLS_USE_SHARP		1
#endif
#ifndef IR_PROTOCOLS_USE_NEC
# define IR_PROTOCOLS_USE_NEC		1
#endif
#ifndef IR_PROTOCOLS_USE_SAMSUNG
# define IR_PROTOCOLS_USE_SAMSUNG	1
#endif
#ifndef IR_PROTOCOLS_USE_MARANTZ
# define IR_PROTOCOLS_USE_MARANTZ	1
#endif
#ifndef IR_PROTOCOLS_USE_PANASONIC
# define IR_PROTOCOLS_USE_PANASONIC	1
#endif
#ifndef IR_PROTOCOLS_USE_SKY
# define IR_PROTOCOLS_USE_SKY		1
#endif
#ifndef IR_PROTOCOLS_USE_IROBOT
# define IR_PROTOCOLS_USE_IROBOT		1
#endif
#ifndef IR_PROTOCOLS_USE_NEXA2
# define IR_PROTOCOLS_USE_NEXA2	1
#endif
#ifndef IR_PROTOCOLS_USE_NEXA1
# define IR_PROTOCOLS_USE_NEXA1	1
#endif
#ifndef IR_PROTOCOLS_USE_VIKING
# define IR_PROTOCOLS_USE_VIKING	1
#endif
#ifndef IR_PROTOCOLS_USE_VIKING_T3
# define IR_PROTOCOLS_USE_VIKING_T3	0
#endif
#ifndef IR_PROTOCOLS_USE_VIKING_STEAK
# define IR_PROTOCOLS_USE_VIKING_STEAK	1
#endif
#ifndef IR_PROTOCOLS_USE_RUBICSON
# define IR_PROTOCOLS_USE_RUBICSON	1
#endif
#ifndef IR_PROTOCOLS_USE_OREGON
# define IR_PROTOCOLS_USE_OREGON	1
#endif
#ifndef IR_PROTOCOLS_USE_RUBICSONSTN
# define IR_PROTOCOLS_USE_RUBICSONSTN	1
#endif



/* All these functions take a buffer with pulse times and tries to parse it
 * to a Ir_Protocol_Data_t structure. They return IR_OK on success
 * and IR_NOT_CORRECT_DATA if there was no match. */
#if (IR_PROTOCOLS_USE_SIRC)
int8 parseSIRC(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_RC5)
int8 parseRC5(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_SHARP)
int8 parseSharp(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_NEC)
int8 parseNEC(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_SAMSUNG)
int8 parseSamsung(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_MARANTZ)
int8 parseMarantz(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_PANASONIC)
int8 parsePanasonic(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_SKY)
int8 parseSky(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_IROBOT)
int8 parseiRobot(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);
#endif


/* RF protocols needs index parameter */
#if (IR_PROTOCOLS_USE_NEXA2)
int8 parseNexa2(const uint16 *buf, uint16 len, uint16 index, Ir_Protocol_Data_t *proto,uint16 *used_len);
#endif
#if (IR_PROTOCOLS_USE_NEXA1)
int8 parseNexa1(const uint16 *buf, uint8 len, uint8 index, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_VIKING)
int8 parseViking(const uint16 *buf, uint8 len, uint8 index, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_VIKING_T3)
#include <util/crc16.h>
int8 parseVikingT3(const uint16 *buf, uint8 len, uint8 index, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_VIKING_STEAK)
int8 parseVikingSteak(const uint16 *buf, uint8 len, uint8 index, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_RUBICSON)
int8 parseRubicson(const uint16 *buf, uint8 len, uint8 index, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_OREGON)
int8 parseOregon(const uint16 *buf, uint8 len, uint8 index, Ir_Protocol_Data_t *proto);
#endif
#if (IR_PROTOCOLS_USE_RUBICSONSTN)

extern uint8 receiverBufferLong[14];
int8 parseRubicsonStn(const uint16 *buf, uint16 len, uint16 index, Ir_Protocol_Data_t *proto,uint16 *used_len);
#endif


/* Try to parse all above protocols until a match is found. */
//int8 parseProtocol(const uint16 *buf, uint8 len, uint8 index, Ir_Protocol_Data_t *proto);
int8 parseProtocol(const uint16 *buf, uint16 len, uint16 index, Ir_Protocol_Data_t *proto,uint16 *used_len);
/* The Hash protocol always succeeds and creates a one-way signature of the
 * pulse times buffer that is supposed to be unique and constant for a specific
 * IR event. It may be used to send a valid event even if the protocol hasn't
 * been implemented or decoded yet. */
int8 parseHash(const uint16 *buf, uint8 len, Ir_Protocol_Data_t *proto);

/* These functions expand a Ir_Protocol_Data_t structure into a raw buffer with
 * pulse lengths. They return IR_OK on success and IR_NOT_CORRECT_DATA if the
 * Ir_Protocol_Data_t structure is for another protocol or contains invalid
 * data. */
int8 expandSIRC(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandRC5(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandSharp(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandNEC(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandSamsung(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandMarantz(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandPanasonic(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandSky(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandiRobot(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandNexa2(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
int8 expandNexa1(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);
/* Pass the Ir_Protocol_Data_t automatically to the correct function. */
int8 expandProtocol(uint16 *buf, uint8 *len, Ir_Protocol_Data_t *proto);


#define IR_OK 			1
#define IR_NO_PROTOCOL		2
#define IR_TIME_OVFL		3
#define IR_NO_DATA 		4
#define IR_NOT_CORRECT_DATA 	5
#define IR_TO_MUCH_DATA		6
#define IR_NOT_FINISHED		7
#define IR_SEND_DEBUG		8
#define IR_OK_LONG		9
#define IR_BUTTON_DOWN		0x0
#define IR_BUTTON_UP		0xf

// defined for the module, uses same definitions for pressed and released as other buttons
#define IR_BUTTON_RELEASED	0x0
#define IR_BUTTON_PRESSED	0x1

#ifndef IR_MIN_PULSE_WIDTH
#define IR_MIN_PULSE_WIDTH	(0)									//us, used in continuous mode
#endif
#ifndef IR_MIN_STARTPULSE_WIDTH
#define IR_MIN_STARTPULSE_WIDTH	(0UL)							//us, not used when set to 0
#endif
#ifndef IR_MAX_PULSE_WIDTH
#define IR_MAX_PULSE_WIDTH	(12000UL)							//us
#endif

/* RC5 Implementation
 * Receiver: DONE
 * Transmitter: DONE
 */
#define IR_RC5_HALF_BIT		(889)		//us
#define IR_RC5_BIT			(889*2)	//us
#define IR_RC5_TIMEOUT		(117-IR_MAX_PULSE_WIDTH/1000)		//ms	(time between ir frames)
#define IR_RC5_REPS			(1)									//		(minimum number of times to repeat code)
#define IR_RC5_F_MOD		(36)								//kHz	(modulation frequency)
#define IR_RC5_TOL_DIV		(4)

/* RC6 Implementation
 * Receiver: 
 * Transmitter: 
 */
#define IR_RC6_ST_BIT		(1)		//us
#define IR_RC6_TIMEOUT		(50-IR_MAX_PULSE_WIDTH/1000)		//ms	(time between ir frames)
#define IR_RC6_REPS			(1)									//		(minimum number of times to repeat code)
#define IR_RC6_F_MOD		(36)								//kHz	(modulation frequency)
#define IR_RC6_TOL_DIV		(4)

/* RCMM Implementation
 * Receiver: 
 * Transmitter: 
 */
#define IR_RCMM_ST_BIT		(256)		//us
#define IR_RCMM_TIMEOUT 	(170-IR_MAX_PULSE_WIDTH/1000)		//ms	(time between ir frames)
#define IR_RCMM_REPS		(1)									//		(minimum number of times to repeat code)
#define IR_RCMM_F_MOD		(36)								//kHz	(modulation frequency)
#define IR_RCMM_TOL_DIV		(4)

/* SIRC Implementation
 * Receiver: DONE
 * Transmitter: DONE
 */
#define IR_SIRC_ST_BIT		(2400)	//us
#define IR_SIRC_LOW			(600)		//us
#define IR_SIRC_HIGH_ONE	(1200)	//us
#define IR_SIRC_HIGH_ZERO	(600)		//us
#define IR_SIRC_TIMEOUT		(52-IR_MAX_PULSE_WIDTH/1000)									//ms	(time between ir frames)
#define IR_SIRC_REPS		(3)									//		(minimum number of times to repeat code)
#define IR_SIRC_F_MOD		(40)								//kHz	(modulation frequency)
#define IR_SIRC_TOL_DIV		(4)

/* Sharp Implementation
 * Receiver: DONE
 * Transmitter: 
 */
#define IR_SHARP_HIGH		(280)		//us
#define IR_SHARP_LOW_ONE	(1850)	//us
#define IR_SHARP_LOW_ZERO	(780)		//us
#define IR_SHARP_TIMEOUT	(67-IR_MAX_PULSE_WIDTH/1000)		//ms	(time between ir frames)
#define IR_SHARP_REPS		(2)									//		(minimum number of times to repeat code)
#define IR_SHARP_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_SHARP_TOL_DIV	(4)

/* NEC Implementation
 * Receiver: DONE
 * Transmitter: DONE
 */
#define IR_NEC_ST_BIT		(9000)	//us
#define IR_NEC_ST_PAUSE		(4500)	//us
#define IR_NEC_LOW_ONE		(1690)	//us
#define IR_NEC_LOW_ZERO		(560)		//us
#define IR_NEC_HIGH			(560)		//us
#define IR_NEC_TIMEOUT		(122-IR_MAX_PULSE_WIDTH/1000)		//ms	(time between ir frames)
#define IR_NEC_ST_TIMEOUT	(65)								//ms	(time between first ir frames and second)
#define IR_NEC_REPS			(1)									//		(minimum number of times to repeat code)
#define IR_NEC_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_NEC_TOL_DIV		(4)

/* Samsung Implementation
 * Receiver: DONE
 * Transmitter: DONE
 */
#define IR_SAMS_ST_BIT		(4500)	//us
#define IR_SAMS_ST_PAUSE	(4500)	//us
#define IR_SAMS_LOW_ONE		(1720)	//us
#define IR_SAMS_LOW_ZERO	(650)		//us
#define IR_SAMS_HIGH		(500)		//us
#define IR_SAMS_TIMEOUT		(62-IR_MAX_PULSE_WIDTH/1000)		//ms	(time between ir frames)
#define IR_SAMS_REPS		(1)									//		(minimum number of times to repeat code)
#define IR_SAMS_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_SAMS_TOL_DIV		(4)

/* Marantz Implementation
 * Receiver: DONE (has not been tested with odd adressbits)
 * Transmitter: DONE
 */
#define IR_MARANTZ_HALF_BIT		(889)		//us
#define IR_MARANTZ_BIT			(889*2)	//us
#define IR_MARANTZ_TIMEOUT		(117-IR_MAX_PULSE_WIDTH/1000)		//ms	(time between ir frames)
#define IR_MARANTZ_REPS			(1)									//		(minimum number of times to repeat code)
#define IR_MARANTZ_F_MOD		(36)								//kHz	(modulation frequency)
#define IR_MARANTZ_TOL_DIV		(4)

/* Panasonic Implementation
 * Receiver: DONE
 * Transmitter: DONE
 */
#define IR_PANA_ST_BIT		(3570)	//us
#define IR_PANA_ST_PAUSE	(1630)	//us
#define IR_PANA_LOW_ONE		(1240)	//us
#define IR_PANA_LOW_ZERO	(400)		//us
#define IR_PANA_HIGH		(495)		//us
#define IR_PANA_TIMEOUT		(92-IR_MAX_PULSE_WIDTH/1000)		//ms	(time between ir frames)
#define IR_PANA_REPS		(1)									//		(minimum number of times to repeat code)
#define IR_PANA_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_PANA_TOL_DIV		(4)

/* Sky Implementation
 * Receiver: DONE
 * Transmitter: 
 */
#define IR_SKY_ST_BIT		(2800)	//us
#define IR_SKY_SHORT		(460)		//us
#define IR_SKY_LONG			(920)		//us
#define IR_SKY_TIMEOUT		(162-IR_MAX_PULSE_WIDTH/1000)		//ms	(time between ir frames)
#define IR_SKY_REPS			(1)									//		(minimum number of times to repeat code)
#define IR_SKY_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_SKY_TOL_DIV		(4)

/* iRobot Implementation
 * Receiver: -
 * Transmitter: DONE
 */
#define IR_IROBOT_ST_BIT		(2800)		//us
#define IR_IROBOT_SHORT		(1000)		//us
#define IR_IROBOT_LONG		(3000)		//us
#define IR_IROBOT_TIMEOUT		30		//ms	(time between ir frames)
#define IR_IROBOT_REPS		(6)									//		(minimum number of times to repeat code)
#define IR_IROBOT_F_MOD		(40)								//kHz	(modulation frequency)
#define IR_IROBOT_TOL_DIV		(4)


/* Nexa2 Implementation
 * Receiver: DONE
 * Transmitter: DONE
 */
#define IR_NEXA2_START1 	(10000)	//us
#define IR_NEXA2_START2 	(2500)	//us
#define IR_NEXA2_HIGH 		(210)		//us
#define IR_NEXA2_LOW_ONE	(320)		//us
#define IR_NEXA2_LOW_ZERO	(1200)	//us
#define IR_NEXA2_TIMEOUT	(200)								//ms	(time between ir frames)
#define IR_NEXA2_REPS		(5)									//		(minimum number of times to repeat code)
#define IR_NEXA2_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_NEXA2_TOL_DIV	(2)


/* Nexa1 Implementation
 * Receiver: DONE
 * Transmitter: 
 */
#define IR_NEXA1_START	 	(10000)	//us
#define IR_NEXA1_SHORT 		(370)		//us
#define IR_NEXA1_LONG		(1050)	//us
#define IR_NEXA1_TIMEOUT	(200)								//ms	(time between ir frames)
#define IR_NEXA1_REPS		(4)									//		(minimum number of times to repeat code)
#define IR_NEXA1_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_NEXA1_TOL_DIV	(2)


/* Viking Temperature sensor Implementation
 * Receiver: 
 */
#define IR_VIKING_LOW 		(940)		//us
#define IR_VIKING_HIGH_ONE	(1483)		//us
#define IR_VIKING_HIGH_ZERO	(550)	//us
#define IR_VIKING_TIMEOUT	(0)									//ms BURST!	(time between ir frames)
#define IR_VIKING_REPS		(1)									//		(minimum number of times to repeat code)
#define IR_VIKING_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_VIKING_TOL_DIV	(3)

/* Viking Steak temperature sensor Implementation
 * Receiver: 
 */
#define IR_VIKING_STEAK_HIGH		(700)		//us
#define IR_VIKING_STEAK_LOW_ONE	(4000)		//us
#define IR_VIKING_STEAK_LOW_ZERO	(1700)	//us
#define IR_VIKING_STEAK_LOW_START	(7800)		//us
#define IR_VIKING_STEAK_TIMEOUT	(200)									//ms BURST!	(time between ir frames)
#define IR_VIKING_STEAK_REPS		(1)									//		(minimum number of times to repeat code)
#define IR_VIKING_STEAK_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_VIKING_STEAK_TOL_DIV	(4)

/* Rubicson temperature sensor Implementation
 * Receiver: 
 */
#define IR_RUBICSON_HIGH		(550)		//us
#define IR_RUBICSON_LOW_ONE		(1880)		//us
#define IR_RUBICSON_LOW_ZERO		(900)	//us
#define IR_RUBICSON_LOW_START		(3850)		//us
#define IR_RUBICSON_TIMEOUT		(200)									//ms BURST!	(time between ir frames)
#define IR_RUBICSON_REPS		(1)									//		(minimum number of times to repeat code)
#define IR_RUBICSON_F_MOD		(38)								//kHz	(modulation frequency)
#define IR_RUBICSON_TOL_DIV		(4)

/* Oregon weather sensor Implementation
 * Receiver: 
 */
#define IR_OREGON_SHORT_S		(250)		//us
#define IR_OREGON_SHORT_L		(700)		//us
#define IR_OREGON_LONG_S		(750)		//us
#define IR_OREGON_LONG_L		(1250)	//us
#define IR_OREGON_END			(2000)	//us
#define IR_OREGON_DATASIZE		25
#define IR_OREGON_TIMEOUT		(200)								//ms BURST!	(time between ir frames)
#define IR_OREGON_REPS			(1)									//		(minimum number of times to repeat code)
#define IR_OREGON_F_MOD			(38)								//kHz	(modulation frequency)

/* Rubicson weather station Implementation
 * Receiver: 
 */
#define IR_RUBICSONSTN_HIGH		(500)		//us
#define IR_RUBICSONSTN_LOW_ONE		(1000)	//us
#define IR_RUBICSONSTN_LOW_ZERO		(500)		//us
#define IR_RUBICSONSTN_LOW_START	(2400)	//us
#define IR_RUBICSONSTN_TIMEOUT		(200)					//ms BURST!	(time between ir frames)
#define IR_RUBICSONSTN_REPS		(1)					//		(minimum number of times to repeat code)
#define IR_RUBICSONSTN_F_MOD		(38)					//kHz	(modulation frequency)
#define IR_RUBICSONSTN_TOL_DIV		(4)

#define IR_PROTO_HASH		0xfe
#define IR_PROTO_UNKNOWN	0xff								//



/**@}*/
#endif /*IR_PROTOCOLS_H_*/
