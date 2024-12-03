#include <stdio.h>
#include <stdlib.h>
#include "animal_concert.h"

int main(int argc, char **argv)
{

  if (argc < 5)
  {
    printf("引数の数が正しくありません。\n"
           "%s 猫の名前 うさぎの名前 犬の名前 ライオンの名前\n",
           argv[0]);
    return 1;
  }
  Animal_t animals[] = {
      {Cat, 0, NULL},
      {Rabbit, 0, NULL},
      {Dog, 0, NULL},
      {Lion, 0, NULL},
  };
  for (int i = 1; i < argc; i++)
  {
    char *name = malloc(sizeof(argv[i]));
    name = argv[i];
    animals[i - 1].name = name;
  }

  startAnimalConcert(animals);

  for (int i = 0; i < ANIMAL_NUM; i++)
  {
    free(animals[i].name);
  }

  return 0;
}
