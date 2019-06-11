/*
 * ComStack_Type.h
 *
 *  Created on: 10-Jun-2019
 *      Author: Atul
 */

#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

/*Communication related basic software modules shall not include Std_Types.h directly */
#include"Std_Types.h"
#include"ComStack_Cfg.h"

/***** API Specification  *****/

/**  Type Definition  **/
/* Software modules deals with PDUs that 256 */
		
 #define PduLengthType	uint8		
 uint8	PNCHandleType;		
 uint8	IcomConfigIdType;	

/* This type can be used as standard API return type which is shared between the RTE and the BSW modules */
typedef uint8 Std_ReturnType;

enum TPParameterType {
	TP_STMIN	= 0x00,	/* Separation Time */
	TP_BS 		= 0x01,	/* Block Size */
	TP_BC 		= 0x02	/* The Band width control parameter used in FlexRay transport protocol module */
};

/** Symbol Definition **/

enum BufReq_ReturnType {
	BUFREQ_OK 	= 0x00,	/* Buffer request accomplished successful */
	BUFREQ_E_NOT_OK = 0x01,	/* Buffer request not successful. Buffer cannot be accessed */
	BUFREQ_E_BUSY 	= 0x02,	/* Temporarily no buffer available. It's up the requester to retry request for a certain time */
	BUFREQ_E_OVFL 	= 0x03	/* No Buffer of the required length can be provided */
};

enum TpDataStateType {
	TP_DATACONF 	= 0x00,	/* All data that have been copied so far,
				 * are confirmed and can be removed from the TP buffer */
	TP_DATARETRY 	= 0x01,	/* API call shall copy already copied data in order to recover from an error */
	TP_CONFPENDING 	= 0x02	/* The previously copied data must remain in the TP */
};

enum IcomSwitch_ErrorType {
	ICOM_SWITCH_E_OK 	= 0x00,	/* The activation of Pretended Networking was successful */
	ICOM_SWITCH_E_FAILED 	= 0x01	/* The activation of Pretended Networking was not */
};

struct PduInfoType {
	uint8 *SduDataPtr;		/* Pointer to the SDU of the PDU */
	uint8 *MetaDataPtr;		/* Pointer to the meta data of the PDU */
	PduLengthType SduLength;	/* Length of the SDU in bytes */
};

struct RetryInfoType {
	
	enum TpDataStateType TpDataState;	/* The enumeration type to be used to store the state of Tp buffer */
	PduLengthType TxTpDataCnt;		/* Offset from the current position which identifies the number of bytes to be retransmitted */
};

#endif /* COMSTACK_TYPES_H */
