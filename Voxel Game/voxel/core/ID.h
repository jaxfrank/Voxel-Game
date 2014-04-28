#pragma once

class ID
{
public:
	ID(void);
	ID(const int x, const int y, const int z);

	int getX() const;
	void setX(const int x);
	int getY() const;
	void setY(const int y);
	int getZ() const;
	void setZ(const int z);

	bool operator==(const ID& other);
	bool operator!=(const ID& other);

	struct Hash {
		size_t operator() (const ID& id) const {
			const int prime = 31;
			long result = 1;
			result = prime * result + id.getX();
			result = prime * result + id.getY();
			result = prime * result + id.getZ();
			return (size_t)(result % 16908799);
		}
	};

	struct Equals {
		bool operator()(const ID& left, const ID& right) const {
			if(left.getX() != right.getX()) return false;
			if(left.getY() != right.getY()) return false;
			if(left.getZ() != right.getZ()) return false;
			return true;
		}
	};

private:
	int x;
	int y;
	int z;
};

