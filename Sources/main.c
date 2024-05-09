#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define maxCaracPlayer 11

void InsertPlayerName(char playerName[maxCaracPlayer]);

int main() {
    // Seta a localização do projeto para português
    setlocale(LC_ALL, "Portuguese");

    char playerName[maxCaracPlayer];
    char yesOrNo;

    printf("Olá! Antes de iniciar sua aventura, nos diga como gostaria de ser chamado! (Máx. 10 carecteres)\n");
    
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