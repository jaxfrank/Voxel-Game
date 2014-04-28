#pragma once

#include "..\ID.h"
#include "World.h"
#include <unordered_map>
#include <unordered_set>
#include <string>

typedef std::unordered_map<int, World*> WorldHashMap;
typedef std::unordered_set<int> IntHashSet;

class WorldManager {
public:
	WorldManager(void);
	~WorldManager(void);

	void update();
	bool addWorld(int id, World* world);
	bool removeWorld(int id, World* world); //The second parameter is the world that is being removed
	bool deleteWorld(int id);
	World*const getWorld(int id) const;
	bool loadWorld(int id);

private:
	WorldHashMap* worlds;
	IntHashSet* loadedWorlds;
};

