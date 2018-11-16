#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

int InOrder(file, int size)
{
  int i=0;
  while (i != size)
  {
    printf("%ld ; %d\n", file[i].temps, file[i].pouls);
    i++;
  }
}
  
int Increasing(file, int size, char data)
{
  int messy = TRUE;
  while (messy)
  {
    messy = FALSE;
    for (int j = 0; j < size-1; j++)
        {
            if(file[j].data > file[j+1].data)
            {
                int tmp = file[j+1].data;
                file[j+1].data = file[j].data;
                file[j].data = tmp;
                messy = TRUE;
            }
        }
    }
    return file;
}

int Decreasing(file, int size, char data)
{
  int messy = TRUE;
  while (messy)
  {
    messy = FALSE;
    for (int j = 0; j < size-1; j++)
        {
            if(file[j].data > file[j+1].data)
            {
                int tmp = file[j+1].data;
                file[j+1].data = file[j].data;
                file[j].data = tmp;
                messy = TRUE;
            }
        }
    }
    return file;
}
int average(file)
{
  int a;
  int b;
  int i;
  int ave=0;
  int nb;
  printf("A partir de quel temps voulez vous commencer la moyenne des pouls?");
  scanf("%d", &a);
  printf("Jusqu'à quel temps voulez vous faire la moyenne des pouls?");
  scanf("%d", &b);
  while (file[i].temps < b)
  {
    while (file[i].temps < a)
      {
	i++;
      }
    ave += file[i].pouls;
    nb++;
    i++;
  }
  return ave / nb;
}

int size(int ArraySize)
{
  return ArraySize
}

int MaxMin(file, int size)
{
  int a;
  printf ("Voulez vous la valeur maximum ou minimum?\n1: max\n2: min");
  scanf("%d", &a);
  int i;
  int val;
  if (a = 1)
  {
    for (i=0; i <= size; i++)
      {
    if (file[i].pouls > val)
      val = i;
      }
    printf("%ld ; %d\n", file[val].temps, file[val].pouls);
  }
  
  else if (a = 2)
  {
    for (i=0; i <= size; i++)
      {
	if (file[i].pouls > val)
	  val = i;
      }
    printf("%ld ; %d\n", file[val].temps, file[val].pouls);
  }
}

int main()
{
  int a=0;
  switch (a)
  {
  case 2:
    int b;
    printf("Quelle donnée voulez vous trier?\n1: pouls\n2: temps\n");
    scanf("%d", b);
    if (b == 1)
    {
      printf(Increasing(fichier, 5, "pouls"));
    }
    else if (b == 2)
    {
      printf(Increasing(fichier, 5, "temps"));
    }
    else
      printf("error");
      
  case 3:
    int c;
    printf("Quelle donnée voulez vous trier?\n1: pouls\n2: temps\n");
    scanf("%d", c);
        if (c == 1)
    {
      printf(Decreasing(fichier, 5));
    }
    else if (c == 2)
    {
      printf(Decreasing(fichier, 5));
    }
    else
      printf("error");
      
  default:
    printf("error");
    break;
  }
}
