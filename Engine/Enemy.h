#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:

	Enemy(const int&x, const int&y);

	~Enemy();

	void Render(Graphics* gfx) const override;

private:
};

