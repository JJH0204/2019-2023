#include <stdio.h>
extern int all_file;
extern int this_file; //�ش� ������ static�������� ������� �־� ������ �� ����.
int this_file; //�� �����ʹ� �ٸ� ����
void sub(void) {
	all_file = 10;
	printf("adress all_file: %d\n", &all_file); // �ٸ� ������ ������ ������ �ּ� ��

//	printf("adress this_file: %d\n", &this_file);
	//this_file = 20;//����
	
	//���� ������ extern ������ ����� �� ����.
	//extern int a;
	//a = 10;
}