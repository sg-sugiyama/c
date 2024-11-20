#include <stdio.h>

int fibonacci(int n)
{
  return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  printf("表示する範囲を指定\n*** 30以下の自然数のみ ***\n");

  int start, end;
  printf("開始 > ");
  scanf("%d", &start);
  printf("終了 > ");
  scanf("%d", &end);

  if (start <= 0 || end <= 0)
  {
    printf("自然数を入力してください。\n");
    return 0;
  }

  if (start >= 30 || end >= 30)
  {
    printf("30以下の自然数を入力してください。\n");
    return 0;
  }

  for (int n = start - 1; n < end; n++)
    printf("%d ", fibonacci(n));
  puts("");

  return 0;
}
