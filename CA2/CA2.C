#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "check.h"
#include "playing.h"
#include "print.h"
#include "dealcard.h"
#include "shuffle.h"

int main()
{
    int team1_round = 0;
    int team2_round = 0;

    do
    {
        int card[44];
        shuffle_card(card);
        int p1[11];
        int p2[11];
        int p3[11];
        int p4[11];
        deal5(p1, card, 0);
        printf("\nTo Start the game,choose your circular from your 5 first card \n\nif you want A,enter 0\tif you want B,enter 1\nif you want C,enter 2\tif you want D,enter 3\n\n");
        printf("\n\t");
        for (int i = 0; i < 5; i++)
        {
            int num_for_circ = p1[i] % 11;
            if (num_for_circ == 0)
                num_for_circ = 11;
            if (p1[i] / 11 == 0)
                printf("A");
            if (p1[i] / 11 == 1)
                printf("B");
            if (p1[i] / 11 == 2)
                printf("C");
            if (p1[i] / 11 == 3)
                printf("D");
            printf("%d\t", num_for_circ);
        } /*printing the player1 5 first card for selecting the circular*/
        printf("\n");
        int y, circular = -1;
        do
        {
            scanf("%d", &y);
            switch (y)
            {
            case 0:
                circular = 0;
                break;

            case 1:
                circular = 1;
                break;

            case 2:
                circular = 2;
                break;

            case 3:
                circular = 3;
                break;

            default:
                printf("The Entered number is invalid , please enter from the above box \n");
                break;
            }
        } while (circular < 0 || circular > 3); /*getting the circular from the user*/

        deal5(p2, card, 5);
        deal5(p3, card, 10);
        deal5(p4, card, 15);
        deal4(p1, card, 20);
        deal4(p2, card, 24);
        deal4(p3, card, 28);
        deal4(p4, card, 32);
        deal2(p1, card, 36);
        deal2(p2, card, 38);
        deal2(p3, card, 40);
        deal2(p4, card, 42);
        /*dealing cards to players*/

        int player1[4][11] = {0};
        int player2[4][11] = {0};
        int player3[4][11] = {0};
        int player4[4][11] = {0};
        fillplayers(p1, player1);
        fillplayers(p2, player2);
        fillplayers(p3, player3);
        fillplayers(p4, player4);
        /*fill the player 2D arrays with 0&1*/
        int team1 = 0;
        int team2 = 0;

        int turn = 1;
        while (team1 < 6 && team2 < 6) /*while loop for repeating the game in many rounds*/
        {
            if (turn == 1) /*when the turn is with player1*/
            {
                print_mine(p1);
                printf("\n\nyou should play one of your cards so enter from the mentioned indexes : \n");
                int play1;
                scanf("%d", &play1);
                /*getting the card1 from player1*/
                int num_play = p1[play1] % 11;
                if (num_play == 0)
                    num_play = 11;
                printf("\nyou choose ");
                if (p1[play1] / 11 == 0)
                    printf("A");
                if (p1[play1] / 11 == 1)
                    printf("B");
                if (p1[play1] / 11 == 2)
                    printf("C");
                if (p1[play1] / 11 == 3)
                    printf("D");
                printf("%d\t\n", num_play);
                /*printing the choice of player1*/
                printf("\nwaiting for other players...\n");
                Sleep(2000);
                int sym1 = p1[play1] / 11;
                int play2 = firstPlay(player2, circular, sym1);
                int play3 = firstPlay(player3, circular, sym1);
                int play4 = firstPlay(player4, circular, sym1);
                /*find the starting card of player2*/
                turn = check_in_round(p1, play1, play2, play3, play4, circular); /*judge*/
                if (turn == 1 || turn == 3)
                {
                    team1++;
                    print_screen(p1, play1, play2, play3, play4, team1, team2, 0);
                    printf("\n\nteam1 got 1 point\n\nwaiting for next round...");
                    /*print screen after showing all of cards */
                }
                else
                {
                    team2++;
                    print_screen(p1, play1, play2, play3, play4, team1, team2, 0);
                    printf("\n\nteam2 got 1 point\n\nwaiting for next round...");
                }
                Sleep(7500);
                system("cls");
                if (team1 == 6)
                {
                    team1_round++;
                    continue;
                }
                if (team2 == 6)
                {
                    team2_round++;
                    continue;
                }
                p1[play1] = -1;
                player2[play2 / 11][play2 % 11] = 0;
                player3[play3 / 11][play3 % 11] = 0;
                player4[play4 / 11][play4 % 11] = 0;
                /*changing cards after playing*/
            }
            if (turn == 2) /*when the turn is with player2*/
            {
                int play2 = start(player2, circular); /*find the starting card of player2*/
                int sym = play2 / 11;
                int play3 = firstPlay(player3, circular, sym);
                int play4 = firstPlay(player4, circular, sym);

                print_screen(p1, 0, play2, play3, play4, team1, team2, 2);
                printf("\n");
                print_mine(p1);
                printf("\n\nyou should play one of your cards so enter from the mentioned indexes : \n");
                int play1;
                scanf("%d", &play1);
                turn = check_in_round(p1, play1, start(player2, circular), play3, play4, circular); /*judge*/
                system("cls");

                if (turn == 1 || turn == 3)
                {
                    team1++;
                    print_screen(p1, play1, play2, play3, play4, team1, team2, 0);
                    printf("\n\nteam1 got 1 point\n\nwaiting for next round...");
                }
                else
                {
                    team2++;
                    print_screen(p1, play1, play2, play3, play4, team1, team2, 0);
                    printf("\n\nteam2 got 1 point\n\nwaiting for next round...");
                }
                Sleep(7500);
                system("cls");
                if (team1 == 6)
                {
                    team1_round++;
                    continue;
                }
                if (team2 == 6)
                {
                    team2_round++;
                    continue;
                }
                p1[play1] = -1;
                player2[play2 / 11][play2 % 11] = 0;
                player3[play3 / 11][play3 % 11] = 0;
                player4[play4 / 11][play4 % 11] = 0;
                /*changing cards after playing*/
            }
            if (turn == 3) /*when the turn is with player3*/
            {
                int play3 = start(player3, circular); /*find the starting card of player3*/
                int sym = play3 / 11;
                int play4 = firstPlay(player4, circular, sym); /*find the choice of player4*/

                print_screen(p1, 0, 0, play3, play4, team1, team2, 3);
                printf("\n");

                print_mine(p1); /*show mine cards*/
                printf("\n\nyou should play one of your cards so enter from the mentioned indexes : \n");
                int play1;
                scanf("%d", &play1);

                int play2 = firstPlay(player2, circular, sym);                                      /*find the choice of player2*/
                turn = check_in_round(p1, play1, play2, start(player3, circular), play4, circular); /*judge*/
                system("cls");

                if (turn == 1 || turn == 3)
                {
                    team1++;
                    print_screen(p1, play1, play2, play3, play4, team1, team2, 0);
                    printf("\n\nteam1 got 1 point\n\nwaiting for next round...");
                }
                else
                {
                    team2++;
                    print_screen(p1, play1, play2, play3, play4, team1, team2, 0);
                    printf("\n\nteam2 got 1 point\n\nwaiting for next round...");
                }
                Sleep(7500);
                system("cls");
                if (team1 == 6)
                {
                    team1_round++;
                    continue;
                }
                if (team2 == 6)
                {
                    team2_round++;
                    continue;
                }
                p1[play1] = -1;
                player2[play2 / 11][play2 % 11] = 0;
                player3[play3 / 11][play3 % 11] = 0;
                player4[play4 / 11][play4 % 11] = 0;
                /*changing cards after playing*/
            }
            if (turn == 4) /*when the turn is with player4*/
            {
                int play4 = start(player4, circular); /*find the starting card of player4*/
                int sym = play4 / 11;

                print_screen(p1, 0, 0, 0, play4, team1, team2, 4);
                printf("\n");
                print_mine(p1);
                printf("\n\nyou should play one of your cards so enter from the mentioned indexes : \n");
                int play1;
                scanf("%d", &play1);

                int play2 = firstPlay(player2, circular, sym);
                int play3 = firstPlay(player3, circular, sym);
                /*find the choice of player2 & 3*/
                turn = check_in_round(p1, play1, play2, start(player3, circular), play4, circular); /*judge*/
                system("cls");
                if (turn == 1 || turn == 3)
                {
                    team1++;
                    print_screen(p1, play1, play2, play3, play4, team1, team2, 0);
                    printf("\n\nteam1 got 1 point\n\nwaiting for next round...");
                }
                else
                {
                    team2++;
                    print_screen(p1, play1, play2, play3, play4, team1, team2, 0);
                    printf("\n\nteam2 got 1 point\n\nwaitinging for next round...");
                }
                Sleep(7500);
                system("cls");
                if (team1 == 6)
                {
                    team1_round++;
                    continue;
                }
                if (team2 == 6)
                {
                    team2_round++;
                    continue;
                }
                p1[play1] = -1;
                player2[play2 / 11][play2 % 11] = 0;
                player3[play3 / 11][play3 % 11] = 0;
                player4[play4 / 11][play4 % 11] = 0;
                /*changing cards after playing*/
            }
        }
        printf("\nSets Of Team1 is %d\t\t\t\t\tSets Of Team2 is %d\n\n", team1_round, team2_round);
    } while (team1_round < 3 && team2_round < 3); /*while for repeating round to 3*/

    if (team1_round == 3)
        printf("\n\n\n\t\t\tCongratulations,Winner is Team1");
    if (team2_round == 3)
        printf("\n\n\n\t\t\tUnfortunately,Winner is Team2 :)");
    /*print the result of game*/

    char x;
    scanf("%c", &x);
}
