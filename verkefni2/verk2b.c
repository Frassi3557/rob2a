#pragma config(Sensor, dgtl5,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, /*reversed*/)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//#define BASEROTATION 490
#include "header.h"
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|                                                 *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|                                                                        *|
|*
			Program drives robot forwards half a metre, back half a metre, then 1 metre forward etc..
			until it has reached a distance of 2,5 metres forwards and backwards.
*|
\*-----------------------------------------------------------------------------------------------4246-*/

void drive_forward(int k){
	while(abs(SensorValue[leftEncoder]) < (BASEROTATION * k))
  {
    //...Move Forward
    motor[rightMotor] = POWER;
    motor[leftMotor] = POWER;
  }
}
void drive_back(int k){
	while(abs(SensorValue[leftEncoder]) < (BASEROTATION * k))
  {
    //...Move Forward
    motor[rightMotor] = -POWER;
    motor[leftMotor] = -POWER;
  }
}
void stop_rob(){
	motor[rightMotor] = 0;		  // Motor is stop
	motor[leftMotor]  = 0;
	wait1Msec(500);
}
void reset_encoder(){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
}


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  wait1Msec(1000);  // 1 Second Delay

  //Clear Encoders


	for(int i = 1;i < 6; i++) {
		reset_encoder();
		drive_forward(i);//drives the distance forward
		stop_rob();//stops so it does not change direction
		reset_encoder();
		drive_back(i);//drives back to starting point
		stop_rob();
	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
