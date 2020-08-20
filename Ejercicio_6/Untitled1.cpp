#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int factura [50];
	int nvendedor=0;
	int vendedor[4];
	int importe[50];
	int caja_dia=0;
	float sumt=0;
	float prom=0;
	int x=0;

	// limpiamos vector
	for (int i = 0; i < 4; i++)
	{
		vendedor[i]=0;
	}
		
	for (int i = 0; i < 50; i++)
	{
		printf("Ingrese factura N. %i\n",i+1 );
		scanf("%i", &factura[i]);
		if (nvendedor==4) // reseteador de contador de vendedor
		{
			nvendedor=0;
		}
		printf("Estaas siendo atendido por el vendedor %i\n",nvendedor+1 );
		printf("Ingrese el importe de la factura\n");
		scanf ("%i",&importe[i]);
		sumt+= importe[i];
		vendedor[nvendedor]+=importe[i]; // sacamos el importe de X vendedor
		x++; // sumamos una factura mas 
		if (caja_dia<vendedor[nvendedor-1]) // buscamos a que empleado le pertenece la caja del dia
		{
			caja_dia=vendedor[nvendedor+1];
		}
		nvendedor++; // sumanos 1 para que atienda el siguiente vendedor
		printf("-----------------------------------------------------\n");
	}
	// RESPUESTA
	printf("La caja del dia es la caja %i\n",caja_dia );
	for (int i = 0; i < 4; i++)
	{
		prom= (100*vendedor[i])/sumt;
		printf("El empleado %i recaudo un %.2f Porc. del total\n",i+1,prom );
	}
	prom= sumt/x;
	printf("El valor promedio de las facturas es %.2f \n", prom);

	return 0;
}
