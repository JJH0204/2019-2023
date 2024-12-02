/*ClrArea.cpp*/
#include <stdio.h>
#include <limits.h>
#define PI 3.141592 //상수

//원 넓이 구하는 프로그램(단, 반지름은 사용자가 결정)
//원 넓이 구하는 방법: 반지름 제곱 PI
//입력: 반지름 (scanf)
//변경되는 값(변수): 원 넓이, 반지름
//변경되지 않는 값(상수): PI값(3.141592)
//출력: 원 넓이
//원 넓이 = 반지름*반지름*PI

void CircleAreaMain() {	//함수 선언 정의
	//const: 상수변수(변수를 상수화)를 만듦,  값을 저장한 후 변경되지 않게 함,
	//변경시도시 프로그래머의 실수 (컴파일러가 알려줌)
	//const 선언시 이니셜라이저(초기화) 필수
	const float fPI = 3.141592; 

	//변수: 변경되는 수 - DATA를 저장하는 공간
	//타입 이름 = 데이터; // 초기화: 변수를 만들자 마자 값을 넣는 것
	// 변수는 선언과 동시에 초기화 하는 것이 좋다. (error 발생률 내려감)
	float rad = 0;
	float area = 0;
	//타입: 데이터의 종류, 이름: 데이터를 구별하기위해 지어진 이름

	printf("rad: ");
	scanf("%f", &rad);	//입력받는 기능 (& 필수: 주소 값을 받아오는 기능)

	area = rad * rad * fPI;
	printf("area: %f\n", area);

	return;
}

void SizeMain(void) {
	int x;
	//sizeof(변수, 자료형): 해당 변수나 타입의 크기를 확인함
	printf("변수 x의 크기: %d \n", sizeof(x));
	printf("char형의 크기: %d \n", sizeof(char));
	printf("int형의 크기: %d \n", sizeof(int));
	printf("short형의 크기: %d \n", sizeof(short));
	printf("long형의 크기: %d \n", sizeof(long));
	printf("float형의 크기: %d \n", sizeof(float));
	printf("double의 크기: %d \n", sizeof(double));
	return;
}

//오버플로우: 최대 숫자보다 더 큰 숫자를 사용하면 발생하는 오류
//최대숫자에 1을 더하면 최소숫자가 된다.
void OverFlowMain(void) {
	short s_money = SHRT_MAX;
	unsigned short u_money = USHRT_MAX;

	s_money = s_money + 1;
	u_money = u_money + 1;

	printf("s_money = %d\n", s_money);
	printf("u_money = %u \n", u_money);

	return;
}

void BinaryMain(void) {
	int x = 3;
	int y = -3;
	printf("x = %08X\n", x);
	printf("y = %08X\n", y);
	printf("x+y = %08X\n", x+y);

	return;
}

void CharMain(void) {
	char code1 = 'A';
	char code2 = 65;

	printf("문자 상수 초기화 : %d \n", code1);
	printf("아스키 코드 초기화 : %c \n", code2);
	return;
}

int main(void) {
	//CircleAreaMain();		//함수 호출
	//SizeMain();
	//OverFlowMain();
	//BinaryMain();
	CharMain();
	return 0;
}