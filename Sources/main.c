#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#define maxCaracPlayer 11

void InsertPlayerName(char playerName[maxCaracPlayer]);
void AreYouSure(char playerName[maxCaracPlayer], char *yesOrNo);
void Intro(char playerName[maxCaracPlayer], char *yesOrNo);

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

    // Chama a função para rodar a introdução do jogo
    Intro(playerName, &yesOrNo);
    
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

void Intro(char playerName[maxCaracPlayer], char *yesOrNo)
{
    sleep(3);
    printf("\n\nAlguns avisos importantes:");
    sleep(2);
    printf("\n\n   1: Seu progresso pelo purgatório não poderá ser salvo,\n   evite fechar esta janela se não quiser parar de jogar!");
    sleep(1);
    printf("\n\n   2: O jogo termina se seu PV (Pontos de Vida) chegar a zero!\n   Mas você poderá sempre tentar mais uma vez!");
    sleep(1);
    printf("\n\n   3: Purgatory é um RPG de texto, portanto, preste atenção em suas escolhas!\n   E conte com a sorte!");
    sleep(1);
    printf("\n\n   4: Para auxiliar em sua imersão, algumas trilhas sonoras serão sugeridas!\n   Os links (do youtube) serão passados por aqui, mas fique a vontade\n   para não usá-las! Ou, escolher você mesmo sua trilha sonora!");
    sleep(3);

    printf("\n\nSe estiver tudo pronto para entrar no purgatório,\ndigite [s] para começar ou [n] para esperar: ");
    scanf("%c", yesOrNo);
    fflush(stdin);
    printf("\n\n");

    if (*yesOrNo == 's')
    {
        system("cls");
        printf("Ual! Você tem coragem, %s! Então tá, se achar uma boa ideia,\ncoloca essa música de trilha para começarmos: https://www.youtube.com/watch?v=TQnUctUq2_Y", playerName);
    }
    else if (*yesOrNo == 'n')
    {
        system("cls");
        printf("E quem pode te culpar? Nem todo mundo tem a coragem necessária! \nVai tomar um ar e volta quando tiver bem! Eu vou deixar os avisos aqui de novo.");
        Intro(playerName, yesOrNo);
    }
    else {
        system("cls");
        printf("Você tá bem? As opções são [s] ou [n]...\nVamos de novo que dessa vez você consegue!");
        Intro(playerName, yesOrNo);
    }
}