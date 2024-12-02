#include <stdio.h>
#define SIZE 5

void Arr(void) {
	int i;
	//�迭 �ʱ�ȭ {}�ȿ� �ʱⰪ ����
	int arr[SIZE] = { 1,2,3,4,5 }; //{}�ȿ� �ƹ� �͵� ���� ������ 0���� ��� �ʱ�ȭ
	//	�ڷ��� �迭�̸�[����] = {�ʱⰪ}; // �ʱⰪ ������ �����Ⱚ ����

	//int nSize = 5;
	//int arr[nSize]; //����
	//��ó������ �޸� ������ ����� �Ҵ������� ������ �����ϸ� 
	//���� �߿� (runtime)���� ������ ����Ǹ� ���� �˼� ���� ������ ������ �ε��� ������ �ϴ� 
	//�迭 ������ ���� �Ǿ� �ִ�.
	//�ٸ� const������ �����ϸ� ������ �ε��� ������ �ϴ� �迭 ������ �����ϴ�
	//��, �迭 ������ ����� �����ϴ�



	printf("1.\n");
	for (i = 0; i < 5; i++) {
		printf("[%d]%d\n", i + 1, arr[i]);
	}

	for (i = 0; i < 5; i++) { //�����δ� ������ ���� �Է��� �޴´�.
		arr[i] = (i + 1) * 10;
	}
	//arr[5]=10; arr[-1]=2; // ���� (���� ���� ����Ǿ� �ִ��� ��)
	printf("2.\n");
	for (i = 0; i < 5; i++) {
		printf("[%d]%d\n", i + 1, arr[i]);
	}
	printf("arr count: %d\n", sizeof(arr) / sizeof(arr[0]));
	printf("arr size: %d\n", sizeof(arr));
	printf("adress arr: %p\n", &arr); //�迭�̸��� �迭�� ù ���ڸ� ����Ű�� ����� ������
	for (i = 0; i < 5; i++) {
		printf("adress arr[%d]: %p\n", i, &arr[i]);
	}
	int arrsize[5];
	//arrsize=arr ����
	//�迭�̸��� ���� �����ϴ� ������ �ƴ϶�
	//�迭�� ���� ��ġ (ù��° ����)�� �ּ� ���� �����ϰ� �ִ� �������̴�.(�����)
	//����� �������̱⶧���� �ּҰ��� �������� ���ϰ� �����ϴ��� �� �̸��� ����Ű�� �޸� ������ �ϳ��� �ȴ�.
	for (i = 0; i < 5; i++) { //���� ���
		arrsize[i] = arr[i];
	}

}
void miniVal(void) {
	int arr[5] = { 7,8,5,3,1 };
	int i, result=arr[0];
	for (i = 1; i < 5; i++) {
		if (result > arr[i]) {
			result = arr[i];
		}
	}
	printf(" mini val : %d\n", result);
}

void InitArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (i + 1);
	}
}

void PrintArray(const int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("[%d]%d", i, arr[i]);
	}
	printf("\n");
}
void SetArray(void) {
	int arr[SIZE];
	InitArray(arr, SIZE);
	PrintArray(arr, SIZE);
}

#define H 3
#define W 2

void Array2(void) {
	int x, y;
	int array[H][W];
	for (y = 0; y < H; y++) {
		for (x = 0; x < W; x++) {
			array[y][x] = y * x + 1;
		}
	}
	for (y = 0; y < H; y++) {
		for (x = 0; x < W; x++) {
			printf("[%d][%d]%d ", y, x, array[y][x]);
		}
		printf("\n");
	}
}


int main(void) {
	//Arr();
	/*miniVal();
	SetArray();*/
	Array2();
	return 0;
}