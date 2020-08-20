#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {

	int nticket=0;
	float ticket[999][2];
	int ticket_mas=0;
	int ndestino=0;
	int destino[4][3];
	char* destino_c [4];		
		destino_c[0]= "salta";
		destino_c[1]= "jujuy";
		destino_c[2]= "tucuman";
		destino_c[3]= "formosa";
	int destino_ch [4];
		destino_ch [0]=0;
		destino_ch [1]=1;
		destino_ch [2]=2;
		destino_ch [3]=3;
	int destino_mas=1;
	int ncodigo=0;
	int codigo[3][2];
		codigo[0][0] =85;		
		codigo[1][0] =70;
		codigo[2][0] =50;
	int ncant=0;
	float sumt=0;
	float prom=0;
	int aux=0;

	for (int i = 0; i < 999; i++)
	{
		ticket[i][0]= i+1;
		ticket[i][1]=0;
	}
	for (int i = 0; i < 3; i++)
	{
		codigo[i][1]=0;
	}
	for (int i = 0; i < 4; i++)
	{
		destino[i][2]=i+1;
		for (int j = 0; j < 2; j++)
		{
			destino[i][j]=0;
		}
	}
	printf("Ingrese el numero de ticket(Ingrese 0 para terminar)\n");
	scanf("%i", &nticket );
	while (nticket!=0){
		printf("Ingrese el codigo del destino\n");
		printf("1. salta    2. jujuy    3. tucuman    4. formosa\n");
		scanf("%i", &ndestino);
		if (ndestino>=1 && ndestino<=4)
		{
			printf("Ingrese e� codigo de la tarifa\n");
			printf("codigo de tarifa          descripcion             valor\n");
			printf("1                         pulllman                $85\n");
			printf("2                         primera                 $70\n");
			printf("3                         turista                 $50\n");	
			scanf("%i", &ncodigo);
			if (ncodigo >=1 && ncodigo <=3)
			{
				printf("Ingrese la cantidad de boletos que desea comprar\n");
				scanf("%i", &ncant );
				if (ncant >10)
				{
					codigo[ncodigo-1][0]= codigo[ncodigo-1][0]*0.10;
				}	
				destino[ndestino-1][0]+= ncant;
				ticket[nticket-1][1]+= ncant*codigo[ncodigo-1][0];
				if (ticket[nticket-1][1] > ticket[ticket_mas-1][1])
				{
					ticket_mas=nticket;
				}
				destino[ndestino-1][1]+= ncant* codigo[ncodigo-1][0];
				codigo[ncodigo-1][1] += ncant;
				if (destino[ndestino-1][1]>destino[destino_mas-1][1])
				{
					destino_mas=ndestino;
				}
				sumt+=ncant* codigo[ncodigo-1][0];
				codigo[0][0] =85;		
				codigo[1][0] =70;
				codigo[2][0] =50;
				printf("----------------------------------------------------\n");
				printf("Ingrese el numero de ticket(Ingrese 0 para terminar)\n");
				scanf("%i", &nticket );
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
	for (int i = 0; i < 4; i++)
	{
		if (destino[i][0]!=0)
		{
			printf("En el destino %i se vendieron %i pasajes\n",i+1,destino[i][0] );
		}
	}
	// 2
	printf("El ticket con mayor valor es %i\n",ticket_mas );
	// 3
	for (int i = 0; i < 4; i++)
	{
		if (destino[i][1]!=0)
		{
			printf("En el destino %i se recaudo %i pesos\n",i+1, destino[i][1] );
		}
	}
	// 4
	for (int i = 0; i < 4; i++)
	{
		if (destino[i][1]!=0)
		{
			prom= (100*destino[i][1])/sumt;
			printf("El destino %i representa un %.2f Porc. del total\n",i+1, prom );
		}

	}
	// 5
	for (int i = 0; i < 3; i++)
	{
		if (codigo[i][1]!=0)
		{
			printf("En la clase %i se vendieron %i pasajes\n",i+1, codigo[i][1] );
		}
	}
	// 6
	printf("El destino mas solicitado es el destino N. %i \n",destino_mas );
	// 7
	printf("Si se debe pagar el 21 Porc. de IVA\n");
	for (int i = 0; i < 999; i++)
	{	
		if (ticket[i][1]!=0)
		{
			printf("En el ticket %.0f se pagaria %.2f en total \n",ticket[i][0],(ticket[i][1]*0.21+ticket[i][1] ));
		}
	}
	// 8
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4-i-1; j++)
		{
			if (destino[j][1] > destino[j+1][1])
			{
				aux= destino[j][0];
				destino[j][0]= destino[j+1][0];
				destino[j+1][0]= aux;
				aux=0;
				aux= destino[j][1];
				destino[j][1]= destino[j+1][1];
				destino[j+1][1]= aux;
				aux=0;
				aux= destino[j][2];
				destino[j][2]= destino[j+1][2];
				destino[j+1][2]= aux;
				aux=0;
				aux= destino_ch[j];
				destino_ch[j]= destino_ch[j+1];
				destino_ch[j+1]= aux;
			}
		}
	} 
	for (int i = 3; i >= 0; i--)
	{
		printf("En el destino %s \n",destino_c[destino_ch[i]] );
		printf("    Con el codigo %i \n",destino[i][2] );
		printf("    Se recaudo %i pesos\n",destino[i][1] );
		printf("    Y se vendieron %i pasajes\n",destino[i][0] );
	}
	return 0;
}
