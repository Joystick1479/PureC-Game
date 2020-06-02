#pragma once
class Graphics;

class Player
{
public:

	Player(const int&x, const int&y);
	Player(class MainWindow& wnd);

	~Player();

	int GetXLocation(Player* player);
	int GetYLocation(Player* player);
	void GoUp();
	void GoDown();
	void GoLeft();
	void GoRight();

	void DrawPlayer(Graphics* gfx);


private:

	//Location
	int xCord, yCord;

	void PlayerController();

};

