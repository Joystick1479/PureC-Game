#include "Entity.h"



Entity::Entity()
{

}


Entity::~Entity()
{

}

void Entity::Render(Graphics * graphics) const
{
}

int Entity::GetXPosition() const
{
	return xCord;
}

int Entity::GetYPosition() const
{
	return yCord;
}

void Entity::SetXPosition(const int & Xposition)
{
	xCord = Xposition;
}

void Entity::SetYPosition(const int & Yposition)
{
	yCord = Yposition;
}
