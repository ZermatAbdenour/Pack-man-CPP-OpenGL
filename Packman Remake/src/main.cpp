#include <iostream>
#include "Game.h"
#include"Levels/GameLevel.h"

int main() {
	Game pacman = Game();
	GameLevel gameLevel = GameLevel();
	pacman.LoadLevel(&gameLevel);
	pacman.Run();
}