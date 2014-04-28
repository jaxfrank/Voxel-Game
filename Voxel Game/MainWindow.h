#pragma once
#include "voxel\core\Screen.h"

#include "voxel\core\Game.h"
#include "voxel\core\rendering\Shader.h"
#include "voxel\core\math\Transform.h"
#include "voxel\core\rendering\Camera.h"
#include "voxel\core\rendering\Mesh.h"

class MainWindow : public Screen {
public:
	MainWindow(Game* game);
	
	virtual void init();
	virtual void initGL();
	virtual void resize(const int width, const int height);
	virtual void input();
	virtual void update();
	virtual void render(const float interpolation);
	virtual void cleanUp();

	virtual void onWindowClosed(sf::Window* window);
	virtual void onMouseMove(glm::vec2 previousMousePos, glm::vec2 newMousePos);

private:
	Transform transform;
	Camera* camera;
	Shader* shader;
	Game* game;

	float xSensitivity;
	float ySensitivity;
};