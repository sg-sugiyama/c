#pragma once

#define THOUSAND(N) ((N) * 1000)
#define MILLION(N) THOUSAND((N) * 1000)
#define JP_YEN(N) ((N) / 10000)
#define ANIMAL_NUM 4

typedef enum
{
  Cat,
  Dog,
  Rabbit,
  Lion,
} AnimalType;

typedef struct
{
  AnimalType type;
  int price;
  char *name;
} Animal_t;

extern const char *animalTypeLabels[];

void printAnimals(Animal_t *animals);
void startAnimalConcert(Animal_t animals[]);