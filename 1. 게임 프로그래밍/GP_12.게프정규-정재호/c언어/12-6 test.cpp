#include <stdio.h>

//�Լ� ���� / ����
int square(int result);

//����Ÿ�� �Լ��̸� (�Ű�����) / ���·� ���� ���� ��

//�Լ� ���� ���� ���� �Ҽ� ����
//���� ����� ���Ǹ� ������ �Ѵٸ� �� �� �ϳ��� ������ ������ �߻��Ѵ�.
//������ ���ٸ� ������ �������� �ĺ��� ������ ���߰� ���ǰ� ���ٸ� �ܺα�ȣ�� �� ã�� ������ ���߿� �����


int inc(int counter);

int g_nData=0; //��������, ��� �Լ����� ��밡��

void sub(void);


int main(void) {
	int i = 0;
	i = 10;
	
	printf("\n<�������� ����>\n");
	printf("g_nData: %d\n", g_nData);
	inc(i);
	printf("g_nData: %d\n", g_nData);
	printf("i: %d(%d)\n", i, &i);

	printf("\n<static ���� ����>\n");
	for (i = 0; i < 4; i++) {
		sub();
	}

	return 0;
}
//�������� : �Լ�, ��� �ȿ����� ���� & ��밡��
//�Ű������� ������ ���� ����




int square(int result)//�Ű����� (�Լ� ȣ�⿡�� ���޵� �� 
{
	printf("square: %d(%d\n", result, &result);
	return result * result; //���ϰ�
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