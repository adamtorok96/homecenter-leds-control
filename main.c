#include <stdlib.h>

#include <wiringPi.h>
#include <softPwm.h>

#define PIN_RED 10
#define PIN_GREEN 9
#define PIN_BLUE 11

int main(int argc, char * args[]) {

    if( argc != 2 )
        return 1;

    if( wiringPiSetupSys() == -1 )
        return 1;

    int value = atoi(args[1]);

    if( value < 0 || value > 100 )
        return 1;

#ifdef RED
    softPwmCreate(PIN_RED, 0, 100);
    softPwmWrite(PIN_RED, value);
#elif GREEN
    softPwmCreate(PIN_GREEN, 0, 100);
    softPwmWrite(PIN_GREEN, value);
#elif BLUE
    softPwmCreate(PIN_BLUE, 0, 100);
    softPwmWrite(PIN_BLUE, value);
#endif

    return 0;
}
