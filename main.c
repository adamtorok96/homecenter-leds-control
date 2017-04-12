#include <cstdlib>

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
    softPwmWrite(0, value);
#elseif GREEN
    softPwmWrite(0, value);
#elseif BLUE
    softPwmWrite(0, value);
#else

    return 0;
}
