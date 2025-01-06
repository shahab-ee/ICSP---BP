#include <stdio.h>
int main()
{

  float a, b, c, fault;

  scanf("%f", &a);
  scanf("%f", &b);
  scanf("%f", &c);
  scanf("%f", &fault);
  /*the process for getting the factors and fault of equation*/

  float max;
  if (a > b)
    max = a;
  else
    max = b; /*finding the maximum of the factors*/
  if (c > max)
    max = c;

  int num_of_answers = 0;
  float lim = max * max;
  float i = -lim;
  float result;
  while (i <= lim)
  { /*the loop which puts the numbers beetween the period */

    result = i * i * i + a * i * i + b * i + c; /*calculating the amount of equation*/

    if ((result >= 0 && result < 0.1) || (result <= 0 && result > -0.1)) /*condition that tell the equations is aproximately is 0*/
    {
      printf("\n %.3f\n", i); /*showing the answer*/
      i += 30 * fault;
      num_of_answers++;
    }
    i += fault / 10;
  } /*enf of while*/

  for (int j = num_of_answers + 1; j <= 3; j++)
  {
    printf("NO ROOT\n");
  }
  char ch; /*the exit process*/
  printf("\nPress any key and then ENTER key to Continue\n");
  scanf("%s", &ch);
  return 0;
}