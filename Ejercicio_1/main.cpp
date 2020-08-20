#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int vector[35];
	int vector_maximo=0;

	for (int i = 0; i < 3; ++i) // Ingreso de los metodos
	{
		printf("Ingrese el elemento %i\n", i+1);
		scanf("%i",&vector[i]);
		if (vector[i]>=vector_maximo ) // Verifica si el valor ingresado puede ser el nuevo maximo
		{
			vector_maximo= vector[i];
		}
	}
	printf("El valor maximo es: %i\n",vector_maximo );
	return 0;
}
