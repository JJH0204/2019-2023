#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define DELAY(n) Sleep(n) //n/1000 초를 기다리고 실행됨
#define CLEANING() system("cls")

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



#define yLine 5
#define xLine 5

const char * tail[] = { "◇", "◆", "‘ " };
int arr[yLine][xLine];

enum {WALL, Brick, EMPTY};

void setting(int x, int y) {
	/*int x, y;
	for (x = 0; x < xLine + 2; x++) {
		for (y = 0; y < yLine + 2; y++) {
			arr[x][y] = (y == 0 || y == yLine + 1 || x == 0 || x == xLine) ? WALL : EMPTY;
		}
	}*/
	arr[x][y] = Brick;
}

void printing() {
	int x, y;
	for (x = 0; x < xLine + 2; x++) {
		for (y = 0; y < yLine + 2; y++) {
			puts(tail[arr[xLine+x*2][yLine+y]]);
		}
	}
}


int main(void) {
	int x=0, y=0;
	
	while(1) {
		int kye = getch();
		switch (kye) {
		case 75:
			x--;
			break;
		case 72:
			y--;
			break;
		case 77:
			x++;
			break;
		case 80:
			y++;
			break;
		}
		setting(x, y);
		/*gotoxy(x, y);
		printf("★");
		if (y == 20) {
			y = 0;
		}*/
		printing();


		DELAY(1000/2);
		CLEANING();
		y++;
	}
	return 0;
}