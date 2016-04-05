#include <stdio.h>
#include <stdlib.h>

int size = 32;
int main()
{
  int i, j;

  int** grid=malloc(size*sizeof(int)); 

  for(i = 0; i < size; i++)
    grid[i]=malloc(size*sizeof(int));

  FILE *file;
  file=fopen("input.txt", "r");

  for(i = 0; i < size; i++)
  {
    if (i != 0)
     printf("\n");

    for(j = 0; j < size; j++) 
    {
        fscanf(file, "%d", &grid[i][j]);
        if (!fscanf(file, "%d", &grid[i][j])) 
           break;
        printf("%d",grid[i][j]); 
    }

  }
  printf("\n");
  fclose(file);
}