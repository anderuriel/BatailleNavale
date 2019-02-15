#include <stdio.h>

void AfficherRegles()
{
    printf("Regles De La Bataille Navale:\n -Machin \n -Truc \n -Kaarthi\n");
}
void AfficherScoreboard()
{
    printf("Scores :\n Ander ---- 9999pts\n Jan ---- 2pts\n Johny ---- 420pts\n");
}

int main()
{
    int choice;
    choose:
    printf("Afficher Règles - 1 \n""Afficher Scoreboard - 2 \n""Jouer - 3 \n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            AfficherRegles();
            goto choose;
        case 2:
            AfficherScoreboard();
            goto choose;
        case 3:

            break;
        default:
            printf("Choisis un chiffre entre 1 et 3 Einstein\n");
            goto choose;
            break;
    }
    return 0;
}

