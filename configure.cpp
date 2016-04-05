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
char level[HEIGHT][WIDTH]={0};

int main()
{
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
                                file >> level[i][j];
                                cout << level[i][j];
                            }
                            cout << endl;
                    }
            }

    }

    file.close();
    return 0;
}