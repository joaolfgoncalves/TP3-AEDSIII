#include <stdio.h>
#include <stdlib.h>
#include  "lib.h"

// Funçoões usadas para montar o mapa

int **Aloca_grid(Tipo_mapa *Mapa){
 
   int i;
   int **mat;

  /* aloca as linhas da matriz */
  mat = (int **) malloc (Mapa->M*(sizeof(int *)));
 
  /* aloca as colunas da matriz */
  for ( i = 0; i < Mapa->M; i++ ) {
      mat[i] = (int *) malloc (Mapa->N*(sizeof(int)));
 
      }
  return(mat);	
}


int **libera(Tipo_mapa *Mapa){
  int i;
  for(i=0;i<Mapa->M;i++) free(Mapa->Grid[i]);
  free(Mapa->Grid);
  return (NULL);
}


void imprime_grid(Tipo_mapa *Mapa){
    int i,j;
    printf("     ");
     for(i=0;i<Mapa->N;i++)printf("%d ",i);
    printf("\n\n");
    for(i=0;i<Mapa->M;i++){
    	printf("%i    ",i);
    	for(j=0;j<Mapa->N;j++){
    		printf("%i ",Mapa->Grid[i][j]);
    	}
               printf("\n");
    }

}

int max(int a,int b){
  if(a>b) return(a);

  return (b);
}
// Implementacao das funções e estruturas Programação Dinâmica

int Prog_din_coluna(Tipo_mapa *Mapa, int linha,int *max_linhas){
  int *Memo;
  int i, maximo;
//  int j,aux = 0;
  
  Memo =(int *) malloc (((Mapa->N)+1)*(sizeof(int))) ;
  /*for(i=0;i<900000;i++){
     for(j=0;j<50;j++){
      aux--;
      aux = aux+1;
         }
     }*/    
  for(i=0;i<Mapa->N;i++){
  if(i > 1){
     Memo[i] = max (Memo[i-1], Mapa->Grid[linha][i] + Memo[i-2] );
  }
   if(i<=1){ 
      Memo[0] = Mapa->Grid[linha][0];
      Memo[1] = max( Mapa->Grid[linha][0], Mapa->Grid[linha][1]);
   }

}
  maximo = Memo[(Mapa->N)-1];
  max_linhas[linha] = maximo;
  //printf("\n Maximo da linha[%i] = %i \n",linha,maximo);
  free(Memo);
  return (maximo);
}

int Prog_din_linha(Tipo_mapa *Mapa,int *max_linhas){
    int *Memo;
    int i, maximo;
    Memo =(int *) malloc (((Mapa->M)+1)*(sizeof(int))) ;
    for(i=0;i<Mapa->M;i++){
    if(i<=1){
      Memo[0] = max_linhas[0];
      Memo[1] = max(max_linhas[0],max_linhas[1]); 
     }
     if(i>1){
      Memo[i] = max(max_linhas[i-1],
                    max_linhas[i] + Memo[i-2]);
     }
    }
   maximo = Memo[(Mapa->M)-1];
   printf("%i\n",maximo);
  return maximo;
}


// Implementações funçoes Programação Paralela 

void *func(void *arg){
limites *var = (limites *) arg;
 int i,aux;
 for(i=var->inicio ; i<var->fim ;i++){
   aux =Prog_din_coluna(var->Mapa,i,var->max_linhas);
 }
 
 return (NULL);
}






