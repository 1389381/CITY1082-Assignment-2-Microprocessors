/*
Main thread launcher for the City 1082 Telemetry project
Each of the RTOS modules will be started by main and then main will sleep forever.
*/

#include "mbed.h"
#include "status.h"
#include "sensors.h"
#include"display.h"

Thread statusHandle;
Thread sensorHandle;
Thread displayHandle;

// main() runs in its own thread in the OS
int main()
{
    statusHandle.start(callback(statusTask));
    sensorHandle.start(callback(readSensorsTask));
    displayHandle.start(callback(displayTask));

    while (true)
    {
        ThisThread::sleep_for(100);
    }
}

