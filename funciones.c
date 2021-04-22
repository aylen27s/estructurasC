#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cabecera.h"


int cargar (Corredor **listado)
{
	int j=0; 
    int nro=1, aux, ID=1000;
    float d;
	char entrada[255];
	
	
	while (ID !=0 && ID>=INICIO && ID <=TOPE)
	{	
       
        printf("  ID: ");
		scanf("%d", &ID);
		(*listado)[j].id = ID;
        
        if(ID  != 0)
        {
            printf("  Nombre y Apellido: ");
            scanf("%s", entrada);

            
            (*listado)[j].NombApI = malloc ( strlen(entrada)+1 );
            strcpy ((*listado)[j].NombApI , entrada); 
            
            printf("  Tiempo(min): ");
            scanf("%d", &nro);
            (*listado)[j].minutos = nro;

            
            printf("  Distancia(km): ");
            scanf("%f", &d);
            (*listado)[j].Distancia = d;
            
            printf("\n");

            j++;
            aux= j+1;
            
            *listado =  realloc (*listado, aux * sizeof(Corredor));
            
            if (listado == NULL) 
                printf("  Error, no se reasigno memoria\n" );

            //fflush (stdin);
        }
        else if (ID == 0)
            printf("\n---------------------------carga finalizada--------------------------\n");

	}
	return j;
}


void calculo (Corredor * listadoC, Velocidad ** resultado, int cant)
{
  int i=0;
  
  float tiempo;
  
  *resultado =  realloc (*resultado, cant * sizeof(Velocidad));
  
  for ( i=0 ; i<cant ; i++)
  {
      (*resultado)[i].id_c = listadoC[i].id;
      (*resultado)[i].NombApR = malloc ( strlen(listadoC[i].NombApI) + 1 );
      strcpy ((*resultado)[i].NombApR, listadoC[i].NombApI); 
      
      tiempo = (float)(listadoC[i].minutos) / (float)HORA;
      //printf ("tiempo %f\n", tiempo);
      (*resultado)[i].V = (listadoC[i].Distancia) / tiempo;
  }
    
}

Velocidad ** ordenar_nom(Velocidad * res, int cant_n)
{
    Velocidad ** IndexN = malloc (cant_n * sizeof(Velocidad*));
    Velocidad * aux;
    int i=0, j=0, k=1;
   
    
    for (i=0; i < cant_n; i++)
    IndexN[i]= &res[i];

    for (i=0; i < cant_n-1 ; i++)
    {
        for (j=k ; j < cant_n ; j++)
        {
                if (strcmp( IndexN[i]->NombApR , IndexN[j]->NombApR) > 0)
                {
                    aux = IndexN[i];
                    IndexN[i]= IndexN[j];
                    IndexN[j] = aux;
                }
        }
        k++;
    }
            
    return IndexN;
}



Velocidad ** ordenar_vel(Velocidad * res_v, int cant_v)
{
    Velocidad ** IndexV = malloc (sizeof(Velocidad*) * cant_v);
    Velocidad * aux;
    int i,j=0;
   
    
    for (i=0; i < cant_v; i++)
    IndexV[i]= &res_v[i];
    

        for (i=0; i < cant_v; i++)
            for (j=0 ; j < cant_v ; j++)
                if ( (IndexV[i]->V) < (IndexV[j]->V) )
                {
                    aux = IndexV[i];
                    IndexV[i]= IndexV[j];
                    IndexV[j] = aux;
                }
 
    return IndexV;
}

char menu()
{
    char l[2];

    printf ("\n>>>> Presione 'A' para elegir otro filtro\n");
    printf (">>>> Presione otra letra para finalizar el programa\n\n");
    printf ("      Ingrese letra >>  ");
    scanf("%s", l);
 
    l[0]= toupper(l[0]);
    
    return l[0];
}

void liberar_corredores(Corredor * punteroc, int cant1)
{
    int i;
    for (i=0; i < cant1; i++)
	{
		free ( punteroc[i].NombApI );
    }
    
    free (punteroc);   
}

void liberar_velocidades(Velocidad * punterov, int cant0)
{
    int i;
    for (i=0; i < cant0; i++)
	{
		free ( punterov[i].NombApR );
    }
    
    free (punterov);
}















