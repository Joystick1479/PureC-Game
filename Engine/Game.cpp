/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

#include <ctime>


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	playerX = 400;
	playerY = 500;
	player = new Player(playerX, playerY);
	playerlist_.push_back(player);
	
}

Game::~Game()
{
	delete player;
	DeleteAllPlayers();
	DeleteAllEnemies();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	SpawnPlayer();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT) || wnd.kbd.KeyIsPressed('D'))
	{
		if (player)
		{
			player->MovementHandle("GoRight");
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_UP) || wnd.kbd.KeyIsPressed('W'))
	{
		if (player)
		{
			player->MovementHandle("GoUp");
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT) || wnd.kbd.KeyIsPressed('A'))
	{
		if (player)
		{
			player->MovementHandle("GoLeft");
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN) || wnd.kbd.KeyIsPressed('S'))
	{
		if (player)
		{
			player->MovementHandle("GoDown");
		}
	}
}

void Game::SpawnPlayer()
{

	if(wnd.mouse.LeftIsPressed())
	{
		int mousePosX = wnd.mouse.GetPosX();
		int mousePosY = wnd.mouse.GetPosY();

		enemy = new Enemy(mousePosX, mousePosY);
		enemylist_.push_back(enemy);
	}

}

void Game::ComposeFrame()
{
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		DeleteAllPlayers();
	}

	for (PlayersList::const_iterator playerIt = playerlist_.begin(),
		end = playerlist_.end();
		playerIt != end;
		++playerIt)
	{
		(*playerIt)->Render(&gfx);

	}

	//Render,deleting enemies when player overlaps with them

	for (EnemyList::const_iterator enemyIt = enemylist_.begin(),
		end = enemylist_.end();
		enemyIt != end;
		++enemyIt)
	{
		if (player)
		{
			if (!IsColliding(player->GetXPosition(), player->GetYPosition(), player->width, player->height,
				(*enemyIt)->GetXPosition(), (*enemyIt)->GetYPosition(), (*enemyIt)->width, (*enemyIt)->height))
			{
				(*enemyIt)->Render(&gfx);
			}
			else
			{
				enemylist_.remove(*enemyIt);
			}
		}
	}
}

void Game::DeleteAllPlayers()
{
	for (PlayersList::const_iterator playerIt = playerlist_.begin(),
		end = playerlist_.end();
		playerIt != end;
		++playerIt)
	{
		delete (*playerIt);
	}

	playerlist_.clear();
}
void Game::DeleteAllEnemies()
{
	for (EnemyList::const_iterator enemyIt = enemylist_.begin(),
		end = enemylist_.end();
		enemyIt != end;
		++enemyIt)
	{
		delete (*enemyIt);
	}

	enemylist_.clear();
}

bool Game::IsColliding(const int & x0, const int & y0, const int & width0, const int & height0, 
	const int & x1, const int & y1, const int & width1, const int & height1)
{
	const int right0 = x0 + width0;
	const int bottom0 = y0 + height0;
	const int right1 = x1 + width1;
	const int bottom1 = y1 + height1;

	return right0 >= x1 &&
		x0 <= right1 &&
		bottom0 >= y1 &&
		y0 <= bottom1;
}

