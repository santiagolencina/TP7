#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "inc/my_watch.h"










void test_SetUp_CorrectTime(void) {



    my_watch_t watch = CreateWatch(1000);

    static uint8_t time_set[] = {0, 8, 1, 2, 3, 5};



    do {if ((SetUpTime(watch,time_set, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(50)));}} while(0);

}



void test_SetUp_IncorrectTime(void) {



    my_watch_t watch = CreateWatch(1000);

    static uint8_t time_set[] = {4, 8, 1, 2, 3, 5};



    do {if (!(SetUpTime(watch,time_set, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(58)));}} while(0);

}



void test_GetTime(void) {



    my_watch_t watch = CreateWatch(1000);

    static uint8_t time_set[] = {1, 2, 3, 0, 1, 5};

    uint8_t time[6];



    SetUpTime(watch,time_set, 6);

    GetTime(watch, time, 6);

    UnityAssertEqualIntArray(( const void*)((time_set)), ( const void*)((time)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_SetUpAlarm(void) {



    my_watch_t watch = CreateWatch(1000);

    static uint8_t time_set[] = {1, 0, 0, 0, 0, 0};

    uint8_t alarm[6] = {1, 0, 0, 0, 0, 0};



    SetUpTime(watch,time_set, 6);

    SetUpAlarm(watch, alarm, 6);



    do {if ((EnableAlarm(watch, 

   1

   ))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(81)));}} while(0);

    do {if ((AlarmRinging(watch))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(82)));}} while(0);

}



void test_snoozealarm(void) {



    my_watch_t watch = CreateWatch(1000);

    static uint8_t time_set[] = {1, 0, 0, 0, 0, 0};

    uint8_t alarm[6] = {1, 0, 0, 0, 0, 0};



    SetUpTime(watch,time_set, 6);

    SetUpAlarm(watch, alarm, 6);



    do {if ((EnableAlarm(watch, 

   1

   ))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(94)));}} while(0);

    do {if ((AlarmRinging(watch))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(95)));}} while(0);

    do {if ((SnoozeAlarm(watch, 5))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(96)));}} while(0);

    do {if (!(AlarmRinging(watch))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(97)));}} while(0);



}
