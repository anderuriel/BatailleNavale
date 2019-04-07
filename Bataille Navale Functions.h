//
//Tittle : Bataille Navale Functions
// Created by Ander.URIEL-GLARIA on 22.03.2019.
//
#ifndef BATAILLENAVALE_BATAILLE_NAVALE_FUNCTIONS_H
#define BATAILLENAVALE_BATAILLE_NAVALE_FUNCTIONS_H
#define GRIDSIZE 10
#define SMALLSHIPHP 2
#define MEDIUMSHIPHP 3
#define LARGESHIPHP 4
#define HUGESHIPHP 5
//Display The Grid
void displayGrid(char grid [GRIDSIZE][GRIDSIZE])
{
    char miss = 'O';
    char ship = 'X';
    char water = '~';
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i = 0; i < GRIDSIZE; i++)
    {
        printf("%d ",i );
        for(int j = 0; j < GRIDSIZE; j++)
        {
            switch (grid[i][j])
            {
                case '~':
                    printf("%c ", water);
                    break;
                case 's':
                    printf("%c ", ship);
                    break;
                case 'm':
                    printf("%c ", ship);
                    break;
                case 'l':
                    printf("%c ", ship);
                    break;
                case 'h':
                    printf("%c ", ship);
                    break;
                case 'x':
                    printf("%c ", miss);
                    break;
            }
        }
        printf("\n");
    }
}
//Play
void play(int grid[GRIDSIZE][GRIDSIZE], char visualgrid[GRIDSIZE][GRIDSIZE])
{
    system("cls");
    int smallhp = SMALLSHIPHP, mediumhp = MEDIUMSHIPHP, largehp = LARGESHIPHP, hugehp = HUGESHIPHP,numberOfShips = 4, score = 100,row,col;
    char hit;
    bool GameIsActive = true;
    while (GameIsActive)
    {
        displayGrid(visualgrid);
        printf("Your current score: %d \n",score);
        printf("choose a column (x axis): ");
        scanf("%d", &col);
        printf("choose a row (y axis): ");
        scanf("%d", &row);
        hit = grid[row][col];
        system("cls");
        switch (hit)
        {
            case 1:
                printf("You already shot there...Try again\n\n");
                break;
            case 2:
                printf("You just hit a smol one...\n\n");
                visualgrid[row][col] = 's';
                grid[row][col] = 1;
                smallhp--;
                if(smallhp == 0)
                {
                    printf("You sunk a babyship.\n\n");
                    numberOfShips--;
                }
                break;
            case 3:
                printf("You just hit a medium one...\n\n");
                visualgrid[row][col] = 'm';
                grid[row][col] = 1;
                mediumhp--;
                if(mediumhp == 0)
                {
                    printf("You sunk a medium one.\n\n");
                    numberOfShips--;
                }
                break;
            case 4:
                printf("You just hit a big one !\n\n");
                visualgrid[row][col] = 'l';
                grid[row][col] = 1;
                largehp--;
                if(largehp == 0)
                {
                    printf("You sunk a big boi.\n\n");
                    numberOfShips--;
                }
                break;
            case 5:
                printf("you just hit a huge one !!\n\n");
                visualgrid[row][col] = 'h';
                grid[row][col] = 1;
                hugehp--;
                if(hugehp == 0)
                {
                    printf("You sunk a big boss !\n\n");
                    numberOfShips--;
                }
                break;
            default:
                printf("You hit a miss !\n\n");
                visualgrid[row][col] = 'x';
                grid[row][col] = 1;
                score--;
                break;
        }
        if(numberOfShips == 0 )
            GameIsActive = false;
    }
    printf("Congrats ! You won !\n\nYour Reward:\n-Nothing\n\n");
    printf("Your final score: %d \n",score);
}
//Choose Grid
void chooseGrid(int grid1 [GRIDSIZE][GRIDSIZE] ,int grid2 [GRIDSIZE][GRIDSIZE] ,int grid3 [GRIDSIZE][GRIDSIZE],char visualgrid[GRIDSIZE][GRIDSIZE])
{
    system("cls");
    int randomChoice;
    int choice;
    int r;
    printf("Play on a randomly picked grid or choose one ?\n 1 - Random\n 2 - Choose\n");
    scanf("%d",&randomChoice);
    switch (randomChoice)
    {
        case 1:
            r = rand() % 3;
            switch (r)
            {
                case 1:
                    play(grid1, visualgrid);
                    break;
                case 2:
                    play(grid2, visualgrid);
                    break;
                case 3:
                    play(grid3, visualgrid);
                    break;
                default:
                    break;
            }
        break;
        case 2:
            system("cls");
            printf("Please Choose a grid : \n Grid #1 - 1 \n Grid #2 - 2\n Grid #3 - 3\n");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                    play(grid1, visualgrid);
                    break;
                case 2:
                    play(grid2, visualgrid);
                    break;
                case 3:
                    play(grid3, visualgrid);
                    break;
                default:
                    break;
            }
        break;
    }
}
//Display Scoreboard
void scoreboard()
{
    system("cls");
    for(int i = 0; i < 4; i ++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("Yeet");
        }
        printf("\n");
    }
}
void help()
{
    system("cls");
    printf("Help:\nThe goal of playing Battleships is to sink all enemy ships,\n you first have to choose a column then choose a row,\n if you hit a ship, the program will let you know,\n as well as if you actually sink a ship\n");

}
int menu(int grid1[GRIDSIZE][GRIDSIZE],int grid2[GRIDSIZE][GRIDSIZE],int grid3[GRIDSIZE][GRIDSIZE], char visualgrid[GRIDSIZE][GRIDSIZE])
{
    int menuchoice = 0;
    while (menuchoice > 5 || menuchoice <= 0)
    {
        printf("Please choose something to do:\n1 - Play\n2 - Scoreboard\n3 - Help\n4 - Quit\n");
        scanf("%d", &menuchoice);
    }
    do {
        switch (menuchoice) {
            case 1:
                chooseGrid(grid1,grid2,grid3,visualgrid);
                printf("\nPlease choose something to do:\n1 - Play\n2 - Scoreboard\n3 - Help\n4 - Quit\n");
                scanf("%d", &menuchoice);
                break;
            case 2:
                scoreboard();
                printf("\nPlease choose something to do:\n1 - Play\n2 - Scoreboard\n3 - Help\n4 - Quit\n");
                scanf("%d", &menuchoice);
                break;
            case 3:
                help();
                printf("\nPlease choose something to do:\n1 - Play\n2 - Scoreboard\n3 - Help\n4 - Quit\n");
                scanf("%d", &menuchoice);
                break;
            case 4:
                return 0;
            default:
                printf("\nPlease choose something to do:\n1 - Play\n2 - Scoreboard\n3 - Help\n4 - Quit\n");
                scanf("%d", &menuchoice);
                break;
        }
    }while(menuchoice != 4);
}
#endif //BATAILLENAVALE_BATAILLE_NAVALE_FUNCTIONS_H
