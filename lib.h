#ifndef Mapa_GRID
#define Mapa_GRID

typedef struct Tipo_mapa {

	int **Grid;
	int  M;
	int  N;
    
}Tipo_mapa;

typedef struct  limites{
  int inicio;
  int fim;
  Tipo_mapa * Mapa;
  int *max_linhas;
 	
}limites;


// Funçoões usadas para montar o mapa

int **Aloca_grid(Tipo_mapa *Mapa);
int **libera(Tipo_mapa *Mapa);
void imprime_grid(Tipo_mapa *Mapa);

//Funções usadas na Programação Dinamica
int max(int a,int b);

int Prog_din_coluna(Tipo_mapa *Mapa, int linha, int *max_linhas);
int Prog_din_linha(Tipo_mapa *Mapa, int *max_linhas);
/*Funções usadas na Programação paralela */

void *func(void *arg);
#endif // Mapa_GRID
