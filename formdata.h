/*
 * FormData.h
 *
 *  Created on: Oct 29, 2009
 *      Author: Nancy Minderman
 */

#ifndef FORMDATA_H_
#define FORMDATA_H_

#include <basictypes.h>
#include <ucos.h>
#include "LCD.h"

#ifndef LCD_STRING_LENGTH
#define LCD_STRING_LENGTH 48
#endif

class FormData {
public:
	FormData();
	virtual ~FormData();

	void Init(void);

	// Motor Info
	void SetMotorRotations(char * rot);
	DWORD GetMotorRotations(void);
	void SetMotorDirection(char * dir);
	BYTE GetMotorDirection(void);
	void SetMotorMode(BYTE mode);
	BYTE GetMotorMode(void);

	// LCD Info
	void SetLCDString (char * str);
	char * GetLCDString (void);

	// Keypad Info
	void SetKeypadKey(BYTE key);
	BYTE GetKeypadKey(void);

	// AD segment info for bar graph display
	void SetADSegment(BYTE seg);
	BYTE GetADSegment(void);

	// Lock/Unlock methods for resource management
	void Lock(void);
	void Unlock(void);

private:
	DWORD	dword_motor_rotations;
	BYTE 	byte_motor_direction;
	BYTE 	byte_motor_mode;
	char 	str_LCD[LCD_STRING_LENGTH + 1];
	BYTE 	byte_keypad_key_number;
	BYTE 	byte_AD_segment;
	OS_SEM 	sem_form;
};

#endif /* FORMDATA_H_ */
