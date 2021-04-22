#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cabecera.h"


int main(void)
{	
	Corredor * DatosCorredor;
	Velocidad * ResultadoVelocidad, ** IndiceVel, ** IndiceNom;

    char letra[2], caracter[2];
    int i=0;
    int cantidad;
    
    DatosCorredor = malloc ( sizeof(Corredor) );
    if ( DatosCorredor == NULL)
        printf("Error, no se asigno memoria\n" );
    else
        printf("Se asigno memoria\n" );
    
    ResultadoVelocidad = malloc ( sizeof(Velocidad) );
    if ( ResultadoVelocidad == NULL)
        printf("Error, no se asigno memoria\n" );
    else
    {
        printf("Se asigno memoria\n");
    }   
    
	printf("---------------------------------------------------------------------\n" );
	printf("-                  CARGA DE DATOS - CORREDORES                      -\n" );
	printf("---------------------------------------------------------------------\n" );
	printf("-      La carga finalizara cuando ingrese <0> en el campo <ID>      -\n" );
	printf("------------------------------------------------------------\n" );
	printf("-              Los numeros de ID van desde el 1000 al 9999          -\n" );
	printf("---------------------------------------------------------------------\n" );
	
    cantidad = cargar(&DatosCorredor);

    printf("\n---------------------------------------------------------------------\n" );
	printf("-                          DATOS CARGADOS                           -\n" );
	printf("---------------------------------------------------------------------\n" );
    for ( i=0 ; i<cantidad ; i++ )
    {
        printf ("| %u |  ",
                DatosCorredor[i].id);
        
        if (DatosCorredor[i].minutos < 100)
            printf ("  %u  |   ", DatosCorredor[i].minutos);
        else
            printf (" %u  |   ", DatosCorredor[i].minutos);
        
        if (DatosCorredor[i].Distancia < 10)
            printf ("%.2f   ", DatosCorredor[i].Distancia);
        else
            printf ("%.2f  ", DatosCorredor[i].Distancia);
                
        printf ("|  %s  \n",DatosCorredor[i].NombApI);
    }
    printf("\n---------------------------------------------------------------------\n" );
	printf("-                      VELOCIDAD DE LOS CORREDORES                  -\n" );
	printf("---------------------------------------------------------------------\n" );
    
    calculo(DatosCorredor, &ResultadoVelocidad, cantidad);
    
    for (i=0; i<cantidad;i++)
    {
        printf ("| %u | ",
                ResultadoVelocidad[i].id_c);
        
        if (ResultadoVelocidad[i].V < 10)
            printf ("  %.2f km/h     ", ResultadoVelocidad[i].V);
        else
            printf (" %.2f km/h     ", ResultadoVelocidad[i].V);
        
         printf (" |  %s \n",
                ResultadoVelocidad[i].NombApR);     
    }   

    printf("\n--------------------------Filtro de busqueda-------------------------\n" );

    letra[0] = 'A';
    
   while (letra[0] == 'A')
   {
       printf("\n---------------------------------------------------------------------\n" );
       printf("-   Tecla V para ver por Velocidad | Tecla N para ver por Nombre    -\n" );
       printf("---------------------------------------------------------------------\n" );
       printf("       Ingrese letra :   " );
       
       //__fpurge(stdin);
       scanf("%s", caracter);
       //caracter = getchar();
       
       caracter[0] = toupper(caracter[0]);
       
       if (caracter[0] == 'V')
        {
            printf("\n---------------------------------------------------------------------\n" );
            printf("-                         ORDEN POR VELOCIDADES                     -\n" );
            printf("---------------------------------------------------------------------\n" );
            
            IndiceVel = ordenar_vel(ResultadoVelocidad, cantidad);
            
            for ( i = 0 ; i < cantidad ; i++)
            {
                printf ("| %u |   %.2f km/h   |  %s\n",
                        IndiceVel[i]->id_c,
                        IndiceVel[i]->V, 
                        IndiceVel[i]->NombApR);
                
            }
            
            free(IndiceVel);
        }
        else if (caracter[0] == 'N')
        {
            printf("\n---------------------------------------------------------------------\n" );
            printf("-                           ORDEN ALFABETICO                        -\n" );
            printf("---------------------------------------------------------------------\n" );

            IndiceNom = ordenar_nom(ResultadoVelocidad, cantidad);
            
            for (i=0; i<cantidad ;i++)
            {
                printf ("| %u |",IndiceNom[i]->id_c);
                
                if ( IndiceNom[i]->V >=10 )
                    printf ("  %.2f km/h   ",IndiceNom[i]->V);
                else
                    printf ("   %.2f km/h   ",IndiceNom[i]->V);
                
                printf ("|  %s\n",IndiceNom[i]->NombApR);
            }
            
            free(IndiceNom);
        }
        else
        {
            printf("\n\n---------       Ha ingresado un caracter no valido            -------\n" );   
        }
        
       //__fpurge(stdin);
       
       letra[0] = menu();
   }
        
       printf("\n\n---------------------------------------------------------------------\n" );
       printf("-                    ¡Gracias por usar el programa!                 -\n" );
       printf("---------------------------------------------------------------------\n" );


	liberar_velocidades(ResultadoVelocidad, cantidad);
    liberar_corredores(DatosCorredor, cantidad);
    
    
	return 0;
}

