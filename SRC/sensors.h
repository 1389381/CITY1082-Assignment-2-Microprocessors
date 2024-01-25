#ifndef SENSORS
#define SENSORS
#define VCC P10_0
#define GND P10_3
#define THERMISTOR P10_1

#define SENSOR_RATE 1000

#define THERMISTOR2 P10_2 // Second output of thermistor

#define R_REF 10000   // 10K resistor in potential divider

/* A constant of NCP18XH103F03RB thermistor is */
#define A_COEFF                          (float)(0.0009032679f)
/* B constant of NCP18XH103F03RB thermistor is */
#define B_COEFF                          (float)(0.000248772f)
/* C constant of NCP18XH103F03RB thermistor is */
#define C_COEFF                          (float)(0.0000002041094f)
/* Zero Kelvin in degree C */
#define ABSOLUTE_ZERO                    (float)(-273.15)

void readSensorsTask();
#endif