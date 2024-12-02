#include <stdio.h>
#define SIZE 5

void Arr(void) {
	int i;
	//배열 초기화 {}안에 초기값 저장
	int arr[SIZE] = { 1,2,3,4,5 }; //{}안에 아무 것도 적지 않으면 0으로 모두 초기화
	//	자료형 배열이름[갯수] = {초기값}; // 초기값 생략시 쓰래기값 저장

	//int nSize = 5;
	//int arr[nSize]; //에러
	//전처리에서 메모리 공간을 계산해 할당함으로 변수로 선언하면 
	//실행 중에 (runtime)에서 실행이 종료되면 값을 알수 없기 때문에 변수를 인덱스 값으로 하는 
	//배열 선언은 금지 되어 있다.
	//다만 const선언을 포함하면 변수를 인덱스 값으로 하는 배열 선언이 가능하다
	//즉, 배열 선언은 상수만 가능하다



	printf("1.\n");
	for (i = 0; i < 5; i++) {
		printf("[%d]%d\n", i + 1, arr[i]);
	}

	for (i = 0; i < 5; i++) { //실제로는 파일을 통해 입력을 받는다.
		arr[i] = (i + 1) * 10;
	}
	//arr[5]=10; arr[-1]=2; // 에러 (무슨 값이 저장되어 있는지 모름)
	printf("2.\n");
	for (i = 0; i < 5; i++) {
		printf("[%d]%d\n", i + 1, arr[i]);
	}
	printf("arr count: %d\n", sizeof(arr) / sizeof(arr[0]));
	printf("arr size: %d\n", sizeof(arr));
	printf("adress arr: %p\n", &arr); //배열이름이 배열의 첫 인자를 가리키는 상수형 포인터
	for (i = 0; i < 5; i++) {
		printf("adress arr[%d]: %p\n", i, &arr[i]);
	}
	int arrsize[5];
	//arrsize=arr 에러
	//배열이름은 값을 저장하는 변수가 아니라
	//배열의 시작 위치 (첫번째 인자)의 주소 값을 저장하고 있는 포인터이다.(상수형)
	//상수형 포인터이기때문에 주소값을 복사하지 못하고 복사하더라도 두 이름이 가리키는 메모리 공간은 하나가 된다.
	for (i = 0; i < 5; i++) { //복사 방법
		arrsize[i] = arr[i];
	}

}
void miniVal(void) {
	int arr[5] = { 7,8,5,3,1 };
	int i, result=arr[0];
	for (i = 1; i < 5; i++) {
		if (result > arr[i]) {
			result = arr[i];
		}
	}
	printf(" mini val : %d\n", result);
}

void InitArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (i + 1);
	}
}

void PrintArray(const int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("[%d]%d", i, arr[i]);
	}
	printf("\n");
}
void SetArray(void) {
	int arr[SIZE];
	InitArray(arr, SIZE);
	PrintArray(arr, SIZE);
}

#define H 3
#define W 2

void Array2(void) {
	int x, y;
	int array[H][W];
	for (y = 0; y < H; y++) {
		for (x = 0; x < W; x++) {
			array[y][x] = y * x + 1;
		}
	}
	for (y = 0; y < H; y++) {
		for (x = 0; x < W; x++) {
			printf("[%d][%d]%d ", y, x, array[y][x]);
		}
		printf("\n");
	}
}


int main(void) {
	//Arr();
	/*miniVal();
	SetArray();*/
	Array2();
	return 0;
}