#include "MainWindow.h"

#include <GL\glew.h>
#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\noise.hpp>

#include <SFML\Window.hpp>
#include "voxel\core\rendering\Util.h"

glm::vec2 previousMousePos;

MainWindow::MainWindow(Game* game):
	game(game),
	xSensitivity(0.5f),
	ySensitivity(0.5f)
{}

void MainWindow::init(){
	previousMousePos = game->getMousePos();
	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	Transform::setCamera(camera);
	transform = Transform(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	shader = new Shader();
	shader->addFragmentShaderFromFile("res\\shaders\\Basic.fs");
	shader->addVertexShaderFromFile("res\\shaders\\Basic.vs");
	shader->compileShader();
	shader->addUniform("projectedTransformationMatrix");

	glPointSize(4);

}

void MainWindow::initGL(){
	glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
        
    glEnable(GL_TEXTURE_2D);
        
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void MainWindow::resize(const int width, const int height){
	glViewport(0,0, width, height);
	Transform::setProjection(70.0f, (float)width / (float)height, 0.1f, 1000.0f);
}

void MainWindow::input(){
	if(game->isMouseGrabbed()){
		float speed = 0.1f;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
			speed += 3.0f;

		glm::vec3 movement = glm::vec3(0.0f, 0.0f, 0.0f);
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			movement = movement + camera->getForward();
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			movement = movement - camera->getForward();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			movement = movement + glm::cross(camera->getForward(), camera->getUp());
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			movement = movement - glm::cross(camera->getForward(), camera->getUp());

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			movement = movement + glm::vec3(0, 1, 0);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			movement = movement - glm::vec3(0, 1, 0);

		camera->setPosition(camera->getPosition() + (movement * speed));

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			game->setMouseGrabbed(false);
	} else {
		glm::vec2 mousePos = game->getMousePos();
		glm::vec2 screenSize = game->getWindowSize();
		if(game->hasFocus() && mousePos.x>= 0 && mousePos.y >= 0 && mousePos.x < screenSize.x && mousePos.y < screenSize.y && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			game->setMouseGrabbed(true);
	}

}

void MainWindow::update(){
	if(game->isMouseGrabbed()){
		glm::vec3 forward = camera->getForward();
		glm::vec2 deltaMousePos = previousMousePos - game->getMousePos();
		previousMousePos = game->getMousePos();
		glm::vec3 newForward = glm::mat3(glm::rotate(glm::mat4(), deltaMousePos.x * xSensitivity, camera->getUp())) * forward;
		newForward = glm::mat3(glm::rotate(glm::mat4(), deltaMousePos.y * ySensitivity, glm::cross(camera->getForward(), camera->getUp()))) * newForward;
		camera->setForward(newForward);
		game->setMousePosition(glm::vec2(game->getWindowWidth() / 2.0f, game->getWindowHeight() / 2.0f));
		previousMousePos = game->getMousePos();
	}
}

void MainWindow::render(const float interpolation){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->bind();
	shader->setUniform("projectedTransformationMatrix", transform.getProjectedTransforationMatrix());

	glUseProgram(0);
}

void MainWindow::cleanUp(){
	delete shader;
}

void MainWindow::onWindowClosed(sf::Window* window){
	game->setRunning(false);
}

void MainWindow::onMouseMove(glm::vec2 previousMousePos, glm::vec2 newMousePos) {

}