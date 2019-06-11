/*
 * Std_Types.h
 *
 *  Created on: 10-Jun-2019
 *      Author: Atul
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Communication related basic software module */
#include"Platform_Types.h"
#include"Compiler.h"

typedef uint8 Std_ReturnType;
typedef unsigned char StatusType;

/**** Symbol Definitions ****/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u
#endif

#define E_NOT_OK 0x01u

/* Physical state 5V or 3.3V */
#define STD_HIGH 0x01u
/* Physical state 0V */
#define STD_LOW 0x00
/* Logical state active */
#define STD_ACTIVE 0x01u
/* Logical state idle */
#define STD_IDLE 0x00u

#define STD_ON 0x01u
#define STD_OFF 0x00u

/**** Type Definition ****/
struct Std_VersionInfoType {
	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
};



#endif /* STD_TYPES_H */
