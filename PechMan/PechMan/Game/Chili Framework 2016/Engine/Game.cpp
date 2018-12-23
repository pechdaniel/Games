
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		j = 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_END))
	{
		j = 0;
	}
	if (j == 1)
	{
		MoveBox(x, y, r, g, b);
		Crosshair(a, c, r1, g1, b1);
	}
	else
		if (j == 0)
		{
			Crosshair(x, y, r, g, b);
			DrawBox(a, c, r1, g1, b1);
		}
	if (heart==0)
	{
		DrawDots(516, 360, 255);
		DrawE(510, 360, 255);
		DrawR(502, 360);
		DrawO(494, 360);
		DrawC(486, 360);
		DrawS(478, 360, 255);
		aux = k;
		DrawGameOver(450, 286);
		r = g = b = r1 = g1 = b1 = 0;
	}
	else
	{
		DrawDots(460, 10, 150);
		DrawS(454, 10, 150);
		DrawE(446, 10, 150);
		DrawV(438, 10, 150);
		DrawI(431, 10, 150);
		DrawL(424, 10, 150);
		DrawLine(19, 70);
		if (wnd.kbd.KeyIsPressed(VK_TAB))
		{
			vx = 0;
			vy = 0;
		}
		if ((x >= a - 15 && x <= a + 15) && (y >= c - 15 && y <= c + 15))
		{
			r = 255;
			g = 0;
			b = 0;
		}
		else
		{
			if (wnd.kbd.KeyIsPressed(VK_SPACE))
			{
				r = 0;
				g = 255;
				b = 255;
			}
			else
				if (wnd.kbd.KeyIsPressed(VK_SHIFT))
				{
					g = 0;
					b = 0;
					r = 254;
				}
				else
				{
					r = 255;
					g = 255;
					b = 255;
				}
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			x = x - 1 - vx;
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			x = x + 1 + vx;
		}
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			y = y - 1 - vy;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			y = y + 1 + vy;
		}
		DrawHeart(470, 10, col0);
		DrawHeart(485, 10, col1);
		DrawHeart(500, 10, col2);
		DrawHeart(515, 10, col3);
		DrawHeart(530, 10, col4);
		if (r == 254 && g == 0 && b == 0)
		{
			vx = 10;
			vy = 10;
		}
		if (r == 0 && g == 255 && b == 255)
		{
			vx = 0;
			vy = 0;
		}
		if (k % 20 == 0 && k != 0)
		{
			r = 0;
			g = 255;
			b = 255;
			vx = 0;
			vy = 0;
		}
		if (r == 0 && g == 255 && b == 255)
		{
			if (((x + 6 >= gfx.ScreenWidth) || (x - 6 <= 0) || (y + 6 >= gfx.ScreenHeight) || (y - 6 <= 19) ||
				((x + 5 >= d0x) && (x - 5 <= d0x + 20) && (y + 5 >= d0y) && (y - 5 <= d0y + 20) && k >= 10)))
			{
				if (heart == 4)
				{
					heart += 1;
					col4 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d0x = 100;
					d0y = 29;
				}
				if (heart == 3)
				{
					heart += 1;
					col3 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d0x = 100;
					d0y = 29;
				}
				if (heart == 2)
				{
					heart += 1;
					col2 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d0x = 100;
					d0y = 29;
				}
				if (heart == 1)
				{
					heart += 1;
					col1 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d0x = 100;
					d0y = 29;
				}
				if (heart == 0)
				{
					heart += 1;
					col0 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d0x = 100;
					d0y = 29;
				}
			}
			if (((x + 6 >= gfx.ScreenWidth) || (x - 6 <= 0) || (y + 6 >= gfx.ScreenHeight) || (y - 6 <= 19) ||
				((x + 5 >= d1x) && (x - 5 <= d1x + 20) && (y + 5 >= d1y) && (y - 5 <= d1y + 20) && k >= 20)))
			{
				if (heart == 4)
				{
					heart += 1;
					col4 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d1x = 250;
					d1y = 670;
				}
				if (heart == 3)
				{
					heart += 1;
					col3 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d1x = 250;
					d1y = 670;
				}
				if (heart == 2)
				{
					heart += 1;
					col2 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d1x = 250;
					d1y = 670;
				}
				if (heart == 1)
				{
					heart += 1;
					col1 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d1x = 250;
					d1y = 670;
				}
				if (heart == 0)
				{
					heart += 1;
					col0 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d1x = 250;
					d1y = 670;
				}
			}
			if (((x + 6 >= gfx.ScreenWidth) || (x - 6 <= 0) || (y + 6 >= gfx.ScreenHeight) || (y - 6 <= 19) ||
				((x + 5 >= d2x) && (x - 5 <= d2x + 20) && (y + 5 >= d2y) && (y - 5 <= d2y + 20) && k >= 30)))
			{
				if (heart == 4)
				{
					heart += 1;
					col4 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d2x = 400;
					d2y = 29;
				}
				if (heart == 3)
				{
					heart += 1;
					col3 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d2x = 400;
					d2y = 29;
				}
				if (heart == 2)
				{
					heart += 1;
					col2 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d2x = 400;
					d2y = 29;
				}
				if (heart == 1)
				{
					heart += 1;
					col1 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d2x = 400;
					d2y = 29;
				}
				if (heart == 0)
				{
					heart += 1;
					col0 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d2x = 400;
					d2y = 29;
				}
			}
			if (((x + 6 >= gfx.ScreenWidth) || (x - 6 <= 0) || (y + 6 >= gfx.ScreenHeight) || (y - 6 <= 19) ||
				((x + 5 >= d3x) && (x - 5 <= d3x + 20) && (y + 5 >= d3y) && (y - 5 <= d3y + 20) && k >= 40)))
			{
				if (heart == 4)
				{
					heart += 1;
					col4 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d3x = 550;
					d3y = 670;
				}
				if (heart == 3)
				{
					heart += 1;
					col3 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d3x = 550;
					d3y = 670;
				}
				if (heart == 2)
				{
					heart += 1;
					col2 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d3x = 550;
					d3y = 670;
				}
				if (heart == 1)
				{
					heart += 1;
					col1 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d3x = 550;
					d3y = 670;
				}
				if (heart == 0)
				{
					heart += 1;
					col0 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d3x = 550;
					d3y = 670;
				}
			}
			if (((x + 6 >= gfx.ScreenWidth) || (x - 6 <= 0) || (y + 6 >= gfx.ScreenHeight) || (y - 6 <= 19) ||
				((x + 5 >= d4x) && (x - 5 <= d4x + 20) && (y + 5 >= d4y) && (y - 5 <= d4y + 20) && k >= 50)))
			{
				if (heart == 4)
				{
					heart += 1;
					col4 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d4x = 700;
					d4y = 29;
				}
				if (heart == 3)
				{
					heart += 1;
					col3 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d4x = 700;
					d4y = 29;
				}
				if (heart == 2)
				{
					heart += 1;
					col2 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d4x = 700;
					d4y = 29;
				}
				if (heart == 1)
				{
					heart += 1;
					col1 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d4x = 700;
					d4y = 29;
				}
				if (heart == 0)
				{
					heart += 1;
					col0 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d4x = 700;
					d4y = 29;
				}
			}
			if (((x + 6 >= gfx.ScreenWidth) || (x - 6 <= 0) || (y + 6 >= gfx.ScreenHeight) || (y - 6 <= 19) ||
				((x + 5 >= d5x) && (x - 5 <= d5x + 20) && (y + 5 >= d5y) && (y - 5 <= d5y + 20) && k >= 60)))
			{
				if (heart == 4)
				{
					heart += 1;
					col4 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d5x = 850;
					d5y = 670;
				}
				if (heart == 3)
				{
					heart += 1;
					col3 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d5x = 850;
					d5y = 670;
				}
				if (heart == 2)
				{
					heart += 1;
					col2 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d5x = 850;
					d5y = 670;
				}
				if (heart == 1)
				{
					heart += 1;
					col1 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d5x = 850;
					d5y = 670;
				}
				if (heart == 0)
				{
					heart += 1;
					col0 = 255;
					k += 1;
					r = 255;
					g = 255;
					b = 255;
					d5x = 850;
					d5y = 670;
				}
			}
		}
		else
		{
			if (((x + 6 >= gfx.ScreenWidth) || (x - 6 <= 0) || (y + 6 >= gfx.ScreenHeight) || (y - 6 <= 19) ||
				((x + 5 >= d0x) && (x - 5 <= d0x + 20) && (y + 5 >= d0y) && (y - 5 <= d0y + 20) && k >= 10) ||
				((x + 5 >= d1x) && (x - 5 <= d1x + 20) && (y + 5 >= d1y) && (y - 5 <= d1y + 20) && k >= 20) ||
				((x + 5 >= d2x) && (x - 5 <= d2x + 20) && (y + 5 >= d2y) && (y - 5 <= d2y + 20) && k >= 30) ||
				((x + 5 >= d3x) && (x - 5 <= d3x + 20) && (y + 5 >= d3y) && (y - 5 <= d3y + 20) && k >= 40) ||
				((x + 5 >= d4x) && (x - 5 <= d4x + 20) && (y + 5 >= d4y) && (y - 5 <= d4y + 20) && k >= 50) ||
				((x + 5 >= d5x) && (x - 5 <= d5x + 20) && (y + 5 >= d5y) && (y - 5 <= d5y + 20) && k >= 60)) && 
				(cool!=k))
			{
				heart -= 1;
				x = 500;
				y = 350;
				r = 255;
				g = 0;
				b = 0;
				vx = 0;
				vy = 0;
				cool = k;
			}
		}
		if (cool == k)
		{
			r = 253;
			g = 0;
			b = 0;
		}
		if (heart == 4)
		{
			col4 = 0;
		}
		if (heart == 3)
		{
			col3 = 0;
		}
		if (heart == 2)
		{
			col2 = 0;
		}
		if (heart == 1)
		{
			col1 = 0;
		}
		if (heart == 0)
		{
			col0 = 0;
		}
		if (k >= 10)
		{
			DrawDude(d0x, d0y);
			if (v0x != BorderTestx(d0x, d0y, v0x))
			{
				v0x = -v0x;
			}
			if (v0y != BorderTesty(d0x, d0y, v0y))
			{
				v0y = -v0y;
			}
			d0x += v0x;
			d0y += v0y;
		}
		if (k >= 20)
		{
			DrawDude(d1x, d1y);
			if (v1x != BorderTestx(d1x, d1y, v1x))
			{
				v1x = -v1x;
			}
			if (v1y != BorderTesty(d1x, d1y, v1y))
			{
				v1y = -v1y;
			}
			d1x = d1x + v1x;
			d1y = d1y + v1y;
		}
		if (k >= 30)
		{
			DrawDude(d2x, d2y);
			if (v2x != BorderTestx(d2x, d2y, v2x))
			{
				v2x = -v2x;
			}
			if (v2y != BorderTesty(d2x, d2y, v2y))
			{
				v2y = -v2y;
			}
			d2x = d2x + v2x;
			d2y = d2y + v2y;
		}
		if (k >= 40)
		{
			DrawDude(d3x, d3y);
			if (v3x != BorderTestx(d3x, d3y, v3x))
			{
				v3x = -v3x;
			}
			if (v3y != BorderTesty(d3x, d3y, v3y))
			{
				v3y = -v3y;
			}
			d3x = d3x + v3x;
			d3y = d3y + v3y;
		}
		if (k >= 50)
		{
			DrawDude(d4x, d4y);
			if (v4x != BorderTestx(d4x, d4y, v4x))
			{
				v4x = -v4x;
			}
			if (v4y != BorderTesty(d4x, d4y, v4y))
			{
				v4y = -v4y;
			}
			d4x = d4x + v4x;
			d4y = d4y + v4y;
		}
		if (k >= 60)
		{
			DrawDude(d5x, d5y);
			if (v5x != BorderTestx(d5x, d5y, v5x))
			{
				v5x = -v5x;
			}
			if (v5y != BorderTesty(d5x, d5y, v5y))
			{
				v5y = -v5y;
			}
			d5x = d5x + v5x;
			d5y = d5y + v5y;
		}

		if ((x + 5 >= a - 4) && (x - 5 <= a + 4) && (y + 5 >= c - 4) && (y - 5 <= c + 4))
		{
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> aDist(40, 960);
			std::uniform_int_distribution<int> cDist(69, 660);
			a = aDist(rng);
			c = cDist(rng);
			vx += 1;
			vy += 1;
			k += 1;
		}
		if ((x >= a - 15 && x <= a + 15) && (y >= c - 15 && y <= c + 15))
		{
			r1 = 255;
			g1 = 0;
			b1 = 0;
		}
		else
		{
			r1 = 0;
			g1 = 255;
			b1 = 0;
		}
		if (wnd.kbd.KeyIsPressed(VK_ADD))
		{
			vx += 0.3;
			vy += 0.3;
		}
		if (x + 5 >= gfx.ScreenWidth)
		{
			x = gfx.ScreenWidth - 6;
			vx = 0;
			vy = 0;
		}
		if (x - 5 <= 0)
		{
			x = 5;
			vx = 0;
			vy = 0;
		}
		if (y + 5 >= gfx.ScreenHeight)
		{
			y = gfx.ScreenHeight - 6;
			vx = 0;
			vy = 0;
		}
		if (y - 5 < 20)
		{
			y = 25;
			vx = 0;
			vy = 0;
		}
	}

}

void Game::ComposeFrame()
{
	DrawBox(a,c,r1,g1,b1);
	if (heart == 0)
	{
		score = 513;
		if (aux == 0)
		{
			Draw0(score, 371);
		}
		else
		while (aux>0)
		{
			if (aux % 10 == 0)
			{
				Draw0(score, 371);
			}
			if (aux % 10 == 1)
			{
				Draw1(score, 371);
			}
			if (aux % 10 == 2)
			{
				Draw2(score, 371);
			}
			if (aux % 10 == 3)
			{
				Draw3(score, 371);
			}
			if (aux % 10 == 4)
			{
				Draw4(score, 371);
			}
			if (aux % 10 == 5)
			{
				Draw5(score, 371);
			}
			if (aux % 10 == 6)
			{
				Draw6(score, 371);
			}
			if (aux % 10 == 7)
			{
				Draw7(score, 371);
			}
			if (aux % 10 == 8)
			{
				Draw8(score, 371);
			}
			if (aux % 10 == 9)
			{
				Draw9(score, 371);
			}
			aux /= 10;
			score -= 8;
		}
	}
}

void Game::DrawBox(int a, int c, int r1, int g1, int b1)
{
	gfx.PutPixel(-5 + a, -5 + c, r1, g1, b1);
	gfx.PutPixel(-4 + a, -4 + c, r1, g1, b1);
	gfx.PutPixel(-3 + a, -3 + c, r1, g1, b1);
	gfx.PutPixel(3 + a, 3 + c, r1, g1, b1);
	gfx.PutPixel(4 + a, 4 + c, r1, g1, b1);
	gfx.PutPixel(5 + a, 5 + c, r1, g1, b1);
	gfx.PutPixel(5 + a, -5 + c, r1, g1, b1);
	gfx.PutPixel(4 + a, -4 + c, r1, g1, b1);
	gfx.PutPixel(3 + a, -3 + c, r1, g1, b1);
	gfx.PutPixel(-5 + a, 5 + c, r1, g1, b1);
	gfx.PutPixel(-4 + a, 4 + c, r1, g1, b1);
	gfx.PutPixel(-3 + a, 3 + c, r1, g1, b1);
	gfx.PutPixel(-3 + a, -5 + c, r1, g1, b1);
	gfx.PutPixel(-4 + a, -4 + c, r1, g1, b1);
	gfx.PutPixel(-5 + a, -3 + c, r1, g1, b1);
	gfx.PutPixel(3 + a, 5 + c, r1, g1, b1);
	gfx.PutPixel(4 + a, 4 + c, r1, g1, b1);
	gfx.PutPixel(5 + a, 3 + c, r1, g1, b1);
	gfx.PutPixel(3 + a, -5 + c, r1, g1, b1);
	gfx.PutPixel(4 + a, -4 + c, r1, g1, b1);
	gfx.PutPixel(5 + a, -3 + c, r1, g1, b1);
	gfx.PutPixel(-3 + a, 5 + c, r1, g1, b1);
	gfx.PutPixel(-4 + a, 4 + c, r1, g1, b1);
	gfx.PutPixel(-5 + a, 3 + c, r1, g1, b1);
}

void Game::MoveBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(-5 + x, -5 + y, r, g, b);
	gfx.PutPixel(-4 + x, -4 + y, r, g, b);
	gfx.PutPixel(-3 + x, -3 + y, r, g, b);
	gfx.PutPixel(3 + x, 3 + y, r, g, b);
	gfx.PutPixel(4 + x, 4 + y, r, g, b);
	gfx.PutPixel(5 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, -5 + y, r, g, b);
	gfx.PutPixel(4 + x, -4 + y, r, g, b);
	gfx.PutPixel(3 + x, -3 + y, r, g, b);
	gfx.PutPixel(-5 + x, 5 + y, r, g, b);
	gfx.PutPixel(-4 + x, 4 + y, r, g, b);
	gfx.PutPixel(-3 + x, 3 + y, r, g, b);
	gfx.PutPixel(-3 + x, -5 + y, r, g, b);
	gfx.PutPixel(-4 + x, -4 + y, r, g, b);
	gfx.PutPixel(-5 + x, -3 + y, r, g, b);
	gfx.PutPixel(3 + x, 5 + y, r, g, b);
	gfx.PutPixel(4 + x, 4 + y, r, g, b);
	gfx.PutPixel(5 + x, 3 + y, r, g, b);
	gfx.PutPixel(3 + x, -5 + y, r, g, b);
	gfx.PutPixel(4 + x, -4 + y, r, g, b);
	gfx.PutPixel(5 + x, -3 + y, r, g, b);
	gfx.PutPixel(-3 + x, 5 + y, r, g, b);
	gfx.PutPixel(-4 + x, 4 + y, r, g, b);
	gfx.PutPixel(-5 + x, 3 + y, r, g, b);
}

void Game::Crosshair(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(-5 + x, y, r, g, b);
	gfx.PutPixel(-4 + x, y, r, g, b);
	gfx.PutPixel(-3 + x, y, r, g, b);
	gfx.PutPixel(3 + x, y, r, g, b);
	gfx.PutPixel(4 + x, y, r, g, b);
	gfx.PutPixel(5 + x, y, r, g, b);
	gfx.PutPixel(x, -5 + y, r, g, b);
	gfx.PutPixel(x, -4 + y, r, g, b);
	gfx.PutPixel(x, -3 + y, r, g, b);
	gfx.PutPixel(x, 3 + y, r, g, b);
	gfx.PutPixel(x, 4 + y, r, g, b);
	gfx.PutPixel(x, 5 + y, r, g, b);
}

int Game::BorderTestx(int x, int y, int vx)
{
	if (x + 21 >= gfx.ScreenWidth)
	{
		return -vx;
	}
	else {
		if (x <= 1)
		{
			return -vx;
		}
		else return vx;
	}
}

int Game::BorderTesty(int x, int y, int vy)
{
	if (y + 21 >= gfx.ScreenHeight)
	{
		return -vy;
	}
	else {
		if (y <= 19)
		{
			return -vy;
		}
		else return vy;
	}
}

void Game::DrawDude(int x, int y)
{
	gfx.PutPixel(7 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 3 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 3 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 4 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 4 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(14 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(15 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 10 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 10 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 11 + y, 20, 14, 18);
	gfx.PutPixel(8 + x, 11 + y, 18, 11, 14);
	gfx.PutPixel(9 + x, 11 + y, 18, 12, 14);
	gfx.PutPixel(10 + x, 11 + y, 18, 12, 14);
	gfx.PutPixel(11 + x, 11 + y, 21, 13, 16);
	gfx.PutPixel(12 + x, 11 + y, 24, 11, 15);
	gfx.PutPixel(13 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 12 + y, 23, 9, 23);
	gfx.PutPixel(7 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(10 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(11 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(12 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(13 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(10 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(11 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(12 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(13 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 15 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(9 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(14 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 15 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 16 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(9 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(14 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 16 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 19 + y, 0, 0, 0);

}

void Game::DrawGameOver(int x, int y)
{
	gfx.PutPixel(49 + x, 0 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 0 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 0 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 1 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 1 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 1 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 1 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 5 + y, 0, 118, 11);
	gfx.PutPixel(35 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 5 + y, 0, 142, 13);
	gfx.PutPixel(52 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 7 + y, 0, 142, 13);
	gfx.PutPixel(79 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 9 + y, 0, 118, 11);
	gfx.PutPixel(34 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 12 + y, 0, 142, 13);
	gfx.PutPixel(36 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 13 + y, 0, 142, 13);
	gfx.PutPixel(57 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 15 + y, 0, 25, 2);
	gfx.PutPixel(25 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 22 + y, 0, 25, 2);
	gfx.PutPixel(62 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 23 + y, 0, 3, 0);
	gfx.PutPixel(18 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 23 + y, 0, 25, 2);
	gfx.PutPixel(63 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 29 + y, 0, 25, 2);
	gfx.PutPixel(64 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 30 + y, 0, 25, 2);
	gfx.PutPixel(81 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 31 + y, 0, 70, 6);
	gfx.PutPixel(11 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 32 + y, 0, 118, 11);
	gfx.PutPixel(62 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 32 + y, 0, 25, 2);
	gfx.PutPixel(79 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 33 + y, 0, 25, 2);
	gfx.PutPixel(8 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 37 + y, 0, 70, 6);
	gfx.PutPixel(38 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 38 + y, 0, 70, 6);
	gfx.PutPixel(39 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 40 + y, 0, 70, 6);
	gfx.PutPixel(12 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 42 + y, 0, 25, 2);
	gfx.PutPixel(4 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 42 + y, 0, 25, 2);
	gfx.PutPixel(13 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 44 + y, 0, 3, 0);
	gfx.PutPixel(78 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 45 + y, 0, 118, 11);
	gfx.PutPixel(38 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 46 + y, 0, 118, 11);
	gfx.PutPixel(78 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 49 + y, 0, 142, 13);
	gfx.PutPixel(1 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 50 + y, 0, 142, 13);
	gfx.PutPixel(41 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 55 + y, 0, 118, 11);
	gfx.PutPixel(49 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 55 + y, 0, 3, 0);
	gfx.PutPixel(67 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 56 + y, 0, 142, 13);
	gfx.PutPixel(19 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 56 + y, 0, 142, 13);
	gfx.PutPixel(47 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 56 + y, 0, 25, 2);
	gfx.PutPixel(51 + x, 56 + y, 0, 25, 2);
	gfx.PutPixel(52 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 56 + y, 0, 25, 2);
	gfx.PutPixel(80 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 57 + y, 0, 25, 2);
	gfx.PutPixel(10 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 57 + y, 0, 118, 11);
	gfx.PutPixel(19 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 57 + y, 0, 25, 2);
	gfx.PutPixel(66 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 58 + y, 0, 118, 11);
	gfx.PutPixel(15 + x, 58 + y, 0, 25, 2);
	gfx.PutPixel(16 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 58 + y, 0, 25, 2);
	gfx.PutPixel(66 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 59 + y, 0, 25, 2);
	gfx.PutPixel(15 + x, 59 + y, 0, 70, 6);
	gfx.PutPixel(16 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 59 + y, 0, 25, 2);
	gfx.PutPixel(25 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 59 + y, 0, 25, 2);
	gfx.PutPixel(66 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 62 + y, 0, 142, 13);
	gfx.PutPixel(1 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 62 + y, 0, 70, 6);
	gfx.PutPixel(16 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 62 + y, 0, 3, 0);
	gfx.PutPixel(54 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 62 + y, 0, 70, 6);
	gfx.PutPixel(1 + x, 63 + y, 0, 142, 13);
	gfx.PutPixel(2 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 63 + y, 0, 25, 2);
	gfx.PutPixel(16 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 63 + y, 0, 146, 14);

}

void Game::DrawHeart(int x, int y, int r)
{
	gfx.PutPixel(x, y - 3, r, 0, 0);
	gfx.PutPixel(x - 1, y - 4, r, 0, 0);
	gfx.PutPixel(x - 2, y - 5, r, 0, 0);
	gfx.PutPixel(x - 3, y - 5, r, 0, 0);
	gfx.PutPixel(x - 4, y - 5, r, 0, 0);
	gfx.PutPixel(x - 5, y - 4, r, 0, 0);
	gfx.PutPixel(x - 5, y - 3, r, 0, 0);
	gfx.PutPixel(x - 5, y - 2, r, 0, 0);
	gfx.PutPixel(x - 4, y - 1, r, 0, 0);
	gfx.PutPixel(x - 3, y, r, 0, 0);
	gfx.PutPixel(x - 2, y + 1, r, 0, 0);
	gfx.PutPixel(x - 1, y + 2, r, 0, 0);
	gfx.PutPixel(x, y + 3, r, 0, 0);
	gfx.PutPixel(x + 2, y - 4, r, 0, 0);
	gfx.PutPixel(x + 3, y - 4, r, 0, 0);
	gfx.PutPixel(x + 4, y - 4, r, 0, 0);
	gfx.PutPixel(x + 1, y - 3, r, 0, 0);
	gfx.PutPixel(x + 2, y - 3, r, 0, 0);
	gfx.PutPixel(x + 3, y - 3, r, 0, 0);
	gfx.PutPixel(x + 4, y - 3, r, 0, 0);
	gfx.PutPixel(x + 5, y - 3, r, 0, 0);
	gfx.PutPixel(x - 1, y - 2, r, 0, 0);
	gfx.PutPixel(x, y - 2, r, 0, 0);
	gfx.PutPixel(x + 1, y - 2, r, 0, 0);
	gfx.PutPixel(x + 2, y - 2, r, 0, 0);
	gfx.PutPixel(x + 3, y - 2, r, 0, 0);
	gfx.PutPixel(x + 4, y - 2, r, 0, 0);
	gfx.PutPixel(x + 5, y - 2, r, 0, 0);
	gfx.PutPixel(x - 2, y - 1, r, 0, 0); 
	gfx.PutPixel(x - 1, y - 1, r, 0, 0);
	gfx.PutPixel(x, y - 1, r, 0, 0);
	gfx.PutPixel(x + 1, y - 1, r, 0, 0);
	gfx.PutPixel(x + 2, y - 1, r, 0, 0);
	gfx.PutPixel(x + 3, y - 1, r, 0, 0);
	gfx.PutPixel(x + 4, y - 1, r, 0, 0);
	gfx.PutPixel(x - 2, y, r, 0, 0);
	gfx.PutPixel(x - 1, y , r, 0, 0);
	gfx.PutPixel(x, y , r, 0, 0);
	gfx.PutPixel(x + 1, y, r, 0, 0);
	gfx.PutPixel(x + 2, y, r, 0, 0);
	gfx.PutPixel(x + 3, y, r, 0, 0);
	gfx.PutPixel(x - 1, y + 1, r, 0, 0);
	gfx.PutPixel(x, y+1, r, 0, 0);
	gfx.PutPixel(x + 1, y+1, r, 0, 0);
	gfx.PutPixel(x + 2, y+1, r, 0, 0);
	gfx.PutPixel(x , y + 2, r, 0, 0);
	gfx.PutPixel(x - 2, y - 4, r, 0, 0);
	gfx.PutPixel(x - 3, y - 4, r, 0, 0);
	gfx.PutPixel(x - 4, y - 4, r, 0, 0);
	gfx.PutPixel(x - 1, y - 3, r, 0, 0);
	gfx.PutPixel(x - 2, y - 3, r, 0, 0);
	gfx.PutPixel(x - 3, y - 3, r, 0, 0);
	gfx.PutPixel(x - 4, y - 3, r, 0, 0);
	gfx.PutPixel(x - 5, y - 3, r, 0, 0);
	gfx.PutPixel(x, y - 2, r, 0, 0);
	gfx.PutPixel(x - 1, y - 2, r, 0, 0);
	gfx.PutPixel(x - 2, y - 2, r, 0, 0);
	gfx.PutPixel(x - 3, y - 2, r, 0, 0);
	gfx.PutPixel(x - 4, y - 2, r, 0, 0);
	gfx.PutPixel(x - 5, y - 2, r, 0, 0);
	gfx.PutPixel(x - 3, y - 1, r, 0, 0);
	gfx.PutPixel(x + 1, y - 4, r, 0, 0);
	gfx.PutPixel(x + 2, y - 5, r, 0, 0);
	gfx.PutPixel(x + 3, y - 5, r, 0, 0);
	gfx.PutPixel(x + 4, y - 5, r, 0, 0);
	gfx.PutPixel(x + 5, y - 4, r, 0, 0);
	gfx.PutPixel(x + 5, y - 3, r, 0, 0);
	gfx.PutPixel(x + 5, y - 2, r, 0, 0);
	gfx.PutPixel(x + 4, y - 1, r, 0, 0);
	gfx.PutPixel(x + 3, y, r, 0, 0);
	gfx.PutPixel(x + 2, y + 1, r, 0, 0);
	gfx.PutPixel(x + 1, y + 2, r, 0, 0);
}

void Game::Draw0(int x, int y)
{
	gfx.PutPixel(x - 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x + 3, y, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 4, 255, 255, 255);
}

void Game::Draw1(int x, int y)
{
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x -1, y - 3, 255, 255, 255);
	gfx.PutPixel(x , y - 3, 255, 255, 255);
	gfx.PutPixel(x -2, y - 2, 255, 255, 255);
	gfx.PutPixel(x , y - 2, 255, 255, 255);
	gfx.PutPixel(x , y - 1, 255, 255, 255);
	gfx.PutPixel(x , y, 255, 255, 255);
	gfx.PutPixel(x , y + 1, 255, 255, 255);
	gfx.PutPixel(x , y + 2, 255, 255, 255);
	gfx.PutPixel(x , y + 3, 255, 255, 255);
	gfx.PutPixel(x , y + 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 4, 255, 255, 255);
}

void Game::Draw2(int x, int y)
{
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 2, y - 3, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 2, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 1, 255, 255, 255);
	gfx.PutPixel(x, y + 2, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 3, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 4, 255, 255, 255);
}

void Game::Draw3(int x, int y)
{
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x+1, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
}

void Game::Draw4(int x, int y)
{
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 3, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 2, 255, 255, 255);
	gfx.PutPixel(x - 2, y - 1, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x - 2, y, 255, 255, 255);
	gfx.PutPixel(x - 1, y, 255, 255, 255);
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x + 3, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
}

void Game::Draw5(int x, int y)
{
	gfx.PutPixel(x - 3, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x - 2, y, 255, 255, 255);
	gfx.PutPixel(x - 1, y, 255, 255, 255);
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 4, 255, 255, 255);
}

void Game::Draw6(int x, int y)
{
	gfx.PutPixel(x - 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x - 2, y, 255, 255, 255);
	gfx.PutPixel(x - 1, y, 255, 255, 255);
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 4, 255, 255, 255);
}

void Game::Draw7(int x, int y)
{
	gfx.PutPixel(x - 3, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 3, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 1, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x, y + 1, 255, 255, 255);
	gfx.PutPixel(x, y + 2, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 3, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
}

void Game::Draw8(int x, int y)
{
	gfx.PutPixel(x - 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x - 2, y, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x - 1, y, 255, 255, 255);
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 4, 255, 255, 255);
}

void Game::Draw9(int x, int y)
{
	gfx.PutPixel(x - 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x - 2, y, 255, 255, 255);
	gfx.PutPixel(x - 1, y, 255, 255, 255);
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x + 3, y, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 4, 255, 255, 255);
}

void Game::DrawS(int x, int y,int c)
{
	gfx.PutPixel(x - 2, y - 4, c, c, c);
	gfx.PutPixel(x - 1, y - 4, c, c, c);
	gfx.PutPixel(x, y - 4, c, c, c);
	gfx.PutPixel(x + 1, y - 4, c, c, c);
	gfx.PutPixel(x + 2, y - 4, c, c, c);
	gfx.PutPixel(x - 3, y - 3, c, c, c);
	gfx.PutPixel(x - 3, y - 2, c, c, c);
	gfx.PutPixel(x - 3, y - 1, c, c, c);
	gfx.PutPixel(x - 2, y - 1, c, c, c);
	gfx.PutPixel(x - 1, y, c, c, c);
	gfx.PutPixel(x, y, c, c, c);
	gfx.PutPixel(x + 1, y + 1, c, c, c);
	gfx.PutPixel(x + 3, y + 2, c, c, c);
	gfx.PutPixel(x + 2, y + 2, c, c, c);
	gfx.PutPixel(x + 3, y + 3, c, c, c);
	gfx.PutPixel(x + 2, y + 4, c, c, c);
	gfx.PutPixel(x + 1, y + 4, c, c, c);
	gfx.PutPixel(x, y + 4, c, c, c);
	gfx.PutPixel(x - 1, y + 4, c, c, c);
	gfx.PutPixel(x - 2, y + 4, c, c, c);
	gfx.PutPixel(x - 3, y + 4, c, c, c);
}

void Game::DrawC(int x, int y)
{
	gfx.PutPixel(x - 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 4, 255, 255, 255);
}

void Game::DrawO(int x, int y)
{
	gfx.PutPixel(x - 2, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x + 3, y, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x - 2, y + 3, 255, 255, 255);
	gfx.PutPixel(x - 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 3, 255, 255, 255);
}

void Game::DrawR(int x, int y)
{
	gfx.PutPixel(x - 3, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 1, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 2, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 3, 255, 255, 255);
	gfx.PutPixel(x - 3, y + 4, 255, 255, 255);
	gfx.PutPixel(x - 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x - 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 1, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 2, y - 4, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 3, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y - 1, 255, 255, 255);
	gfx.PutPixel(x + 2, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x - 1, y, 255, 255, 255);
	gfx.PutPixel(x - 2, y, 255, 255, 255);
	gfx.PutPixel(x - 1, y, 255, 255, 255);
	gfx.PutPixel(x, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 4, 255, 255, 255);
}

void Game::DrawE(int x, int y, int c)
{
	gfx.PutPixel(x - 3, y - 4, c, c, c);
	gfx.PutPixel(x - 3, y - 3, c, c, c);
	gfx.PutPixel(x - 3, y - 2, c, c, c);
	gfx.PutPixel(x - 3, y - 1, c, c, c);
	gfx.PutPixel(x - 3, y, c, c, c);
	gfx.PutPixel(x - 3, y + 1, c, c, c);
	gfx.PutPixel(x - 3, y + 2, c, c, c);
	gfx.PutPixel(x - 3, y + 3, c, c, c);
	gfx.PutPixel(x - 3, y + 4, c, c, c);
	gfx.PutPixel(x - 2, y - 4, c, c, c);
	gfx.PutPixel(x - 1, y - 4, c, c, c);
	gfx.PutPixel(x, y - 4, c, c, c);
	gfx.PutPixel(x + 1, y - 4, c, c, c);
	gfx.PutPixel(x + 2, y - 4, c, c, c);
	gfx.PutPixel(x + 3, y - 4, c, c, c);
	gfx.PutPixel(x - 2, y, c, c, c);
	gfx.PutPixel(x - 1, y, c, c, c);
	gfx.PutPixel(x, y, c, c, c);
	gfx.PutPixel(x + 1, y, c, c, c);
	gfx.PutPixel(x - 2, y + 4, c, c, c);
	gfx.PutPixel(x - 1, y + 4, c, c, c);
	gfx.PutPixel(x, y + 4, c, c, c);
	gfx.PutPixel(x + 1, y + 4, c, c, c);
	gfx.PutPixel(x + 2, y + 4, c, c, c);
	gfx.PutPixel(x + 3, y + 4, c, c, c);
}

void Game::DrawDots(int x, int y, int c)
{
	gfx.PutPixel(x, y - 4, c, c, c);
	gfx.PutPixel(x, y - 3, c, c, c);
	gfx.PutPixel(x, y + 3, c, c, c);
	gfx.PutPixel(x, y + 4, c, c, c);
}

void Game::DrawLine(int y, int c)
{
	int x = 0;
	while (x < 1000)
	{
		gfx.PutPixel(x, y, c, c, c);
		gfx.PutPixel(x, y-1, c, c, c);
		x += 1;
	}
	
}

void Game::DrawL(int x, int y, int c)
{
	gfx.PutPixel(x - 3, y - 4, c, c, c);
	gfx.PutPixel(x - 3, y - 3, c, c, c);
	gfx.PutPixel(x - 3, y - 2, c, c, c);
	gfx.PutPixel(x - 3, y - 1, c, c, c);
	gfx.PutPixel(x - 3, y, c, c, c);
	gfx.PutPixel(x - 3, y + 1, c, c, c);
	gfx.PutPixel(x - 3, y + 2, c, c, c);
	gfx.PutPixel(x - 3, y + 3, c, c, c);
	gfx.PutPixel(x - 3, y + 4, c, c, c);
	gfx.PutPixel(x - 2, y + 4, c, c, c);
	gfx.PutPixel(x - 1, y + 4, c, c, c);
	gfx.PutPixel(x, y + 4, c, c, c);
	gfx.PutPixel(x + 1, y + 4, c, c, c);
}

void Game::DrawI(int x, int y, int c)
{
	gfx.PutPixel(x, y - 4, c, c, c);
	gfx.PutPixel(x, y - 3, c, c, c);
	gfx.PutPixel(x, y - 2, c, c, c);
	gfx.PutPixel(x, y - 1, c, c, c);
	gfx.PutPixel(x, y, c, c, c);
	gfx.PutPixel(x, y + 1, c, c, c);
	gfx.PutPixel(x, y + 2, c, c, c);
	gfx.PutPixel(x, y + 3, c, c, c);
	gfx.PutPixel(x, y + 4, c, c, c);
	gfx.PutPixel(x - 2, y + 4, c, c, c);
	gfx.PutPixel(x - 1, y + 4, c, c, c);
	gfx.PutPixel(x, y + 4, c, c, c);
	gfx.PutPixel(x + 1, y + 4, c, c, c);
	gfx.PutPixel(x + 2, y + 4, c, c, c);
	gfx.PutPixel(x - 2, y - 4, c, c, c);
	gfx.PutPixel(x - 1, y - 4, c, c, c);
	gfx.PutPixel(x, y - 4, c, c, c);
	gfx.PutPixel(x + 1, y - 4, c, c, c);
	gfx.PutPixel(x + 2, y - 4, c, c, c);
}

void Game::DrawV(int x, int y, int c)
{
	gfx.PutPixel(x - 3, y - 4, c, c, c);
	gfx.PutPixel(x - 3, y - 3, c, c, c);
	gfx.PutPixel(x - 3, y - 2, c, c, c);
	gfx.PutPixel(x - 2, y - 1, c, c, c);
	gfx.PutPixel(x - 2, y, c, c, c);
	gfx.PutPixel(x - 2, y + 1, c, c, c);
	gfx.PutPixel(x - 1, y + 2, c, c, c);
	gfx.PutPixel(x - 1, y + 3, c, c, c);
	gfx.PutPixel(x, y + 4, c, c, c);
	gfx.PutPixel(x + 3, y - 4, c, c, c);
	gfx.PutPixel(x + 3, y - 3, c, c, c);
	gfx.PutPixel(x + 3, y - 2, c, c, c);
	gfx.PutPixel(x + 2, y - 1, c, c, c);
	gfx.PutPixel(x + 2, y, c, c, c);
	gfx.PutPixel(x + 2, y + 1, c, c, c);
	gfx.PutPixel(x + 1, y + 2, c, c, c);
	gfx.PutPixel(x + 1, y + 3, c, c, c);
}
