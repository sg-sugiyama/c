#include <stdio.h>

#define THOUSAND(N) ((N) * 1000)
#define MILLION(N) THOUSAND((N) * 1000)
#define JP_YEN(N) ((N) / 10000)

typedef enum
{
  Cat,
  Dog,
  Rabbit,
  Lion,
} AnimalType;

typedef struct
{
  char name[100];
  AnimalType type;
  int price;
} Animal_t;

const char *animalTypeLabels[] = {
    "猫",
    "犬",
    "うさぎ",
    "ライオン",
};

void printAnimals(Animal_t *animals, int size)
{

  printf("==========\n"
         " 動物一覧 \n"
         "==========\n");
  for (int i = 0; i < size; i++)
  {
    printf("--- %d匹目 ---\n", i + 1);
    printf("種類\t: %s\n", animalTypeLabels[animals[i].type]);
    printf("名前\t: %s\n", animals[i].name);
    printf("値段\t: %'d万円\n", JP_YEN(animals[i].price));
    puts("");
  }
}
void sortAnimals(Animal_t *animals, int size)
{

  for (int i = 0; i < size - 1; i++)
  {
    for (int j = size - 1; j > i; j--)
    {
      if (animals[j].type < animals[j - 1].type)
      {
        Animal_t temp = animals[j];
        animals[j] = animals[j - 1];
        animals[j - 1] = temp;
      }
    }
  }
}

void startAnimalAudition(Animal_t animals[], int size)
{
  printf("動物を選んでください。\n"
         "犬かうさぎを選んだ場合\t\t：5万円値引き\n"
         "ライオンか猫を選んだ場合\t：5万円増額\n");

  while (1)
  {
    for (int i = 0; i < size; i++)
    {
      printf("%d: %s\n", i + 1, animalTypeLabels[animals[i].type]);
    }

    int selectedIndex;
    scanf("%d", &selectedIndex);
    selectedIndex--;

    if (selectedIndex < 0 || selectedIndex >= size)
    {
      printf("正しい動物を選択してください。\n");
      continue;
    }

    Animal_t selectedAnimal = animals[selectedIndex];
    int movePrice = selectedAnimal.type == Lion || selectedAnimal.type == Cat ? 50 : -50;
    int afterPrice = selectedAnimal.price += THOUSAND(movePrice);
    if (afterPrice <= 0 || afterPrice > MILLION(1))
    {
      printf("これ以上値段を変更できません。\n\n");
      continue;
    }
    animals[selectedIndex].price = afterPrice;

    printAnimals(animals, size);
  }
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  Animal_t animals[] = {
      {"トム", Cat, THOUSAND(250)},
      {"ミッフィー", Rabbit, THOUSAND(100)},
      {"シロ", Dog, THOUSAND(200)},
      {"シンバ", Lion, THOUSAND(800)},
  };

  int size = sizeof animals / sizeof animals[0];
  printAnimals(animals, size);

  startAnimalAudition(animals, size);

  return 0;
}
