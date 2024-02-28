#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generateRandomNumber(int n){
    srand(time(NULL));

    return rand() % n;
}

int main(){
    int i;
    int num;
    int Cpoints, Ppoints;
    char PlayerName[50];
    char Pselection[8], Cselection[8];

    printf("Give a Name to Player: ");
    fgets(PlayerName, sizeof(PlayerName), stdin);
    PlayerName[strcspn(PlayerName, "\n")] = '\0';

    printf("\nPlayer 1: %s\nPlayer 2: PC\n\n", PlayerName);

    Cpoints = 0;
    Ppoints = 0;
    puts("The Game of Rock, Paper, and Scissor begins.\nMay the Odds be in your Favor!\n");
    for (i=0; i<3; i++){
        puts("Make a Choice (rock, paper, scissor):");
        printf("%s: ", PlayerName);
        scanf("%s", Pselection);
    
        num = generateRandomNumber(3);
        if (num == 0)
            strcpy(Cselection, "rock");
        else if (num == 1)
            strcpy(Cselection, "paper");
        else if (num == 2)
            strcpy(Cselection, "scissor");
        
        printf("PC: %s\n", Cselection);
    
        if (strcasecmp(Cselection, Pselection) == 0);
        else if (strcasecmp(Cselection, "rock") == 0 && strcasecmp(Pselection, "paper") == 0) Ppoints++;
        else if (strcasecmp(Cselection, "paper") == 0 && strcasecmp(Pselection, "rock") == 0) Cpoints++;
        else if (strcasecmp(Cselection, "scissor") == 0 && strcasecmp(Pselection, "paper") == 0) Cpoints++;
        else if (strcasecmp(Cselection, "paper") == 0 && strcasecmp(Pselection, "scissor") == 0) Ppoints++;
        else if (strcasecmp(Cselection, "scissor") == 0 && strcasecmp(Pselection, "rock") == 0) Ppoints++;
        else if (strcasecmp(Cselection, "rock") == 0 && strcasecmp(Pselection, "scissor") == 0) Cpoints++;
        else printf("\t*******\tSelection Error! Please check your selection and try again.\t*******\t\n");
        
        printf("Score: %d/%d\n\n", Ppoints, Cpoints);
    }

    if (Ppoints >= Cpoints)
        puts("Congratulations! You Won!");
    else
        puts("Better Luck Next Time! PC Won!");

    return 0;
}