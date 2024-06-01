/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/12
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/19
Description:
		基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，
		ESC是離開畫面。同時更新圖版上的資訊。
************************************************************************/
#include "main.h"
#include "Hero.h"

Hero gHero(2, 2);

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

const int GWIDTH = 10;
const int GHEIGHT = 10;
const double gTimeLog = 0.033;

// 用來儲存版面資料
char gBoard[GHEIGHT][GWIDTH];

class Creature
{ // creature class
private:
	Position sPos;	  // Creature position
	char sIcon = 'C'; // Creature icon
	int power;
	int hp;
	int cooldown;

public:
	// Default constructor
	Creature(void)
	{
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = 'C';
		this->power = 5;
		this->hp = 20;
		this->cooldown = 0;
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

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Update the creature
	void update(Hero &hero)
	{
		if (this->cooldown) this->cooldown -= 1;
		Position hPos = hero.getPos();

		Position dir;

		if (canSee(this->sPos, hPos, dir))
		{
			std::cout << "Creature has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
			this->sIcon = '!';
		}
		else
		{
			std::cout << "Creature didn't find the Hero\n";
			this->sIcon = 'C';
		}

		// Check is hero in the attack range of creature.
		if (abs(hPos.x - this->sPos.x) <= 1 && abs(hPos.y - this->sPos.y) <= 1)
		{
			if (!cooldown)
			{
				std::cout << "Creature attacked Hero.\n";
				hero.damage(power);
				this->cooldown = 3;
			}
			else 
			{
				std::cout << "Creature's attack cooldown is: " << this->cooldown << std::endl;
			}
		}

		// Check is creature touched the hero.
		// if true, damage the hero with the power of creature
		if (hPos.x == sPos.x && hPos.y == sPos.y)
		{
			hero.damage(power);
			this->damage(hero.getPower());
		}
	}

	void damage(int power)
	{
		this->hp -= power;

		// if the creature's hp reduced to zero, reborn the creature
		if (this->hp <= 0)
		{
			std::cout << "Creature is dead, reborning...\n";
			reBorn();
		}
	}

	// reborn the creature
	void reBorn(void)
	{
		// Random the reborn position
		int randX = rand() % GWIDTH, randY = rand() % GHEIGHT;
		Position newPos = { randX, randY };
		
		// 
		if (isPositionValid(newPos))
		{
			this->sPos.x = randX;
			this->sPos.y = randY;
			this->hp = 20;
		}
		else
		{
			reBorn();
		}
	}
};

// Distance
const int gDistance = 4;

// 定義六種輸入指令與對應陣列index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	EF = 6,
	INVALID
};

Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 初始化版面
void setupBoard();
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

// 程式主驅動函式
void update(bool key[]);

Trigger gTrigger(5, 5, 10);

int main(void)
{
	srand(time(NULL));

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[7];

	// Setup a clear dungeon
	setupBoard();

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

		// if hero's hp reduced to zero, end the game.
		if (gHero.getHP() <= 0)
		{
			std::cout << "hero is dead, end game." << std::endl;
			break;
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
	case 'f':
		key[ValidInput::EF] = true;
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

	return true;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimun, float maximum)
//==================================================================
{
	return std::max(minimun, std::min(n, maximum));
}

//******************************************************************
//
// * 利用 call-by-referce 將計算得到的方向回傳
//==================================================================
bool canSee(Position cPos, Position hPos, Position &dir)
//==================================================================
{
	// the dir_x and dir_y value are call-by-refernce
	dir.x = (int)clip((float)(hPos.x - cPos.x), -1.f, 1.f); // clip the value between -1 ~ 1
	dir.y = (int)clip((float)(hPos.y - cPos.y), -1.f, 1.f);
	int count = 0;

	do { // spot the target position
		if (cPos.x + dir.x * count == hPos.x &&
			cPos.y + dir.y * count == hPos.y)
		{
			return true;
		}
		count++;
	} while (count < gDistance); // check the range in 4 units
	
	return false;
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
			if (i == 0 || i == GHEIGHT - 1)
			{
				gBoard[i][j] = GWALL;
			}
			else if (j == 0 || j == GWIDTH - 1)
			{
				gBoard[i][j] = GWALL;
			}
			else
			{
				gBoard[i][j] = GNOTHING;
			}
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

	Position t = gTrigger.getPos();
	drawBoard[t.y][t.x] = gTrigger.getIcon();

	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

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
	std::cout << "The hero is level " << gHero.getLevel() << "(" << gHero.getExp() << "/" << gHero.getMaxExp() << " to level up)" << std::endl;
	std::cout << "The hero has " << gHero.getHP() << " hp" << std::endl;
	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Every time you step on a trigger T, the hero gets " << gTrigger.getExpAmount() << " EXP points" << std::endl;
	std::cout << "Press ESC key to exit" << std::endl;

	int turns = gHero.getAttackCooldown();

	if (turns)
	{
		std::cout << "The attack cooldown remain " << turns << std::endl;
	}
	else std::cout << "Hero's attack is ready, press f key to attack." << std::endl;
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
	else if (key[ValidInput::EF])
	{
		if (gHero.attack(gCreature.getPos()))
		{
			gCreature.damage(gHero.getPower());
		}

		hasInput = true;
	}
	else
	{
		std::cout << "invalid input\n";
	}

	// reduce the hero's attack cooldown.
	gHero.reduceAttackCooldown();

	// update trigger
	gTrigger.update(gHero);

	// update creature
	gCreature.update(gHero);

	// print out the Board and information.
	draw();
	drawInfo();
}