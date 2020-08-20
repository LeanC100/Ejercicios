#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int ncorrredor=0;
	int cant=0;
	int narticle=0;
	float corredor[10][4];
	int article[4];
		article[0]=10;
		article[1]=15;
		article[2]=20;
		article[3]=12;
	int corredor_mas=0;
	int nventa=0;
	float sumt=0;
	float prom=0;
	float aux=0;
	float comi [10];
		comi [0]= 0.05;
		comi [1]= 0.05;
		comi [2]= 0.05;
		comi [3]= 0.08;
		comi [4]= 0.08;
		comi [5]= 0.08;
		comi [6]= 0.10;
		comi [7]= 0.10;
		comi [8]= 0.10;
		comi [9]= 0.12;	

	// Limpieza de vectores
	for (int i = 0; i < 10; i++)
	{	
		corredor[i][3]=i+1;
		for (int j = 0; j < 3; j++)
		{
			corredor[i][j]=0;
		}
	}

	printf("Ingrese el nro de corrredor|1 al 10|(Ingrese 0 para terminar)\n");
	scanf("%i",&ncorrredor );
	while (ncorrredor !=0){
		if (ncorrredor>=1 && ncorrredor<10)
		{
			printf("Ingrese el numero del articulo |1 al 4| \n");
			printf("1. $10     2. $15      3. $20     4. $12\n");
			scanf("%i",&narticle );
			if (narticle >=1 && narticle<=4)
			{
				printf("Ingrese la cantidad de articulos\n");
				scanf("%i",&cant );
					corredor [ncorrredor-1][0] += (article[narticle-1]*cant)+(article[narticle-1]*cant*comi[ncorrredor-1] );  // importe que realizo el corredor
					corredor [ncorrredor -1][1] += (article[narticle-1]*cant*comi [ncorrredor -1]);  // Calculo de cuanto cobra el corredor
					corredor [ncorrredor-1][2]++; // Importe de cuanto vendio cada corredor 
					sumt+= (article[narticle-1]*cant)+(article[narticle-1]*cant*comi [ncorrredor -1]); // suma total 
				if (corredor[ncorrredor-1][2]> corredor[corredor_mas-1][2]) // Busca que corredor vendio mas 
				{
					corredor_mas= ncorrredor;
				}
				nventa++; // aumenta el numero de venta
				printf("-----------------------------------\n");
				printf("Ingrese el nro de corrredor|1 al 10|(Ingrese 0 para terminar)\n");
				scanf("%i",&ncorrredor );
			}else{
				printf("Valor ingresado invalido\n");
				return -1;
			}
		}else{
			printf("Valor ingresado invalido\n");
			return -1;
		}
	}

	// RESPUESTAS
	// 1
	for (int i = 0; i < 10 ; i++)
	{
		if (corredor[i][0] !=0)
		{
			printf("El corredor %i realizo un importe %.2f pesos \n",i+1,corredor[i][0] );
		}
	}
	// 2
	prom= sumt/nventa; // calculo del porcentaje
	printf("El porcentaje que representa es %.2f \n",prom );
	// 3
	for (int i = 0; i < 10; i++)
	{
		if (corredor[i][1]!=0)
		{
			printf("El corredor %i cobra %.2f pesos por comision\n",i+1 , corredor[i][1] );
		}
	}
	// 4
	for (int i = 0; i < 10; i++)
	{
		if (corredor[i][2]!=0)
		{
			printf("El corredor %i vendido %.0f productos\n",i+1,corredor[i][2] );
		}
	}
	// 5
	for (int i = 0; i < 10; i++)
	{
		if (corredor[i][0]!=0)
		{
			prom=(100*corredor[i][0])/sumt;
			printf("El corredor %i tiene un %.2f Porc. de valor vendido\n",i+1, prom );
		}
	}	
	// 6
	printf("El corredor %i vendido mas \n",corredor_mas );
	// 7
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10-i-1; j++)
		{
			if (corredor[j][0] > corredor[j+1][0])
			{
				aux= corredor[j][0];
				corredor[j][0]= corredor[j+1][0];
				corredor[j+1][0]= aux;
				aux=0;
				aux= corredor[j][1];
				corredor[j][1]= corredor[j+1][1];
				corredor[j+1][1]= aux;
				aux=0;
				aux= corredor[j][2];
				corredor[j][2]= corredor[j+1][2];
				corredor[j+1][2]= aux;
				aux=0;
				aux= corredor[j][3];
				corredor[j][3]= corredor[j+1][3];
				corredor[j+1][3]= aux;
			}
		}
	} 
	for (int i = 9; i >= 0; i--)
	
	{
		printf("El corredor %0.f \n",corredor[i][3]);
		printf("   Consigo un monto %.2f de pesos \n", corredor[i][0] );
		printf("   Realizo %0.f facturas\n",corredor[i][2] );
		printf("   Recibio %.2f en comision\n",corredor[i][1] );
	}

	return 0;
}
