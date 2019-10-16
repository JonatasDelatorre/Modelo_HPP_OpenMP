#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


struct ficha_de_aluno {
    int direcao;
    int posicao;
} particula;


int numero_aleatorio() {
	return ( rand() % 5 );
}




int ** alocando_matriz_inicial( int n ) {
    int i, j;
    int ** curr = (int **) malloc( sizeof( int * ) * n );
    for( i=0; i < n; i++ ) {
        curr[i] = (int *)malloc( sizeof( int ) * n );
        for( j=0; j < n; j++ ) {
            curr[i][j] = 0;
        }
    }
    return curr;
}


int *iniciar_particulas( int *particulas, int np ) {
    int i, j; 

    for( i=0; i < np; i++ ) {
        particulas[i].direcao = numero_aleatorio();
    }
    
    return particulas;
}


int  alocando_vetor_particulas( int *particulas, int n, int np ) {
    int i;
    int * particulas = (int *) malloc( sizeof( int ) * np );
    for( i=0; i < n; i++ ) {
        particulas[i] = (particula) malloc( sizeof( particula ) );
    }
    return particulas;
}

void hpp () {
    int i;


}


void copia_curr_para_next( int * destino_mat, int * origem_mat, int n ) {
  memcpy( destino_mat, origem_mat, n * n * sizeof(int) );
}


void hpp( int N, int n, int **curr, int **next, int np ) {
    int i, j, k;
    
    int indo_esquerda = 1, indo_direita = 2, indo_baixo = 3, indo_cima = 4, vazio = 0;
    int parade_esquerda = 0, parede_direita = (n-1), parede_baixo = (n-1), parede_cima = 0;

    curr = alocando_matriz_inicial(n);
    curr = iniciar_particulas( curr, n, np );
    copia_curr_para_next(curr, next, n)

    for( k=0; k < N; k++ ) {
        for( i=0; i < n; i++ ) {
        	for( j=0; j < n; j++ ) {
                no = curr[i][j];
        		// se existe particula na posicao
        		if( no != vazio ) {
                    // se particula esta indo para esquerda
                    if( no == indo_esquerda ) {
                        if( j == parade_esquerda ) {
                            next[i][j] = indo_direita;
                        }
                        else if( curr[i][j-1] == indo_direita) {
                            next[i][j] = indo_cima;
                            next[i][j-1] = indo_baixo;
                        }
                        else if( curr[i][j-1] == vazio) {
                            next[i][j-1] = no;
                        }
                    }
                    // se particula esta indo para direita
                    else if( no == indo_direita ) {
                        if( j == parede_direita ) {
                            next[i][j] = indo_esquerda;
                        }
                        else if( curr[i][j+1] == indo_esquerda) {
                            next[i][j] = indo_baixo;
                            next[i][j+1] = indo_cima;
                        }
                        else if( curr[i][j+1] == vazio) {
                            next[i][j+1] = no;
                        }
                    }
                    // se particula esta indo para baixo
                    else if( no == indo_baixo ) {
                        if( i == parede_baixo ) {
                            next[i][j] = indo_cima;
                        }
                        else if( curr[i+1][j] == indo_cima) {
                            next[i][j] = indo_esquerda;
                            next[i+1][j] = indo_direita;
                        }
                        else if( curr[i+1][j] == vazio) {
                            next[i+1][j] = no;
                        }
                    }
                    // se particula esta indo para cima
                    else if( no == indo_cima ) {
                        if( i == parede_cima ) {
                            next[i][j] = indo_baixo;
                        }
                        else if( curr[i-1][j] == indo_baixo) {
                            next[i][j] = indo_direita;
                            next[i][j-1] = indo_esquerda;
                        }
                        else if( curr[i-1][j] == vazio) {
                            next[i-1][j] = no;
                        }
                    }
        		}
        	}
    	}
    }
}


int main() {
    // n x n tamanho da matrix
    // N numero de interacoes
    // curr matriz corrente
    // next matriz obtida a partir de curr

    int n, N, deno;
    int *particulas, *next;
    int deno;
    int np = (n*n)/deno;

    N = 100;

    srand( (unsigned)time(0) );

    hpp( N, n, curr, next, np);

}