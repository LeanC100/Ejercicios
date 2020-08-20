#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int cliente[999];
	int nviaje=0;
	int ncliente=0;
	int ncamion=0;
	int camion[8][3];
	int nvalor=0;
	int valor[4][2];
		valor[0][0] =300 ;
		valor[1][0] =250 ;
		valor[2][0] =200 ;
		valor[3][0] =150 ;
	int ncant=0;
	int valor_mas=1;
	char* valor_mas_c[4];
		valor_mas_c[0]="oro";
		valor_mas_c[1]="billetes";
		valor_mas_c[2]="piedras preciosas";
		valor_mas_c[3]="documentos";
	int cliente_menos=1;
	int camion_val1[8];
	float sumt=0;
	float prom=0;
	int aux=0;

	// Limpieza de vectores
	for (int i = 0; i < 8; i++)
	{
		camion[i][0]=i+1;
		for (int j = 1; j < 3; j++)
		{
			camion[i][j]=0;
		}
		camion_val1[i]=0;
	}
	for (int i = 0; i < 4; i++)
	{
		valor[i][1]=0;
	}
	for (int i = 0; i < 999; i++)
	{
		cliente[i]=999999;
	}

	printf("Ingrese el codigo del cliente (Ingrese 0 para terminar)\n");
	scanf("%i", &ncliente);
	while ( ncliente !=0){
		printf("Introduce el numero del camion |1 al 8| \n");
		scanf ("%i", &ncamion);
		if (ncamion>=1 && ncamion<=8)
		{
			printf("Ingrese el codigo del valor transportado |1 al 4|\n");
			printf("codigo del valor         descripcion             costo\n");
			printf("1                        oro                       300\n");
			printf("2                        billetes                  250\n");
			printf("3                        piedras preciosas         200\n");
			printf("4                        documentos                150\n");
			scanf("%i", &nvalor);
			if (nvalor >=1 && nvalor<= 4)
			{
				printf("Ingrese la cantidad que se transporto\n");
				scanf("%i", &ncant);

				camion[ncamion-1][1]++;
				if (nvalor==1)
				{
					camion_val1[ncamion-1]+= ncant;
				}
				valor[nvalor-1][1]+= ncant * valor[nvalor-1][0]; // Indica cuanto gano el dapartamento
				camion[ncamion-1][2]+= ncant * valor[nvalor-1][0];  //Indica cuando gano  el cacmion
				if (valor[nvalor-1][1] > valor [valor_mas-1][1]) // Buscamos el valor mas alto
				{
					valor_mas= nvalor;
				}
				cliente[ncliente]=0;
				cliente[ncliente] =ncant * valor[nvalor-1][0]; // Indicamos cuanto gano el cliente
				if (cliente[ncliente] < cliente[cliente_menos]) // Buscamos que cliente 
				{
					cliente_menos= ncliente;
				}
				sumt+=ncant * valor[nvalor-1][0]; // suma total del valor total
				nviaje++; // agrega un +1 a los viajes realizados
				printf("--------------------------------------\n");
				printf("Ingrese el codigo del cliente (Ingrese 0 para terminar)\n");
				scanf("%i", &ncliente);
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
	for (int i = 0; i < 8; i++)
	{
		if (camion[i][1]!=0)
		{
			printf("En el camion %i se realizo %i viajes \n",i+1, camion[i][1] );
		}
	}
	// 2
	for (int i = 0; i < 8; i++)
	{
		if (camion_val1[i]!=0)
		{
			printf("El camion %i transporto %i productos del valor 1\n",i+1, camion_val1[i]);
		}
	}
	// 3
	for (int i = 0; i < 4; i++)
	{
		if (valor[i][1]!=0)
		{
			printf("El valor %i recaudo %i pesos\n",i+1,valor[i][1] );
		}
	}
	// 4
	for (int i = 0; i < 8; i++)
	{
		if (camion[i][2] !=0)
		{
			printf("El camion %i recaudo %i pesos\n",i+1,camion[i][2] );
		}
	}
	// 5
	printf("El %s es el valor mas transportado\n",valor_mas_c [valor_mas-1] );
	// 6
	printf("El codigo cliente %i es el que menos transporto en un viaje\n",cliente_menos );
	// 7
	for (int i = 0; i < 8; i++)
	{
		if (camion[i][2]!=0)
		{
			prom= (100*camion[i][2])/ sumt;
			printf("El camion %i tiene un %.2f Porc. sobre el total\n",i+1, prom );
		}
	}
	// 8 
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8-i-1; j++)
		{
			if (camion[j][1] > camion[j+1][1])
			{
				aux= camion[j][0];
				camion[j][0]= camion[j+1][0];
				camion[j+1][0]= aux;
				aux=0;
				aux= camion[j][1];
				camion[j][1]= camion[j+1][1];
				camion[j+1][1]= aux;
				aux=0;
				aux= camion[j][2];
				camion[j][2]= camion[j+1][2];
				camion[j+1][2]= aux;
			}
		}
	} 	
	for (int i = 0; i < 8; i++)
	{
		printf("El camion %i\n",camion[i][0] );
		printf("     Realizo %i viajes \n",camion[i][1] );
		printf("     Y recaudo %i pesos\n", camion[i][2]);
	}
	return 0;
}
