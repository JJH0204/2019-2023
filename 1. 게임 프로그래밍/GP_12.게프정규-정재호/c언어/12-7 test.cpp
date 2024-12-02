#include <stdio.h>

int all_file;
static int this_file;  //static (정적인, 고정적인) , static 선언으로 만든 전역변수는 다른 파일에서 extern 선언으로 가져 갈 수 없다.
extern void sub();

int main(void) {
	//int a;
	sub();
	printf("all_file: %d\n", all_file);
	printf("this_file: %d\n", this_file);
	printf("adress all_file : %d\n", &all_file);
	//printf("a: %d \n", a);
	return 0;
}