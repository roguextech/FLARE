/*Commands Header*/
#ifndef COMMANDS_H
#define COMMANDS_H

/*Includes------------------------------------------------------------*/
#include "sensors.h"

/*Constants------------------------------------------------------------*/

#define ARM 'r'
#define CAMERAS_ON 'C'
#define CAMERAS_OFF 'O'
#define HALO 'H'
#define SATCOM 's'
#define RESET 'R'
#define PING 'p'
#define MAIN 'm'
#define DROGUE 'd'
#define STATUS 'S'


/*Variables------------------------------------------------------------*/


/*Functions------------------------------------------------------------*/
void doCommand(char command,FlightStates * state, InitStatus *status);
void sendRadioResponse(const char* response);


#endif