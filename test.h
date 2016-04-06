# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <ctime>
# include <cstring>
# include <array>

using namespace std;

static const int WIDTH = 32;
static const int HEIGHT = 32;

class test
{
	test();
	~test();
	void life_init();
	void life_update (int, int);
	void print_grid();

private:
	array<array<int, WIDTH>, HEIGHT> grid;	

};

int main()
{
	test setup;
    setup.life_init();
    setup.life_update(WIDTH, HEIGHT);
    setup.print_grid();
    
    return 0;
}

void life_init()
{

    ifstream file("input.txt");
    for (int i = 0; i < WIDTH; ++i) 
        for (int j = 0; j < HEIGHT; ++j)
        {
          file >> grid[i][j];  
        } 
            
    print_grid();
}

void life_update(int m, int n)
{
    cout << "Computing next generation..." << endl;
}

void print_grid()
{
     for(int i = 0; i < HEIGHT; i++)
     {
        for(int j = 0; j < WIDTH; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

}
