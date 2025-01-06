#include <stdio.h>

int main()
{

  printf("Hi , we are going to help you in finding the place and number of jumps you need to see your score \n so please tell us below information\n\n");
  int room_floor;
  printf("please enter the room number:\n"); /*getting the floor and room number*/
  scanf("%d", &room_floor);

  float jump_height;
  printf("enter your first jump height (a number smaller than 1):\n"); /*getting the height of first jump*/
  scanf("%f", &jump_height);

  int floor = room_floor / 100; /*calculating room number and floor number*/
  int room_num = room_floor % 100;
  int min_height = 2 * floor + 1; /*Calculating the minimum height */
  int area;
  if ((room_num <= 4) && (room_num >= 1))
    area = 1;
  if ((room_num <= 8) && (room_num > 4))
    area = 2;
  if ((room_num <= 12) && (room_num > 8))
    area = 3;
  if ((room_num <= 16) && (room_num > 12))
    area = 4;
  /*finding the area of room*/
  int jump_num = 0;
  float jump_sum = jump_height;
  while (jump_sum < min_height) /*doing the process that find the last  jump height*/
  {
    jump_sum += 0.5 * jump_height;
    jump_num++;
  }
  printf("if you want to see your score you should be in %dth area and have %d jumps\n\n\n", area, jump_num); /*showing the result*/
  char ch;
  printf("Press any key and then ENTER key to Continue\n"); /*the exit process*/
  scanf("%s", &ch);
  return 0;
}
