#include <stdio.h>

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  int row_num;

  printf("段数を入力してください > ");
  scanf("%d", &row_num);

  for (int i = 0; i < row_num; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      printf("%c", '*');
    }
    printf("\n");
  }
  return 0;
}