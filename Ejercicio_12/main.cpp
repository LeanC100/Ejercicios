#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int boleta[999];
	int nboleta=0;	
	int nestacion=0;
	float estacion[20][4];
	int ncombust=0;
	float combust[3][2];
		combust[0][0]=1.50;
		combust[1][0]=1.30;
		combust[2][0]=1.10;
	int est1_mas =1;
	char* est_mas_c[2];
		est_mas_c[0]="no";
		est_mas_c[1]="si";
	int boleta_mayor=1;
	int ncant=0;
	int aux=0;

	for (int i = 0; i < 3; i++)
	{
		combust[i][1]=0;
	}
	for (int i = 0; i < 999; i++)
	{
		boleta[i]=0;
	}
	for (int i = 0; i < 20; i++)
	{
		estacion[i][3]=i+1;
		for (int j = 0; j < 3; j++)
		{
			estacion[i][j]=0;
		}
	}

	printf("Ingrese el numero de boleta (Ingrese el numero 99 para finalizar)\n");
	scanf("%i", &nboleta );
	while (nboleta!=99){
		printf("Ingrese el numero de estacion|1 al 20| \n");
		scanf("%i", &nestacion );
		if (nestacion>=1 && nestacion<=20)
		{
			printf("Ingrese el tipo de combustible \n");
			printf("Tipo                     descripcion             sueldo\n");
			printf("1                        ecologica               1,50\n");
			printf("2                        super                   1,30\n");
			printf("3                        comun                   1,10\n");
			scanf("%i", & ncombust);
			if (ncombust >=1 && ncombust<=3)
			{

				printf("Ingrese la cantidad de litros que desea llevar\n");
				scanf("%i", &ncant );
				estacion[nestacion-1][0]+= ncant;
				estacion[nestacion-1][1]+= ncant * combust[ncombust-1][0];
				estacion[nestacion-1][2]++;
				combust[ncombust-1][1]+= ncant;
				boleta[nboleta]=ncant * combust[ncombust-1][0];
				printf("----------------------------------------------------------\n");
				printf("Ingrese el numero de boleta (Ingrese el numero 99 para finalizar)\n");
				scanf("%i", &nboleta );
				if (estacion[nestacion][0]< estacion[1][0])
				{
					est1_mas=1;
				}else {
					est1_mas=0;
				}
				if (boleta[nboleta]>boleta[boleta_mayor])
				{
					boleta_mayor=nboleta;
				}
			}else{
				printf("Valor ingresado invalido\n");
				return -1;
			}
		}else{
			printf("Valor ingresado invalido\n");
			return -1;
		}
	}

	// 1
	for (int i = 0; i < 20 ; i++)
	{
		if (estacion[i][0]!=0)
		{
			printf("La estacion %i vendio %.0f litros\n",i+1,estacion[i][0] );
		}
	}
	// 2
	for (int i = 0; i < 20; i++)
	{
		if (estacion[i][1]!=0)
		{
			printf("La estacion %i recaudo %.2f pesos\n",i+1,estacion[i][1] );
		}
	}
	// 3
	for (int i = 0; i < 20; i++)
	{
		if (estacion[i][2]!=0)
		{
			printf("En la estacion %i se emitieron %.0f boletos\n",i+1,estacion[i][2] );
		}
	}
	// 4
	for (int i = 0; i < 3; i++)
	{	
		if (combust[i][1]!=0)
		{
			printf("En el tipo de combustible N. %i se vendieron %.0f litros\n",i+1,combust[i][1] );
		}
	}
	// 5
		printf("La estacion N. 1 %s fue la que mas recaudo\n", est_mas_c[est1_mas-1]);
	// 6
	printf("El numero de boleto N. %i tiene el mayor importe \n",boleta[boleta_mayor] );
	// 7
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20-i-1; j++)
		{
			if (estacion[j][1] > estacion[j+1][1])
			{
				aux= estacion[j][0];
				estacion[j][0]= estacion[j+1][0];
				estacion[j+1][0]= aux;
				aux=0;
				aux= estacion[j][1];
				estacion[j][1]= estacion[j+1][1];
				estacion[j+1][1]= aux;
				aux=0;
				aux= estacion[j][2];
				estacion[j][2]= estacion[j+1][2];
				estacion[j+1][2]= aux;
				aux=0;
				aux= estacion[j][3];
				estacion[j][3]= estacion[j+1][3];
				estacion[j+1][3]= aux;
			}
		}
	} 
	for (int i = 0; i < 20 ; i++)
	{
		printf("La estacion %.0f \n",estacion[i][3] );
		printf("     Vendio %.0f litros\n",estacion[i][0]);
		printf("     Recaudo %.2f pesos\n",estacion[i][1] );
		printf("     Emitio %.0f boletas\n", estacion[i][2]);
	}
	return 0;
}
