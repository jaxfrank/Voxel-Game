#include "Block.h"

BlockHashMap Block::blocks;

Block::Block():
	ID(-1)
{}

Block::Block(int id):
	ID(id)
{
	setTextureIndices(-1);
}

void Block::registerBlock(const Block& block){
	if(block.getID() > 0) {
		blocks[block.getID()] = new Block(block);//this is a weird line of code
	}
}

bool Block::unregisterBlock(const int id){
	return blocks.erase(id) != 0;
}

std::array<int, 6> Block::getTextureIndices(){
	return std::array<int, 6>(this->textureIndices);
}

void Block::setTextureIndices(int index){
	this->textureIndices.fill(index);
}

void Block::setTextureIndices(std::array<int, 6> indices){
	for(int i = 0; i < indices.size(); i++){
		this->textureIndices[i] = indices[i];
	}
}
