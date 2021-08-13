#pragma once
#include "MinesweeperGame.h"

int main()
{
	MinesweeperGame game;

	game.LoadTexture(TextureData());
	game.StartGame();
	return 0;
}