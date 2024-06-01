/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/07
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/15
Description:
		基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，
		ESC是離開畫面。同時更新圖版上的資訊。
************************************************************************/
#include "main.h"
#include "hero.h"

const int GWIDTH = 11;
const int GHEIGHT = 11;
const double gTimeLog = 0.033;

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

// 用來儲存版面資料
char gBoard[GHEIGHT][GWIDTH];
int **used;

//************************************************************
// Creature Class
//************************************************************
class Creature
{
private:
	Position sPos;	  // Creature location
	char sIcon; // Creature icon
	bool sawHero = false;

public:
	// Default constructor
	Creature()
	{
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = 'C';
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y)
	{
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char &icon) { this->sIcon = icon; }

	// Set State of sawHero
	void setSawHero(bool state) { this->sawHero = state; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Get State of sawHero
	bool getSawHero(void) { return this->sawHero; }

	// Update the creature position
	void update(Position heroPos)
	{
		int deltaX = heroPos.x - this->sPos.x, deltaY = heroPos.y - this->sPos.y;

		// Check if the hero is in the range of the creature's sight.
		if (canSee(this->sPos, heroPos))
		{
			// Set the creature's icon and state
			this->sawHero = true;
			this->sIcon = '!';

			bool moved = false;

			// Move the creature to the hero's position, each time only move 1 unit
			if (deltaX > 0 && !moved)
			{
				Position newPos = {this->sPos.x + 1, this->sPos.y};
				moved = movement(newPos);
			}

			if (deltaX < 0 && !moved)
			{
				Position newPos = {this->sPos.x - 1, this->sPos.y};
				moved = movement(newPos);
			}

			if (deltaY > 0 && !moved)
			{
				Position newPos = {this->sPos.x, this->sPos.y + 1};
				moved = movement(newPos);
			}

			if (deltaY < 0 && !moved)
			{
				Position newPos = {this->sPos.x, this->sPos.y - 1};
				moved = movement(newPos);
			}
		}
		else
		{
			this->sIcon = 'C';
			bool moved;

			// rand the dir until the creature move to a valid position.
			do
			{
				Position newPos = {this->sPos.x, this->sPos.y};
				int randMove = rand() % 4;

				switch (randMove)
				{
				case 0:
					newPos.y -= 1;
					break;
				case 1:
					newPos.x += 1;
					break;
				case 2:
					newPos.y += 1;
					break;
				case 3:
					newPos.x -= 1;
				}

				moved = movement(newPos);
			} while (!moved);
		}
	}

	// Creature movement
	bool movement(Position newPos)
	{
		// Before move, check if the position is valid or not.
		if (isPositionValid(newPos))
		{
			setPos(newPos);
			return true;
		}

		return false;
	}

	// Creature's sight
	bool canSee(Position cPos, Position hPos)
	//==================================================================
	{
		int dx = hPos.x - cPos.x, dy = hPos.y - cPos.y;

		// Range of creature's sight
		if (abs(dx) > 2 || abs(dy) > 2) return false;

		// The iterator that pass through the path between the creature and the hero
		dx = (dx > 0) ? -1 : 1;
		dy = (dy > 0) ? -1 : 1;

		int x = hPos.x, y = hPos.y; // Current position buffer

		// Check if there is a wall between the creature and the hero
		while (x != cPos.x || y != cPos.y)
		{
			if (x != cPos.x) x += dx;
			if (y != cPos.y) y += dy;

			if (gBoard[y][x] == GWALL) return false;
		}

		return true;
	}
};

// Distance
const int gDistance = 4;

// 4 directions
std::vector<std::pair<int, int>> dir = {
	{0, 1},	 // down
	{0, -1}, // up
	{-1, 0}, // left
	{1, 0}	 // right
};

// 定義六種輸入指令與對應陣列index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

Hero gHero;
Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 判斷位置是否為空
bool isPositionValid(Position &loc);
// 初始化版面
void setupBoard();
void setUsed();

// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

// 程式主驅動函式
void update(bool key[]);

int main(void)
{
	srand(time(NULL));

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[6];

	// Setup a clear dungeon
	setupBoard();
	setUsed();

	// Generate Maze randomly
	generateMaze(1, 1);

	// Set the position of Hero
	gHero.setPos(1, 1);

	gCreature.setPos(5, 6);

	// Draw the bord and information
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

	// Get the press key
	keyUpdate(gKeyState);

	// Run the game loop
	while (!gKeyState[ValidInput::EESC])
	{
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog)
		{
			update(gKeyState);
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();
	}

	system("pause");
	return 0;
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++)
	{
		key[i] = false;
	}
	char input = _getch();
	switch (input)
	{
	case 'w':
		key[ValidInput::EW] = true;
		break;
	case 's':
		key[ValidInput::ES] = true;
		break;
	case 'a':
		key[ValidInput::EA] = true;
		break;
	case 'd':
		key[ValidInput::ED] = true;
		break;
	case ' ':
		key[ValidInput::ESPACE] = true;
		break;
	case 27:
		key[ValidInput::EESC] = true;
		break;
	default:
		break;
	}
}

//******************************************************************
//
// * 判斷位置是否為空
//==================================================================
bool isPositionValid(Position &pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] != GNOTHING)
		return false;

	if (pos.x == gHero.getPos().x && pos.y == gHero.getPos().y)
		return false;

	if (pos.x == gCreature.getPos().x && pos.y == gCreature.getPos().y)
		return false;

	return true;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimum, float maximum)
//==================================================================
{
	return std::max(minimum, std::min(n, maximum));
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard()
//==================================================================
{
	for (int i = 0; i < GHEIGHT; i++)
	{
		for (int j = 0; j < GWIDTH; j++)
		{
			gBoard[i][j] = GWALL;
		}
	}
}

//******************************************************************
//
// * Setup the used array
//==================================================================
void setUsed()
//==================================================================
{
	used = new int *[GHEIGHT];

	for (int i = 0; i < GHEIGHT; i++)
	{
		used[i] = new int[GWIDTH];

		for (int j = 0; j < GWIDTH; j++)
		{
			// set the edge to 1, represent can't use
			if (i == 0 || i == GHEIGHT - 1 || j == 0 || j == GWIDTH - 1)
			{
				used[i][j] = 1;
			}
			else
			{
				used[i][j] = 0;
			}
		}
	}
}

//******************************************************************
//
// * 隨機生成迷宮
//==================================================================
void generateMaze(int x, int y)
{
	// Set the current position as nothing (path) and mark it as used
	gBoard[y][x] = GNOTHING;
	used[y][x] = 1;

	// Shuffle the direction array randomly
	random_shuffle(dir.begin(), dir.end());

	// Iterate through the directions
	for (int i = 0; i < 4; i++)
	{
		int newX = 0, newY = 0;
		newX = x + dir[i].first * 2;
		newY = y + dir[i].second * 2;

		// Check if the new position is within the maze boundaries and not used
		if (newX > 0 && newX < GHEIGHT - 1 && newY > 0 && newY < GWIDTH - 1 && used[newY][newX] == 0)
		{
			int passX = 0, passY = 0;
			passX = x + dir[i].first;
			passY = y + dir[i].second;

			// Set the passed position as nothing (path) and mark it as used
			gBoard[passY][passX] = GNOTHING;
			used[passY][passX] = 1;

			// Recursively generate the maze from the new position
			generateMaze(newX, newY);
		}
	}
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	char drawBoard[GHEIGHT][GWIDTH];

	for (int i = 0; i < GHEIGHT; i++)
	{
		for (int j = 0; j < GWIDTH; j++)
		{
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	// Draw the board
	for (int i = 0; i < GHEIGHT; i++)
	{
		for (int j = 0; j < GWIDTH; j++)
		{
			std::cout << drawBoard[i][j]; //  output
		}
		std::cout << "\n";
	}
}

//******************************************************************
//
// * Output information
//==================================================================
void drawInfo(void)
//==================================================================
{
	if (gCreature.getSawHero())
	{
		std::cout << "Creature saw Hero." << std::endl;
		gCreature.setSawHero(false);
	}

	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Press ESC key to exit" << std::endl;
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// 清除版面
	system("CLS");

	// 是否有input
	bool hasInput = false;
	if (key[ValidInput::EW])
	{
		gHero.move(0, -1);
		hasInput = true;
	}
	else if (key[ValidInput::ES])
	{
		gHero.move(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA])
	{
		gHero.move(-1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED])
	{
		gHero.move(1, 0);
		hasInput = true;
	}
	else
	{
		std::cout << "invalid input\n";
	}
	// Calculate and Initiate Move
	gCreature.update(gHero.getPos());
	draw();
	drawInfo();
}
