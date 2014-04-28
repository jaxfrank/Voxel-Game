#pragma once

#include <iostream>

#include <SFML\Window.hpp>
#include <glm\glm.hpp>
#include <string>

#include "Screen.h"

class Game {
public:
	Game();
	~Game(void);
	
	bool start();

	void setScreen(Screen* screen);
	Screen& getScreen() const;

	void setRunning(const bool running);

	glm::vec2 getWindowSize() const;
	void setWindowSize(glm::vec2 size);
	int getWindowWidth() const;
	void setWindowWidth(const int width);
	int getWindowHeight() const;
	void setWindowHeight(const int height);
	std::string getWindowTitle() const;
	void setWindowTitle(std::string title);

	glm::vec2 getMousePos() const;
	void setMousePosition(const glm::vec2 position);
	bool isMouseGrabbed() const;
	void setMouseGrabbed(const bool grabbed);
	bool hasFocus() const;

private:
	sf::Window* window;
	int width;
	int height;
	std::string title;
	bool running;
	Screen *screen;
	glm::vec2 previousMousePos;

	bool isMouseVisible;

	bool init();
	bool loop();
	bool cleanUp();

	void handleEvents();
	bool windowHasFocus;

};

