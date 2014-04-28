#include "World.h"


World::World(void)
{

}


World::~World(void)
{
}

void World::update(){

}

Chunk* World::getChunk(const ID& location) {
	if(!idIsValid(location)) return nullptr;
	return &chunkMap.find(location)->second;//May or may not return nullptr
}

std::string World::getId() const {
	return id;
}

bool World::idIsValid(const ID& id) const{
	return chunkMap.find(id) != chunkMap.end();
}
