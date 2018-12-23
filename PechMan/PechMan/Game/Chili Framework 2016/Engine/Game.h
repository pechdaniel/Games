
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawBox(int a, int c, int r1, int g1, int b1);
	void MoveBox(int x, int y, int r, int g, int b);
	void Crosshair(int x, int y, int r, int g, int b);
	int BorderTestx(int x, int y, int vx);
	int BorderTesty(int x, int y, int vy);
	void DrawDude(int x, int y);
	void DrawGameOver(int x, int y);
	void DrawHeart(int x, int y, int r);
	void Draw0(int x, int y);
	void Draw1(int x, int y);
	void Draw2(int x, int y);
	void Draw3(int x, int y);
	void Draw4(int x, int y);
	void Draw5(int x, int y);
	void Draw6(int x, int y);
	void Draw7(int x, int y);
	void Draw8(int x, int y);
	void Draw9(int x, int y);
	void DrawS(int x, int y, int c);
	void DrawC(int x, int y);
	void DrawO(int x, int y);
	void DrawR(int x, int y);
	void DrawE(int x, int y, int c);
	void DrawDots(int x, int y, int c);
	void DrawLine(int y, int c);
	void DrawL(int x, int y, int c);
	void DrawI(int x, int y, int c);
	void DrawV(int x, int y, int c);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int d0x = 100, v0x = 1;
	int d0y = 29, v0y = 1;
	int d1x = 250, v1x = -1;
	int d1y = 670, v1y = -1;
	int d2x = 400, v2x = 1;
	int d2y = 29, v2y = -1;
	int d3x = 550, v3x = -1;
	int d3y = 670, v3y = 1;
	int d4x = 700, v4x = 1;
	int d4y = 29, v4y = 1;
	int d5x = 850, v5x = -1;
	int d5y = 670, v5y = -1;
	int k = 100;
	int r= 255, g = 255, b = 255;
	int a = 500, c = 350;
	int p=3;
	int r1 = 0, g1 = 255, b1 = 0;
	int heart=5;
	int col0=255;
	int col1=255;
	int col2=255;
	int col3=255;
	int col4=255;
	int score;
	int aux;
	double vx = 0,vy = 0, y = 250, x = 500;
	int z = 11;
	int j=0;
	int cool=-1;
	/********************************/
};