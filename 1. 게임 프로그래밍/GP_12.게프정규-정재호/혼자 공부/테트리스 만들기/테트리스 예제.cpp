//TURBOC.h 의 내용###################################################################################
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define SETRAND() srand((unsigned int)time(NULL))
#define RAND(n) rand()%(n)
#define DELAY(n) Sleep(n) //n/1000 초를 기다리고 실행됨
#define CLEANING() system("cls")

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

//x, y을 토대로 커서의 위치를 이동 시킨다.
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//커서의 x좌표 값을 받아온다
int whereX(void) {
	CONSOLE_SCREEN_BUFFER_INFO BUFINFO;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BUFINFO);
	return BUFINFO.dwCursorPosition.X;
}

//커서의 y좌표 값을 받아온다
int whereY(void) {
	CONSOLE_SCREEN_BUFFER_INFO BUFINFO;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BUFINFO);
	return BUFINFO.dwCursorPosition.Y;
}

//커서의 타입을 변경하는 함수 (커서가 안보이고 보이고 하는 것을 설정 할 수 있음)
void SetCurSorType(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CURINFO;

	switch (c) {
	case NOCURSOR:
		CURINFO.bVisible = FALSE;
		CURINFO.dwSize = 1;
		break;
	case SOLIDCURSOR:
		CURINFO.bVisible = TRUE;
		CURINFO.dwSize = 100;
		break;
	case NORMALCURSOR:
		CURINFO.bVisible = 20;
		CURINFO.dwSize = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CURINFO);
}
//TURBOC.h 의 내용###################################################################################
#define LEFT 75

#define RIGHT 77

#define UP 72

#define DOWN 80

#define ESC 27

#define BX 5

#define BY 1

#define BW 10

#define BH 20



void DrawScreen();

void DrawBoard();

BOOL ProcessKey();

void PrintBrick(BOOL Show);

int GetAround(int x, int y, int b, int r);

BOOL MoveDown();

void TestFull();



struct Point {

	int x, y;

};

Point Shape[][4][4] = {

	 { {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2}, {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2} },

	 { {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1} },

	 { {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1}, {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1} },

	 { {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1}, {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1} },

	 { {0,0,-1,0,1,0,-1,-1}, {0,0,0,-1,0,1,-1,1}, {0,0,-1,0,1,0,1,1}, {0,0,0,-1,0,1,1,-1} },

	 { {0,0,1,0,-1,0,1,-1}, {0,0,0,1,0,-1,-1,-1}, {0,0,1,0,-1,0,-1,1}, {0,0,0,-1,0,1,1,1} },

	 { {0,0,-1,0,1,0,0,1}, {0,0,0,-1,0,1,1,0}, {0,0,-1,0,1,0,0,-1}, {0,0,-1,0,0,-1,0,1} },

};



enum { EMPTY, BRICK, WALL };

const char *arTile[] = { ". ","■","□" };

int board[BW + 2][BH + 2];

int nx, ny;

int brick, rot;



void main()

{

	int nFrame, nStay;

	int x, y;



	SetCurSorType(NOCURSOR);

	SETRAND();

	CLEANING();

	for (x = 0; x < BW + 2; x++) {

		for (y = 0; y < BH + 2; y++) {

			board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;

		}

	}

	DrawScreen();

	nFrame = 20;



	for (; 1;) {

		brick = RAND(sizeof(Shape) / sizeof(Shape[0]));

		nx = BW / 2;

		ny = 3;

		rot = 0;

		PrintBrick(TRUE);



		if (GetAround(nx, ny, brick, rot) != EMPTY) break;

		nStay = nFrame;

		for (; 2;) {

			if (--nStay == 0) {

				nStay = nFrame;

				if (MoveDown()) break;

			}

			if (ProcessKey()) break;

			DELAY(1000 / 20);

		}

	}

	CLEANING();

	gotoxy(30, 12); puts("G A M E  O V E R");

	SetCurSorType(NORMALCURSOR);

}



void DrawScreen()

{

	int x, y;



	for (x = 0; x < BW + 2; x++) {

		for (y = 0; y < BH + 2; y++) {

			gotoxy(BX + x * 2, BY + y);

			puts(arTile[board[x][y]]);

		}

	}



	gotoxy(50, 3); puts("Tetris Ver 1.0");

	gotoxy(50, 5); puts("좌우:이동, 위:회전, 아래:내림");

	gotoxy(50, 6); puts("공백:전부 내림");

}



void DrawBoard()

{

	int x, y;



	for (x = 1; x < BW + 1; x++) {

		for (y = 1; y < BH + 1; y++) {

			gotoxy(BX + x * 2, BY + y);

			puts(arTile[board[x][y]]);

		}

	}

}



BOOL ProcessKey()

{

	int ch, trot;



	if (kbhit()) {

		ch = getch();

		if (ch == 0xE0 || ch == 0) {

			ch = getch();

			switch (ch) {

			case LEFT:

				if (GetAround(nx - 1, ny, brick, rot) == EMPTY) {

					PrintBrick(FALSE);

					nx--;

					PrintBrick(TRUE);

				}

				break;

			case RIGHT:

				if (GetAround(nx + 1, ny, brick, rot) == EMPTY) {

					PrintBrick(FALSE);

					nx++;

					PrintBrick(TRUE);

				}

				break;

			case UP:

				trot = (rot == 3 ? 0 : rot + 1);

				if (GetAround(nx, ny, brick, trot) == EMPTY) {

					PrintBrick(FALSE);

					rot = trot;

					PrintBrick(TRUE);

				}

				break;

			case DOWN:

				if (MoveDown()) {

					return TRUE;

				}

				break;

			}

		}
		else {

			switch (ch) {

			case ' ':

				while (MoveDown() == FALSE) { ; }

				return TRUE;

			}

		}

	}

	return FALSE;

}



void PrintBrick(BOOL Show)

{

	int i;



	for (i = 0; i < 4; i++) {

		gotoxy(BX + (Shape[brick][rot][i].x + nx) * 2, BY + Shape[brick][rot][i].y + ny);

		puts(arTile[Show ? BRICK : EMPTY]);

	}

}



int GetAround(int x, int y, int b, int r)

{

	int i, k = EMPTY;



	for (i = 0; i < 4; i++) {

		k = max(k, board[x + Shape[b][r][i].x][y + Shape[b][r][i].y]);

	}

	return k;

}



BOOL MoveDown()

{

	if (GetAround(nx, ny + 1, brick, rot) != EMPTY) {

		TestFull();

		return TRUE;

	}

	PrintBrick(FALSE);

	ny++;

	PrintBrick(TRUE);

	return FALSE;

}



void TestFull()

{

	int i, x, y, ty;



	for (i = 0; i < 4; i++) {

		board[nx + Shape[brick][rot][i].x][ny + Shape[brick][rot][i].y] = BRICK;

	}



	for (y = 1; y < BH + 1; y++) {

		for (x = 1; x < BW + 1; x++) {

			if (board[x][y] != BRICK) break;

		}

		if (x == BW + 1) {

			for (ty = y; ty > 1; ty--) {

				for (x = 1; x < BW + 1; x++) {

					board[x][ty] = board[x][ty - 1];

				}

			}

			DrawBoard();

			DELAY(200);

		}

	}

}