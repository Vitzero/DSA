#include <stdio.h>
#define N 5
struct piloto{
    char nome[51];
    char equipe[51];
    int pontuacao;
};
typedef struct piloto PILOTO;


void calcula_classificacao(PILOTO p[N], PILOTO *campeao, PILOTO *vice){
    int i = 0;
    
    for(i = 0; i < N; i++){
        if(p[i].pontuacao > campeao->pontuacao){
            *vice = *campeao;
            *campeao = p[i];
        }
        else if(p[i].pontuacao > vice->pontuacao){
            *vice = p[i];
        }
    }
    
}

int main()
{
    PILOTO p[N] = {
        {"Max Verstappen", "Red Bull Racing", 390},
        {"Lando Norris", "McLaren", 290},
        {"Charles Leclerc", "Ferrari", 260},
        {"Lewis Hamilton", "Mercedes", 240},
        {"Fernando Alonso", "Aston Martin", 180}
    };
    
    PILOTO campeao, viceCampeao;
    
    calcula_classificacao(p, &campeao, &viceCampeao);
    printf("%s camepeao %s equipe %d pontuacao", campeao.nome, campeao.equipe, campeao.pontuacao);
    printf("\n%s Vice nome %s Vice equipe %d Vice pontuacao", viceCampeao.nome, viceCampeao.equipe, viceCampeao.pontuacao);
    
    return 0;
}