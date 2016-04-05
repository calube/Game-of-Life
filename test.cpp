/*
 * Input: input.txt
 * Output: 2D array filled with game of life configuration 
 * This file will read the matrix from the txt file and store the data into a 2D array
 * Written by: Caleb Davis (w741357)
 */

# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <ctime>
# include <cstring>

using namespace std;

static const int WIDTH = 32;
static const int HEIGHT = 32;



void life_update ( int m, int n, int grid[] );


int** life_init()
{
    int **grid = new int*[WIDTH];
    for (int i = 0; i < WIDTH; i++)
    {
        grid[i] = new int[HEIGHT];
    }

    ifstream file;
    file.open("input.txt");

    if(file.is_open())
    {
            cout << "File Opened successfully!!!. Reading data from file into array" << endl;
            while(!file.eof())
            {
                    for(int i = 0; i < HEIGHT; i++)
                    {
                            for(int j = 0; j < WIDTH; j++)
                            {
                                // int value = grid[i][j];
                                // cout << "value: " << value << endl;
                                file >> grid[i][j];
                                cout << grid[i][j];
                            }
                            cout << endl;
                    }
            }

    }

    file.close();
    return grid;
}

void life_update(int m, int n, int grid[])
{
    int i, j, *s;

    s = new int[m*n];

    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= m; i++)
        {
            s[(i-1)+(j-1)*m] = grid[(i-1)+(j-1)*(m+2)] + grid[i-1+j*(m+2)] + 
                               grid[i-1+(j+1)*(m+2)]+ grid[i  +(j-1)*(m+2)] + 
                               grid[i +(j+1)*(m+2)]+ grid[i+1+(j-1)*(m+2)] + 
                               grid[i+1+j*(m+2)] + grid[i+1+(j+1)*(m+2)];
        }
    }

    /*
     * Any dead cell with 3 living neighbors becomes alive
     * Any living cell with less than 2 or more than 3 neighbors dies from over-crowded.
     */

     for ( j = 1; j <= n; j++ )
     {
        for ( i = 1; i <= m; i++ )
        {
            if ( grid[i+j*(m+2)] == 0 )
            {
                if ( s[i-1+(j-1)*m] == 3 )
                {
                    grid[i+j*(m+2)] = 1;
                }
            }
            else if ( grid[i+j*(m+2)] == 1 )
            {
                if ( s[i-1+(j-1)*m] < 2 || 3 < s[i-1+(j-1)*m] )
                {
                    grid[i+j*(m+2)] = 0;
                }
            }
        }
    }

  delete [] s;
}

int main()
{
    int m, n, generation_count, i;
    int **grid;

    grid = life_init();


    // m = 10, n = 10, generation_count = 10;

    // for (i = 0; i <= generation_count; i++)
    // {
    //     if (i == 0)
    //     {
    //         grid = life_init();
    //     }
    //     else 
    //     {
    //         //life_update(m, n, grid);
    //     }
    // }

    
    delete [] grid;
    return 0;
}
