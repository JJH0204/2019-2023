#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	int number;
	char name[10];
	float score;
};
void MallocFUNC(void) {
	int * score;
	int size = 0;
	int i;
	void* pMalloc = NULL;
	printf("�Ҵ��� �迭�� ũ�⸦ �Է��ϼ���\n");
	scanf("%d", &size);
	pMalloc = malloc(size * sizeof(int));
	score = (int*)pMalloc; //int�� ������ sizeũ�� ��ŭ �Ҵ� (int�� �迭 �����Ҵ�) 
	//size ���� 100�� �ִ´ٸ� 400byte��ŭ�� ũ�Ⱑ �޸𸮿� �������� �Ҵ���
	if (score == NULL) {
		printf("�޸� ���� �Ҵ� ����\n");
		return ;
	}
	for (i = 0; i < size; i++) {
		score[i] = i + 1;
	}
	for (i = 0; i < size; i++) {
		printf("%2d. %2d\n", i + 1, *(score+i)); //������ �������� �迭�� �����ϱ� ���� malloc ���� ��ȯ���� ���������
		//(int*)�� ��ȯ�� ���� 4byte ���� �о� �������� �Ѿ�� ���� (ĳ�����̶�� ��)
	}

	free(score); //���� �Ҵ�� �޸� �Ҵ� ����
}

void StructMalloc(void) {
	int size=0;
	student* ArrStudent = NULL;
	student* pStudent = NULL;
	printf("�Ҵ��� �迭�� ũ�⸦ �Է��ϼ���\n");
	scanf("%d", &size);
	
	ArrStudent = (student*)malloc(size * sizeof(student));
	pStudent = (student*)malloc(sizeof(student));

	for (int i = 0; i < size; i++) {
		scanf("%d", &pStudent->number);
		scanf("%s", &pStudent->name);
		scanf("%f", &pStudent->score);

		strcpy(pStudent->name , (ArrStudent + i)->name);
		(ArrStudent + i)->score = pStudent->score;
		(ArrStudent + i)->number = pStudent->number;
	}

	for (int i = 0; i < size; i++) {
		printf("%d %s %f\n", (ArrStudent + i)->number, (ArrStudent + i)->name, (ArrStudent + i)->score);
	}

	free(pStudent);
}

//�����Ҵ�<-----------------------------------------------------> �����Ҵ�(runtime)
//�ڵ�-> ����{������(���̳ʸ�ȭ)-> ��ũ(���̺귯�����)} -> ��������
//���� �Ҵ��̶� �����Ϸ��� ������ ������ �����ñ⸦ ����. ���� �������� ����, �������� Ȯ��
//�����Ҵ��� ���α׷��Ӱ� ������ ������ �����ñ⸦ ����. ��Ÿ�ӿ��� ����, ���� ����
//������ �̸��� �ڵ��ϸ鼭 �����Ϸ��� Ȯ���� �����Ҵ�� �޸𸮴� �̸��� �������� �ּҰ����θ� ������ �����ϴ�

//�ڷ���*, �ڷ���&
//�Ű������� �����Ҵ�� �޸𸮸� �������� ������ & �� ����� �� ����.
//������ ������ �ݵ�� �ʿ��� ����

void cppdynamic(void) {
	//c++ ����
	student* pStudent = new student;
	student* ArrStudent = new student[100];

	delete pStudent;
	delete[] ArrStudent;// ���� �Ҵ�� �迭�� ���� ���
}


int main(void) {
//	MallocFUNC();
//	StructMalloc();
	return 0;
}