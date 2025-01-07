
void print_screen(int p[], int x, int p2, int p3, int p4, int t1, int t2, int turn)/*function for printing the board game */
{
    printf("\t");
    for (int i = 0; i < 23; i++)
        printf(" ");
    printf(" P3");
    for (int i = 0; i < 23; i++)
        printf(" ");

    printf("\n\t");

    for (int i = 0; i < 52; i++)
        printf("-");
    printf("\tTeam 1 = %d", t1); /*printing the score of team1*/
    printf("\n\t");

    printf("|");
    for (int i = 0; i < 23; i++)
        printf(" ");
    if (turn == 2 || turn == 3 || turn == 0)
    {
        if (p3 / 11 == 0)
            printf("A");
        if (p3 / 11 == 1)
            printf("B");
        if (p3 / 11 == 2)
            printf("C");
        if (p3 / 11 == 3)
            printf("D");
        int z;
        if (p3 % 11 == 0)
            z = 11;
        else
            z = p3 % 11;
        printf("%2d", z);
    }/*printing the Player3 card*/
    else
        printf("   ");

    for (int i = 0; i < 24; i++)
        printf(" ");
    printf("|\n\t");

    for (int j = 0; j < 6; j++)
    {
        printf("|");
        for (int i = 0; i < 50; i++)
            printf(" ");
        printf("|\n\t");
    }
    printf("|");
    for (int i = 0; i < 50; i++)
        printf(" ");
    printf("|\n");

    printf("     P2 | ");
    if (turn == 2 || turn == 0)
    {
        if (p2 / 11 == 0)
            printf("A");
        if (p2 / 11 == 1)
            printf("B");
        if (p2 / 11 == 2)
            printf("C");
        if (p2 / 11 == 3)
            printf("D");
        int y;
        if (p2 % 11 == 0)
            y = 11;
        else
            y = p2 % 11;
        printf("%2d", y);
    }/*printing the player2 card*/
    else
        printf("   ");

    for (int i = 0; i < 41; i++)
        printf(" ");

    if (turn == 2 || turn == 3 || turn == 4 || turn == 0)
    {
        if (p4 / 11 == 0)
            printf("A");
        if (p4 / 11 == 1)
            printf("B");
        if (p4 / 11 == 2)
            printf("C");
        if (p4 / 11 == 3)
            printf("D");
        int t;
        if (p4 % 11 == 0)
            t = 11;
        else
            t = p4 % 11;
        printf("%2d ", t);
    }/*printing the player4 card*/
    else
        printf("   ");

    printf(" | P4");
    printf("\n\t");

    for (int j = 0; j < 7; j++)
    {
        printf("|");
        for (int i = 0; i < 50; i++)
            printf(" ");
        printf("|\n\t");
    }

    printf("|");
    for (int i = 0; i < 23; i++)
        printf(" ");
    if (turn == 1 || turn == 0)
    {
        if (p[x] / 11 == 0)
            printf("A");
        if (p[x] / 11 == 1)
            printf("B");
        if (p[x] / 11 == 2)
            printf("C");
        if (p[x] / 11 == 3)
            printf("D");
        int k;
        if (p[x] % 11 == 0)
            k = 11;
        else
            k = p[x] % 11;
        printf("%2d", k);
    }/*printing the player1 card*/
    else
        printf("   ");

    for (int i = 0; i < 24; i++)
        printf(" ");
    printf("|\n\t");

    for (int i = 0; i < 52; i++)
        printf("-");
    printf("\tTeam 2 = %d", t2); /*printing the score of team2*/
    printf("\n\t");

    for (int i = 0; i < 23; i++)
        printf(" ");
    printf(" P1");
}

void print_mine(int p[])/*function for showing our cards*/
{
    printf("\n\t  ");
    for (int i = 0; i < 44; i++)
        printf("-");
    printf("\n  symbol  ");
    for (int i = 0; i < 11; i++)
    {
        printf("|");

        if (p[i] == -1)
            printf("--");
        else
        {
            if (p[i] / 11 == 0)
                printf(" A");
            if (p[i] / 11 == 1)
                printf(" B");
            if (p[i] / 11 == 2)
                printf(" C");
            if (p[i] / 11 == 3)
                printf(" D");
        }/*finding the symbol to show*/
        printf("|");
    }
    printf("\n\t  ");
    for (int i = 0; i < 44; i++)
        printf("-");

    printf("\n  number  ");
    for (int i = 0; i < 11; i++)
    {
        int k = p[i] % 11;
        if (k == 0)
            k = 11;
        printf("|");
        if (p[i] == -1)
            printf("--");
        else
            printf("%2d", k);
        printf("|");
    }/*finding the number to show*/
    printf("\n\t  ");
    for (int i = 0; i < 44; i++)
        printf("-");

    printf(" ");
    printf("\n  index   ");
    for (int i = 0; i < 11; i++)
    {
        printf("|");
        printf("%2d", i);
        printf("|");
    }/*showing the index of a card*/
}