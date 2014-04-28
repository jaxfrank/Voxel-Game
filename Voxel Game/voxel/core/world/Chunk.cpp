#include "Chunk.h"

int Chunk::numBlocksX = 16, Chunk::numBlocksY = 16, Chunk::numBlocksZ = 16;

Chunk::Chunk()
{
	blocks = new int[numBlocksX * numBlocksY * numBlocksZ];
}

Chunk::~Chunk(void) {
	delete blocks;
}

void Chunk::update() {
	
}

int Chunk::getBlockIDAt(const ID& location) const { 
	if(!idIsValid(location)) return -1;

	return blocks[idToInt(location)];
}

void Chunk::setBlock(const ID& location, const Block& block) {
	if(!idIsValid(location)) return;

	int position = idToInt(location);
	memcpy(&blocks[position], &block, sizeof(Block));
	
	shouldRebuild = true;

}

bool Chunk::needsRebuild() const {
	return shouldRebuild;
}

void Chunk::rebuilt() {
	this->shouldRebuild = false;
}

void Chunk::rebuild() {
	this->shouldRebuild = true;
}

bool Chunk::idIsValid(const ID& location) const {
	if(location.getX() < 0) return false;
	if(location.getX() >= numBlocksX) return false;
	if(location.getY() < 0) return false;
	if(location.getY() >= numBlocksY) return false;
	if(location.getZ() < 0) return false;
	if(location.getZ() >= numBlocksZ) return false;
	return true;
}

int Chunk::idToInt(const ID& location) const {
	return location.getX() + location.getY() * numBlocksX + location.getZ() * numBlocksX * numBlocksY;
}
