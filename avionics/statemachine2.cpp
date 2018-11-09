/*State Machine Source*/

/*Includes------------------------------------------------------------*/
#include "statemachine.h2"

#include <Arduino.h>
#include <SD.h>

/*Variables------------------------------------------------------------*/
File statelog;
FlightStates state = STANDBY;

/*Functions------------------------------------------------------------*/

void switchState(FlightStates new_state){
    state = new_state;
}

void stateMachine(float altitude, float delta_altitude) { 
    static int coast_count, main_count, land_count, apogee_count = 0;

    switch (state) {
        case STANDBY:
            if (altitude > (threshold + 200)) {
                switchState(POWERED_ASCENT);
            }
            break;

        case ARMED:
            if ((abs_accel > LAUNCH_THRESHOLD) || launch_interrupt_flag) {
                switchState(POWERED_ASCENT);
            }
            break;

        case ASCENT:
            if (abs_accel < COAST_THRESHOLD) {
                coast_count++;
                if (coast_count >= COAST_CHECKS) {
                    switchState(APOGEE_DETECT);
                    coast_count = 0;
                }
            } else {
                coast_count = 0;
            }
            break;

        case MACH_LOCK:
            if (delta_altitude < 0) {
                apogee_count ++;
                if (apogee_count >= APOGEE_CHECKS) {
                    //deploy drogue and payload
                    //delay to avoid pressure spikes
                    switchState(INITIAL_DESCENT);
                    apogee_count = 0;
                }
            } else {
                apogee_count = 0;
            }
            break;

        case INITIAL_DESCENT:
            if (altitude < FINAL_DESCENT_THRESHOLD) {
                main_count ++;
                if (main_count >= MAIN_CHECKS) {
                    //deploy main
                    switchState(FINAL_DESCENT);
                }
            } else {
                main_count = 0;
            }
            break;

        case FINAL_DESCENT:
            if (abs_accel > LANDING_THRESHOLD_LOW && abs_accel < LANDING_THRESHOLD_HIGH && altitude < LAND_HEIGHT_THRESHOLD) {
                land_count++;
                if (land_count >= LAND_CHECKS) {
                    //turn off sensors except GPS
                    switchState(LANDED);
                }
            } else {
                land_count = 0;
            }
            break;

        case LANDED:
            break;

        default:
            break;
    }
}