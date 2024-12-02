/*ClrArea.cpp*/
#include <stdio.h>
#include <limits.h>
#define PI 3.141592 //���

//�� ���� ���ϴ� ���α׷�(��, �������� ����ڰ� ����)
//�� ���� ���ϴ� ���: ������ ���� PI
//�Է�: ������ (scanf)
//����Ǵ� ��(����): �� ����, ������
//������� �ʴ� ��(���): PI��(3.141592)
//���: �� ����
//�� ���� = ������*������*PI

void CircleAreaMain() {	//�Լ� ���� ����
	//const: �������(������ ���ȭ)�� ����,  ���� ������ �� ������� �ʰ� ��,
	//����õ��� ���α׷����� �Ǽ� (�����Ϸ��� �˷���)
	//const ����� �̴ϼȶ�����(�ʱ�ȭ) �ʼ�
	const float fPI = 3.141592; 

	//����: ����Ǵ� �� - DATA�� �����ϴ� ����
	//Ÿ�� �̸� = ������; // �ʱ�ȭ: ������ ������ ���� ���� �ִ� ��
	// ������ ����� ���ÿ� �ʱ�ȭ �ϴ� ���� ����. (error �߻��� ������)
	float rad = 0;
	float area = 0;
	//Ÿ��: �������� ����, �̸�: �����͸� �����ϱ����� ������ �̸�

	printf("rad: ");
	scanf("%f", &rad);	//�Է¹޴� ��� (& �ʼ�: �ּ� ���� �޾ƿ��� ���)

	area = rad * rad * fPI;
	printf("area: %f\n", area);

	return;
}

void SizeMain(void) {
	int x;
	//sizeof(����, �ڷ���): �ش� ������ Ÿ���� ũ�⸦ Ȯ����
	printf("���� x�� ũ��: %d \n", sizeof(x));
	printf("char���� ũ��: %d \n", sizeof(char));
	printf("int���� ũ��: %d \n", sizeof(int));
	printf("short���� ũ��: %d \n", sizeof(short));
	printf("long���� ũ��: %d \n", sizeof(long));
	printf("float���� ũ��: %d \n", sizeof(float));
	printf("double�� ũ��: %d \n", sizeof(double));
	return;
}

//�����÷ο�: �ִ� ���ں��� �� ū ���ڸ� ����ϸ� �߻��ϴ� ����
//�ִ���ڿ� 1�� ���ϸ� �ּҼ��ڰ� �ȴ�.
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

	printf("���� ��� �ʱ�ȭ : %d \n", code1);
	printf("�ƽ�Ű �ڵ� �ʱ�ȭ : %c \n", code2);
	return;
}

int main(void) {
	//CircleAreaMain();		//�Լ� ȣ��
	//SizeMain();
	//OverFlowMain();
	//BinaryMain();
	CharMain();
	return 0;
}