/*
 * Stepper.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: nem
 */


#include <basictypes.h>
#include <pins.h>
#include <predef.h>
#include <stdio.h>
#include <ctype.h>
#include <startnet.h>
#include "Stepper.h"

Stepper::Stepper() {
	// TODO Auto-generated constructor stub

}

Stepper::~Stepper() {
	// TODO Auto-generated destructor stub
}

void Stepper::Step(BYTE direction, WORD steps) {

	Enable(); // motor should only be on when moving

	// Insert Exercise 2 code here

	Disable(); // once movement is over turn the motor off

}

void Stepper::Init(BYTE mode) {

	// Insert Exercise 2 code here

}

void Stepper::Enable(void) {
	// Insert Exercise 2 code here
}

void Stepper::Disable(void) {
	// Insert Exercise 2 code here
}

void Stepper::SetDirection(BYTE dir) {
	// Insert Exercise 2 code here
}

BYTE Stepper::GetDirection(void) {
	return direction;
}

void Stepper::SetMode(BYTE mode){

	// Insert Execise 2 code here
}

BYTE Stepper::GetMode(void) {
	return motor_mode;
}

BYTE Stepper::GetState(void) {
	return state;
}
