#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int noperacion=0;
	int nsucursal=0;
	int ttransaccion;
	int transaccion[10][2];
	int monto=0;
	int n=0;

	// Limpieza de vectores
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			transaccion[i][j]=0;
		}
	}

	printf("Ingrese el numero de operacion (Ingrese 0 para terminar)\n");
	scanf("%i", &noperacion);
	while(noperacion!=0){
		printf("Ingrese el numero de la sucursal(1 al 10)\n");
		scanf("%i", &nsucursal);
		if (nsucursal >=1 && nsucursal <10)
		{
			printf("Ingrese el tipo de transaccion\n" );
			printf("1. deposito          2. extraccion\n");
			scanf("%i", &ttransaccion);
			if (ttransaccion>=1 && ttransaccion<=2)
			{
				printf("Ingrese el monto que desea depositar \n");
				scanf("%i", &monto);	
				transaccion[nsucursal-1][ttransaccion-1]+=monto; // Añadimos la cantidad que se deposito
				printf("---------------------------------------\n");
				printf("Ingrese el numero de operacion (Ingrese 0 para terminar)\n");
				scanf("%i", &noperacion);
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
		for (int i = 0; i < 10; i++)
		{
			if (transaccion[i][1]!=0)
			{
				printf("El la sucursal %i se recaudo %i pesos en consepto de extraccion\n",i+1,transaccion[i][1] );
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (transaccion[i][0]!=0)
			{
			printf("En la sucursal %i se recaudo %i pesos en consepto de deposito\n",i+1,transaccion[i][0] );
			}
		}
		printf("Las surcusales en la que se extrajo mas de lo que se deposito es: \n");
		for (int i = 0; i < 10; i++)
		{
			if (transaccion[i][0]< transaccion[i][1])
			{
				printf("En la sucursual N. %i\n",i+1 );
				n=1;
			}else if (n==0 && i==9){
				printf("En ninguna sucursal \n");
			}
		}


	return 0;
}
