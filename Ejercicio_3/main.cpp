#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int car[25];
	int car_ult=0;
	int carn_ult=0;
	int car_prim=999999;
	int carn_prim=0;

	for (int i = 0; i < 25; i++)
	{
		printf("Ingrese cuanto tiempo tardo el auto N. %i\n", i+1);
		scanf("%i",&car[i]);

		if (car[i]<car_prim){ // Busca el auto que llego primero
			car_prim=car[i];
			carn_prim = i+1;
		} 
		if (car[i] > car_ult){ // Busca el auto que llego ultimo
			car_ult=car[i];
			carn_ult= i+1;			
		}
	}

	printf("El auto N. %i llego primero\n",carn_prim );
	printf("El auto N. %i llego ultimo\n",carn_ult );
	return 0;
}
