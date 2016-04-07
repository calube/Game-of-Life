#include <stdio.h>

#define WIDTH   32
#define HEIGHT  32

void init_board(int board[][HEIGHT]){
  int i, j;
  for (i = 0; i < WIDTH; i++)
    for(j = 0; j < HEIGHT; j++)
      board[i][j] = 0;
}

int compare(int a, int b){

  if(a == b)
    return 1;
  else
    return 0;
}

//Copies one array to another.
void copy(int array1[][HEIGHT], int array2[][HEIGHT])
{
	int i, j;
	for(int j = 0; j < WIDTH; j++)
		for(int i = 0; i < HEIGHT; i++)            
            array2[j][i] = array1[j][i]; 
}

void print(int board[][HEIGHT]){
  int i, j;
  for (j = 0; j < HEIGHT; j++)
  {
  	for (i = 0; i < WIDTH; i++)
    {
    	if (board[i][j] == 1)
    		printf("*");
    	else printf(" ");
    }
     printf("\n");
  }
}

void life(int array[][HEIGHT])
{
	int i, j, a;
	int temp[WIDTH][HEIGHT];
	copy(array,temp);

	for(int j = 1; j < WIDTH-1; j++)
    {
        for(int i = 1; i < HEIGHT-1; i++)            
        {  
        	int count = 0;
            count = array[j-1][i] + 
                    array[j-1][i-1] +
                    array[j][i-1] +
                    array[j+1][i-1] +
                    array[j+1][i] +
                    array[j+1][i+1] +
                    array[j][i+1] +
                    array[j-1][i+1];

			//The cell dies.
	        if(count < 2 || count > 3)
	        	temp[j][i] = 0;
	        //The cell stays the same.
	        if(count == 2)
	        	temp[j][i] = array[j][i];
	        //The cell either stays alive, or is "born".
	        if(count == 3)
	        	temp[j][i] = 1;              
        }
    }
  //Copies the completed temp array back to the main array.
  copy(temp, array);
}

void load_data(int board[][HEIGHT], char *file_name) 
{
  FILE *file;
  int i, j, buffer;
  buffer = 100;
  char data[buffer];

  file = fopen(file_name, "r");
  if(file != NULL)
  {
  	for (j=0; j<HEIGHT; j++)
  	{
  		fgets (data, buffer, file);
  		for (i=0; i<WIDTH; i++) 
  		{
  			board[i][j] = data[i] - '0';
  		}
  	}

  }
  fclose (file);
}

int main(int argc, char *argv[]){
  int board[WIDTH][HEIGHT];
  int i, j;
  char decoration[13] = "#############";

  init_board(board);
  load_data(board, argv[1]);
  //print(board);

  for(i=0; i<=10; i++){
    printf("%s\nGeneration %i\n%s", decoration, i, decoration);
    print(board);
    life(board);
  }
  return 0;
}