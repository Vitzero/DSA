#include <stdio.h>
#define N 30
#define P 10

struct piloto{
    char nome[50];
    char equipe[50];
    int pontuacao[P];
};
typedef struct piloto PILOTO;

int SomaPontuacao(PILOTO p){
    int i = 0;
    int soma = 0;
    
    for(i = 0; i < P; i++){
        soma+= p.pontuacao[i];
    }
    
    return soma;
}

void OrganizaPilotos(PILOTO p[]){
    int i = 0;
    int j = 0;
    PILOTO aux;
    
    for(i = 0; i < 3 - 1; i++){
        for(j = 0; j < 3 - i - 1; j++){
            
           if(SomaPontuacao(p[j]) < SomaPontuacao(p[j+1])){
                aux = p[j];
                p[j] = p[j+1];
                p[j+1] = aux;
            }
        
        }
    }
    
}

int main()
{
    int i;
    
    PILOTO p[3] = {
        {
            .nome = "Verstappen",
            .equipe = "Red Bull",
            .pontuacao = {18, 2, 15, 11, 10, 13, 12, 11, 10, 29}
        },
        {
            .nome = "Charles Leclerc",
            .equipe = "Scuderia Ferrari",
            .pontuacao = {18, 25, 15, 25, 10, 18, 25, 15, 18, 25}
        },
        {
            .nome = "xxxx",
            .equipe = "xxxxxx",
            .pontuacao = {8, 5, 5, 5, 0, 8, 5, 5, 8, 25}
        }
    };
    
    OrganizaPilotos(p);
    
    for(i = 0; i < 3; i++){
        printf("\n %s %s / Total de pontos: %d", p[i].nome, p[i].equipe, SomaPontuacao(p[i]));
    }

    return 0;
}