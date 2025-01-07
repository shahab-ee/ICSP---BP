
int firstPlay(int p[][11], int circ, int sym) /*function that return a card from 3 players after playing one card by another player*/
{
    int num_play;
    int sym_play;
    int nSym = 0;
    for (int i = 0; i < 11; i++)
    {
        if (p[sym][i] == 1)
            nSym++;
    }/*counting number of the playing card symbol*/
    int nCirc = 0;
    if (nSym == 0)
    {
        for (int i = 0; i < 11; i++)
        {
            if (p[circ][i] == 1)
                nCirc++;
        }
    }/*counting the number of circular cards*/
    if ((nSym == 0) && (nCirc == 0))
    {
        for (int i = 3; i > -1; i--)
            if ((i != circ) && (i != sym))
            {
                for (int j = 0; j < 11; j++)
                {
                    if (p[i][j] == 1)
                    {
                        if (j == 0)
                        {
                            return (11 * i + 11);
                        }
                        else
                            return (11 * i + j);
                    }
                }
            }
            else
                continue;
    } /*finding the return of cards when there is no circular and playing symbol*/
    if ((nSym == 0) && (nCirc != 0))
    {
        for (int i = 3; i > -1; i--)
            if (i == circ)
            {
                for (int j = 10; j > -1; j--)
                {
                    if (p[i][j] == 1)
                    {
                        if (j == 0)
                        {
                            return (11 * i + 11);
                        }
                        else
                            return (11 * i + j);
                    }
                }
            }
            else
                continue;
    } /*finding the return of cards when there is a circular and we dont have playing symbol*/
    if (nSym != 0)
    {
        for (int i = 3; i > -1; i--)
            if (i == sym)
            {
                for (int j = 10; j > -1; j--)
                {
                    if (p[i][j] == 1)
                    {
                        if (j == 0)
                        {
                            return (11 * i + 11);
                        }
                        else
                            return (11 * i + j);
                    }
                }
            }
    }/*finding the return of cards when the player have something from playing symbol*/
}

int start(int p[][11], int circ)/*function for selecting which card to play for the player when he starts*/
{
    int maxA = -1;
    for (int i = 10; i > -1; i--)
    {
        if (p[0][i] == 1 && circ != 0)
        {
            maxA = i;
            break;
        }
    }

    int maxB = -1;
    for (int i = 10; i > -1; i--)
    {
        if (p[1][i] == 1 && circ != 1)
        {
            maxB = i;
            break;
        }
    }

    int maxC = -1;
    for (int i = 10; i > -1; i--)
    {
        if (p[2][i] == 1 && circ != 2)
        {
            maxC = i;
            break;
        }
    }

    int maxD = -1;
    for (int i = 10; i > -1; i--)
    {
        if (p[3][i] == 1 && circ != 3)
        {
            maxD = i;
            break;
        }
    }
    /*finding maximum of 4 symbols*/

    if (maxA >= maxB && maxA >= maxC && maxA >= maxD)
        return maxA;

    else if (maxB >= maxA && maxB >= maxC && maxB >= maxD)
        return 11 + maxB;

    else if (maxC >= maxA && maxC >= maxB && maxC >= maxD)
        return 22 + maxC;

    else if (maxD >= maxA && maxD >= maxB && maxD >= maxD)
        return 33 + maxD;
    /*finding the return when the player have a card except the circular*/

    int maxCirc;
    if (maxA == -1 && maxB == -1 && maxC == -1 && maxD == -1)
    {
        for (int i = 10; i > -1; i--)
            if (p[circ][i] == 1)
            {
                maxCirc = i;
                break;
            }

        return 11 * circ + maxCirc;
    }/*finding the return when the player should play from circulars*/
}