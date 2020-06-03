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

	for (EnemyList::const_iterator enemyIt = enemylist_.begin(),
		end = enemylist_.end();
		enemyIt != end;
		++enemyIt)
	{
		(*enemyIt)->Render(&gfx);
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
