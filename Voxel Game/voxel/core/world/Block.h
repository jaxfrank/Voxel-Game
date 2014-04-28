#pragma once

#include <unordered_map>
#include <array>

class Block;

typedef std::unordered_map<int, Block*> BlockHashMap;

class Block
{
public:
	static BlockHashMap blocks;
	static void registerBlock(const Block& block);
	static bool unregisterBlock(const int id);

	Block();
	Block(int id);

	int getID() const { return ID; }
	std::array<int, 6> getTextureIndices();
	//Sets all textureIndices to the single index
	void setTextureIndices(int index);
	//Order of indices is decided by the Directions Enum
	void setTextureIndices(std::array<int, 6> indices);

private:
	const int ID;
	std::array<int, 6> textureIndices;
};
