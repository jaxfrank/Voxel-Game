#include "ID.h"

ID::ID(void)
{}

ID::ID(const int x, const int y, const int z):
	x(x),
	y(y),
	z(z)
{}

int ID::getX() const {
	return this->x;
}

void ID::setX(const int x){
	this->x = x;
}

int ID::getY() const{
	return this->x;
}

void ID::setY(const int y){
	this->y = y;
}

int ID::getZ() const{
	return this->x;
}

void ID::setZ(const int z) {
	this->z = z;
}

bool ID::operator==(const ID& other) {
	if(getX() != other.getX()) return false;
	if(getY() != other.getY()) return false;
	if(getZ() != other.getZ()) return false;
	return true;
}

bool ID::operator!=(const ID& other) {
	if(getX() != other.getX()) return true;
	if(getY() != other.getY()) return true;
	if(getZ() != other.getZ()) return true;
	return false;
}