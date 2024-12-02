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

//데이터 ###################################################################################################
//출력 위치 상수화
//게임 시작 설명 위치 상수화
#define PRINTLINEX  30
#define PRINTLINEY  10
//게임 정보 출력위치 상수화(시간, 다음 블록, 점수)
#define INFODATAPRINTX 85
#define INFODATAPRINTY 0
// 플레이 필스 규격화
#define FEELDX 5
#define FEELDY 1
#define FEELDW 10
#define FEELDH 20

//USER정보 구조체화
typedef struct player {
	unsigned int score = 0;
	unsigned int blcokPosX;
	unsigned int blcokPosY;
}PLAYER;
//###################################################################################################

//데이터 출력###################################################################################################
//콘솔창에 시간 표시
void PrintTIME() {
	time_t PRINTTIME = time(NULL);
	printf("%s", asctime(localtime(&PRINTTIME)));
	return;
}
//플레이 정보를 화면에 출력 (시간, 다음 블록(아직 구현 x), 점수)
void PlayerInfo(PLAYER * user) {
	gotoxy(INFODATAPRINTX, INFODATAPRINTY);
	PrintTIME();
	gotoxy(INFODATAPRINTX, INFODATAPRINTY+1);
	printf("점수 : %d", user->score);
}
//필드 출력
void PlayFeeld(){
	gotoxy(FEELDPRINTX, FEELDPRINTY);
}
//###################################################################################################

//게임플레이###################################################################################################
//게임 시작 화면 출력
//게임 방법도 설명해야 됨
int GAMESTART(void) {
	int choise;
	gotoxy(PRINTLINEX, PRINTLINEY);
	printf("-------------------------------------------------------------");
	gotoxy(PRINTLINEX, PRINTLINEY + 1);
	printf("| @ 전통 테트리스 게임 @					  |");
	gotoxy(PRINTLINEX, PRINTLINEY + 2);
	printf("| <게임방법>					          |");
	gotoxy(PRINTLINEX, PRINTLINEY + 3);
	printf("| 방향키로 내려 오는 블록을 쌓아 맞추면 됩니다.		  |");
	gotoxy(PRINTLINEX, PRINTLINEY + 4);
	printf("| '←', '→'키로 블록을 움직일 수 있습니다.		  |");
	gotoxy(PRINTLINEX, PRINTLINEY + 5);
	printf("| 스페이스키로 블록을 회전 시킬 수 있습니다.		  |");
	gotoxy(PRINTLINEX, PRINTLINEY + 6);
	printf("| '↑'키로 다음에 나올 블록과 교환할 수 있습니다.           |");
	gotoxy(PRINTLINEX, PRINTLINEY + 7);
	printf("| '↓'키로 블록을 바로 내려 놓을 수 있습니다.	          |");
	gotoxy(PRINTLINEX, PRINTLINEY + 8);
	printf("-------------------------------------------------------------");
	gotoxy(PRINTLINEX, PRINTLINEY + 9);
	printf("1. 게임 시작 2. 종료");
	gotoxy(PRINTLINEX, PRINTLINEY + 10);
	printf("선택: ");
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

//게임 플레이 화면 출력
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
	SetCurSorType(NOCURSOR); //커서를 지운다.
	if (GAMESTART()==-1) {
		printf("게임을 종료 합니다.");
		DELAY(1000);
		return 0;
	}
	else {
		GAMEPLAYSCREAN(&user);
	}
	
	return 0;
}