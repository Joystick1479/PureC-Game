#pragma once

class Graphics;

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Render(Graphics *graphics) const;

	virtual int GetXPosition() const;
	virtual int GetYPosition() const;

	virtual void SetXPosition(const int& Xposition);
	virtual void SetYPosition(const int& Yposition);

	int xCord, yCord;

	int height, width;

private:

	

};

