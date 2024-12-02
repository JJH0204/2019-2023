//로또 번호 추첨기 / 자동
//1~45번까지 수를 6개 골라 작은 수에서 큰 수로 오름차순으로 정리해서 출력해라
//한번 나온 번호는 다음번에 뽑을 수 없다.

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//1~45까지 수중 하나를 뽑아 내는 함수
#define ROTTO() rand() % 45 + 1

//배열에 값을 저장하는 함수
void scanRotto(int* ptr, int* data, int End) {
	int RottoNum = ROTTO();
	int count;
	for (count = 0; count < End; count++) {
		if (ptr[count] == RottoNum) {
			count = 0;
			RottoNum = ROTTO();
			continue;
		}
	}
	*data = RottoNum;
	return;
}

//6개의 랜덤 수를 배열에 저장하는 함수
void RandRotto(int* ptr, int lend) {
	int count;
	for (count = 0; count < lend; count++) {
		//배열에 값을 저장하는 함수
		scanRotto(ptr, &ptr[count], count);
	}
	return;
}
//로또 번호를 오름차순으로 정렬
void BubleRotto(int* ptr, int lend) {
	int temp;
	int count=0;

	

	for (count = 0; count < lend; count++) {
		if (ptr[count] > ptr[count + 1]) {
			temp = ptr[count];
			ptr[count] = ptr[count + 1];
			ptr[count + 1] = temp;
		}

	}
	return;
}
//로또 번호를 출력하는 함수
void PrintRotto(int* ptr, int lend) {
	int count;
	for (count = 0; count < lend; count++) {
		printf("%d ", ptr[count]);
	}
	return;
}
//로또번호만드는 함수
void RottoNUMBER(int* ptr, int lend) {
	//6개의 랜덤 수를 배열에 저장하는 함수
	RandRotto(ptr, lend);
	//6개의 랜덤 수를 오른차순으로 정리하는 함수
	//BubleRotto(ptr, lend);
	//6개의 숫자를 차례로 출력하는 함수
	PrintRotto(ptr, lend);
	return;
}
int main(void){

	srand(time(NULL));
	int RandArr[6];
	int nIdx=0;
	int lend = sizeof(RandArr) / sizeof(int);
	//로또번호를 만들어주는 함수
	RottoNUMBER(RandArr, lend);

	return 0;
}