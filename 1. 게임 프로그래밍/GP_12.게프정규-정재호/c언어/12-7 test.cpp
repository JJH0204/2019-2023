#include <stdio.h>

int all_file;
static int this_file;  //static (������, ��������) , static �������� ���� ���������� �ٸ� ���Ͽ��� extern �������� ���� �� �� ����.
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