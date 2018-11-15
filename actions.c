#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

int InOrder(file, int size)
{
  int i=0;
  while (i != size)
  {
    printf("%s ; %s\n", file[i].temps, file[i].pouls);
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
