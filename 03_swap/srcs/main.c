#include <stdio.h>

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  int first, second;

  printf("1番目の数字を入力 > ");
  scanf("%d", &first);
  printf("2番目の数字を入力 > ");
  scanf("%d", &second);

  puts("\n==========================");
  puts("--- 入れ替え前 ---");
  printf("1番目の数字: %d\n", first);
  printf("2番目の数字: %d\n\n", second);

  int tmp = first;
  first = second;
  second = tmp;

  puts("--- 入れ替え後 ---");
  printf("1番目の数字: %d\n", first);
  printf("2番目の数字: %d\n", second);

  return 0;
}
