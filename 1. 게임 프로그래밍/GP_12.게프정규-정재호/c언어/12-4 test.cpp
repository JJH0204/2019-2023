#include <stdio.h>
//���� n���� 100���� ũ�ų� ������ "large", 
//100���� ������ "small"�� ���
//������ �ϳ� �Ҵ��ϰ� ���� �Է� �޴´�.
//���� ���ϰ� ����� ����Ѵ�
void IfElse() {
	int a;
	scanf("%d", &a);
	if (a >= 100) printf("large\n");
	else printf("small\n");
	return;
}
//���� ����
void GradeScore() {
	int a;
	printf("����� ������ �Է����ּ���\n:");
	scanf("%d", &a);

	if (a >= 90) printf("����� ����: A\n");
	else if (a >= 80) printf("����� ����: B\n");
	else if (a >= 70) printf("����� ����: C\n");
	else if (a >= 60) printf("����� ����: D\n");
	else if (a >= 50) printf("����� ����: E\n");
	else printf("����� ����: F\n");

	if (a >= 90) printf("���� ����ϼ̱��� �̴�θ� �Ͻø� ��ž�� ��� ���Դϴ�!!\n");
	else if (a >= 70) printf("�Ϳ� �����ϳ׿� ���ݸ� �� ����Ͻø� A�� ������ �Ǽ� �ְھ��~\n");
	else if (a >= 50) printf("����.. ������� ���� �ʾҳ���? ���ݸ� �� ����غ���\n");
	else printf("������� ������Դϴ�. ���� �����Ϸ� ������!!!\n");

	return;
}

//���ڸ� �ϳ� �Է¹޴µ� �װ��� �빮�ڿ� �ҹ���, Ư�����ڷ� ������ ������ ��Ÿ������ ���α׷��� �ۼ��غ��ƶ�
//�ƽ�Ű �ڵ� ���� �빮�ڴ� 65~90�����̰�, �ҹ��ڴ� 97~122, ���ڴ� 48~57 ���� �����̴�. 
//������ ������ Ư�����ڷ� �����ϸ� �ȴ�.
void Ascii(void) {
	char ch;

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%c", &ch);

	if (ch >= 'A'&&ch <= 'Z') {
		printf("%c�� �빮�� �Դϴ�.\n", ch);
	}
	else if (ch >= 'a'&&ch <= 'z') {
		printf("%c�� �ҹ��� �Դϴ�.\n", ch);
	}
	else if(ch>='0'&&ch<='9'){
		printf("%c�� ���� �Դϴ�.\n", ch);
	}
	else {
		printf("%c�� ��Ÿ���� �Դϴ�.\n", ch);
	}
	
}


//1. ����ؾ��ϴ� ������ ������ Ÿ�� ������ ����Ѵٸ� int �Ǽ��� ���� �������� �ؾ��Ѵٸ� �Ǽ��� ������� ������ result, ����data 2��
//2. �Է¹�� �����ϱ� scanf�� ���� ���� �ޱ�
//3. �����ڰ� �ٸ��� ��� ó���ұ�? �����ڸ� ������ ������ ǥ��

//�Է�: 5+1
//����: 6
//�Է�: 6-2
//����: 4

//���� �����
void cal(void) {
	char sign;
	float fA, fB;
	printf("��: ");
	scanf("%f%c%f", &fA, &sign, &fB);
	if (sign == '+') {
		printf("����: %.2f\n", fA + fB);
	}
	else if (sign == '-') {
		printf("����: %.2f\n", fA - fB);
	}
	else if (sign == '*') {
		printf("����: %.2f\n", fA * fB);
	}
	else {
		printf("����: %.2f\n", fA / fB);
	}
	return;
}

//200ml �̻��� large, 200�̸� 100�ʰ� medium, 100���� small
void cupsize() {
	int cup;
	printf("�� ����� �Է����ּ���: ");
	scanf("%d", &cup);
	if (cup >= 200) {
		printf("large");
	}
	else if (cup > 100) {
		printf("Medium");
	}
	else {
		printf("small");
	}
	return;
}

//���� �����
void calSwtich(void) {
	char sign;
	float fA, fB;
	printf("��: ");
	scanf("%f%c%f", &fA, &sign, &fB);
	switch (sign)
	{
	case '+':
		printf("����: %.2f\n", fA + fB);
		break;
	case '-':
		printf("����: %.2f\n", fA - fB);
		break;
	case '*':
		printf("����: %.2f\n", fA * fB);
		break;
	case '/':
		printf("����: %.2f\n", fA / fB);
		break;
	}
	return;
}

int main(void) {
	//IfElse();
	//GradeScore();
	//Ascii();
	//cal();
	//cupsize();
	calSwtich();

	return 0;
}