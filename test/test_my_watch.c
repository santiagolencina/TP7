/* Copyright 2022, Laboratorio de Microprocesadores
 * Facultad de Ciencias Exactas y Tecnología
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2022, Lencina Martinez Luis Santiago
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS  "
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/* === Headers files inclusions =============================================================== */



#include "my_watch.h"
#include "unity.h"
#include <stdint.h>
#include <string.h>



void test_SetUp_CorrectTime(void) {

    my_watch_t watch = CreateWatch(CLOCK_SEC);
    static uint8_t time_set[] = {0, 8, 1, 2, 3, 5}; // 08:12:35

    TEST_ASSERT_TRUE(SetUpTime(watch,time_set, 6)); 
}

void test_SetUp_IncorrectTime(void) {

    my_watch_t watch = CreateWatch(CLOCK_SEC);
    static uint8_t time_set[] = {4, 8, 1, 2, 3, 5}; // 48:12:35

    TEST_ASSERT_FALSE(SetUpTime(watch,time_set, 6)); 
}

void test_GetTime(void) {

    my_watch_t watch = CreateWatch(CLOCK_SEC);
    static uint8_t time_set[] = {1, 2, 3, 0, 1, 5}; // 12:30:15
    uint8_t time[6];

    SetUpTime(watch,time_set, 6); 
    GetTime(watch, time, 6);   
    TEST_ASSERT_EQUAL_UINT8_ARRAY(time_set, time, 6); 
}

void test_SetUpAlarm(void) {

    my_watch_t watch = CreateWatch(CLOCK_SEC);
    static uint8_t time_set[] = {1, 0, 0, 0, 0, 0}; //  10:00:00
    uint8_t alarm[6] = {1, 0, 0, 0, 0, 0};          //  10:00:00

    SetUpTime(watch,time_set, 6);   
    SetUpAlarm(watch, alarm, 6); 

    TEST_ASSERT_TRUE(EnableAlarm(watch, true));     //  turn on the alarm
    TEST_ASSERT_TRUE(AlarmRinging(watch));          //  alarm ringing
}

void test_snoozealarm(void) {

    my_watch_t watch = CreateWatch(CLOCK_SEC);
    static uint8_t time_set[] = {1, 0, 0, 0, 0, 0}; //  10:00:00
    uint8_t alarm[6] = {1, 0, 0, 0, 0, 0};          //  10:00:00

    SetUpTime(watch,time_set, 6);   
    SetUpAlarm(watch, alarm, 6);

    TEST_ASSERT_TRUE(EnableAlarm(watch, true));                 //  turn on the alarm
    TEST_ASSERT_TRUE(AlarmRinging(watch));                      //  alarm ringing
    TEST_ASSERT_TRUE(SnoozeAlarm(watch, SNOOZE_TIME_MINUTES));  //  snooze alarm
    TEST_ASSERT_FALSE(AlarmRinging(watch));                     //  alarm is not ringing

}