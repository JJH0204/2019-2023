#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#define SETRAND() srand((unsigned int)time(NULL))
#define RAND(n) rand()%(n)
#define DELAY(n) Sleep(n)
#define CLEANING() system("cls")

//게임 정보 출력위치 상수화(시간, 다음 블록, 점수)
#define INFODATAPRINTX 85
#define INFODATAPRINTY 0

#define FEELDW 5 //필드넓이
#define FEELDH 10//필드높이

//게임 출력 기본 위치
#define FX 5
#define FY 1


void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

typedef struct player {
	unsigned int score = 0;
	unsigned int playX;
	unsigned int playY;
}PLAYER;

//게임에 사용될 구조물 타일
enum { EMPTY, BRICK, WALL };
const char * arTile[] = { ". ", "■", "□" };

//화면에 띄울 보드판
int Board[FEELDW + 2][FEELDH + 2];




//블럭을 한칸씩 내리는 함수
void DOWNBOARD(int _Y) {
	int X = 1;
	int Y;
	for (;X<FEELDW+2;X++) {
		for (Y = _Y ; Y>1 ; Y--) {
			Board[Y][X] = Board[Y - 1][X];
			
		}
		Board[Y][X] = EMPTY;
	}
}

//점수를 계산하고 해당 줄을 지우는 함수
void CheckScore(PLAYER * USER) {
	int checkX;
	int checkY = FEELDH + 1;
	int count = 0;
	for (;checkY>0;checkY--) {
		for (int checkX = 1; checkX < FEELDW + 2;checkX++) {
			if (Board[checkX][checkY] != BRICK)
				break;
			
			count++;
			
			if (count == FEELDW) {
				USER->score += 1;
				DOWNBOARD(checkY);
				
			}
		}
	}
		
}


//플레이 정보를 화면에 출력 (시간, 다음 블록(아직 구현 x), 점수)
void PlayerInfo(PLAYER * user) {
	gotoxy(INFODATAPRINTX, INFODATAPRINTY);
	printf("점수 : %d", user->score);
}

//게임 화면을 출력
void printborad(PLAYER * USER) {
	int x, y;
	//상태를 출력
	for (x = 0; x < FEELDW + 2; x++) {
		for (y = 0; y < FEELDH + 2; y++) {
			gotoxy(FX + x * 2, FY + y);// x값에 *2를 하지 않으면 정확한 출력 결과를 볼 수 없다.
			puts(arTile[Board[x][y]]);
		}
	}
	PlayerInfo(USER);
	DELAY(1000/2);
	CLEANING();
}

//게임 플레이 화면 출력
void GAMEPLAYSCREAN(PLAYER * USER) {
	int nowplay = 0;
	while (1) {
		int x, y;
		if (nowplay == 0) {
			//배열에 플레이 보드의 상태를 저장
			for (x = 0; x < FEELDW + 2; x++) {
				for (y = 0; y < FEELDH + 2; y++) {
					Board[x][y] = (y == 0 || y == FEELDH + 1 || x == 0 || x == FEELDW + 1) ? WALL : EMPTY;
				}
			}
			USER->playX = FX ;
			USER->playY = FY ;
			Board[USER->playX][USER->playY] = BRICK;
			nowplay = 1;
		}
		else {
			if (Board[USER->playX][USER->playY + 1] == WALL|| Board[USER->playX][USER->playY + 1] == BRICK) {
				USER->playX = FX;
				USER->playY = FY;
				if (Board[USER->playX-4][USER->playY] == BRICK|| Board[USER->playX-3][USER->playY] == BRICK|| Board[USER->playX-2][USER->playY] == BRICK|| Board[USER->playX-1][USER->playY] == BRICK|| Board[USER->playX][USER->playY] == BRICK
					|| Board[USER->playX+1][USER->playY] == BRICK|| Board[USER->playX+2][USER->playY] == BRICK|| Board[USER->playX+3][USER->playY] == BRICK|| Board[USER->playX+4][USER->playY] == BRICK|| Board[USER->playX+5][USER->playY] == BRICK) {
					CLEANING();
					printf("GAME OVER~ YOU LOSE\nYOUR SCORE : %d", USER->score);
					break;
				}

				Board[USER->playX][USER->playY] = BRICK;
			}
			else {
				Board[USER->playX][USER->playY] = EMPTY;
				if (kbhit()) {
					int getkye = getch();
					getkye = getch();
					if (getkye == 75) {
						if (Board[USER->playX - 1][USER->playY] == BRICK || Board[USER->playX - 1][USER->playY] == WALL) { }
						else USER->playX -= 1;
						
					}
					else if (getkye == 77) {
						if (Board[USER->playX + 1][USER->playY] == BRICK || Board[USER->playX + 1][USER->playY] == WALL) { }
						else USER->playX += 1;
					}
					else if (getkye == 80) {
						if (Board[USER->playX][USER->playY + 1] == BRICK || Board[USER->playX][USER->playY + 1] == WALL) { }
						else USER->playY += 1;
					}
				}
				USER->playY++;
				Board[USER->playX][USER->playY] = BRICK;
				CheckScore(USER);
			}

		}
		printborad(USER);
	}
}

int main(void) {
	PLAYER user;

		GAMEPLAYSCREAN(&user);

	return 0;
}