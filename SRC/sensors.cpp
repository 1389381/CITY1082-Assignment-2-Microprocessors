/*
Read the sensors and store in our telemetry data packet 
*/

#include "mbed.h"
#include "sensors.h"
#include "config.h"
#include "display.h"

void readSensorsTask()
{
    message_t myMessage;
    DigitalOut vcc(VCC);
    DigitalOut gnd(GND);
    AnalogIn tempVolts(THERMISTOR);
    //AnalogIn therm(THERMISTOR2);
    vcc = 1;
    gnd = 0;
    float temperatureVoltage;
    
    while(true)
    {
      temperatureVoltage = tempVolts.read();
        float thermVolts = temperatureVoltage * 2.4; //Convert adc reading to volts
        float current = (3.3 - thermVolts) / R_REF; //3.3V input minus the output voltage from the thermistor / by the resistor in potential divider
        float thermResistance = (thermVolts / current); //Ohms Law to get resistance

    float logrT = (float32_t)log((float64_t)thermResistance);

        /* Calculate temperature from the resistance of thermistor using
        * Steinhart-Hart Equation */
        float stEqn = (float32_t)((A_COEFF) + ((B_COEFF)*logrT) +
                                  ((C_COEFF)*pow((float64)logrT, (float32)3)));
        float temperatureC = (float32_t)(((1.0 / stEqn) + ABSOLUTE_ZERO) + 0.05);

        //printf("The temp Voltage is: %2.2f \n", temperatureVoltage);  //prints temp voltage
        sprintf( myMessage.buffer, "The Temperature is: %2.2f C \n", temperatureC);  //prints temperature
        myMessage.displayType = TEMP_DISPLAY;
        queueMessage(myMessage);
        ThisThread::sleep_for(SENSOR_RATE);
    }
}