#pragma once

#include <glm\glm.hpp>

#include <unordered_map>
#include <unordered_set>

#include <string>
#include "Block.h"
#include "Chunk.h"
#include "../ID.h"

typedef std::unordered_map<ID, Chunk, ID::Hash, ID::Equals> ChunkMap;
typedef std::unordered_set<ID, ID::Hash, ID::Equals> IDSet;

class World {
public:
	World();
	~World();

	void update();
	Chunk* getChunk(const ID& location);

	std::string getId() const;

	//This will be removed
	//Just needs to be here till there is an entity/player system
	glm::vec3 playerPos;

private:
	std::string id;
	ChunkMap chunkMap;
	bool idIsValid(const ID& id) const;
};

