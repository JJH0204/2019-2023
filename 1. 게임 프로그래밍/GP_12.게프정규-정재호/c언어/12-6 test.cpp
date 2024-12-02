#include <stdio.h>

//함수 선언 / 정의
int square(int result);

//리턴타입 함수이름 (매개변수) / 형태로 선언 정의 됨

//함수 선언 정의 같이 할수 있음
//만약 선언과 정의를 나눠서 한다면 둘 중 하나라도 없으면 에러가 발생한다.
//선언이 없다면 컴파일 과정에서 식별자 오류로 멈추고 정의가 없다면 외부기호를 못 찾아 컴파일 도중에 멈춘다


int inc(int counter);

int g_nData=0; //전역변수, 모든 함수에서 사용가능

void sub(void);


int main(void) {
	int i = 0;
	i = 10;
	
	printf("\n<전역변수 예제>\n");
	printf("g_nData: %d\n", g_nData);
	inc(i);
	printf("g_nData: %d\n", g_nData);
	printf("i: %d(%d)\n", i, &i);

	printf("\n<static 변수 예제>\n");
	for (i = 0; i < 4; i++) {
		sub();
	}

	return 0;
}
//지역변수 : 함수, 블록 안에서만 존재 & 사용가능
//매개변수도 일종의 지역 변수




int square(int result)//매개변수 (함수 호출에서 전달된 값 
{
	printf("square: %d(%d\n", result, &result);
	return result * result; //리턴값
}

int inc(int counter){
	g_nData++;
	printf("inc: %d(%d)\n", counter, &counter);
	counter++;
	return counter;
}

void sub(void) {
	int auto_count = 0;
	static int static_count = 0;

	auto_count++;
	static_count++;

	printf("auto_count : %d (%d)\n", auto_count, &auto_count);
	printf("static_count : %d (%d)\n", static_count, &static_count);
	return;
}