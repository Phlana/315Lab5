#include <predef.h>
#include <stdio.h>
#include <ctype.h>
#include <startnet.h>
#include <autoupdate.h>
#include <smarttrap.h>
#include <taskmon.h>
#include <NetworkDebug.h>
#include "error_wrapper.h"
#include "LCD.h"
#include "Keypad.h"
#include "AD.h"
#include "Stepper.h"
#include "Formdata.h"

#define MAX_COUNTER_BUFFER_LENGTH 100

extern "C" {
void UserMain(void * pd);
void DisplayLameCounter( int sock, PCSTR url );
}

extern void RegisterPost();

const char * AppName="Put your name here";

LCD myLCD;
Keypad myKeypad;
AD myAD;
Stepper myStepper;
FormData myData;


void UserMain(void * pd) {
	InitializeStack();
	OSChangePrio(MAIN_PRIO);
	EnableAutoUpdate();
	StartHTTP();
	EnableTaskMonitor();

	#ifndef _DEBUG
	EnableSmartTraps();
	#endif

	#ifdef _DEBUG
	InitializeNetworkGDB_and_Wait();
	#endif

	myStepper.Init(STEPPER_MODE_FULL_STEP);
	myKeypad.Init(KEYPAD_POLL_MODE);  // Interrupts would work too
	myData.Init();
	myLCD.Init();
	myLCD.Clear();
	myAD.Init();
	RegisterPost();

	iprintf("Application started\n");
	while (1) {
		OSTimeDly(TICKS_PER_SECOND);
	}
}

void DisplayLameCounter(int sock, PCSTR url) {
	static int form_counter = 0;
	char buffer[MAX_COUNTER_BUFFER_LENGTH+1];

	if ((sock > 0) && (url != NULL)) {
		iprintf(url);
		snprintf(buffer, MAX_COUNTER_BUFFER_LENGTH, "<H1>The page has been reloaded %d times. </H1>", form_counter);
		form_counter++;
		writestring(sock, (const char *)buffer);
	}
}

void motorHandler(int sock, PCSTR url) {
	char buffer[MAX_COUNTER_BUFFER_LENGTH+1];

	if ((sock > 0) && (url != NULL)) {
		iprintf(url);
		myData.Lock();
		char *motorError = myData.GetMotorErrorMessage();
		myData.Unlock();

		snprintf(buffer, MAX_COUNTER_BUFFER_LENGTH, motorError);
		writestring(sock, (const char *)buffer);
	}
}

void LCDHandler(int sock, PCSTR url) {
	char buffer[MAX_COUNTER_BUFFER_LENGTH+1];

	if ((sock > 0) && (url != NULL)) {
		iprintf(url);
		myData.Lock();
		int LCDError = myData.GetLCDErrorMessage();
		myData.Unlock();

		snprintf(buffer, MAX_COUNTER_BUFFER_LENGTH, LCDError);
		writestring(sock, (const char *)buffer);
	}
}

void keypadHandler(int sock, PCSTR url) {
	char buffer[MAX_COUNTER_BUFFER_LENGTH+1];

	if ((sock > 0) && (url != NULL)) {
		iprintf(url);
		myData.Lock();
		int keypadKey = myData.GetKeypadKey();
		myData.Unlock();

		if (keypadKey < 16) {
			snprintf(buffer, MAX_COUNTER_BUFFER_LENGTH, "<img src=\"Keypad%d.bmp\">", keypadKey);
		}
		else {
			snprintf(buffer, MAX_COUNTER_BUFFER_LENGTH, "<img src=\"Keypad_empty.bmp\">");
		}
		writestring(sock, (const char *)buffer);
	}
}

void ADHandler(int sock, PCSTR url) {
	char buffer[MAX_COUNTER_BUFFER_LENGTH+1];

	if ((sock > 0) && (url != NULL)) {
		iprintf(url);
		myData.Lock();
		char *ADSegment = myData.GetADSegment();
		myData.Unlock();

		snprintf(buffer, MAX_COUNTER_BUFFER_LENGTH, "<img src=\"BarGraph%d.bmp\">", ADSegment);
		writestring(sock, (const char *)buffer);
	}
}
