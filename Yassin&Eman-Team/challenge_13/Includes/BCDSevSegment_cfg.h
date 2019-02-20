/*
 * BCDSevSegment_cfg.h
 *
 * Created: 2/18/2019 12:49:59 PM
 *  Author: Yassin
 */ 


#ifndef BCDSEVSEGMENT_CFG_H_
#define BCDSEVSEGMENT_CFG_H_

/************************************************************************/
/* Define Seven Segment Pins                                            */
/************************************************************************/
#define SEGMENT_A						PIN8				
#define SEGMENT_B						PIN9
#define SEGMENT_C						PIN10
#define SEGMENT_D						PIN11

#define SEG1_EN							PIN26
#define SEG2_EN							PIN27
#define SEG3_EN							PIN30
#define SEG4_EN							PIN31


/*************************************************************************/
/* Bits to display on Seven segment			                             */
/* these bits holds the values of bits that control the number displayed */
/*************************************************************************/
#define SEG_BIT0				0
#define SEG_BIT1				1
#define SEG_BIT2				2
#define SEG_BIT3				3



#endif /* BCDSEVSEGMENT_CFG_H_ */