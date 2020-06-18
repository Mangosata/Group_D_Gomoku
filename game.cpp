#include "game.h"

void initgame();
void beginGame();



void initgame()
{
	// Create a drawing window
	initgraph(700, 700);
	
	// Draw background
	float H = 190;
	float S = 1;
	float L = 0.7f;
	for (int y = 0; y < 700; y++)
	{
		L += 0.0005f;
		setlinecolor(HSLtoRGB(H, S, L));
		line(0, y, 699, y);
	}

	//Set options
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(35, 0, "");
	outtextxy(260, 100, "Gomoku");
	outtextxy(220, 400, "man-man game");
	outtextxy(190, 455, "man-machine game");
	outtextxy(230, 510, "quit game");
	outtextxy(430, 650, "by group D");

	MOUSEMSG m;	

	while (true)
	{
		m = GetMouseMsg();

		FlushMouseMsgBuffer();

		//putimage(0, 0, &backgrand);

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			if (m.x >= 220 && m.x <= 460 && m.y >= 400 && m.y <= 440)
			{
				settextcolor(RED);
				outtextxy(220, 400, "man-man game");
				settextcolor(BLACK);
				outtextxy(190, 455, "man-machine game");
				outtextxy(230, 510, "quit game");
			}
			if (m.x >= 190 && m.x <= 510 && m.y >= 455 && m.y <= 495)
			{
				settextcolor(RED);
				outtextxy(190, 455, "man-machine game");
				settextcolor(BLACK);
				outtextxy(220, 400, "man-man game");
				outtextxy(230, 510, "quit game");
			}
			if (m.x >= 230 && m.x <= 410 && m.y >= 510 && m.y <= 550)
			{
				settextcolor(RED);
				outtextxy(230, 510, "quit game");
				settextcolor(BLACK);
				outtextxy(220, 400, "man-man game");
				outtextxy(190, 455, "man-machine game");
			}
			
			break;

		case WM_LBUTTONDOWN:
			if (m.x >= 260 && m.x <= 360 && m.y >= 100 && m.y <= 150)  
			{
				
			}
			if (m.x >= 190 && m.x <= 510 && m.y >= 455 && m.y <= 495)  
			{
				
			}
			if (m.x >= 230 && m.x <= 410 && m.y >= 510 && m.y <= 550)  
			{
				closegraph();
				exit(0);
			}
			
		}
	}

}


void beginGame()
{

}