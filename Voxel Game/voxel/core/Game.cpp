#include "Game.h"

#include <gl\glew.h>
#include <SFML\OpenGL.hpp>
#include <chrono>

Game::Game():
	window(NULL),
	running(false),
	width(720),
	height(480),
	title("Game"),
	screen(NULL)
{}

Game::~Game(void) {
	delete screen;
}

bool Game::start(){
	if(screen == NULL){
		std::cerr << "No screen attached to game!" << std::endl;
		return false;
	}

	window = new sf::Window(sf::VideoMode(width, height), title);

	if(!init())
		return false;

	if(!loop())
		return false;

	if(!cleanUp())
		return false;

	return true;
}

bool Game::init(){
	GLenum res = glewInit();
    if(res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return false;
    }

	setMouseGrabbed(false);
	previousMousePos = glm::vec2(getMousePos().x, getMousePos().y);

	screen->initGL();
	screen->init();
	screen->resize(window->getSize().x, window->getSize().y);

	return true;
}

bool Game::loop(){
	const int CLOCK_TICKS_PER_SECOND = 10000000;
	const int TICKS_PER_SECOND = 25;
	const int SKIP_TICKS = CLOCK_TICKS_PER_SECOND / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;

	double next_game_tick = std::chrono::steady_clock::now().time_since_epoch().count();
	int loops;
	float interpolation;

	running = true;

	std::chrono::steady_clock::time_point oldTime = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point curTime = std::chrono::steady_clock::now();

	int frames = 0;
	int ticks = 0;

	while( running ) {
		curTime = std::chrono::steady_clock::now();
		if(curTime.time_since_epoch().count() - oldTime.time_since_epoch().count() >= CLOCK_TICKS_PER_SECOND) {
			std::cout << "FPS: " << frames << " TPS: " << ticks << std::endl;

			ticks = 0;
			frames = 0;

			oldTime = curTime;
		}

		loops = 0;
		while( std::chrono::steady_clock::now().time_since_epoch().count() > next_game_tick && loops < MAX_FRAMESKIP) {
			handleEvents();
			screen->input();
			screen->update();

			next_game_tick += SKIP_TICKS;
			loops++;
			ticks++;
		}

		interpolation = float( std::chrono::steady_clock::now().time_since_epoch().count() + SKIP_TICKS - next_game_tick ) 
											/ float( SKIP_TICKS );
		
		screen->render(interpolation);
		window->display();
		frames++;
	}
	return true;
}

void Game::handleEvents(){
	sf::Event event;

	while(window->pollEvent(event)){
		switch(event.type) {
		case sf::Event::Closed:
			screen->onWindowClosed(window);
			break;
		case sf::Event::Resized:
			screen->resize(window->getSize().x, window->getSize().y);
			break;
		case sf::Event::GainedFocus:
			windowHasFocus = true;
			break;
		case sf::Event::LostFocus:
			windowHasFocus = false;
			break;
		case sf::Event::KeyPressed:
			screen->onKeyPressed(event.key.code, event.key.control, event.key.alt, event.key.shift, event.key.system);
			break;
		case sf::Event::KeyReleased:
			screen->onKeyReleased(event.key.code, event.key.control, event.key.alt, event.key.shift, event.key.system);
			break;
		case sf::Event::MouseButtonPressed:
			screen->onMouseButtonPressed(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
			break;
		case sf::Event::MouseButtonReleased:
			screen->onMouseButtonReleased(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
			break;
		case sf::Event::MouseMoved:
			glm::vec2 mousePos = getMousePos();
			screen->onMouseMove(previousMousePos, mousePos);
			this->previousMousePos = mousePos;
			break;
		}
	}
}

bool Game::cleanUp(){
	screen->cleanUp();
	return true;
}

void Game::setRunning(const bool running){
	this->running = running;
}

Screen& Game::getScreen() const {
	return *screen;
}

void Game::setScreen(Screen* screen){
	this->screen = screen;
}

glm::vec2 Game::getWindowSize() const{
	return glm::vec2(window->getSize().x, window->getSize().y);
}

void Game::setWindowSize(glm::vec2 size) {
	if(window != NULL)
		window->setSize(sf::Vector2u(size.x, size.y));
	this->width = size.x;
	this->height = size.y;
}

int Game::getWindowWidth() const{
	return window->getSize().x;
}

void Game::setWindowWidth(const int width) {
	if(window != NULL)
		window->setSize(sf::Vector2u(width, window->getSize().y));
	this->width = width;
}

int Game::getWindowHeight() const{
	return window->getSize().y;
}

void Game::setWindowHeight(const int height){
	if(window != NULL)
		window->setSize(sf::Vector2u(window->getSize().x, height));
	this->height = height;
}

std::string Game::getWindowTitle() const {
	return title;
}

void Game::setWindowTitle(std::string title) {
	if(window != NULL)
		window->setTitle(title);
	this->title = title;
}

glm::vec2 Game::getMousePos() const{
	return glm::vec2(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
}

void Game::setMousePosition(const glm::vec2 position){
	sf::Mouse::setPosition(sf::Vector2i(position.x, position.y), *window);
	this->previousMousePos = position;
}

bool Game::isMouseGrabbed() const{
	return !isMouseVisible;
}

void Game::setMouseGrabbed(const bool grabbed){
	isMouseVisible = !grabbed;
	window->setMouseCursorVisible(isMouseVisible);
}

bool Game::hasFocus() const{
	return windowHasFocus;
}