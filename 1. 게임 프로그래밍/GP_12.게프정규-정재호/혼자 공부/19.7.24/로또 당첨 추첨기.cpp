//�ζ� ��ȣ ��÷�� / �ڵ�
//1~45������ ���� 6�� ��� ���� ������ ū ���� ������������ �����ؼ� ����ض�
//�ѹ� ���� ��ȣ�� �������� ���� �� ����.

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//1~45���� ���� �ϳ��� �̾� ���� �Լ�
#define ROTTO() rand() % 45 + 1

//�迭�� ���� �����ϴ� �Լ�
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

//6���� ���� ���� �迭�� �����ϴ� �Լ�
void RandRotto(int* ptr, int lend) {
	int count;
	for (count = 0; count < lend; count++) {
		//�迭�� ���� �����ϴ� �Լ�
		scanRotto(ptr, &ptr[count], count);
	}
	return;
}
//�� ���� ���ؼ� ���� �ٲٴ� �Լ�
void TransData(int* a, int* b) {
	int temp=0;
	if (*a > * b) {
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
//�ζ� ��ȣ�� ������������ ����
void BubleRotto(int* ptr, int lend) {
	int count=0;

	while (lend >= 0) {
		for (count = 0; count < lend-1; count++) {
			TransData(&ptr[count], &ptr[count+1]);
		}
		lend--;
	}
	return;
}
//�ζ� ��ȣ�� ����ϴ� �Լ�
void PrintRotto(int* ptr, int lend) {
	int count;
	for (count = 0; count < lend; count++) {
		printf("%d ", ptr[count]);
	}
	printf("\n");
	return;
}
//�ζǹ�ȣ����� �Լ�
void RottoNUMBER(int* ptr, int lend) {
	//6���� ���� ���� �迭�� �����ϴ� �Լ�
	RandRotto(ptr, lend);
	//6���� ���� ���� ������������ �����ϴ� �Լ�
	BubleRotto(ptr, lend);
	//6���� ���ڸ� ���ʷ� ����ϴ� �Լ�
	PrintRotto(ptr, lend);
	return;
}
int main(void){

	srand((unsigned int)time(NULL));
	int RandArr[6];
	int nIdx=0;
	int lend = sizeof(RandArr) / sizeof(int);
	printf("������ ��÷ ��ȣ: ");
	//�ζǹ�ȣ�� ������ִ� �Լ�

	RottoNUMBER(RandArr, lend);

	printf("���� �帳�ϴ�!!\n");
	return 0;
}