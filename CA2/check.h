int check_in_round(int a[], int x, int b, int c, int d, int circ) /* a function for check and find the winner*/
{
    int sym1 = a[x] / 11;
    int sym2 = b / 11;
    int sym3 = c / 11;
    int sym4 = d / 11;
    /*finding the symbol of cards*/

    int num1 = a[x] % 11;
    if (num1 == 0)
        num1 = 11;

    int num2 = b % 11;
    if (num2 == 0)
        num2 = 11;

    int num3 = c % 11;
    if (num3 == 0)
        num3 = 11;

    int num4 = d % 11;
    if (num4 == 0)
        num4 = 11;
    /*finding the number of cards*/

    if ((sym1 == sym2) && (sym1 == sym3) && (sym1 == sym4) && (sym2 == sym3) && (sym2 == sym4) && (sym3 == sym4))
    {
        if ((num1 > num2) && (num1 > num3) && (num1 > num4))
            return 1;

        if ((num2 > num1) && (num2 > num3) && (num2 > num4))
            return 2;

        if ((num3 > num1) && (num3 > num2) && (num3 > num4))
            return 3;

        if ((num4 > num1) && (num4 > num2) && (num3 > num4))
            return 4;
    } /*situations which all 4 cards are same symbol*/

    if ((sym1 == circ) && (sym2 != circ) && (sym3 != circ) && (sym4 != circ))
        return 1;

    if ((sym2 == circ) && (sym1 != circ) && (sym3 != circ) && (sym4 != circ))
        return 2;

    if ((sym3 == circ) && (sym1 != circ) && (sym3 != circ) && (sym4 != circ))
        return 3;

    if ((sym4 == circ) && (sym1 != circ) && (sym2 != circ) && (sym3 != circ))
        return 4;
    /*situations which just one player has circular*/

    if ((sym2 == circ) && (sym3 == circ) && (sym4 != circ) && (sym1 != circ))
    {
        if (num2 > num3)
            return 2;
        if (num2 < num3)
            return 3;
    }
    if ((sym3 == circ) && (sym4 == circ) && (sym2 != circ) && (sym1 != circ))
    {
        if (num3 > num4)
            return 3;
        if (num3 < num4)
            return 4;
    }
    if ((sym2 == circ) && (sym4 == circ) && (sym3 != circ) && (sym1 != circ))
    {
        if (num2 > num4)
            return 2;
        if (num2 < num4)
            return 4;
    }
    if ((sym1 == circ) && (sym2 == circ) && (sym4 != circ) && (sym3 != circ))
    {
        if (num1 > num2)
            return 1;
        if (num1 < num2)
            return 2;
    }
    if ((sym3 == circ) && (sym1 == circ) && (sym2 != circ) && (sym4 != circ))
    {
        if (num3 > num1)
            return 3;
        if (num3 < num1)
            return 1;
    }
    if ((sym1 == circ) && (sym4 == circ) && (sym3 != circ) && (sym2 != circ))
    {
        if (num1 > num4)
            return 1;
        if (num1 < num4)
            return 4;
    } /*situations which 2 players played circular*/

    if ((sym1 == circ) && (sym2 == circ) && (sym3 == circ) && (sym4 != circ))
    {
        if ((num1 > num2) && (num1 > num3))
            return 1;
        if ((num2 > num1) && (num2 > num3))
            return 2;
        if ((num3 > num2) && (num3 > num1))
            return 3;
    }
    if ((sym1 == circ) && (sym2 == circ) && (sym4 == circ) && (sym3 != circ))
    {
        if ((num1 > num2) && (num1 > num4))
            return 1;
        if ((num2 > num1) && (num2 > num4))
            return 2;
        if ((num4 > num2) && (num4 > num1))
            return 4;
    }
    if ((sym1 == circ) && (sym3 == circ) && (sym4 == circ) && (sym2 != circ))
    {
        if ((num4 > num3) && (num4 > num1))
            return 4;
        if ((num1 > num3) && (num1 > num4))
            return 1;
        if ((num3 > num1) && (num3 > num4))
            return 3;
    }
    if ((sym2 == circ) && (sym3 == circ) && (sym4 == circ) && (sym1 != circ))
    {
        if ((num4 > num3) && (num4 > num2))
            return 4;
        if ((num2 > num3) && (num2 > num4))
            return 2;
        if ((num3 > num2) && (num3 > num4))
            return 3;
    } /*situations which one of players has'nt played circular*/
}
