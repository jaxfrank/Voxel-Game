#pragma once

#include "Block.h"
#include "..\ID.h"

class Chunk {

public:
	//Defaults the width, length, and depth of the chunk to 16 blocks
	Chunk();
	//This is a destructor
	virtual ~Chunk();

	//Returns a copy of the block at location
	int getBlockIDAt(const ID& location) const;
	//Sets the block at the location specified to the specified block
	//if location is invalid it does not do the above
	//if the block is invalid it does not do the above
	void setBlock(const ID& location, const Block& block);

	//Handles block and chunk update stuff
	void update();

	//Returns whether there has been a state change or some other object has made this chunk aware of the fact that it needs to be rebuilt
	bool needsRebuild() const;
	//Tells the chunk that the renderer has rebuilt the chunk. Has no check to make sure this has actually happened
	void rebuilt();
	//Doesn't actually rebuild the chunk just sets a flag so that the renderer knows a chunk needs to be rebuilt
	void rebuild();

private:
	//The size of this chunk(should be uniform across all chunks)
	static int numBlocksX , numBlocksY, numBlocksZ;
	//A pointer to where all the blocks are stored
	int* blocks;

	//A local flag that lets the renderer know when the chunk's mesh needs to be rebuilt
	bool shouldRebuild;

	//Converts the position stored in the id to an int which represents that block in memory
	int idToInt(const ID& location) const;
	//Returns false if any of the dimensions of the ID are less than zero or greater in size than the corresponding dimension of this chunk
	bool idIsValid(const ID& location) const;
};

