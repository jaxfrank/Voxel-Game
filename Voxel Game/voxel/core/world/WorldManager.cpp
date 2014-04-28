#include "WorldManager.h"

WorldManager::WorldManager():
	worlds(new WorldHashMap)
{}

WorldManager::~WorldManager() {
	for(WorldHashMap::iterator i = worlds->begin(); i != worlds->end(); i++){
		delete i->second; //Delete all worlds that are still in this WorldManager
	}
	delete worlds;
}

void WorldManager::update() {
	for(IntHashSet::iterator i = loadedWorlds->begin(); i != loadedWorlds->end(); i++) {
		World* world = (*worlds)[*i];
		if(world != nullptr) 
			world->update();
	}
}

bool WorldManager::addWorld(int id, World* world){
	if(worlds->find(id) == worlds->end()) {
		(*this->worlds)[id] = world;
		return true;
	}
	return false;
}

bool WorldManager::removeWorld(int id, World* world){
	World* w = (*worlds)[id];
	if(w != nullptr) {
		worlds->erase(id);
		world = w;
		return true;
	}
	return false;
}

bool WorldManager::deleteWorld(int id) {
	World* world = (*worlds)[id];
	if(world != nullptr) {
		worlds->erase(id);
		delete world;
		return true;
	}
	return false;
}

World*const WorldManager::getWorld(int id) const{
	World*const world = (*this->worlds)[id];
	if(world != nullptr) {
		return world;
	} else {
		return nullptr;
	}
}

bool WorldManager::loadWorld(int id) {
	if(worlds->find(id) != worlds->end() && loadedWorlds->find(id) != loadedWorlds->end()) {
		loadedWorlds->insert(id);
		return true;
	}
	return false;
}
