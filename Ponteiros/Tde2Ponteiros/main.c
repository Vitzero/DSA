#include <stdio.h>
#define N 5
struct piloto{
    char nome[51];
    char equipe[51];
    int pontuacao[22];
};
typedef struct piloto PILOTO;


int somaPontuacao(int * p, int qtd){
    int i = 0;
    int soma = 0;
    
    for(i = 0; i < qtd; i++){
        soma += p[i];
    }
    
    return soma;
}

void calcula_classificacao(PILOTO p[N], PILOTO *campeao, PILOTO *vice){
    int i = 0;
    
    for(i = 0; i < N; i++){
        if(somaPontuacao(p[i].pontuacao,22) > somaPontuacao(campeao->pontuacao,22)){
            *vice = *campeao;
            *campeao = p[i];
        }
        else if(somaPontuacao(p[i].pontuacao,22) > somaPontuacao(vice->pontuacao,22)){
            *vice = p[i];
        }
    }
    
}

int main()
{
    PILOTO p[N] = {
        {"Max Verstappen", "Red Bull Racing", {25,18,25,26,25,18,0,25,26,25,25,25,18,26,25,0,0,0,0,0,0,0}},
        {"Lando Norris", "McLaren", {18,15,18,12,15,10,12,10,18,15,10,15,18,15,10,12,0,0,0,0,0,0}},
        {"Charles Leclerc", "Ferrari", {10,12,15,10,18,8,18,12,10,15,18,15,12,10,15,12,0,0,0,0,0,0}},
        {"Lewis Hamilton", "Mercedes", {18,25,15,18,12,10,25,18,15,10,12,18,25,15,18,25,0,0,0,0,0,0}},
        {"Fernando Alonso", "Aston Martin", {12,10,12,8,10,6,10,8,6,10,8,6,10,8,6,4,0,0,0,0,0,0}}
    };
    
    PILOTO campeao, viceCampeao;
    
    calcula_classificacao(p, &campeao, &viceCampeao);
    printf("camepeao: %s %s ", campeao.nome, campeao.equipe);
    printf("\nVice: %s %s  ", viceCampeao.nome, viceCampeao.equipe);
    
    return 0;
}