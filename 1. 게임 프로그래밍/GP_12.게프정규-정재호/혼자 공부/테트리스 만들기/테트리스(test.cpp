//TURBOC.h �� ����###################################################################################
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define SETRAND() srand((unsigned int)time(NULL))
#define RAND(n) rand()%(n)
#define DELAY(n) Sleep(n) //n/1000 �ʸ� ��ٸ��� �����
#define CLEANING() system("cls")

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR} CURSOR_TYPE;

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

//Ŀ���� Ÿ���� �����ϴ� �Լ� (Ŀ���� �Ⱥ��̰� ���̰� �ϴ� ���� ���� �� �� ����)
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
//TURBOC.h �� ����###################################################################################

//���� ���� ȭ�� ���
void GAMESTART(void) {
	char GameName[] = "??( ���� ��Ʈ���� ���� ??)";
	char GameRULE1[5][] = { "<���ӹ��>",
							"����Ű�� ���� ���� ����� �׾� ���߸� �˴ϴ�.", 
							"'�����̽���'�� ����� ȸ�� ��ų �� �ֽ��ϴ�." ,
							"'c'Ű�� ������ ���� ��ϰ� ��ȯ�� �� �ֽ��ϴ�.",
							"'v'Ű�� ����� �ٷ� ���� ���� �� �ֽ��ϴ�." };
	char GameRULE2[] = ;
	char GameRULE3[] = ;
	char GameRULE4[] = ;
	char GameRULE5[] = ;
	int choise;
	printf("%s", &block);
	return;
}


//�ܼ�â�� �ð� ǥ��
void PrintTIME() {
	time_t PRINTTIME = time(NULL);
	gotoxy(95, 0);
	
	printf("%s", asctime(localtime(&PRINTTIME)));
	return;
}
//���� �÷��� ȭ�� ���
void GAMEPLAYSCREAN(void) {
	while (1) {
		PrintTIME();


		DELAY(1000);
		CLEANING();
	}
}


int main(void) {
	SetCurSorType(NOCURSOR); //Ŀ���� �����.
	GAMESTART();
	GAMEPLAYSCREAN();
	return 0;
}