#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


struct ficha_de_aluno {
    int direcao;
    int posicao;
    int id;
} particula;


void copia_curr_para_next( int * destino_mat, int * origem_mat, int n ) {
  memcpy( destino_mat, origem_mat, n * n * sizeof(int) );
}

int *copia_particulas_para_next( int * destino_mat, int * origem_mat, int np ) {
    for( i=0; i < np; i++ ) {
        next[i] = particulas[i];
    }
    return next;
}


int numero_aleatorio( int intervalo) {
	return ( rand() % intervalo );
}


int *iniciar_particulas( int *particulas, int np, int n_posicoes ) {
    int i, j; 
    int posicoes = 0;

    for( i=0; i < np; i++ ) {
        particulas[i].id = i;
        particulas[i].direcao = numero_aleatorio(5);
        particulas[i].posicao = numero_aleatorio(n_posicoes);
    }
    return particulas;
}


int alocando_vetor_particulas( int *particulas, int n, int np ) {
    int i;
    int * particulas = (int *) malloc( sizeof( int ) * np );
    for( i=0; i < n; i++ ) {
        particulas[i] = (particula) malloc( sizeof( particula ) );
    }
    return particulas;
}

int checkParedeLados(int posicao) {
    return posicao % n;
}

void hpp ( int *particulas, int *next, int N, int np, int n ) {
    int i, j, k;
    int parade_esquerda
    particula atual;
    int flag;

    int indo_esquerda = 1, indo_direita = 2, indo_baixo = 3, indo_cima = 4, vazio = 0;
    int parede_horizontal, parede_vertical;

    for( i=0; i < N; i++ ) {
        for( j=0; j < np; j++) {
            flag = 0;
            atual = particulas[i];
            parede_horizontal = checkParedeLados(atual.posicao);
            if(atual.direcao == indo_esquerda && parede_horizontal == 0){
                atual.direcao == indo_direita;
            }
            else if(atual.direcao == indo_direita && parede_horizontal == n-1){
                atual.direcao == indo_esquerda;
            }
            else if(atual.direcao == indo_cima && atual.posicao < n){
                atual.direcao == indo_baixo;
            }
            else if(atual.direcao == indo_baixo && atual.posicao > (n*n)-n-1 ){
                atual.direcao == indo_cima;
            }
            else {
                for( k=0; k < np; k++) {
                    if(atual.posicao == particulas[k].posicao && atual.id != particulas[k].id){
                        if( atual.direcao == indo_esquerda ) {
                            flag = 1;
                            particulas[k].direcao == indo_direita;
                            if(atual.posicao > n-1){
                                atual.posicao = atual.posicao - n;
                                atual.direcao = indo_cima;
                            }
                            else {
                                atual.direcao = indo_baixo;
                            }
                        }
                        else if( atual.direcao == indo_direita ) {
                            flag = 1;
                            particulas[k].direcao == indo_esquerda;
                            if(atual.posicao < (n*n)-n){
                                atual.posicao = atual.posicao + n;
                                atual.direcao = indo_baixo;
                            }
                            else {
                                atual.direcao = indo_cima;
                            }
                        }
                        else if( atual.direcao == indo_cima ) {
                            particulas[k].direcao == indo_baixo;
                            if(parede_horizontal < n-1){
                                atual.posicao = atual.posicao + 1;
                                atual.direcao = indo_direita;
                            }
                            else {
                                atual.direcao = indo_esquerda;
                            }
                        }
                        else if( atual.direcao == indo_baixo ) {
                            particulas[k].direcao == indo_cima;
                            if(parede_horizontal != 0){
                                atual.posicao = atual.posicao + 1;
                                atual.direcao = indo_esquerda;
                            }
                            else {
                                atual.direcao = indo_direita;
                            }
                        }
                    }
                }
            }
            if(flag == 0) {
                if( atual.direcao == indo_esquerda && parede_horizontal > 0 ) {
                    atual.posicao = atual.posicao - 1;
                }
                else if( atual.direcao == indo_direita && parede_horizontal < n-1 ) {
                    atual.posicao = atual.posicao + 1;
                }
                else if( atual.direcao == indo_cima && atual.posicao > n-1 ) {
                    atual.posicao = atual.posicao - n;
                }
                else if( atual.direcao == indo_baixo && atual.posicao <= n*n-n ) {
                    atual.posicao = atual.posicao + n;
                }
            }
            next[i] = atual;
        }
        particulas = copia_particulas_para_next(particulas, next, n)
    }
}


int main() {
    // n x n tamanho da matrix
    // N numero de interacoes
    // curr matriz corrente
    // next matriz obtida a partir de curr
    // np numero de particulas

    int n, N, deno;
    int *particulas, *next;
    int deno;
    int np = (n*n)/deno;

    N = 100;

    srand( (unsigned)time(0) );

    hpp( N, n, particulas, next, np);

}