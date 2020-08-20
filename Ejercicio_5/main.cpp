#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int producto[10][2];
	int producto_max[1][2];
		producto_max[0][0]=0;
	int producto_min[1][2];
		producto_min[0][0]=99999999;
	int arti_sup_prom=0;
	float sumt=0;
	float prom=0;
	int arti10=0;
	int x=0;

	for (int i = 0; i <10 ; i++)
	{
		printf("Ingrese el costo del producto %i \n", i+1);
		scanf("%i", &producto[i][0]);
		printf("Ingrese el codigo\n");
		scanf("%i", &producto[i][1]);
		if (producto[i][0] <producto_min[0][0]){ // Busca el prodcuto minimo
			producto_min[0][0]=producto[i][0] ;
			producto_min[0][1]= producto[i][1];
		} 
		if (producto[i][0] > producto_max[0][0]){  // Busca el producto maximo
			producto_max[0][0]=producto[i][0] ;
			producto_max[0][1]= producto[i][1];			
		}

		x++; // sumamos un producto  a la variabler X
		sumt+=producto[i][0]; // suma total del costo de los prodcutos


	}
	prom= sumt/x; // Sacamos promedio
	for (int i = 0; i < x; i++)
	{
		if (prom<producto[i][0]) // Buscamos si el producto supero al promedio 
		{
			arti_sup_prom++;
		}
		if (producto[i][0]<10) // Buscamos si el costo del producto es menos de 10
		{
			arti10++;
		}
	}
	// RESPUESTAS
	printf("EL precio maximo es %i y tiene el codigo %i\n",producto_max[0][0],producto_max[0][1] );
	printf("EL precio minimo es %i y tiene el codigo %i\n",producto_min[0][0], producto_min[0][1]);
	printf("%i articulos superaron al promedio \n", arti_sup_prom);
	printf("%i articulos son inferiores a 10 pesos\n",arti10);
	return 0;
}
