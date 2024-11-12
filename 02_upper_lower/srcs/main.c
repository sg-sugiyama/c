#include <stdio.h>

char toUpper(char c)
{
  return 'a' <= c && c <= 'z' ? c - ('a' - 'A') : c;
}

char toLower(char c)
{
  return 'A' <= c && c <= 'Z' ? c + ('a' - 'A') : c;
}

void toUpperString(char *result, const char *string)
{
  int i = -1;
  while (string[++i])
    result[i] = toUpper(string[i]);
}

void toLowerString(char *result, const char *string)
{
  int i = -1;
  while (string[++i])
    result[i] = toLower(string[i]);
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  char string[100];
  char uppered[100];
  char lowered[100];

  printf("文字列を入力 > ");
  fgets(string, sizeof string, stdin);

  toUpperString(uppered, string);
  toLowerString(lowered, string);

  puts("\n==========================");
  puts("--- 入力 ---");
  puts(string);
  puts("--- 大文字 ---");
  puts(uppered);
  puts("--- 小文字 ---");
  puts(lowered);

  return 0;
}
