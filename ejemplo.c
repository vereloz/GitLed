/* Parpadear un led por 5 segundos encendido y 3 segundo apagado*/
//gcc -Wall -pthread -o ejemplo ejemplo.c -lpigpio -lrt
#include <stdio.h>
#include <pigpio.h>


int main (int argc, char*argv[])

{

	if (gpioInitialise()<0) {
			return -1; //Inicializando pigpio
		}

	gpioSetMode(04,PI_OUTPUT);
	gpioSetMode(02,PI_OUTPUT);
	gpioSetMode(14,PI_INPUT);
while(1)
{
		gpioWrite(04,1);
		sleep(5);
	    	gpioWrite(04,0);
		sleep(3);
		if(gpioRead(14)){
		gpioWrite(02,1);
		sleep(2);
		gpioWrite(02,0);
		sleep(3);
		}
}
gpioTerminate();
}
