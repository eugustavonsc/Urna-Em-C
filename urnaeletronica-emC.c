#include <stdio.h> 
struct Candidato
{
    int numero;
    char nome[50];
    int votos;
};

int votar (struct Candidato candidatos[], int totalCandidatos){
    int voto;
    printf("digite o numero do candidato (1 a 99): ");
    scanf("%d",&voto);
    int encontrado = 0;
    for (int i= 0; i<totalCandidatos; i++){
        if (candidatos[i].numero== voto)
        {
            candidatos[i].votos++;
            encontrado= 1;
            printf("voto computado para %s! \n", candidatos[i].nome);
            return 1;
        }
        
    }
    if (!encontrado)
    {
        printf("numero de candidato invalido! \n");
        return 0;
    }
    
}
void apurarVotos(struct Candidato candidatos[], int totalCandidatos){
    printf("resultado da apuração de votos: \n");
    for (int i = 0; i< totalCandidatos; i++){
        printf("%s (numero %d): %d votos \n", candidatos[i].nome,candidatos[i].numero,candidatos[i].votos);
    }
}
void percentualVotos(struct Candidato candidatos[], int totalCandidatos, int totalVotos){
    if (totalVotos == 0)
    {
        printf("nenhum voto computado ainda \n");
        return;
    }
    printf("\n percentual de votos \n");
    for( int i = 0; i<totalCandidatos; i++){
        float percentual = ((float)candidatos[i].votos / totalVotos) * 100;
        printf("%s: %.2f%% dos votos \n", candidatos[i].nome, percentual);
    }
    
}
int main(){
    struct Candidato candidatos[3] = {{10,"Joao da Padaria",0},{20,"Maria da farmacia",0},{30,"Zé do gas",0} };
    int opcao;
    int totalVotos= 0;
    int totalCandidatos= 3;
    do{
        printf("\n menu de opções\n");
        printf("1. votar \n");
        printf("2. apurar\n");
        printf("3. emitir percentual de votos\n");
        printf("4. sair\n");
        printf("escolha uma opção:");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            totalVotos+= votar(candidatos, totalCandidatos);

        case 2:
        apurarVotos(candidatos, totalCandidatos);

        case 3:
        percentualVotos(candidatos,totalCandidatos,totalVotos);

        case 4: 
        printf("saindo... \n");
        
        default:
            printf("opção invalida");
        }

    } while (opcao != 4);
    return 0;

}