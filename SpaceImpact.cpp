#include <iostream>
#include <windows.h>
#include <conio.h>
#include <random>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int playerX = 3;
int playerY = 10;
int playerHealth = 20;
int playerHealthOld = 20;
int score = 0;
int scoreOld = 0;
int scoreDamage = 0;
int playerHarm = 0;
int level = 1;

char playerBullet = 169;
int playerBulletX[100];
int playerBulletY[100];
int playerBulletCount = 0;

int bugX[50];
int bugY[50];
int bugCount = 0;

int enemy1X[8];
int enemy1Y[8];
int enemy1Health[8];
int enemy1Count = 0;
int enemy1SpeedCount[8];

char enemy1Bullet = 170;
int enemy1BulletX[40];
int enemy1BulletY[40];
int enemy1BulletCount = 0;

int enemy2X[8];
int enemy2Y[8];
int enemy2Health[8];
int enemy2Count = 0;
int enemy2SpeedCount[8];

string enemy2Bullet = "-=";
int enemy2BulletX[40];
int enemy2BulletY[40];
int enemy2BulletCount = 0;

int enemy3X[3];
int enemy3Y[3];
bool isEnemy3MovingUp = true;
int enemy3Health[3];
int enemy3Count = 0;
int enemy3SpeedCount[8];

string enemy3Bullet = "<=-";
int enemy3BulletX[100];
int enemy3BulletY[100];
int enemy3BulletCount = 0;

char healer = 'o';
int healerX[20];
int healerY[20];
int healerCount = 0;

int arrowy;

void printHeader();
int choice();
void instructions();
void storyLine();
void aboutDeveloper();
void printMaze();
void levelScreen();

void printPlayer();
void erasePlayer();

void movePlayer();
void movePlayerLeft();
void movePlayerRight();
void movePlayerUp();
void movePlayerDown();
bool isPlayerCollision(int x, int y);
bool isBulletEnemyCollision(int, int);

void createPlayerBullet();
void erasePlayerBullet(int whichBullet);
void movePlayerBullet();
void deletePlayerBullet(int whichBullet);

void createBug();
void eraseBug(int whichBug);
void moveBug();
void deleteBug(int whichBug);
bool bugGenerationCollosion(int generatedY);

void createEnemy1();
void eraseEnemy1(int index);
void moveEnemy1();
void deleteEnemy1(int index);
bool enemy1GenerationCollosion(int generatedY);

void createEnemy1Bullet();
void eraseEnemy1Bullet(int index);
void moveEnemy1Bullet();
void deleteEnemy1Bullet(int index);

void createEnemy2();
void eraseEnemy2(int index);
void moveEnemy2();
void deleteEnemy2(int index);

void createEnemy2Bullet();
void eraseEnemy2Bullet(int index);
void moveEnemy2Bullet();
void deleteEnemy2Bullet(int index);
bool enemy2GenerationCollosion(int generatedY);

void createEnemy3();
void eraseEnemy3(int index);
void moveEnemy3Vertcal();
void deleteEnemy3(int index);

void createEnemy3Bullet();
void eraseEnemy3Bullet(int index);
void moveEnemy3Bullet();
void deleteEnemy3Bullet(int index);
bool enemy3GenerationCollosion(int generatedY);
bool enemy3BulletGenerationCollosion(int generatedY);

void createHealer();
void eraseHealer(int index);
void moveHealer();
void deleteHealer(int index);

void youWon();
void youLose();

void drawHealth();
void printScore();
void printLevel();

void deleteEnemies();


void gotoxy(int, int);
char getCharAtxy(short int x, short int y);
int generateRandomNumber(int min, int max);
void cursor(bool);
int moveArrow(int input, int arrowLocation, int top, int options);
void printArrow(int y);
void eraseArrow();

main()
{
	cursor(0);

	int option = 0;

	while (option != 5)
	{
		option = choice();

		if (option == 2)
			instructions();
		else if (option == 3)
			storyLine();
		else if (option == 4)
			aboutDeveloper();
		else if (option == 1)	//Start Game Option
		{
			int playerX = 3;
			int playerY = 10;
			deleteEnemies();	//Reset Memory

			int playerFireTime = 0;
			int bugTime = 10;
			int enemy1Time = 20;
			int enemy1FireTime = 5;
			int enemy2Time = 20;
			int enemy2FireTime = 5;
			int enemy3Time = 950;
			int enemy3VerticalTime =0;
			int enemy3FireTime = 0;
			int enemy3FireMoveTime =0;
			int healerTime = 0;

			level = 1;
			playerHealth = 20;
			score = 0;
			bool Status = false;



			printMaze();
			levelScreen();
			printPlayer();
			drawHealth();
			printScore();
			printLevel();

//															  			<---- Level 1 ---=>


			while (playerHealth > 0 && score <= 100)
			{
				// Maze 26 //74

				movePlayer();

				if (GetAsyncKeyState(VK_SPACE) && playerFireTime > 3)
				{
					createPlayerBullet();
					playerFireTime = 0;
				}

				movePlayerBullet();

				if (bugTime > 12)
				{
					createBug();
					bugTime = 0;
				}
				moveBug();

				if (enemy1Time > 50)
				{
					createEnemy1();
					enemy1Time = 0;
				}
				moveEnemy1();

				if (enemy1FireTime > 30)
				{
					createEnemy1Bullet();
					enemy1FireTime = 0;
				}
				moveEnemy1Bullet();

				if (playerHarm > 0)
				{
					playerHarm--;
					printPlayer();
					drawHealth();
				}

				if (playerHealthOld != playerHealth)
				{
					drawHealth();
					playerHealthOld = playerHealth;
				}

				if (scoreOld != score)
				{
					printScore();
					scoreOld = score;
				}

				playerFireTime++;
				bugTime++;
				enemy1Time++;
				enemy1FireTime++;

				Sleep(90);
			}
			deleteEnemies();

//															  			<---- Level 2 ---=>
			if (playerHealth > 0) // 
			{
				playerHealth = 20;
				level = 2;
				levelScreen();
				deleteEnemies();
				printMaze(); // 26 //74
				printPlayer();
				drawHealth();
				printScore();
				printLevel();

				Sleep(1000);
				while (playerHealth > 0 && score <= 250)
				{

					movePlayer();

					if (GetAsyncKeyState(VK_SPACE) && playerFireTime > 4)
					{
						createPlayerBullet();
						playerFireTime = 0;
					}
					movePlayerBullet();

					if (bugTime > 8)
					{
						createBug();
						bugTime = 0;
					}
					moveBug();

					if (enemy1Time > 250)
					{
						createEnemy1();
						enemy1Time = 0;
					}
					moveEnemy1();

					if (enemy1FireTime > 18)
					{
						createEnemy1Bullet();
						enemy1FireTime = 0;
					}
					moveEnemy1Bullet();

					if (enemy2Time > 60) // 60
					{
						createEnemy2();
						enemy2Time = 0;
					}
					moveEnemy2();

					if (enemy2FireTime > 18)
					{
						createEnemy2Bullet();
						enemy2FireTime = 0;
					}
					moveEnemy2Bullet();

					if (healerTime > 200)
					{
						createHealer();
						healerTime = 0;
					}
					moveHealer();

					if (playerHarm > 0)
					{
						playerHarm--;
						printPlayer();
						drawHealth();
						playerHealthOld = playerHealth;
					}

					if (playerHarm < 0)
					{
						playerHarm++;
						drawHealth();
						playerHealthOld = playerHealth;
					}

					if (playerHealthOld != playerHealth)
					{
						drawHealth();
						playerHealthOld = playerHealth;
					}

					if (scoreOld != score)
					{
						scoreOld = score;
						printScore();
					}
					if (scoreDamage > 0)
					{
						scoreDamage--;
						printScore();
					}

					playerFireTime++;
					bugTime++;
					enemy1Time++;
					enemy1FireTime++;
					enemy2Time++;
					enemy2FireTime++;
					healerTime++;

					Sleep(60);
				}
			}
			deleteEnemies();

//															  			<---- Level 3 ---=>
			if (playerHealth > 0)
			{
				playerHealth = 20;
				level = 3;
				levelScreen();
				deleteEnemies();
				printMaze(); // 26 //74
				printPlayer();
				drawHealth();
				printScore();
				printLevel();
				createEnemy3();

				Sleep(generateRandomNumber(500,1000));
				while (playerHealth > 0 && enemy3Count==1 && score>=200)
				{

					movePlayer();

					if (GetAsyncKeyState(VK_SPACE) && playerFireTime > 6)
					{
						createPlayerBullet();
						playerFireTime = 0;
					}
					movePlayerBullet();

					if (bugTime > 15)
					{
						createBug();
						bugTime = 0;
					}
					moveBug();

					if (enemy1Time > 250)
					{
						createEnemy1();
						enemy1Time = 0;
					}
					moveEnemy1();

					if (enemy1FireTime > 18)
					{
						createEnemy1Bullet();
						enemy1FireTime = 0;
					}
					moveEnemy1Bullet();

					if (enemy2Time > 250) // 60
					{
						createEnemy2();
						enemy2Time = 0;
					}
					moveEnemy2();

					if (enemy2FireTime > 18)
					{
						createEnemy2Bullet();
						enemy2FireTime = 0;
					}
					moveEnemy2Bullet();


					if (enemy3VerticalTime > 20)
					{
						moveEnemy3Vertcal();
						enemy3VerticalTime=0;
					}

					if (enemy3FireTime > 18)
					{
						createEnemy3Bullet();
						enemy3FireTime = 0;
					}

					if(enemy3FireMoveTime >2)
					{
						moveEnemy3Bullet();
						enemy3FireMoveTime =0;
					}


					if (healerTime > 500)
					{
						createHealer();
						healerTime = 0;
					}
					moveHealer();

					if (playerHarm > 0)
					{
						playerHarm--;
						printPlayer();
						drawHealth();
						playerHealthOld = playerHealth;
					}

					if (playerHarm < 0)
					{
						playerHarm++;
						drawHealth();
						playerHealthOld = playerHealth;
					}

					if (playerHealthOld != playerHealth)
					{
						drawHealth();
						playerHealthOld = playerHealth;
					}

					if (scoreOld != score)
					{
						scoreOld = score;
						printScore();
					}
					if (scoreDamage > 0)
					{
						scoreDamage--;
						printScore();
					}

					playerFireTime++;
					bugTime++;
					enemy1Time++;
					enemy1FireTime++;
					enemy2Time++;
					enemy2FireTime++;
					enemy3Time++;
					enemy3VerticalTime++;
					enemy3FireTime++;
					enemy3FireMoveTime++;
					healerTime++;

					if(enemy3Count==0 && score>=200)
						Status= true;

					Sleep(40);
				}
			}
			deleteEnemies();

//															  			<---- Win Decider ---=>

			if(Status)
				youWon();
			else
				youLose();
			Sleep(1000);
		}
	}
}

//															  					<---- Player Movement ---=>

void printPlayer()
{
	gotoxy(playerX, playerY);

	if (playerHarm == 0)						//To print Green Player
		SetConsoleTextAttribute(hConsole, 10);
	else										//To Print Red Player
		SetConsoleTextAttribute(hConsole, 12);
	cout << "## /\\";
	gotoxy(playerX, playerY + 1);
	cout << " #-@-#>";
	gotoxy(playerX, playerY + 2);
	cout << "## \\/";
	SetConsoleTextAttribute(hConsole, 15);
}
void erasePlayer()
{
	gotoxy(playerX, playerY);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "      ";
	gotoxy(playerX, playerY + 1);
	cout << "       ";
	gotoxy(playerX, playerY + 2);
	cout << "      ";
	SetConsoleTextAttribute(hConsole, 15);
}
void movePlayer()
{
	//Move to all four directions

	if (GetAsyncKeyState(VK_LEFT))
		movePlayerLeft();
	if (GetAsyncKeyState(VK_RIGHT))
		movePlayerRight();
	if (GetAsyncKeyState(VK_UP))
		movePlayerUp();
	if (GetAsyncKeyState(VK_DOWN))
		movePlayerDown();
}
void movePlayerLeft()
{
	if (getCharAtxy(playerX - 1, playerY) == ' ')
	{
		erasePlayer();
		playerX--;
		printPlayer();
	}
}
void movePlayerRight()
{
	
	if(level==3 && playerX>50)	// movement limitation for Level 3
		return;

	if (getCharAtxy(playerX + 8, playerY) == ' ')
	{
		erasePlayer();
		playerX++;
		printPlayer();
	}
}
void movePlayerUp()
{
	if (getCharAtxy(playerX, playerY - 1) == ' ')
	{
		erasePlayer();
		playerY--;
		printPlayer();
	}
}
void movePlayerDown()
{
	if (getCharAtxy(playerX, playerY + 3) == ' ')
	{
		erasePlayer();
		playerY++;
		printPlayer();
	}
}

//															  					<---- Player Firing ---=>

void createPlayerBullet()
{
	playerBulletX[playerBulletCount] = playerX + 7;		//Prints at the head of Player Spaceship
	playerBulletY[playerBulletCount] = playerY + 1;

	gotoxy(playerBulletX[playerBulletCount], playerBulletY[playerBulletCount]);
	cout << playerBullet;

	playerBulletCount++;
}
void erasePlayerBullet(int whichBullet)
{
	gotoxy(playerBulletX[whichBullet], playerBulletY[whichBullet]);
	cout << ' ';
}
void movePlayerBullet()
{
	for (int i = 0; i < playerBulletCount; i++)
	{
		erasePlayerBullet(i);
		playerBulletX[i]++;

		if (playerBulletX[i] > 73) // hit maze size. Or wall...
		{
			deletePlayerBullet(i);
		}
		else if (isBulletEnemyCollision(playerBulletX[i], playerBulletY[i]))	//If collides with Player
		{
			deletePlayerBullet(i);
		}
		else						// Move Bullet
		{
			gotoxy(playerBulletX[i], playerBulletY[i]);
			cout << playerBullet;
		}
	}
}
void deletePlayerBullet(int whichBullet)
{
	for (int i = whichBullet; i < playerBulletCount - 1; i++)
	{
		playerBulletX[i] = playerBulletX[i + 1];
		playerBulletY[i] = playerBulletY[i + 1];
	}
	playerBulletCount--;
}

//															  					<---- Bugs ---=>

void createBug()
{
	bugX[bugCount] = 70;
	bugY[bugCount] = generateRandomNumber(5, 24);

	int whileCounter = 0;
	while (enemy1GenerationCollosion(bugY[bugCount]) || enemy2GenerationCollosion(bugY[bugCount]) || enemy3GenerationCollosion(bugY[bugCount]) || enemy3BulletGenerationCollosion(bugY[bugCount]))
	{
		//Checks if the generated coordinate Collides with some other enemy

		bugY[bugCount] = generateRandomNumber(5, 24);
		whileCounter++;
		if (whileCounter == 4)
			return;
	}

	gotoxy(bugX[bugCount], bugY[bugCount]);
	SetConsoleTextAttribute(hConsole, 13);
	cout << "(@@";
	SetConsoleTextAttribute(hConsole, 13);
	bugCount++;
}
void eraseBug(int whichBug)
{
	gotoxy(bugX[whichBug], bugY[whichBug]);
	cout << "    ";
}
void moveBug()
{
	for (int i = 0; i < bugCount; i++)
	{
		eraseBug(i);
		bugX[i]--;

		if (bugX[i] < 3) // maze size. Or wall...
		{
			deleteBug(i);
		}
		else if (isPlayerCollision(bugX[i], bugY[i]))
		{
			deleteBug(i);
			playerHealth -= 2;
			playerHarm = 3;
			printPlayer();
		}
		else
		{
			gotoxy(bugX[i], bugY[i]);
			SetConsoleTextAttribute(hConsole, 13);
			cout << "(@@";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}
void deleteBug(int whichBug)
{
	eraseBug(whichBug);

	for (int i = whichBug; i < bugCount - 1; i++)
	{
		bugX[i] = bugX[i + 1];
		bugY[i] = bugY[i + 1];
	}
	bugCount--;
}
bool bugGenerationCollosion(int generatedY)
{
	if (bugCount == 0)
		return false;

	for (int i = 0; i < bugCount; i++)
	{
		if (generatedY == bugY[i])	//if any of the generated location coolides with bug
			return true;
	}
	return false;
}

//															  			    <---- Enemy 1 (Bishops) ---=>

void createEnemy1()
{
	enemy1X[enemy1Count] = 65;
	enemy1Y[enemy1Count] = generateRandomNumber(5, 24);

	int whileCounter = 0;
	while (enemy1GenerationCollosion(enemy1Y[enemy1Count]) || enemy1GenerationCollosion(enemy1Y[enemy1Count] + 1) ||
	enemy2GenerationCollosion(enemy1Y[enemy1Count]) || enemy2GenerationCollosion(enemy1Y[enemy1Count] + 1) ||
	enemy3GenerationCollosion(enemy1Y[enemy1Count]))
	
	// || enemy3GenerationCollosion(enemy1Y[enemy1Count] + 1) || enemy3GenerationCollosion(enemy1Y[enemy1Count] + 2) ||
	// enemy3GenerationCollosion(enemy1Y[enemy1Count]+3) || enemy3GenerationCollosion(enemy1Y[enemy1Count]+4) ||
	// enemy3GenerationCollosion(enemy1Y[enemy1Count]-1) || enemy3GenerationCollosion(enemy1Y[enemy1Count]-2) || enemy3GenerationCollosion(enemy1Y[enemy1Count]-3) || enemy3GenerationCollosion(enemy1Y[enemy1Count]-4) )
	{
		enemy1Y[enemy1Count] = generateRandomNumber(5, 24);
		whileCounter++;
		if (whileCounter == 4)
			return;
	}
	SetConsoleTextAttribute(hConsole, 14);

	gotoxy(enemy1X[enemy1Count], enemy1Y[enemy1Count]);
	cout << "  /%o%o%";
	gotoxy(enemy1X[enemy1Count], enemy1Y[enemy1Count] + 1);
	cout << "\"\"\"%%%%%";

	SetConsoleTextAttribute(hConsole, 15);
	enemy1Health[enemy1Count] = 5;
	enemy1Count++;
}
void eraseEnemy1(int index)
{
	gotoxy(enemy1X[index], enemy1Y[index]);
	cout << "         ";
	gotoxy(enemy1X[index], enemy1Y[index] + 1);
	cout << "         ";
}
void moveEnemy1()
{

	for (int i = 0; i < enemy1Count; i++)
	{
		if (enemy1SpeedCount[i] > 3)
		{
			eraseEnemy1(i);
			enemy1X[i]--;

			if (enemy1X[i] < 3) // maze size. Or wall...
			{
				deleteEnemy1(i);
			}
			else if (isPlayerCollision(enemy1X[i], enemy1Y[i]) || isPlayerCollision(enemy1X[i], enemy1Y[i] + 1))
			{
				deleteEnemy1(i);
				playerHealth -= 5;
				playerHarm = 10;
				printPlayer();
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 14);
				gotoxy(enemy1X[i], enemy1Y[i]);
				cout << "  /%o%o%";
				gotoxy(enemy1X[i], enemy1Y[i] + 1);
				cout << "\"\"\"%%%%%";
				SetConsoleTextAttribute(hConsole, 15);
			}

			enemy1SpeedCount[i] = 0;
		}

		enemy1SpeedCount[i]++;
	}
}
void deleteEnemy1(int index)
{
	eraseEnemy1(index);

	for (int i = index; i < enemy1Count - 1; i++)
	{
		enemy1X[i] = enemy1X[i + 1];
		enemy1Y[i] = enemy1Y[i + 1];
		enemy1Health[i] = enemy1Health[i + 1];
	}
	enemy1Count--;
}
bool enemy1GenerationCollosion(int generatedY)
{
	if (enemy1Count == 0)
		return false;
	for (int i = 0; i < enemy1Count; i++)
	{
		if (generatedY == enemy1Y[i] || generatedY == enemy1Y[i] + 1)	//If generated Location collides with any location of enemy1
			return true;
	}
	return false;
}

void createEnemy1Bullet()
{
	for (int i = 0; i < enemy1Count; i++)
	{
		if (enemy1SpeedCount[i] > 1)
		{
			if (enemy1X[i] < 4)
				continue;
			enemy1BulletX[enemy1BulletCount] = enemy1X[i] + 1;
			enemy1BulletY[enemy1BulletCount] = enemy1Y[i];

			gotoxy(enemy1BulletX[enemy1BulletCount], enemy1BulletY[enemy1BulletCount]);
			cout << enemy1Bullet;

			SetConsoleTextAttribute(hConsole, 12);
			enemy1BulletCount++;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}
void eraseEnemy1Bullet(int whichBullet)
{
	gotoxy(enemy1BulletX[whichBullet], enemy1BulletY[whichBullet]);
	cout << ' ';
}
void moveEnemy1Bullet()
{
	for (int i = 0; i < enemy1BulletCount; i++)
	{
		eraseEnemy1Bullet(i);
		enemy1BulletX[i]--;

		if (enemy1BulletX[i] < 3) // maze size. Or wall...
		{
			deleteEnemy1Bullet(i);
		}
		else if (isPlayerCollision(enemy1BulletX[i], enemy1BulletY[i]))
		{
			deleteEnemy1Bullet(i);
			playerHealth -= 1;
			playerHarm = 3;
			printPlayer();
		}
		else
		{
			gotoxy(enemy1BulletX[i], enemy1BulletY[i]);
			SetConsoleTextAttribute(hConsole, 12);
			cout << enemy1Bullet;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}
void deleteEnemy1Bullet(int whichBullet)
{
	eraseEnemy1Bullet(whichBullet);

	for (int i = whichBullet; i < enemy1BulletCount - 1; i++)
	{
		enemy1BulletX[i] = enemy1BulletX[i + 1];
		enemy1BulletY[i] = enemy1BulletY[i + 1];
	}
	enemy1BulletCount--;
}

//															  				 <---- Enemy 2 (Rooks)---=>

void createEnemy2()
{
	enemy2X[enemy2Count] = 65;
	enemy2Y[enemy2Count] = generateRandomNumber(5, 23);

	int whileCounter = 0;
	while (enemy2GenerationCollosion(enemy2Y[enemy2Count]) || enemy2GenerationCollosion(enemy2Y[enemy2Count] + 1) || enemy2GenerationCollosion(enemy2Y[enemy2Count] + 2) ||
	enemy1GenerationCollosion(enemy2Y[enemy2Count]) || enemy1GenerationCollosion(enemy2Y[enemy2Count] + 1) || enemy1GenerationCollosion(enemy2Y[enemy2Count] + 2) ||
	enemy3GenerationCollosion(enemy2Y[enemy2Count]))
	
	// || enemy3GenerationCollosion(enemy2Y[enemy2Count] + 1) || enemy3GenerationCollosion(enemy2Y[enemy2Count] + 2) ||
	// enemy3GenerationCollosion(enemy2Y[enemy2Count]+3) || enemy3GenerationCollosion(enemy2Y[enemy2Count]+4) ||
	// enemy3GenerationCollosion(enemy2Y[enemy2Count]-1) || enemy3GenerationCollosion(enemy2Y[enemy2Count]-2) || enemy3GenerationCollosion(enemy2Y[enemy2Count]-3))
	{
		enemy2Y[enemy2Count] = generateRandomNumber(5, 23);
		whileCounter++;
		if (whileCounter == 4)
			return;
	}

	SetConsoleTextAttribute(hConsole, 11);

	gotoxy(enemy2X[enemy2Count], enemy2Y[enemy2Count]);
	cout << " --#";
	gotoxy(enemy2X[enemy2Count], enemy2Y[enemy2Count] + 1);
	cout << "<-|o|";

	gotoxy(enemy2X[enemy2Count], enemy2Y[enemy2Count] + 2);
	cout << " --#";

	SetConsoleTextAttribute(hConsole, 15);
	enemy2Health[enemy2Count] = 10;
	enemy2Count++;
}
void eraseEnemy2(int index)
{
	gotoxy(enemy2X[index], enemy2Y[index]);
	cout << "    ";
	gotoxy(enemy2X[index], enemy2Y[index] + 1);
	cout << "     ";
	gotoxy(enemy2X[index], enemy2Y[index] + 2);
	cout << "    ";
}
void moveEnemy2()
{
	for (int i = 0; i < enemy2Count; i++)
	{
		if (enemy2SpeedCount[i] > 3)
		{
			eraseEnemy2(i);
			enemy2X[i]--;

			if (enemy2X[i] < 3) // maze size. Or wall...
			{
				deleteEnemy2(i);
				if (score > 21)
					score -= 20;
				else
					score = 0;
				scoreDamage = 15;
			}
			else if (enemy2X[i] < 10)
			{
				SetConsoleTextAttribute(hConsole, 12);

				gotoxy(enemy2X[i], enemy2Y[i]);
				cout << " --#";
				gotoxy(enemy2X[i], enemy2Y[i] + 1);
				cout << "<-|o|";
				gotoxy(enemy2X[i], enemy2Y[i] + 2);
				cout << " --#";
				SetConsoleTextAttribute(hConsole, 15);
			}

			else
			{
				SetConsoleTextAttribute(hConsole, 11);

				gotoxy(enemy2X[i], enemy2Y[i]);
				cout << " --#";
				gotoxy(enemy2X[i], enemy2Y[i] + 1);
				cout << "<-|o|";
				gotoxy(enemy2X[i], enemy2Y[i] + 2);
				cout << " --#";
				SetConsoleTextAttribute(hConsole, 15);
			}

			if (isPlayerCollision(enemy2X[i], enemy2Y[i]) || isPlayerCollision(enemy2X[i], enemy2Y[i] + 1) || isPlayerCollision(enemy2X[i], enemy2Y[i] + 2))
			{
				deleteEnemy2(i);
				playerHealth -= 5;
				playerHarm = 10;
				printPlayer();
			}
			

			enemy2SpeedCount[i] = 0;
		}

		enemy2SpeedCount[i]++;
	}
}
void deleteEnemy2(int index)
{
	eraseEnemy2(index);

	for (int i = index; i < enemy2Count - 1; i++)
	{
		enemy2X[i] = enemy2X[i + 1];
		enemy2Y[i] = enemy2Y[i + 1];
		enemy2Health[i] = enemy2Health[i + 1];
	}
	enemy2Count--;
}
bool enemy2GenerationCollosion(int generatedY)
{
	if (enemy2Count == 0)
		return false;
	for (int i = 0; i < enemy2Count; i++)
	{
		if (generatedY == enemy2Y[i] || generatedY == enemy2Y[i] + 1 || generatedY == enemy2Y[i] + 2)
			return true;
	}
	return false;
}

void createEnemy2Bullet()
{
	for (int i = 0; i < enemy2Count; i++)
	{
		if (enemy2SpeedCount[i] > 1)
		{
			if (enemy2X[i] < 4)
				continue;
			enemy2BulletX[enemy2BulletCount] = enemy2X[i] - 1;
			enemy2BulletY[enemy2BulletCount] = enemy2Y[i] + generateRandomNumber(0, 2);

			gotoxy(enemy2BulletX[enemy2BulletCount], enemy2BulletY[enemy2BulletCount]);
			cout << enemy2Bullet;

			SetConsoleTextAttribute(hConsole, 12);
			enemy2BulletCount++;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}
void eraseEnemy2Bullet(int whichBullet)
{
	gotoxy(enemy2BulletX[whichBullet], enemy2BulletY[whichBullet]);
	cout << "  ";
}
void moveEnemy2Bullet()
{
	for (int i = 0; i < enemy2BulletCount; i++)
	{
		eraseEnemy2Bullet(i);
		enemy2BulletX[i]--;

		if (enemy2BulletX[i] < 3) // maze size. Or wall...
		{
			deleteEnemy2Bullet(i);
		}
		else if (isPlayerCollision(enemy2BulletX[i], enemy2BulletY[i]))
		{
			deleteEnemy2Bullet(i);
			playerHealth -= 2;
			playerHarm = 5;
			printPlayer();
		}
		else
		{
			gotoxy(enemy2BulletX[i], enemy2BulletY[i]);
			SetConsoleTextAttribute(hConsole, 12);
			cout << enemy2Bullet;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}
void deleteEnemy2Bullet(int whichBullet)
{
	eraseEnemy2Bullet(whichBullet);

	for (int i = whichBullet; i < enemy2BulletCount - 1; i++)
	{
		enemy2BulletX[i] = enemy2BulletX[i + 1];
		enemy2BulletY[i] = enemy2BulletY[i + 1];
	}
	enemy2BulletCount--;
}

//															  			<---- Enemy 3 (Euilo MasterMind)---=>

void createEnemy3()
{
	enemy3X[enemy3Count] = 65;
	enemy3Y[enemy3Count] = generateRandomNumber(5, 21);

	int whileCounter = 0;
	while (enemy2GenerationCollosion(enemy3Y[enemy3Count]) || enemy2GenerationCollosion(enemy3Y[enemy3Count] + 1) || enemy2GenerationCollosion(enemy3Y[enemy3Count] + 2) || enemy1GenerationCollosion(enemy3Y[enemy3Count]) || enemy1GenerationCollosion(enemy3Y[enemy3Count] + 1) || enemy1GenerationCollosion(enemy3Y[enemy3Count] + 2))
	{
		enemy3Y[enemy3Count] = generateRandomNumber(5, 21);
		whileCounter++;
		if (whileCounter == 4)
			return;
	}

	SetConsoleTextAttribute(hConsole, 12);
	gotoxy(enemy3X[enemy3Count], enemy3Y[enemy3Count]);
	cout << "\033[31m  ~-#";
	gotoxy(enemy3X[enemy3Count], enemy3Y[enemy3Count] + 1);
	cout << "_-o\033[33m@\033[31m|";
	gotoxy(enemy3X[enemy3Count], enemy3Y[enemy3Count] + 2);
	cout << " -o\033[33m@\033[31m|";
	gotoxy(enemy3X[enemy3Count], enemy3Y[enemy3Count] + 3);
	cout << "  ~-#";
	SetConsoleTextAttribute(hConsole, 15);

	SetConsoleTextAttribute(hConsole, 15);
	enemy3Health[enemy3Count] = 50;
	enemy3Count++;
}
void eraseEnemy3(int index)
{
	gotoxy(enemy3X[index], enemy3Y[index]);
	cout << "     ";
	gotoxy(enemy3X[index], enemy3Y[index] + 1);
	cout << "      ";
	gotoxy(enemy3X[index], enemy3Y[index] + 2);
	cout << "     ";
	gotoxy(enemy3X[index], enemy3Y[index] + 3);
	cout << "      ";
}
void moveEnemy3Vertcal()
{
	for (int i = 0; i < enemy3Count; i++)
	{
		if (isEnemy3MovingUp)	//Player Moving Up
		{
			eraseEnemy3(i);
			enemy3Y[i]--;

			SetConsoleTextAttribute(hConsole, 12);
			gotoxy(enemy3X[i], enemy3Y[i]);
			cout << "\033[31m  ~-#";
			gotoxy(enemy3X[i], enemy3Y[i] + 1);
			cout << "_-o\033[33m@\033[31m|";
			gotoxy(enemy3X[i], enemy3Y[i] + 2);
			cout << " -o\033[33m@\033[31m|";
			gotoxy(enemy3X[i], enemy3Y[i] + 3);
			cout << "  ~-#";
			SetConsoleTextAttribute(hConsole, 15);
		}

		else // moving down
		{

			eraseEnemy3(i);
			enemy3Y[i]++;

			SetConsoleTextAttribute(hConsole, 12);
			gotoxy(enemy3X[i], enemy3Y[i]);
			cout << "\033[31m  ~-#";
			gotoxy(enemy3X[i], enemy3Y[i] + 1);
			cout << "_-o\033[33m@\033[31m|";
			gotoxy(enemy3X[i], enemy3Y[i] + 2);
			cout << " -o\033[33m@\033[31m|";
			gotoxy(enemy3X[i], enemy3Y[i] + 3);
			cout << "  ~-#";
			SetConsoleTextAttribute(hConsole, 15);
		}

		if (isPlayerCollision(enemy3X[i], enemy3Y[i]) || isPlayerCollision(enemy3X[i], enemy3Y[i] + 1) || isPlayerCollision(enemy3X[i], enemy3Y[i] + 2) || isPlayerCollision(enemy3X[i], enemy3Y[i] + 3))
			{
				playerHealth -= 1;
				playerHarm = 10;
				printPlayer();
			}


		if(enemy3Y[i]==22)			//When Reached at Bottom
			isEnemy3MovingUp=true;
		if(enemy3Y[i]==4)			//When Reached at Top
			isEnemy3MovingUp=false;
	}
}
void deleteEnemy3(int index)
{
	eraseEnemy3(index);

	for (int i = index; i < enemy3Count - 1; i++)
	{
		enemy3X[i] = enemy3X[i + 1];
		enemy3Y[i] = enemy3Y[i + 1];
		enemy3Health[i] = enemy3Health[i + 1];
	}
	enemy3Count--;
}
bool enemy3GenerationCollosion(int generatedY)
{
	if (enemy3Count == 0)
		return false;
	for (int i = 0; i < enemy3Count; i++)
	{
		if(isEnemy3MovingUp)
		{
			if (generatedY == enemy3Y[i] -2 || generatedY == enemy3Y[i] -1 || generatedY == enemy3Y[i] -2 || generatedY == enemy3Y[i] || generatedY == enemy3Y[i] + 1 || generatedY == enemy3Y[i] + 2  || generatedY == enemy3Y[i] + 3)
				return true;
		}

		else
		{
			if (generatedY == enemy3Y[i] || generatedY == enemy3Y[i] + 1 || generatedY == enemy3Y[i] + 2  || generatedY == enemy3Y[i] + 3 || generatedY == enemy3Y[i] + 4 || generatedY == enemy3Y[i] + 5)
				return true;
		}

	}
	return false;
}
bool enemy3BulletGenerationCollosion(int generatedY)
{
	if(enemy3BulletCount==0)
		return false;

	for (int i=0; i<enemy3BulletCount; i++)
	{
		if(enemy3BulletY[i] == generatedY)
			return true;
	}

	return false;
}

void createEnemy3Bullet()
{
	for (int i = 0; i < enemy3Count; i++)
	{
		// if (enemy3SpeedCount[i] > 1)
		// {
			enemy3BulletX[enemy3BulletCount] = enemy3X[i] - 3;
			enemy3BulletY[enemy3BulletCount] = enemy3Y[i] + generateRandomNumber(0, 3);

			gotoxy(enemy3BulletX[enemy3BulletCount], enemy3BulletY[enemy3BulletCount]);
			
			SetConsoleTextAttribute(hConsole, 12);
			cout << enemy3Bullet;
			enemy3BulletCount++;
			SetConsoleTextAttribute(hConsole, 15);
	}
}
void eraseEnemy3Bullet(int whichBullet)
{
	gotoxy(enemy3BulletX[whichBullet], enemy3BulletY[whichBullet]);
	cout << "   ";
}
void moveEnemy3Bullet()
{
	for (int i = 0; i < enemy3BulletCount; i++)
	{
		eraseEnemy3Bullet(i);
		enemy3BulletX[i]--;

		if (enemy3BulletX[i] < 3) // maze size. Or wall...
		{
			deleteEnemy3Bullet(i);
		}
		else if (isPlayerCollision(enemy3BulletX[i], enemy3BulletY[i]))
		{
			deleteEnemy3Bullet(i);
			playerHealth -= 3;
			playerHarm = 5;
			printPlayer();
		}
		else
		{
			gotoxy(enemy3BulletX[i], enemy3BulletY[i]);
			SetConsoleTextAttribute(hConsole, 12);
			cout << enemy3Bullet;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}
void deleteEnemy3Bullet(int whichBullet)
{
	eraseEnemy3Bullet(whichBullet);

	for (int i = whichBullet; i < enemy3BulletCount - 1; i++)
	{
		enemy3BulletX[i] = enemy3BulletX[i + 1];
		enemy3BulletY[i] = enemy3BulletY[i + 1];
	}
	enemy3BulletCount--;
}

//															  			<---- Healer ---=>

void createHealer()
{
	healerX[healerCount] = 70;
	healerY[healerCount] = generateRandomNumber(5, 24);		//Create Healer at some Random Location

	int whileCounter = 0;
	while (enemy1GenerationCollosion(healerY[healerCount]) || enemy2GenerationCollosion(healerY[healerCount]) || bugGenerationCollosion(healerY[healerCount]) || enemy3GenerationCollosion(healerY[healerCount]) || enemy3BulletGenerationCollosion(healerY[healerCount]))
	{
		healerY[healerCount] = generateRandomNumber(5, 24);
		whileCounter++;
		if (whileCounter == 4)
			return;
	}

	gotoxy(healerX[healerCount], healerY[healerCount]);
	SetConsoleTextAttribute(hConsole, 10);
	cout << healer;
	SetConsoleTextAttribute(hConsole, 13);
	healerCount++;
}
void eraseHealer(int whichHealer)
{
	gotoxy(healerX[whichHealer], healerY[whichHealer]);
	cout << " ";
}
void moveHealer()
{
	for (int i = 0; i < healerCount; i++)
	{
		eraseHealer(i);
		healerX[i]--;

		if (healerX[i] < 3) // maze size. Or wall...
		{
			deleteHealer(i);
		}
		else if (isPlayerCollision(healerX[i], healerY[i]))
		{
			deleteHealer(i);
			if (playerHealth < 19)
				playerHealth += 2;
			else if (playerHealth == 19)
				playerHealth++;

			playerHarm = -5;
		}
		else
		{
			gotoxy(healerX[i], healerY[i]);
			SetConsoleTextAttribute(hConsole, 10);
			cout << healer;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}
void deleteHealer(int whichHealer)
{
	eraseHealer(whichHealer);

	for (int i = whichHealer; i < healerCount - 1; i++)
	{
		healerX[i] = healerX[i + 1];
		healerY[i] = healerY[i + 1];
	}
	healerCount--;
}
bool healerGenerationCollosion(int generatedY)
{
	if (healerCount == 0)
		return false;
	for (int i = 0; i < healerCount; i++)
	{
		if (generatedY == healerY[i])
			return true;
	}
	return false;
}

//																<---- Collosion Detectors ---=>

bool isPlayerCollision(int x, int y)
{

	for (int i = 0; i < 7; i++) // checks player width
	{
		for (int j = 0; j < 3; j++) // checks player height
		{
			if (x == playerX + i + 1 && y == playerY + j && getCharAtxy(playerX + i, playerY + j) != ' ')	// all condition for collision excluding space.
			{
				return true;
			}
		}
	}
	return false;
}

bool isBulletEnemyCollision(int x, int y)
{
	// for bug
	for (int i = 0; i < bugCount; i++)
	{
		if ((x == bugX[i] || x == bugX[i] + 1) && y == bugY[i])
		{
			deleteBug(i);
			score += 2;
			return true;
		}
	}

	// for enemy1

	for (int i = 0; i < enemy1Count; i++)
	{
		if ((x == enemy1X[i] || x == enemy1X[i] + 1) && (y == enemy1Y[i] || y == enemy1Y[i] + 1))
		{
			enemy1Health[i]--;

			if (enemy1Health[i] == 0)
			{
				deleteEnemy1(i);
				score += 5;
			}
			return true;
		}
	}

	// for Enemy 1 Bullet
	for (int i = 0; i < enemy1BulletCount; i++)
	{
		if ((x == enemy1BulletX[i] || x == enemy1BulletX[i] + 1) && y == enemy1BulletY[i])
		{
			deleteEnemy1Bullet(i);
			score++;
			return true;
		}
	}

	// for enemy2

	for (int i = 0; i < enemy2Count; i++)
	{
		if ((x == enemy2X[i] || x == enemy2X[i] + 1) && (y == enemy2Y[i] || y == enemy2Y[i] + 1 || y == enemy2Y[i] + 2))
		{
			enemy2Health[i]--;

			if (enemy2Health[i] == 0)
			{
				deleteEnemy2(i);
				score += 10;
			}
			return true;
		}
	}

	// for Enemy 2 Bullet
	for (int i = 0; i < enemy2BulletCount; i++)
	{
		if ((x == enemy2BulletX[i] || x == enemy2BulletX[i] + 1) && y == enemy2BulletY[i])
		{
			deleteEnemy2Bullet(i);
			score++;
			return true;
		}
	}

	// for enemy3

	for (int i = 0; i < enemy3Count; i++)
	{
		if ((x == enemy3X[i] || x == enemy3X[i] + 1) && (y == enemy3Y[i] || y == enemy3Y[i] + 1 || y == enemy3Y[i] + 2  || y == enemy3Y[i] + 3))
		{
			enemy3Health[i]--;

			if (enemy3Health[i] == 0)
			{
				deleteEnemy3(i);
				score += 100;
			}
			return true;
		}
	}

	// for Enemy 3 Bullet
	for (int i = 0; i < enemy3BulletCount; i++)
	{
		if ((x == enemy3BulletX[i] || x == enemy3BulletX[i] + 1) && y == enemy3BulletY[i])
		{
			deleteEnemy3Bullet(i);
			score++;
			return true;
		}

	}

	return false;
}

void deleteEnemies()
{
	//Delete all enemies and their bullets one by one

	for (int i = 0; i < playerBulletCount; i++)
		deletePlayerBullet(i);
	playerBulletCount = 0;
	for (int i = 0; i < bugCount; i++)
		deleteBug(i);
	bugCount = 0;
	for (int i = 0; i < enemy1Count; i++)
		deleteEnemy1(i);
	enemy1Count = 0;
	for (int i = 0; i < enemy1BulletCount; i++)
		deleteEnemy1Bullet(i);
	enemy2Count = 0;
	for(int i=0; i< enemy2Count; i++)
		deleteEnemy2(i);
	enemy2Count = 0;
	for(int i=0; i<enemy2BulletCount; i++)
		deleteEnemy2Bullet(i);
	enemy2BulletCount = 0;
	for(int i=0; i< enemy3Count; i++)
		deleteEnemy3(i);
	enemy3Count = 0;
	for(int i=0; i<enemy3BulletCount; i++)
		deleteEnemy3Bullet(i);
	enemy3BulletCount = 0;
	for(int i=0; i<healerCount; i++)
		deleteHealer(i);
	healerCount = 0;
}

//															       	<---- Player Stats ---=>

void drawHealth()
{

	char healthBar = 219;

	SetConsoleTextAttribute(hConsole, 15);
	gotoxy(43, 1);
	cout << "                             ";
	gotoxy(43, 1);
	cout << "Health: [";

	if (playerHarm == 0)						//Normal Print
		SetConsoleTextAttribute(hConsole, 31);
	else if (playerHarm > 0)					//Print When Player Harm
		SetConsoleTextAttribute(hConsole, 79);
	else if (playerHarm < 0)					//Print when player ear Healer
		SetConsoleTextAttribute(hConsole, 47);

	for (int i = 1; i <= playerHealth; i += 1)
		cout << " ";

	gotoxy(60, 1);
	if (playerHealth < 10)
		SetConsoleTextAttribute(hConsole, 15);
	cout << playerHealth * 100 / 20 << "%";

	SetConsoleTextAttribute(hConsole, 15);
	gotoxy(72, 1);
	cout << "]";
}
void printScore()
{
	gotoxy(30, 1);
	cout << "            ";
	gotoxy(30, 1);
	cout << "Score: ";
	if (scoreDamage > 0)
		SetConsoleTextAttribute(hConsole, 12);
	else
		SetConsoleTextAttribute(hConsole, 10);
	cout << score;
	SetConsoleTextAttribute(hConsole, 15);
}
void printLevel()
{
	gotoxy(3, 1);
	cout << "           ";
	gotoxy(3, 1);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Level: ";
	cout << level;
	SetConsoleTextAttribute(hConsole, 15);
}

//																<---- Printer Functionalities ---=>

void youWon()
{
printMaze();
	gotoxy(33, 13);

	SetConsoleTextAttribute(hConsole, 10);
	cout << "You Won";
	SetConsoleTextAttribute(hConsole, 15);
	gotoxy(28, 22);
	Sleep(500);
	cout << "Press enter twice...";
	Sleep(2000);
	cin.ignore();
	getch();
}

void youLose()
{
	printMaze();
	gotoxy(33, 13);

	SetConsoleTextAttribute(hConsole, 12);
	cout << "You Lose";
	SetConsoleTextAttribute(hConsole, 15);
	gotoxy(28, 22);
	Sleep(500);
	cout << "Press enter twice...";
	Sleep(2000);
	cin.ignore();
	getch();
}

void levelScreen()
{
	printMaze();
	gotoxy(33, 13);

	SetConsoleTextAttribute(hConsole, 10);
	cout << "Level ";
	cout << level;
	SetConsoleTextAttribute(hConsole, 15);

	Sleep(500);

	if(level==1)
	{
	gotoxy(18, 16);
	cout << "Score 100 to qualify for next Level";
	gotoxy(22, 18);
	cout << "Avoid Colliding with Enemies";
	}

	if(level==2)
	{
	gotoxy(18, 16);
	cout << "Score 250 to qualify for next Level";
	gotoxy(12, 18);
	cout << "Don't leave Rooks alive to avoid score deduction";
	}

	if(level==3)
	{
	gotoxy(18, 16);
	gotoxy(12, 18);
	cout << "Kill the Mastermind while maintaining a score of 250";
	}

	gotoxy(28, 22);
	Sleep(500);
	cout << "Press enter twice...";

	cin.ignore();
	getch();
	// while (!_kbhit())
	// {
	// 	Sleep(10); // Prevent high CPU usage
	// }
	printMaze();
}

void printHeader()
{
	system("cls");
	int a = 14, b = 12, c = 14;
	SetConsoleTextAttribute(hConsole, a);
	cout << "          ____                       ";
	SetConsoleTextAttribute(hConsole, b);
	cout << "___                            _";
	cout << endl;

	SetConsoleTextAttribute(hConsole, a);
	cout << "         / ___| _ __   __ _  ___ ___";
	SetConsoleTextAttribute(hConsole, b);
	cout << "|_ _|_ __ ___  _ __   __ _  ___| |_";
	cout << endl;

	SetConsoleTextAttribute(hConsole, a);
	cout << "         \\___ \\| '_ \\ / _` |/ __/ _ \\";
	SetConsoleTextAttribute(hConsole, b);
	cout << "| || '_ ` _ \\| '_ \\ / _` |/ __| __|";
	cout << endl;

	SetConsoleTextAttribute(hConsole, a);
	cout << "          ___) | |_) | (_| | (_|  __/";
	SetConsoleTextAttribute(hConsole, b);
	cout << "| || | | | | | |_) | (_| | (__| |_";
	cout << endl;

	SetConsoleTextAttribute(hConsole, a);
	cout << "         |____/| .__/ \\__,_|\\___\\___";
	SetConsoleTextAttribute(hConsole, b);
	cout << "|___|_| |_| |_| .__/ \\__,_|\\___|\\__|";
	cout << endl;

	SetConsoleTextAttribute(hConsole, a);
	cout << "               |_|                                ";
	SetConsoleTextAttribute(hConsole, b);
	cout << "|_| ";
	cout << endl
		 << endl;
	SetConsoleTextAttribute(hConsole, 15);
	Sleep(250);

	//   ____                       ___                            _
	//  / ___| _ __   __ _  ___ ___|_ _|_ __ ___  _ __   __ _  ___| |_
	//  \___ \| '_ \ / _` |/ __/ _ \| || '_ ` _ \| '_ \ / _` |/ __| __|
	//   ___) | |_) | (_| | (_|  __/| || | | | | | |_) | (_| | (__| |_
	//  |____/| .__/ \__,_|\___\___|___|_| |_| |_| .__/ \__,_|\___|\__|
	//        |_|                                |_|
}

int choice()
{
	printHeader();

	int top = 11;
	int arrowLocation = 1, input, selection = 0;

	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\tSelect Option\n\t\t\t\t=============";

	printArrow(top);

	SetConsoleTextAttribute(hConsole, 12);
	cout << "\t\t1. ";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Start Game";
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n\n\t\t2. ";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Instructions";
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n\n\t\t3. ";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "StoryLine";
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n\n\t\t4. ";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "About the Developer";
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n\n\t\t5. ";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Exit";

	while (true)
	{
		input = getch();

		if (input == '1' || input == '2' || input == '3' || input == '4' || input == '5')
		{
			input -= '0';
			break;
		}

		else if (input == 13)
		{
			input = arrowLocation;
			break;
		}

		else if (input == 224)
		{
			arrowLocation = moveArrow(input, arrowLocation, top, 5);
		}
	}

	return input;
}

void instructions()
{
	printHeader();

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\t\t\t\tInstructions\n\t\t\t\t============";

	SetConsoleTextAttribute(hConsole, 15);

	cout << "\n\n\n\t\t1) Use Arrow Keys to move your Player.";
	cout << "\n\n\t\t2) Press SpaceBar for firing.";
	cout << "\n\n\t\t3) Avoid Colliding with any Enemies.";
	cout << "\n\n\t\t4) Fire to kill Enemies and gain score. ";
	cout << "\n\n\t\t5) Aquire Required Score to enter next level.";
	cout << "\n\n\t\t6) Complete all Levels to win the Game";
	getch();
}

void storyLine()
{
	printHeader();

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\t\t\t\tStoryLine\n\t\t\t\t=========";

	SetConsoleTextAttribute(hConsole, 15);

	cout << "\n\n\n\t\tAliens from the Andromeda Galaxy has attacked";
	cout << "\n\n\t\ton our Milky Way. They have attacked us with";
	cout << "\n\n\t\tstrong Army equipped with latest technological";
	cout << "\n\n\t\tweapons. You have been given the SuperSpaceship,";
	cout << "\n\n\t\tinvented on Earth, to fight with Alien's Army ";
	cout << "\n\n\t\tand their mastemind Eiolu. GoodLuck!";
	getch();
}

void aboutDeveloper()
{
	printHeader();

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\t\t\t\tAbout Developer\n\t\t\t\t===============";

	SetConsoleTextAttribute(hConsole, 15);

	cout << "\n\n\n\t\tThis console game, inspirated by Space Impact,";
	cout << "\n\n\t\tis developed by M. Ahmad Amin. He is student of";
	cout << "\n\n\t\tBSCS at UET Lahore (2024-CS-72). With a knack of";
	cout << "\n\n\t\tcoding, he created this game as a university";
	cout << "\n\n\t\tproject for course of Programming Fundamentals";
	cout << "\n\n\n\t\tThank you for playing Space Impact.";
	cout << "\n\n\n\t\t\t\t\t\t\tRegard Ahmad.";
	getch();
}

void printMaze()
{

	system("cls");
	SetConsoleTextAttribute(hConsole, 7);
	gotoxy(0, 3);

	fstream mazeLoaderFile;

	mazeLoaderFile.open("Maze.txt", ios::in);
	
	string line;
	while (!mazeLoaderFile.eof())
	{
  		getline(mazeLoaderFile, line);
  		cout << line << endl;  
	}
	mazeLoaderFile.close();

	SetConsoleTextAttribute(hConsole, 15);
}



//																<---- Constant Functionalities ---=>

void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
	CHAR_INFO ci;
	COORD xy = {0, 0};
	SMALL_RECT rect = {x, y, x, y};
	COORD coordBufSize;
	coordBufSize.X = 1;
	coordBufSize.Y = 1;
	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void cursor(bool state)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	if (state == true)
	{
		GetConsoleCursorInfo(consoleHandle, &cursorInfo);
		cursorInfo.bVisible = true;
		SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	}
	else
	{
		GetConsoleCursorInfo(consoleHandle, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	}
}

int generateRandomNumber(int min, int max)
{
	// Create a random device and a Mersenne Twister random engine
	// std::random_device rd; // Random number generator
	// std::mt19937 gen(rd()); // Mersenne Twister engine seeded with random_device
	// std::uniform_int_distribution<> distrib(min, max); // Uniform distribution in range [min, max]

	// return distrib(gen);

	// Use a random device for seed generation
	static std::random_device rd;
	// Use Mersenne Twister engine for better random number generation
	static std::mt19937 gen(rd());
	// Create a uniform distribution within the specified range
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);

	// std::srand(static_cast<unsigned>(std::time(nullptr)));
	// return min + std::rand() % ((max - min) + 1);
}

int moveArrow(int input, int arrowLocation, int top, int options)
{
	input = getch();
	int bottom = top + (options * 2) - 2;

	if (input == 72) // up
	{
		if (arrowLocation > 1)
		{
			arrowLocation--;
			eraseArrow();
			printArrow(arrowy - 2);
		}
		else
		{
			arrowLocation = options;
			eraseArrow();
			printArrow(bottom);
		}
	}

	else if (input == 80)
	{
		if (arrowLocation < options)
		{
			arrowLocation++;
			eraseArrow();
			printArrow(arrowy + 2);
		}
		else
		{
			arrowLocation = 1;
			eraseArrow();
			printArrow(top);
		}
	}

	return arrowLocation;
}

void printArrow(int y)
{

	arrowy = y;
	SetConsoleTextAttribute(hConsole, 10);
	gotoxy(11, arrowy);
	cout << "-->\r";
	SetConsoleTextAttribute(hConsole, 15);
}

void eraseArrow()
{
	SetConsoleTextAttribute(hConsole, 10);
	gotoxy(11, arrowy);
	cout << "   ";
	SetConsoleTextAttribute(hConsole, 15);
}
