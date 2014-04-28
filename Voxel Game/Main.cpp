#include <SFML/Window.hpp>

#include "voxel\core\Game.h"
#include "MainWindow.h"
#include <glm\glm.hpp>

Game* game;

int main(int argc, char* argv[]){
	
	game = new Game();
	game->setWindowSize(glm::vec2(1280, 720));
	game->setWindowTitle("Voxel Game");
	game->setScreen(new MainWindow(game));
	if(!game->start())
		return -1;
	
	delete game;
	
	return 0;
}
