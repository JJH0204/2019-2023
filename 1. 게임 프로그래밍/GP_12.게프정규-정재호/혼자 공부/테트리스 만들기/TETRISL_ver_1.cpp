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

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

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

//������ ###################################################################################################
//��� ��ġ ���ȭ
//���� ���� ���� ��ġ ���ȭ
#define PRINTLINEX  30
#define PRINTLINEY  10
//���� ���� �����ġ ���ȭ(�ð�, ���� ���, ����)
#define INFODATAPRINTX 85
#define INFODATAPRINTY 0
// �÷��� �ʽ� �԰�ȭ
#define FEELDX 5
#define FEELDY 1
#define FEELDW 10
#define FEELDH 20

//USER���� ����üȭ
typedef struct player {
	unsigned int score = 0;
	unsigned int blcokPosX;
	unsigned int blcokPosY;
}PLAYER;
//###################################################################################################

//������ ���###################################################################################################
//�ܼ�â�� �ð� ǥ��
void PrintTIME() {
	time_t PRINTTIME = time(NULL);
	printf("%s", asctime(localtime(&PRINTTIME)));
	return;
}
//�÷��� ������ ȭ�鿡 ��� (�ð�, ���� ���(���� ���� x), ����)
void PlayerInfo(PLAYER * user) {
	gotoxy(INFODATAPRINTX, INFODATAPRINTY);
	PrintTIME();
	gotoxy(INFODATAPRINTX, INFODATAPRINTY+1);
	printf("���� : %d", user->score);
}
//�ʵ� ���
void PlayFeeld(){
	gotoxy(FEELDPRINTX, FEELDPRINTY);
}
//###################################################################################################

//�����÷���###################################################################################################
//���� ���� ȭ�� ���
//���� ����� �����ؾ� ��
int GAMESTART(void) {
	int choise;
	gotoxy(PRINTLINEX, PRINTLINEY);
	printf("-------------------------------------------------------------");
	gotoxy(PRINTLINEX, PRINTLINEY + 1);
	printf("| @ ���� ��Ʈ���� ���� @					  |");
	gotoxy(PRINTLINEX, PRINTLINEY + 2);
	printf("| <���ӹ��>					          |");
	gotoxy(PRINTLINEX, PRINTLINEY + 3);
	printf("| ����Ű�� ���� ���� ����� �׾� ���߸� �˴ϴ�.		  |");
	gotoxy(PRINTLINEX, PRINTLINEY + 4);
	printf("| '��', '��'Ű�� ����� ������ �� �ֽ��ϴ�.		  |");
	gotoxy(PRINTLINEX, PRINTLINEY + 5);
	printf("| �����̽�Ű�� ����� ȸ�� ��ų �� �ֽ��ϴ�.		  |");
	gotoxy(PRINTLINEX, PRINTLINEY + 6);
	printf("| '��'Ű�� ������ ���� ��ϰ� ��ȯ�� �� �ֽ��ϴ�.           |");
	gotoxy(PRINTLINEX, PRINTLINEY + 7);
	printf("| '��'Ű�� ����� �ٷ� ���� ���� �� �ֽ��ϴ�.	          |");
	gotoxy(PRINTLINEX, PRINTLINEY + 8);
	printf("-------------------------------------------------------------");
	gotoxy(PRINTLINEX, PRINTLINEY + 9);
	printf("1. ���� ���� 2. ����");
	gotoxy(PRINTLINEX, PRINTLINEY + 10);
	printf("����: ");
	scanf("%d", &choise);
	if (choise == 2) {
		CLEANING();
		return -1;
	}
	else {
		CLEANING();
		return 1;
	}
}

//���� �÷��� ȭ�� ���
void GAMEPLAYSCREAN(PLAYER * USER) {
	while (1) {
		PlayerInfo(USER);
		
		DELAY(1000);
		CLEANING();
	}
}
//###################################################################################################

int main(void) {
	PLAYER user;
	SetCurSorType(NOCURSOR); //Ŀ���� �����.
	if (GAMESTART()==-1) {
		printf("������ ���� �մϴ�.");
		DELAY(1000);
		return 0;
	}
	else {
		GAMEPLAYSCREAN(&user);
	}
	
	return 0;
}