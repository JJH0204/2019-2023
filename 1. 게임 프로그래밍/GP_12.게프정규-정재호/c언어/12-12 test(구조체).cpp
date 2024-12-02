#include <stdio.h>
#include <stdlib.h>

//����ü ���� : (���赵)
struct student {
	//����ü�� �Ҽӵ� ����(���)
	int number;
	char name[10];
	double grade;
};
//call-by-value
void swapStudentInfo(student a, student b) {
	student temp = {};
	temp = a;
	a = b;
	b = temp;
}
//call-by-reference
void SwapStudentInfo(student* a, student* b) {
	student temp = {};
	temp = *a;
	*a = *b;
	*b = temp;
}
//������call-by-reference
void SwapStudentInfoREF(student& a, student& b) { //c++�� �����ڸ� Ȱ��
	student temp = {};
	temp = a;
	a = b;
	b = temp;
}

void swapstruct(void) {
	struct student stArr[3] = { {19, "jung", 3.0}, {17, "ho", 2.8}, {18, "jae", 4.0} };
	int i;
	printf("ArrayStruct\n");
	for (i = 0; i < 3; i++) {
		printf("%d\n", stArr[i].number);
		printf("%s\n", stArr[i].name);
		printf("%lf\n", stArr[i].grade);
		printf("\n");
	}

	printf("swapStudentInfo\n");
	swapStudentInfo(stArr[0], stArr[1]);
	for (i = 0; i < 3; i++) {
		printf("%d\n", stArr[i].number);
		printf("%s\n", stArr[i].name);
		printf("%lf\n", stArr[i].grade);
		printf("\n");
	}
	printf("SwapStudentInfo\n");
	SwapStudentInfo(&stArr[0], &stArr[1]);
	for (i = 0; i < 3; i++) {
		printf("%d\n", stArr[i].number);
		printf("%s\n", stArr[i].name);
		printf("%lf\n", stArr[i].grade);
		printf("\n");
	}
	printf("SwapStudentInfoREF\n");
	SwapStudentInfoREF(stArr[0], stArr[1]);
	for (i = 0; i < 3; i++) {
		printf("%d\n", stArr[i].number);
		printf("%s\n", stArr[i].name);
		printf("%lf\n", stArr[i].grade);
		printf("\n");
	}
}
void Pstruct(void) {
	//����ü ���� ����(����ü Ȱ��)
	//����ü ������ ����, ������ ������ ������ ���� (�迭, ��������, ��������, ������ ����)
	//���� ���� ȣ��, ������ ���� ȣ��
	struct student s;

	struct student* stPtr = &s; //(c++���� struct �� ���� �� �� �ִ�.)

	printf("�й��� �Է��ϼ���: ");
	scanf("%d", &s.number);
	printf("�̸��� �Է��ϼ���: ");
	scanf("%s", s.name);
	printf("������ �Է��ϼ���(�Ǽ�): ");
	scanf("%lf", &s.grade);

	printf("ScanStruct\n");
	printf("�й�: %d\n", s.number);
	printf("�̸�: %s\n", s.name);
	printf("����: %lf\n", s.grade);
	printf("\n");

	printf("PointStruct\n");
	printf("%d \n", stPtr->number);
	printf("%s \n", stPtr->name);
	printf("%lf \n", stPtr->grade);
	printf("\n");
}

int main(void) {
	
	Pstruct();
	swapstruct();
}