#define TOPE 9999
#define INICIO 1000
#define HORA 60

typedef struct 
{
	unsigned int id, minutos;
	char * NombApI;
	float Distancia;
}Corredor;

typedef struct 
{
	unsigned int id_c;
	char * NombApR;
	float V;
}Velocidad;

char menu();

int cargar(Corredor **listado);
void calculo(Corredor * listadoC, Velocidad ** resultado, int cant);

void liberar_velocidades(Velocidad * punterov, int cant0);
void liberar_corredores(Corredor * punteroc, int cant1);

Velocidad ** ordenar_nom(Velocidad * res, int cant_n);
Velocidad ** ordenar_vel(Velocidad * res_v, int cant_v);


