/*
 * Stepper.h
 *
 *  Created on: Nov 1, 2016
 *      Author: nem
 */

#ifndef STEPPER_H_
#define STEPPER_H_

#include <basictypes.h>

#define STEPPER_MODE_FULL_STEP 0
#define STEPPER_MODE_HALF_STEP 1

#define STEPPER_OFF 0
#define STEPPER_ON 	1

#define STEPS_PER_ROTATION_FULL_STEP_MODE 100
#define STEPS_PER_ROTATION_HALF_STEP_MODE 200

#define CLOCKWISE 1
#define COUNTER_CLOCKWISE 0

#define STEPPER_ENABLE  J2[37]
#define STEPPER_MODE 	J2[38]
#define STEPPER_CLK 	J2[39]
#define STEPPER_DIR 	J2[40]


class Stepper {
public:
	Stepper();
	virtual ~Stepper();


	void Step(BYTE direction, WORD steps);

	void Disable(void);

	void Enable(void);

	BYTE GetState(void);

	void SetMode (BYTE mode);

	BYTE GetMode(void);

	void SetDirection(BYTE direction);

	BYTE GetDirection(void);

	void Init(BYTE mode);
private:
	BYTE state; 		// running or stopped
	BYTE motor_mode;	// half or full
	BYTE direction; 	// CW or CCW

};

#endif /* STEPPER_H_ */
