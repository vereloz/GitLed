/* Parpadear el led 04 por 10 segundos encendido y 5 segundo apagado*/
//gcc -Wall -pthread -o ejemplo ejemplo.c -lpigpio -lrt
#include <stdio.h>
#include <pigpio.h>


int main (int argc, char*argv[])

{

	if (gpioInitialise()<0) {
			return -1; //Inicializando pigpio
		}

	gpioSetMode(04,PI_OUTPUT);

while(1)
{
		gpioWrite(04,1);
		sleep(10);
	        gpioWrite(04,0);
		sleep(5);
}
gpioTerminate();
}
