
#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int factura=0;
	int nlibro=0;
	int ngenero=0;
	int cant=0;
	int libro [20];
	int genero[5];
	int x=0;
	int sup100=0;
	float sumt=0;
	float prom=0;

	// limpiamos vectores
	for (int i = 0; i < 20; i++)
	{
		libro [i]=0;
	}	
	for (int i = 0; i < 5; i++)
	{
		genero[i]=0;
	}

	printf("Ingresa el numero de libro que deseas obtener|1 al 20|(ingrese 0 para terminar)\n" );
	scanf ("%i", &nlibro);
	while (nlibro!=0){
		if (nlibro>= 1 && nlibro <=20)
		{
			printf("Ingresa el genero del libro |1 al 5|\n");	
			scanf ("%i", &ngenero);
			if (ngenero>=1 && ngenero<=5)
			{
				printf("El precio por unidad es $50\n");
				printf("Ingresa la cantidad de libros que queres\n");
				scanf ("%i", &cant);
				sumt += cant*50;
				libro[nlibro-1]+= cant*50; // recaudacion por cada libro
				genero[ngenero-1]+= cant*50; // recaudacion por cada genero
				factura = cant*50;
				if (factura>100) // si el costo de la factura es mayor a 100 
				{
					sup100++;
				}
				x++;				
			}else{
				printf("Valor ingresado invalido\n");
				return -1;
			}
		}else{
			printf("Valor ingresado invalido\n");
			return -1;
		}
		printf("--------------------------------------------------------------------------------------\n");
		printf("Ingresa el numero de libro que deseas obtener|1 al 20|(ingrese 0 para terminar)\n" );
		scanf ("%i", &nlibro);
		
	// RESPUESTAS
	printf("La facturacion total es %.2f \n",sumt );
	for (int i = 0; i < 20; i++)
	{	
		if (libro[i]!=0)
		{
			printf("En el libro %i se facturo %i pesos\n",i+1, libro[i] );
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (genero[i]!=0)
		{
			printf("En el genero %i se facturo %i pesos\n",i+1,genero[i] );
		}
	}
	prom = sumt/ x;
	printf("El promedio es %.2f\n", prom);
	printf("%i facturas superaron los $100 \n",sup100 );


	return 0;
}
