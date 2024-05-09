#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define maxCaracPlayer 11

void InsertPlayerName(char playerName[maxCaracPlayer]);
void AreYouSure(char playerName[maxCaracPlayer], char *yesOrNo);

int main() {
    // Seta a localização do projeto para português
    setlocale(LC_ALL, "Portuguese");

    char playerName[maxCaracPlayer];
    char yesOrNo;

    printf("Olá! Antes de iniciar sua aventura, nos diga como gostaria de ser chamado! (Máx. 10 carecteres)\n");

    // Chama a função responsável por salvar o nome da pessoa jogadora
    InsertPlayerName(playerName);

    // Chama a função para confirmar o nome da pessoa jogadora, ou possibilitar que ela mude de ideia
    AreYouSure(playerName, &yesOrNo);
    
    return 0;
}

void InsertPlayerName(char playerName[maxCaracPlayer])
{
    printf("\nInsira seu nome, ou apelido, aqui: ");
    fgets(playerName, 10, stdin);

    // Remove the fgets \n. Source: https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
    playerName[strcspn(playerName, "\n")] = 0;
    fflush(stdin);
}

void AreYouSure(char playerName[maxCaracPlayer], char *yesOrNo)
{
    printf("\nMuito bem! Tem certeza que deseja iniciar a aventura como '%s'?", playerName);
    printf("\n[Aperte [s] para confirmar e [n] para cancelar]\n");
    scanf("%c", yesOrNo);
    fflush(stdin);

    if (*yesOrNo == 's')
    {
        system("cls");
        printf("É um prazer, %s! Sua aventura em Purgatory está para começar!\n", playerName);
    }
    else if (*yesOrNo == 'n')
    {
        printf("\nSem problemas! Vamos tentar novamente!");
        InsertPlayerName(playerName);
        AreYouSure(playerName, yesOrNo);
    }
    else
    {
        printf("\n\nParece que você não digitou nem [s] (sim) e nem [n] (não). Tente Novamente!\n");

        AreYouSure(playerName, yesOrNo);
    }
}