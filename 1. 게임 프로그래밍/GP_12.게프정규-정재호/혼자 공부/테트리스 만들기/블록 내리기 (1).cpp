#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define DELAY(n) Sleep(n) //n/1000 �ʸ� ��ٸ��� �����
#define CLEANING() system("cls")

//x, y�� ���� Ŀ���� ��ġ�� �̵� ��Ų��.
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
//Ŀ���� x��ǥ ���� �޾ƿ´�
int whereX(void) {
	CONSOLE_SCREEN_BUFFER_INFO BUFINFO;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BUFINFO);
	return BUFINFO.dwCursorPosition.X;
}
//Ŀ���� y��ǥ ���� �޾ƿ´�
int whereY(void) {
	CONSOLE_SCREEN_BUFFER_INFO BUFINFO;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BUFINFO);
	return BUFINFO.dwCursorPosition.Y;
}

int main(void) {
	int x=10, y=1;
	while(1) {
		gotoxy(x, y);
		printf("��");
		if (y == 20) {
			y = 0;
		}
		DELAY(1000/2);
		CLEANING();
		y++;
	}
	return 0;
}