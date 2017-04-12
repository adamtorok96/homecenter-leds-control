#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>
#include <softPwm.h>

//12
#define PIN_RED 19
#define PIN_GREEN 13
#define PIN_BLUE 14

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
    printf("Led(%d): %d\n", PIN_RED, value);
#elif GREEN
    softPwmCreate(PIN_GREEN, 0, 100);
    softPwmWrite(PIN_GREEN, value);
    printf("Led(%d): %d\n", PIN_GREEN, value);
#elif BLUE
    softPwmCreate(PIN_BLUE, 0, 100);
    softPwmWrite(PIN_BLUE, value);
    printf("Led(%d): %d\n", PIN_BLUE, value);
#endif

    delay(50);

    return 0;
}
