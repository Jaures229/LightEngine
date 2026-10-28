#include "Grid.h"
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

bool Grid::FindPath(Tile* start, Tile* end)
{
    for (int row = 0; row < _gridSize.x; row++) {
        for (int col = 0; col < _gridSize.y; col++) {
            _tiles[row][col].added = false;
            _tiles[row][col].isInPath = false;
            _tiles[row][col].cameFrom = nullptr;
        }
    }

    // créée une file
    std::queue <Tile*> p_file;
    start->added = true;
    start->cameFrom = nullptr;

    p_file.push(start);

    Tile* front = nullptr;

    while (!p_file.empty())
    {
        front = p_file.front();
        p_file.pop();

        if (front->row == end->row && front->col == end->col)
        {
            Tile* current = end;
            while (true)
            {
                current->isInPath = true;
                current = current->cameFrom;
                if (current == nullptr)
                    break;
            }
            return true;
        }

        int frontRow = front->row;
        int frontCol = front->col;

        std::vector<Tile*> neigbours;

        // voisin droite
        if (frontCol + 1 < _gridSize.y)
            neigbours.push_back(&_tiles[frontRow][frontCol + 1]);
        // voisin gauche
        if (frontCol - 1 >= 0)
            neigbours.push_back(&_tiles[frontRow][frontCol - 1]);
        // voisin haut
        if (frontRow - 1 >= 0)
            neigbours.push_back(&_tiles[frontRow - 1][frontCol]);
        // voisin bas
        if (frontRow + 1 < _gridSize.x)
            neigbours.push_back(&_tiles[frontRow + 1][frontCol]);

        for (int i = 0; i < neigbours.size(); i++)
        {
            if (neigbours[i]->obstacle != true && neigbours[i]->added == false)
            {
                neigbours[i]->cameFrom = front;
                neigbours[i]->added = true;
                p_file.push(neigbours[i]);
            }
        }
    }
    return false;
}

void Grid::Init(std::vector<std::vector<char>>& map)
{
    _gridSize = { (int)map.size(), (int)map[0].size() };
    _tileInterface.resize(_gridSize.x);

    for (int row = 0; row < _gridSize.x; row++)
    {
        for (int col = 0; col < _gridSize.y; col++)
        {
            _tileInterface[row].resize(_gridSize.y);
            _tileInterface[row][col] = map[row][col];
        }
    }

    _tiles.resize(_gridSize.x);

    for (int row = 0; row < _gridSize.x; row++) {
        for (int col = 0; col < _gridSize.y; col++) {
            if (_tileInterface[row][col] == ' ') {
                _tiles[row].resize(_gridSize.y);
                _tiles[row][col].row = row;
                _tiles[row][col].col = col;
                _tiles[row][col].obstacle = false;
                _tiles[row][col].added = false;
                _tiles[row][col].cameFrom = nullptr;
                _tiles[row][col].isInPath = false;

            }
            else if (_tileInterface[row][col] == '#') {
                _tiles[row].resize(_gridSize.y);
                _tiles[row][col].row = row;
                _tiles[row][col].col = col;
                _tiles[row][col].obstacle = true;
                _tiles[row][col].added = false;
                _tiles[row][col].isInPath = false;
                _tiles[row][col].cameFrom = nullptr;
            }
        }
    }
    _active = true;
}

void Grid::Display()
{
    for (int row = 0; row < _gridSize.x; row++) {
        for (int col = 0; col < _gridSize.y; col++) {

            std::cout << "[";

            if (row == _playerPos.x && col == _playerPos.y)
            {
                std::cout << "O";
            }
            else if (row == _cursorPos.x && col == _cursorPos.y)
            {
                std::cout << BG_RED << _tileInterface[row][col] << DEFAULT;
            }
            else if (_tiles[row][col].isInPath == true) {
                std::cout << "X";
            }
            else {
                std::cout << _tileInterface[row][col];
            }

            std::cout << "]";
        }
        std::cout << std::endl;
    }
}

void Grid::Run()
{
    while (_active) {
        Display();
        Input();
    }
}

void Grid::Input()
{
    char input = _getch();
    if (input == 'z') {
        _cursorPos.x = std::max(0, _cursorPos.x - 1);
    }
    if (input == 's') {
        _cursorPos.x = std::min(_gridSize.x - 1, _cursorPos.x + 1);
    }
    if (input == 'q') {
        _cursorPos.y = std::max(0, _cursorPos.y - 1);
    }
    if (input == 'd') {
        _cursorPos.y = std::min(_gridSize.y - 1, _cursorPos.y + 1);
    }
    if (input == '\r') {
        if (FindPath(&_tiles[_playerPos.x][_playerPos.y], &_tiles[_cursorPos.x][_cursorPos.y]))
        {
            std::cout << "oui";
        }
        else {
            std::cout << "non";
        }
    }
    system("cls");
}

void Grid::SetPlayerPos(vector2 newPlayerPos)
{
    _playerPos.x = newPlayerPos.x;
    _playerPos.y = newPlayerPos.y;
}

void Grid::SetCursorPos(vector2 newCursorPos)
{
    _cursorPos.x = newCursorPos.x;
    _cursorPos.y = newCursorPos.y;
}

