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

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR} CURSOR_TYPE;

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

//게임 시작 화면 출력
void GAMESTART(void) {
	char GameName[] = "??( 전통 테트리스 게임 ??)";
	char GameRULE1[5][] = { "<게임방법>",
							"방향키로 내려 오는 블록을 쌓아 맞추면 됩니다.", 
							"'스페이스바'로 블록을 회전 시킬 수 있습니다." ,
							"'c'키로 다음에 나올 블록과 교환할 수 있습니다.",
							"'v'키로 블록을 바로 내려 놓을 수 있습니다." };
	char GameRULE2[] = ;
	char GameRULE3[] = ;
	char GameRULE4[] = ;
	char GameRULE5[] = ;
	int choise;
	printf("%s", &block);
	return;
}


//콘솔창에 시간 표시
void PrintTIME() {
	time_t PRINTTIME = time(NULL);
	gotoxy(95, 0);
	
	printf("%s", asctime(localtime(&PRINTTIME)));
	return;
}
//게임 플레이 화면 출력
void GAMEPLAYSCREAN(void) {
	while (1) {
		PrintTIME();


		DELAY(1000);
		CLEANING();
	}
}


int main(void) {
	SetCurSorType(NOCURSOR); //커서를 지운다.
	GAMESTART();
	GAMEPLAYSCREAN();
	return 0;
}