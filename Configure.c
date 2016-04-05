/*
 * configure.c configures a new grid for the game of life
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int size = 32;
int **grid;
void readingGrid();
int main()
{

	readingGrid();

	return 0;
}

void readGrid()
{
	FILE *ptr_file;
	char buffer[1000];
	ptr_file =fopen("input.txt","r");
	if (!ptr_file)
		return;

	while (fgets(buffer,1000, ptr_file)!=NULL)
	{
		printf("%s",buffer);
	}
	
	printf("\n");
	fclose(ptr_file);
}

void readingGrid()
{
	int i, j;
	i = 0;
    j = 0;
    FILE *fp;
    unsigned char ch;
    fp = fopen("input.txt","r");
    int **C;
    do {
        ch = fgetc(fp);
        if (ch != ' ' && ch != '\n') {
            C[i][j] = ch - '0';;
            j++;
            i += j / size;
            j %= size;
        }
    } while(i < size && j < size);

    //Print 2D Array:
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}


// int** newGrid(int size)
// {	
// 	int** rows = malloc(size*sizeof(int*)); 
// 	int i, j;

// 	srand(time(NULL));

// 	for (i = 0; i < size; i++) {
// 		int* values = calloc(size*size, sizeof(int));
// 		for (j = 0; j < size; j++) {
// 			int r = rand() % 2;
// 			values[j] = r;
// 		}
// 		rows[i] = values;
// 	}
// 	return rows;
// }

// void printGrid(int** grid, int size) {
// 	int i, j, count = 0;

// 	FILE *ptr_file;
// 	ptr_file = fopen("input.txt","w");
// 	if(!ptr_file) printf("File could not be opened"); 

// 	for (i = 0; i < size; i++) {
// 		if (i!= 0)
// 			fprintf(ptr_file, "\n");
// 		for (j = 0; j < size; j++) {
// 			//printf("%d", grid[i][j]);
// 			fprintf(ptr_file,"%d", grid[i][j]);
// 		}

// 	}
// 	printf("\n");
// 	fclose(ptr_file);

// }

// void updateTopBorder(int **grid)
// {
// 	FILE *ptr_file;
// 	ptr_file = fopen("input.txt","w");
// 	if(!ptr_file) printf("File could not be opened"); 

// 	int i,j;
// 	for (i = 0; i < size; i++)
// 	{
// 		for (j = 0; j < size; j++)
// 		if (i == 0){
// 			// update top border
// 			fprintf(ptr_file, 0, grid[0][j]);
// 		}
// 	}
// 	fclose(ptr_file);
// }
// // this function will set all border cells to 0
// void updateGrid(int **grid)
// {
// 	updateTopBorder(grid);

// }
