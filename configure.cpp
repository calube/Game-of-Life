/*
 * Input: input.txt
 * Output: 2D array filled with game of life configuration 
 * This file will read the matrix from the txt file and store the data into a 2D array
 * Written by: Caleb Davis (w741357)
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


static const int WIDTH = 32;
static const int HEIGHT = 32;
char grid[HEIGHT][WIDTH]={0};


void copyChar(char array1[WIDTH][HEIGHT], int array2[WIDTH][HEIGHT]);
void print(int array[WIDTH][HEIGHT]);
void load();

int main()
{

	load();
    cout << "Creating array..." << "\n Copying array... \n   Printing Array... \n\n" ; 
    int array[HEIGHT][WIDTH];
    copyChar(grid, array);
    print(array);
    return 0;
}

void load()
{
	ifstream file;
    file.open("input.txt");

    if(file.is_open())
    {
            cout << "File Opened successfully!!!. Reading data from file into array" << endl;

            // my matrix was printing twice -- so I did this little method with setting i = 0 to prevent it from duplicating when printing.
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
                                cout << grid[i][j];
                            }
                            cout << endl;
                    }

            	}
                   
            }

    }
    file.close();
}

void print(int array[WIDTH][HEIGHT])
{
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			if (grid[i][j] == 1)
				cout << '*';
			else 
				cout << ' ';
		}
		cout << endl;
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
            //cout << array2[j][i];

        }            
              
    }
}
