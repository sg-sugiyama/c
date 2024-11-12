#include <stdio.h>

void sort(int *nums, int size)
{

  for (int i = 0; i < size - 1; i++)
  {
    for (int j = size - 1; j > i; j--)
    {
      if (nums[j] < nums[j - 1])
      {
        int temp = nums[j];
        nums[j] = nums[j - 1];
        nums[j - 1] = temp;
      }
    }
  }
}

void printNums(int nums[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", nums[i]);
  puts("");
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  const int N = 5;
  int nums[N];

  for (int i = 0; i < N; i++)
  {
    printf("%d番目の数字を入力 > ", i + 1);
    scanf("%d", &nums[i]);
  }

  puts("\n==========================");
  puts("--- ソート前 ---");
  printNums(nums, N);

  sort(nums, N);

  puts("\n--- ソート後 ---");
  printNums(nums, N);

  return 0;
}
