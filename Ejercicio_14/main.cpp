#include <iostream>
#include <stdio.h>
#include <string.h>

/* | Leandro | */

int main(int argc, char** argv) {
	int nticket=0;
	int ticket[999];
	int ticket_may=1;
	int npuesto=0;
	float puesto[30][3];
	char nmercad[50];
	char* nmercad_c [3];
		nmercad_c [0]="pan";
		nmercad_c[1]="ham";
		nmercad_c[2]="gas";
	int nmercad_ch [3];
		nmercad_ch[0]=0;
		nmercad_ch[1]=1;
		nmercad_ch[2]=2;
	float mercad[3][2];
		mercad[0][0]=1.00;		
		mercad[1][0]=2.00;
		mercad[2][0]=0.70;
		mercad[0][1]=0;				
		mercad[1][1]=0;				
		mercad[2][1]=0;		
	int mercad_mas=1;	
	int puesto_men=1;	
	int ncant=0;
	float sumt=0;
	float prom=0;

	for (int i = 0; i < 999; i++)
	{
		ticket[i]=0;
	}
	for (int i = 0; i < 30; i++)
	{
		puesto[i][0]=9999;
		puesto[i][1]=0;
		puesto[i][2]=0;
	}

	printf("Ingrese en numero del ticket (Ingrese 0 para terminar)\n");
	scanf("%i", &nticket);
	while (nticket!=0){
		printf("Ingrese el numero de puesto|1 al 30|\n");
		scanf("%i", &npuesto);
		if (npuesto>=1 && npuesto<=30)
		{
			printf("Escribe el codigo de mercaderia\n");
			printf("codigo de mercaderia          descripcion             saldo\n");
			printf("pan                             pancho               1,00\n");
			printf("ham                             hamburguesa          2,00\n");
			printf("gas                             gaseosa              0,75\n");
			scanf("%s", &nmercad);
			if (strcmp(nmercad, "pan") == 0 || strcmp(nmercad, "ham") == 0 || strcmp(nmercad, "gas") == 0)
			{
				int x=0;
				if (strcmp(nmercad, "pan")==0)
				{
					x=0;
				}else if (strcmp(nmercad, "ham") == 0 )
				{
					x=1;
				}else{
					x=2;
				}
				printf("Ingrese la cantidad que desea comprar\n");
				scanf("%i", &ncant);
				ticket[nticket] = ncant * mercad[x][0] ;
				if (ticket[nticket]> ticket[ticket_may])
				{
					ticket_may=nticket;
				}
				if (puesto[npuesto-1][0]==9999)
				{
					puesto[npuesto-1][0]=0;
				}
				puesto[npuesto-1][0] += ncant * mercad[x][0] ;
				sumt+= ncant * mercad[x][0] ;
				mercad[x][1]+=ncant * mercad[x][0] ;
				puesto[npuesto-1][2]+= ncant;
				if (mercad[x][1]> mercad[mercad_mas][1])
				{
					mercad_mas=x;
				}
				if (puesto[npuesto-1][0] < puesto[puesto_men-1][0]  )
				{
					puesto_men=npuesto;
				}
				puesto[npuesto-1][1]++;
				printf("---------------------------------------\n");
				printf("Ingrese en numero del ticket (Ingrese 0 para terminar)\n");
				scanf("%i", &nticket);
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
	printf("El ticket que tiene mayor valor es el ticket %i\n",ticket_may );
	// 2
	for (int i = 0; i < 30; i++)
	{
		if ( puesto[i][0] !=9999)
		{
			printf("El puesto %i recaudo %.2f pesos\n",i+1, puesto[i][0] );
		}
	}
	// 3
	for (int i = 0; i < 3; i++)
	{
		prom = (100*mercad[i][1])/ sumt;
		printf("En el mercado de %s tiene un %.2f Porc. de total\n",nmercad_c[i], prom );
	}
	// 4
	printf("La mercaderia mas vendida es la mercaderia de %s\n", nmercad_c[mercad_mas]);
	// 5
	printf("El puesto menos rentable en dinero es el puesto N: %i\n",puesto_men );
	// 6
	for (int i = 0; i < 30; i++)
	{
		if (puesto[i][0]!=9999)
		{
			printf("El puesto %i debe pagar %.2f pesos en impuesto\n",i+1,(puesto[i][0] *0.10) );
		}
	}	
	// 7
	for (int i = 0; i < 30; i++)
	{
		if (puesto[i][1]!=0)
		{
			printf("El puesto %i vendio %.0f ticket\n",i+1,puesto[i][1] );
		}
	}

	// 8 
	for (int i = 0; i < 30; i++)
	{
		if (puesto[i][0] == 9999 )
		{
			puesto[i][0] =0;
		}
		
		printf("En el puesto %i\n", i+1);
		printf("     Se recaudo %.2f pesos\n",puesto[i][0] );
		printf("     Se vendio %.0f mercaderias\n",puesto[i][2] );
	}
	return 0;
}
