#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

static const int WIDTH = 32;
static const int HEIGHT = 32;
char grid[HEIGHT][WIDTH]={0};

void load()
{
	ifstream file;
    file.open("input.txt");

    if(file.is_open())
    {
    	cout << "File Opened successfully!!!. Reading data from file into array" << endl;
    	// my matrix was printing twice 
    	// so I did this little method with setting i = 0 to prevent it from duplicating when printing.
    	int i = 0;
    	while(!file.eof())
    	{
    		i++;
    		if (i == 1)
    		{
    			for(int i = 0; i < HEIGHT; i++)
    			{
    				for(int j = 0; j < WIDTH; j++)
    				{
    					file >> grid[i][j];
    					//cout << grid[i][j];
    				}
    				cout << endl;
    			}
    		}
    	}
    }
    file.close();
}

//Copies one array to another.
void copy(int array1[WIDTH][HEIGHT], int array2[WIDTH][HEIGHT])
{
  for(int j = 0; j < WIDTH; j++)
  {
        for(int i = 0; i < HEIGHT; i++)            
            array2[j][i] = array1[j][i]; 
    }
}

void copyChar(char array1[WIDTH][HEIGHT], int array2[WIDTH][HEIGHT])
{
  for(int j = 0; j < WIDTH; j++)
  {
        for(int i = 0; i < HEIGHT; i++)
        {
        	array1[j][i] = int(array1[j][i] - '0');
        	array2[j][i] = array1[j][i];
        }            
              
    }
}

//The life function is the most important function in the program.
//It counts the number of cells surrounding the center cell, and 
//determines whether it lives, dies, or stays the same.
void life(int array[WIDTH][HEIGHT], char choice)
{
  //Copies the main array to a temp array so changes can be entered into a grid
  //without effecting the other cells and the calculations being performed on them.
  int temp[WIDTH][HEIGHT];
  copy(array, temp);
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

//Checks to see if two arrays are exactly the same. 
bool compare(int array1[WIDTH][HEIGHT], int array2[WIDTH][HEIGHT])
{
    int count = 0;
    for(int j = 0; j < WIDTH; j++)
    {
        for(int i = 0; i < HEIGHT; i++)
        {
            if(array1[j][i]==array2[j][i])
                count++;    
        }
    }
  //Since the count gets incremented every time the cells are exactly the same,
  //an easy way to check if the two arrays are equal is to compare the count to 
  //the dimensions of the array multiplied together.
    if(count == WIDTH*HEIGHT)
      return true;
    else
      return false;
}

//This function prints the matrix
//The alive cells are the only portion of the array that we're really interested in. 
//A live cell is marked by a '*', and a dead or vacant cell by a ' '.
void print(int array[WIDTH][HEIGHT])
{
    for(int j = 1; j < WIDTH-1; j++)
    {
        for(int i = 1; i < HEIGHT-1; i++)            
        {   
            if(array[j][i] == 1)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
}

int main()
{
	int gen0[WIDTH][HEIGHT];
    int todo[WIDTH][HEIGHT];
    int backup[WIDTH][HEIGHT];
    int num_runs = 50;
    char neighborhood;
    char again;
  	char cont;
  	bool comparison;
    string decoration;


    int i;

    load();
    copyChar(grid, gen0);
    print(gen0);
    cout << endl << "Done setup.." << endl;

    
    //Loop that does the bulk of the game of life.
    for (i = 0; i <= num_runs; i++)
    {
    	//I need to read the grid via txt file here
        //srand(time(NULL));

        // for(int j = 1; j < WIDTH-1; j++)
        // {
        //     for (int i = 1; i < HEIGHT-1; i++)
        //         gen0[j][i] = rand() % 2;
        // }

        //Determines how big the decoration should be.
        if(i < 10)
            decoration = "#############";
        else if(i >= 10 && i < 100)
            decoration = "##############";
        else if(i >= 100 && i < 1000)
            decoration = "###############";
        else if(i >= 1000 && i < 10000)
            decoration = "################";
        else
            decoration = "#################";

        //Prints the generation.  If i == 0, the gen0 array is copied to the 
        //todo array, and is printed before any functions act upon it.
        cout << decoration << endl << "Generation " << i << ":" << endl << decoration << endl << endl;
        //Initializes the arrays by copying the gen0 array to the todo array.
        if(i == 0)
            copy(gen0, todo);  
        copy(todo, backup);         
        print(todo);      
        life(todo, neighborhood);
    }

    return 0;
}
        
