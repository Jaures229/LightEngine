#pragma once

#include <iostream>
#include <vector>

#define BG_RED "\033[41m"
#define DEFAULT "\033[0m"

struct Tile {
	int row, col;
	bool obstacle;
	bool added;
	bool isInPath;
	Tile* cameFrom;
};

struct vector2 {
	int x;
	int y;
};

class Grid
{
public:
	void Init(std::vector<std::vector<char>>& map);
	void Run();
	void Display();
	void Input();
    void SetPlayerPos(vector2 newPlayerPos);
    void SetCursorPos(vector2 newCursorPos);
    vector2 GetGridSize() const { return _gridSize; }
	bool FindPath(Tile* start, Tile* end);
    std::vector<std::vector<Tile>> GetTiles() const { return _tiles; }
private:
	vector2 _gridSize = { 0, 0 };
	vector2 _cursorPos = { 1, 1 };
	vector2 _playerPos = { 0, 0 };
	bool _active = true;
	std::vector<std::vector<char>> _tileInterface;
	std::vector<std::vector<Tile>> _tiles;
};
