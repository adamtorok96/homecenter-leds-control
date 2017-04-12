#include <stdlib.h>

#include <wiringPi.h>
#include <softPwm.h>

int main(int argc, char * args[]) {

    if( argc != 2 )
        return 1;

    if( wiringPiSetupSys() == -1 )
        return 1;

    int value = atoi(args[1]);

    if( value < 0 || value > 100 )
        return 1;

#ifdef RED
    softPwmCreate(12, 0, 100);
    softPwmWrite(12, value);
#elif GREEN
    softPwmCreate(13, 0, 100);
    softPwmWrite(13, value);
#elif BLUE
    softPwmCreate(14, 0, 100);
    softPwmWrite(14, value);
#endif

    return 0;
}
