
void deal5(int p[], int x[], int k) /*function that give 5 card to players*/
{
    for (int i = 0; i < 5; i++)
    {
        p[i] = x[k];
        k++;
    }
}
void deal4(int p[], int x[], int k) /*function that give 4 card to players*/
{
    for (int i = 5; i < 9; i++)
    {
        p[i] = x[k];
        k++;
    }
}
void deal2(int p[], int x[], int k) /*function that give 2 card to players*/
{
    for (int i = 9; i < 11; i++)
    {
        p[i] = x[k];
        k++;
    }
}

void fillplayers(int p[], int x[][11]) /*function for filling 2D players(arrays) with 0&1 nubers*/

{
    for (int i = 0; i < 11; i++)
    {
        x[p[i] / 11][p[i] % 11] = 1;
    }
}