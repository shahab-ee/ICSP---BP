#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n); /* getting days of checking*/

    printf("you can see the list of foods and their calories below: \n\n"); /*showing the menu of foods*/
    printf("1-makarani=329\n2-ghorme sabzi=127\n3-havij polo=61\n4-khoresh karafs=83\n5-sabzi polo ba mahi=156\n6-cholo gardan=296\n7-kale pache=496\n8-kotlet=73\n9-ash reshte=34\n10-salad shirazi=16\n\n");

    int calories_sum = 0;
    int x;
    for (int i = 1; i <= n; i++)
    {
        int day_calory = 0;

        do
        {
            scanf("%d", &x);
            switch (x) /*a switch for getting the foods for each day*/
            {
            case 1:
                day_calory = 329;
                break;

            case 2:
                day_calory = 127;
                break;

            case 3:
                day_calory = 61;
                break;

            case 4:
                day_calory = 83;
                break;

            case 5:
                day_calory = 156;
                break;

            case 6:
                day_calory = 296;
                break;

            case 7:
                day_calory = 496;
                break;

            case 8:
                day_calory = 73;
                break;

            case 9:
                day_calory = 34;
                break;

            case 10:
                day_calory = 16;
                break;

            default:
                printf("you didnt choose from the list,choose from 1 to 10\n");
                break; /*condition for getting food again*/
            }          /*end of switch*/
        } while (day_calory == 0);
        calories_sum += day_calory; /*adding day calory to the sum of calories*/
    }

    if (calories_sum < 100 * n)
    {
        printf("\nLAGHAR", n);
    }
    else if (calories_sum > 100 * n)
    {
        printf("\nCHAGH", n); /*conditions for showing the result*/
    }
    else
    {
        printf("\nBEDOONE TAGHIR", n);
    }

    char ch;
    printf("\nPress any key and then ENTER key to Continue\n"); /*the exit process*/
    scanf("%s", &ch);
    return 0;
}