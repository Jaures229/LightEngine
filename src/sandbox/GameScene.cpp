#include "GameScene.h"

void GameScene::OnInitialize()
{
    std::vector<std::vector<char>> map = {
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ','#',' ',' ',' '},
        {' ',' ',' ',' ','#',' ',' '},
        {' ',' ',' ',' ',' ','#',' '},
        {'#',' ',' ',' ',' ',' ',' '}
    };

    //SetMap(map);
    _gameGrid.Init(map);

    int cellSize = 40;
    int maxRow = _gameGrid.GetGridSize().x;
    int maxCol = _gameGrid.GetGridSize().y;

    // create the initial vector
    _tilesEnttities.resize(maxRow);
    for (int row = 0; row < maxRow; row++)
    {
        //// draw line horizontal
        for (int col = 0; col < maxCol; col++)
        {
            _tilesEnttities[row].resize(maxCol);
            TileEntity* tilentity = CreateEntity<TileEntity>(cellSize, Color::Gray);
            tilentity->SetPosition({ col * (cellSize + cellSize), row * (cellSize + cellSize)});
            //tilentity->GetPosition()

            _tilesEnttities[row][col] = tilentity;

            // draw line vertical
        }
    }
}

void GameScene::OnUpdate()
{
}

void GameScene::SetMap(std::vector<std::vector<char>> map)
{
    _map = map;
}
