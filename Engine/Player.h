#pragma once

#include "Entity.h"
class Graphics;

class Player : public Entity
{
public:

	Player(const int&x, const int&y);

	~Player();

	int GetXPosition() const override;
	int GetYPosition() const override;

	void SetXPosition(const int& Xlocation) override;
	void SetYPosition(const int& Ylocation) override;

	void GoUp();
	void GoDown();
	void GoLeft();
	void GoRight();

	void Render(Graphics* gfx) const override;


private:

	//Location
	int xCord, yCord;


};

