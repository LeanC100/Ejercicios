#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	char name_empl[50];
	int ncat=0;
	int cat[4][3];
		cat[0][0]=2500;
		cat[1][0]=2000;
		cat[2][0]=1500;
		cat[3][0]= 800;		
	int ndepart=2;
	int depart[3];
	int cat_mas_cobra=1;
	int cat_menos_empl=1;
	int depart_men=1;
	int sueldo=0;
	int aux=0;
	// Limpieza de vectores
	for (int i = 0; i < 3; i++)
	{
		depart[i]=0;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			cat[i][j]=0;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (ndepart >=1 && ndepart <=3)
		{
			printf("Ingrese el nomrbre del empleado N. %i\n", i+1);
			scanf("%s", name_empl);
			printf("Ingrese la categoria a la que pertenece\n");
			printf("nro de categoria          descripcion             saldo\n");
			printf("1                        analista senior          2500\n");
			printf("2                        analista junior          2000\n");
			printf("3                        programador              1500\n");
			printf("4                        operador                  800\n");
			scanf("%i", &ncat);
			if (ncat >=1 && ncat <=4)
			{
				printf("Ingresa el numero del departamento del empleado |1-2-3|\n");
				scanf("%i",&ndepart );

				switch (ndepart){ // el Nro de de depto y marcamos a que categoria pertenece
					case 1: depart[0] += cat[ncat-1][0]; break;
					case 2: depart[1] += cat[ncat-1][0]; break;
					case 3: depart[2] += cat[ncat-1][0]; break;
				}
				switch (ncat){
					case 1: cat[0][1] += cat[ncat-1][0];
					cat[0][2]++; break;
					case 2: cat[1][1] += cat[ncat-1][0];
					cat[1][2]++; break;
					case 3: cat[2][1] += cat[ncat-1][0];
					cat[2][2]++; break;
					case 4: cat[3][1] += cat[ncat-1][0];
					cat[3][2]++; break;
				}
				if (cat[ncat-1][1]> cat[cat_mas_cobra-1][1]) // Busca que cat vandio mas
				{
					cat_mas_cobra= ncat;
				}
				if (depart[ndepart-1]< depart[depart_men-1]) // Busca que depart con menos cobra
				{
					depart_men= ndepart;
				}
				sueldo++;
				if (cat[ncat-1][2] < cat[cat_menos_empl-1][2]) // Busca qque categoria tiene menos empleados
				{
					cat_menos_empl= ncat;
				}				

			printf("--------------------------------------------------------\n");
			}else{
				printf("Valor ingresado invalido\n");
				return -1;
			}
		}else{
			printf("Valor ingresado invalido\n");
			return -1;
		}
	}

	// RESPUESTA
	// 1
	for (int i = 0; i < 3; i++)
	{
		if (depart[i]!=0)
		{
			printf("El departamento %i debe pagar %i en sueldos \n",i+1, depart[i]);
		}
	}
	// 2
	for (int i = 0; i < 4; i++)
	{	
		if (cat[i][1]!=0)
		{
			printf("En la categoria %i se debe pagar %i en sueldos \n",i+1 ,cat[i][1]);
		}
	}
	// 3
	printf("La categoria que cobra mas es la categoria %i\n", cat_mas_cobra );
	// 4
	printf("El departamento que cobra menos es el departamento %i\n", depart_men );
	// 5
	for (int i = 0; i < 4; i++)
	{
		if (cat[i][2]!=0)
		{
			printf("En la categoria %i hay %i empleados\n",i+1,cat[i][2] );
		}
	}
	// 6
	printf("La empresa debe pagar %i sueldos\n",sueldo);
	// 7
	printf("La categoria %i tiene menos empleados\n",cat_menos_empl );
	// 8
	for (int i = 0; i < 3; i++)
	{
		printf("En la cat %i\n", i+1);
		printf("     Se debe pagar %i pesos\n",cat[i][1] );
		printf("     En %i empleados\n",cat[i][2]);
	}


	return 0;
}
