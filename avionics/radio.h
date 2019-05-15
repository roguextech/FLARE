/*Radio Header*/
#ifndef __RADIO_H__
#define __RADIO_H__

/*Includes------------------------------------------------------------*/
#include <Arduino.h>
#include <stdint.h>

#include "statemachine.h"
#include "sensors.h"
#include "XBee.h"
#include "commands.h"

/*Constants------------------------------------------------------------*/
/*radio data unique identifiers*/
const char UID_acc_acc_x  = 'X'; //Accelerometer - Acceleration X
const char UID_acc_acc_y  = 'Y'; //Accelerometer - Acceleration Y
const char UID_acc_acc_z  = 'Z'; //Accelerometer - Acceleration Z
const char UID_bar_pres  = 'P'; //Barometer - Pressure
const char UID_bar_temp  = '~'; //Barometer - Temperature
const char UID_temp_temp  = 'T'; //Temperature Sensor - Temperature
const char UID_IMU_yaw  = '@'; //IMU - Yaw
const char UID_IMU_roll  = '#'; //IMU - Roll
const char UID_IMU_pitch  = '$'; //IMU - Pitch
const char UID_GPS_lat  = 'L'; //GPS - Latitude
const char UID_GPS_long  = 'l'; //GPS - Longitude
const char UID_GPS_alt  = 'A'; //GPS - Altitude
const char UID_time  = 't'; //Time
const char UID_altitude = 'a'; //calculated altitude
const char UID_state = 's'; //state machine state
const char UID_batt = 'b';  //Battery voltage
const char UID_ground_altitude = 'g';//Ground Altitude
const char UID_status = 'S';  //Status

#define GROUND_STATION_ADDR_MSB 0x0013A200
#define GROUND_STATION_ADDR_LSB 0x41678FC0

/*Functions------------------------------------------------------------*/
void sendRadioData(float data, char id);
void sendTierOne(unsigned long*, float*, float*, FlightStates state, float altitude);
void sendTierTwo(float*, float*, float*, float*);
void sendTierThree(float*, float*);
void bodyTierOne(XBee* radio, ZBTxRequest* txPacket, float*, FlightStates state, float altitude, uint32_t*);
//void bodyTierTwo(float*); not needed
void noseconeTierOne(XBee* radio, ZBTxRequest* txPacket, float* GPS_data,
                     float bar_data[], float acc_data[], float *temp_sensor_data, float IMU_data[]);
// void noseconeTierTwo(float*, float*, float*, float*);

void resolveRadioRx(XBee* radio, FlightStates *state, InitStatus *status);

#endif
