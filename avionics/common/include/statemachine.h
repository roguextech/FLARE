/*
 * State Machine Header
 *
 * @file    statemachine.h
 * @author  UBC Rocket Avionics 2018/2019
 * @description   Main state machine of the rocket's flight states.
 * Implements state switching and the rocket's state machine.
 *
 * @section LICENSE
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * Distributed as-is; no warranty is given.
 */

#pragma once

/*Constants------------------------------------------------------------*/
// Polling time changes
constexpr unsigned int LANDED_POLLING_TIME_INTERVAL = 5000; // ms
constexpr unsigned int NOMINAL_POLLING_TIME_INTERVAL = 50;  // ms
