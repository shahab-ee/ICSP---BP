#include <stdio.h>

int main()
{

  int room_floor; /*getting the floor and room number */
  scanf("%d", &room_floor);

  float jump_height;  /*  getting the height of first jump*/
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
  printf("%d \n %d", area, jump_num); /*showing the result*/

  char x;
  printf("Press any key and then ENTER key to Continue\n"); /*the exit process*/
  scanf("%s", &x);
  return 0;
}
