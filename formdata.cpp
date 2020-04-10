/*
 * FormData.cpp
 *
 *  Created on: Oct 29, 2009
 *      Author: Nancy Minderman
 */


#include <stdlib.h>
#include <string.h>
#include <ucos.h>
#include <stdio.h>
#include <ctype.h>
#include "formdata.h"
#include "Stepper.h"
#include "LCD.h"
#include "Keypad.h"
#include "AD.h"
#include "error_wrapper.h"

/* Name: FormData Constructor
 * Description: Empty Constructor for the class
 * Inputs: 	none
 * Outputs: none
 */

FormData::FormData() {
	// TODO Auto-generated constructor stub

}

/* Name: FormData Destructor
 * Description: Empty Destructor for the class
 * Inputs:	none
 * Outputs: none
 */
FormData::~FormData() {
	// TODO Auto-generated destructor stub
}

/* Name:
 * Description:
 * Inputs:
 * Outputs:
 */
void FormData::SetMotorDirection(char * dir){

}

/* Name:
 * Description:
 * Inputs:
 * Outputs:
 */
BYTE FormData::GetMotorDirection(void){
	return byte_motor_direction;
}

/* Name:
 * Description:
 * Inputs:
 * Outputs:
 */
BYTE FormData::GetMotorMode(void){
	return byte_motor_mode;
}



/* Name:
 * Description:
 * Inputs:
 * Outputs:
 */
void FormData::Init(void){
	BYTE err = OS_NO_ERR;
	err = display_error("DA::Init Sem", OSSemInit(&sem_form,1));
	dword_motor_rotations = 0;
	byte_motor_direction = CLOCKWISE;
	byte_motor_mode = STEPPER_MODE_FULL_STEP;
	str_LCD[0] = '\0';
	byte_keypad_key_number = 16; // 16 means unset should display empty version
	byte_AD_segment = 0;
}




DWORD FormData::GetMotorRotations(void) {
	return dword_motor_rotations;
}

void FormData::SetMotorRotations(char * rot) {

}


void FormData::SetLCDString (char * str){

}

char * FormData::GetLCDString (void){
	return str_LCD;
}

void FormData::SetKeypadKey(BYTE key){
	byte_keypad_key_number = key;
}

BYTE FormData::GetKeypadKey(void){
	return byte_keypad_key_number;

}

void FormData::SetADSegment(BYTE seg){
	byte_AD_segment = seg;

}

BYTE FormData::GetADSegment(void){
	return byte_AD_segment;
}

void FormData::Lock(void){
	display_error("DA::Lock ", OSSemPend(&sem_form, WAIT_FOREVER));
}

void FormData::Unlock(void){
	display_error("DA::Unlock ", OSSemPost(&sem_form));
}
