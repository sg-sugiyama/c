#include <stdio.h>
#include <stdlib.h>
#include "animal_concert.h"

const char *animalTypeLabels[] = {
    "猫",
    "犬",
    "うさぎ",
    "ライオン",
};

static void catSound(Animal_t *animal) { printf(animal->price >= THOUSAND(200) ? "\"meow meow!!\"\n" : "\"meow...\"\n"); }
static void dogSound(Animal_t *animal) { printf(animal->price >= THOUSAND(150) ? "\"aooooo!!\"\n" : "\"bowwow!\"\n"); }
static void rabbitSound(Animal_t *animal)
{
  (void)animal;
  printf("\"...\"\n");
}
static void lionSound(Animal_t *animal) { printf(animal->price >= THOUSAND(300) ? "\"grrrrrrr!!!\"\n" : "\"grrr...\"\n"); }

static void (*makeSound[4])(Animal_t *) = {catSound, dogSound, rabbitSound, lionSound};

void printAnimals(Animal_t *animals)
{

  printf("==========\n"
         " 動物一覧 \n"
         "==========\n");
  for (int i = 0; i < ANIMAL_NUM; i++)
  {
    printf("--- %d匹目 ---\n", i + 1);
    printf("種類\t: %s\n", animalTypeLabels[animals[i].type]);
    printf("名前\t: %s\n", animals[i].name);
    printf("チップ\t: %'d万円\n", JP_YEN(animals[i].price));
    puts("");
  }
}

void startAnimalConcert(Animal_t animals[])
{
  printAnimals(animals);

  printf("動物を選んでください。\n");
  while (1)
  {
    for (int i = 0; i < ANIMAL_NUM; i++)
    {
      printf("%d: %s\n", i + 1, animalTypeLabels[animals[i].type]);
    }

    int selectedIndex;
    scanf("%d", &selectedIndex);
    selectedIndex--;

    if (selectedIndex < 0 || selectedIndex >= ANIMAL_NUM)
    {
      printf("正しい動物を選択してください。\n");
      continue;
    }

    Animal_t selectedAnimal = animals[selectedIndex];

    int afterPrice = selectedAnimal.price += THOUSAND(50);
    if (afterPrice > MILLION(1))
    {
      printf("これ以上チップを変更できません。\n\n");
      continue;
    }
    animals[selectedIndex].price = afterPrice;

    printAnimals(animals);
    makeSound[selectedAnimal.type](&selectedAnimal);
  }
}
