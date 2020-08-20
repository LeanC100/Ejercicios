#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int sld[40];
	char name[50];
	int sld_max=0;
	char name_min[50];
	float sumt=0;
	float prom=0;
	int dif=0;

	for (int i = 0; i < 4; i++)
	{
		printf("Ingrese el sueldo del empleado\n");
		scanf("%i", &sld[i]);
		printf("Nombre del empleado\n");
		scanf("%s", name);
	}
	return 0;
}
