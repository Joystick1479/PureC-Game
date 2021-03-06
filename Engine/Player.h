#pragma once

#include "Entity.h"
#include <string>
class Graphics;

class Player : public Entity
{
public:

	Player(const int&x, const int&y);

	~Player();

	void Render(Graphics* gfx) const override;

	//Passing strings GoUp,GoDown, etc by player controller ( game)
	void MovementHandle(const std::string& str);



private:

	int ClampScreenX(const int& ClampX, const int& ClampWidth);
	int ClampScreenY(const int& ClampY, const int& ClampHeight);
	mutable int ScreenWidth;
	mutable int ScreenHeight;

};

