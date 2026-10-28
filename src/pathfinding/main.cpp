#include <iostream>
#include "main.h"
#include "Grid.h"

int main()
{
    std::vector<std::vector<char>> map  = {
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ',' ','#',' ',' '},
        {' ',' ',' ',' ',' ','#',' '},
        {'#',' ',' ',' ',' ',' ',' '}
    };
    Grid grid;

    grid.Init(map);
    grid.Run();

    return 0;
}
