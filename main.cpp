/*!****************************************************************************
 * @file main.cpp
 * @brief Activate the alarm when gas or overTemperature is detected
 * This program was built and tested on the NUCLEO F429ZI ARMC6,
 * connected to a Dip Switch and it takes care of turning on and off
 * the LED1 based on the selected state of the dip switch. Additionally,
 * it prints in the terminal the states of the pins
 * The pins is set into a PullDown mode so the dip switch should be connected 
 * to 3.3V pin
 * There is an OFF combination of buttons to set the alarm state to OFF and so its pin LED
 * @author Quattrone Martin
 * @author Vazquez Rodrigo
 *******************************************************************************/

#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2);
    DigitalIn overTempDetector(D3);
    DigitalIn aButton(D4);
    DigitalIn bButton(D5);
    DigitalIn cButton(D6);
    DigitalIn dButton(D7);

    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);
    overTempDetector.mode(PullDown);
    aButton.mode(PullDown);
    bButton.mode(PullDown);
    cButton.mode(PullDown);
    dButton.mode(PullDown);

    alarmLed = OFF;

    bool alarmState = OFF;

    while (true) 
    {

        if ( gasDetector || overTempDetector ) 
        {
            alarmState = ON;
            printf("if ( gasDetector || overTempDetector ) \n");                    //!< The state of the pins are printed
            printf("%s = %d\n","gasDetector = ", gasDetector.read());
            printf("%s = %d\n","overTempDetector = ", overTempDetector.read());
            printf("%s = %d\n","alarmState = ", alarmState);
        }

        alarmLed = alarmState;

        if ( aButton && bButton && !cButton && !dButton) 
        {
            alarmState = OFF;
            printf("if ( alarmOffButton ) \n");                                     //!< The state of the pins are  printed
            printf("%s = %d\n","gasDetector = ", gasDetector.read());
            printf("%s = %d\n","overTempDetector = ", overTempDetector.read());
            printf("%s = %d\n","alarmState = ", alarmState);
        }
    }
}