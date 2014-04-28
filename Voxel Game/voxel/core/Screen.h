#pragma once

#include <SFML\Window.hpp>
#include <glm\glm.hpp>

class Screen {
public:
	Screen();

	virtual void init() = 0;
	virtual void initGL() = 0;
	virtual void resize(const int width, const int height) = 0;
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void render(const float interpolation) = 0;
	virtual void cleanUp() = 0;

	virtual void onWindowClosed(sf::Window* window);
	virtual void onKeyPressed(sf::Keyboard::Key key, bool control, bool alt, bool shift, bool system);
	virtual void onKeyReleased(sf::Keyboard::Key key, bool control, bool alt, bool shift, bool system);
	virtual void onMouseButtonPressed(sf::Mouse::Button button, int mouseX, int mouseY);
	virtual void onMouseButtonReleased(sf::Mouse::Button button, int mouseX, int mouseY);
	virtual void onMouseMove(glm::vec2 previousMousePos, glm::vec2 newMousePos);
};