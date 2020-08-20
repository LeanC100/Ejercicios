#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int car[25][2];
	car[0][0]= 31;
	car[1][0]= 53;
	car[2][0]= 42;
	car[3][0]= 26;
	car[4][0]= 87;
	car[5][0]= 10;
	car[6][0]= 80;
	car[7][0]= 64;
	car[8][0]= 33;
	car[9][0]= 87;
	car[10][0]= 14;
	car[11][0]= 16;
	car[12][0]= 37;
	car[13][0]= 96;
	car[14][0]= 44;
	car[15][0]= 85;
	car[16][0]= 24;
	car[17][0]= 74;
	car[18][0]= 80;
	car[19][0]= 1;
	car[20][0]= 5;
	car[21][0]= 6;
	car[22][0]= 9;
	car[23][0]= 20;
	car[24][0]= 53;	
	int car_ult=0;
	int carn_ult=0;
	int car_prim=999999;
	int carn_prim=0;

	for (int i = 0; i < 25; i++) 
	{
		printf("Ingrese cuanto tiempo tardo el auto N. %i\n",car[i][0]);
		scanf("%i",&car[i][1]);

		if (car[i][1]<car_prim){ // Busca que auto llego primero
			car_prim=car[i][1];
			carn_prim = car[i][0];
		} 
		if (car[i][1] > car_ult){  // Busca que auto llego ultimo
			car_ult=car[i][1];
			carn_ult= car[i][0];			
		}
	}

	printf("El auto N. %i llego primero\n",carn_prim );
	printf("El auto N. %i llego ultimo\n",carn_ult );
	return 0;
}
