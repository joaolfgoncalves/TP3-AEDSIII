#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <time.h>
#include <pthread.h>

//#define N_threads 4
// STEP 2 - Paralização do TP

int main(int argc, char *argv[]){
 
   int t = argc;
   t++;
   int N_threads = atoi(argv[1]);
   pthread_t threads[N_threads];
   limites var[N_threads];
   int i,b,*max_linhas,j;
   float aux;
   Tipo_mapa Mapa;
   float tempo;


   scanf("%i %i",&Mapa.M,&Mapa.N);
    
   Mapa.Grid = Aloca_grid(&Mapa);
   max_linhas = (int *) malloc (((Mapa.M))*(sizeof(int))) ;
   


for(i=0;i<Mapa.M;i++){
      for(j=0;j<Mapa.N;j++){
            scanf("%i",&Mapa.Grid[i][j]);
      }
   
}
clock_t inicio,fim;
    inicio = clock();

    b = Mapa.M / N_threads;
     int c=0;
     aux = Mapa.M % N_threads;

     for(i=0;i<N_threads;i++){
      var[i].Mapa = &Mapa;
      var[i].inicio = c;
      var[i].fim = c+b;
      c +=b;
      var[i].max_linhas = max_linhas;
   
     if(aux > 0){ 
         var[i].fim++;
         aux--;
         c++;
        }
      pthread_create((&threads[i]), NULL,func, (void *)(&var[i]));
      pthread_join((threads[i]),NULL);
      printf(" joing THREADS %i\n",i);
    } 
     

      b = Prog_din_linha(&Mapa,max_linhas);
    
     //imprime_grid(&Mapa);

     Mapa.Grid = libera(&Mapa);
    
      fim = clock();
    tempo = difftime(fim,inicio);
    printf("Tempo total = %.2f \n",((double)tempo)/ (CLOCKS_PER_SEC/1000 ) );
    
	return 0;
}



