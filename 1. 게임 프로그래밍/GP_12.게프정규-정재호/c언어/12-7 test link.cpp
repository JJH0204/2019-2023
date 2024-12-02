#include <stdio.h>
extern int all_file;
extern int this_file; //해당 변수가 static선언으로 만들어져 있어 가져올 수 없다.
int this_file; //위 변수와는 다른 변수
void sub(void) {
	all_file = 10;
	printf("adress all_file: %d\n", &all_file); // 다른 파일의 변수와 동일한 주소 값

//	printf("adress this_file: %d\n", &this_file);
	//this_file = 20;//에러
	
	//지역 변수는 extern 선언을 사용할 수 없다.
	//extern int a;
	//a = 10;
}