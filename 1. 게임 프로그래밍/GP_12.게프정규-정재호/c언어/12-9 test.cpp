#include <stdio.h>
void POINTEREX(void) {
	int * pData = NULL; //�����ͺ��� �ּҰ��� ����
	int nData = 2000; //data�� ����
	pData = &nData; //data�� ����� ������ �ּҰ��� ������ ������ ����
	printf("1.\n");
	printf("Data(%p): %d\n", &nData, nData);
	printf("pData(%p): %p -> %d\n", &pData, pData, *pData);
	//*pData ����� �ּҰ��� �ش��ϴ� �޸𸮿� ������ data�� ��ȯ
	nData = 100;

	printf("2.\n");
	printf("Data(%p): %d\n", &nData, nData);
	printf("pData(%p): %p -> %d\n", &pData, pData, *pData);

	*pData=7000;
	//*pData ����� �ּҰ��� �ش��ϴ� �޸𸮿� ������ data�� ��ȯ
	printf("3.\n");
	printf("Data(%p): %d\n", &nData, nData);
	printf("pData(%p): %p -> %d\n", &pData, pData, *pData);

	int nData2 = 20;
	pData = &nData2;

	printf("4.\n");
	printf("Data2(%p): %d\n", &nData2, nData2);
	printf("pData(%p): %p -> %d\n", &pData, pData, *pData);
	//pData ������ �����ϴ� ������ �ٲ� �� �ִ�. �ٸ� ������ �ּҸ� �����ϴ� ������
}
void arrVal(int arr[], int size) {
	int x;
	printf("\nArrVal\n");
	for (x = 0; x < size; x++) {
		printf("Arr[%d]=%d\n", x, arr[x]);
		printf("arr: %p\n", &arr[x]);
	}
}

void PointVal(int * ptr, int size) {
	int x;
	printf("\nPointVal\n");
	for (x = 0; x < size; x++) {
		printf("ptr+%d=%d\n", x, *(ptr + x)); //�����Ϳ��� + 1�� �ϸ� + �ڷ��� ��ŭ �ּҰ��� ���� �Ѵ�.
		printf("ptr: %p\n", ptr + x);
	}
}

void PointWArray(void) {
	int nArray[] = { 7,5,4,6,2,3,1,0 };
	int * pArray = NULL;
	pArray = nArray;
	int x;
	for (x = 0; x < 8; x++) {
		printf("%d. Array: %2d  Point: %2d\n", x+1, nArray[x], *(pArray + x));
		printf("%d. Array: %p  point: %p\n", x + 1, &nArray[x], pArray + x);
	}
	arrVal(nArray, sizeof(nArray) / sizeof(nArray[0]));
	
	PointVal(nArray, sizeof(nArray) / sizeof(nArray[0]));
}

void swapa(int x, int y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
	printf("swapa: x=%d, y=%d\n", x, y); 
	// �Ű������� ���� �����ϴ� �� ��, ���� ���� ��ȭ�� ���� ����
}

//�����͸� �̿��� call-by-reference (�䳻)
void swapb(int * x, int * y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	printf("swapb: x=%d, y=%d \n", *x, *y);
	//�Ű������� �ּҰ��� ������ ���� ���� ������ �� �ֵ��� ��
}

//�����ڸ� ���(c++ ����)call-by-reference
void SwapRef(int & a, int & b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void exSwap(void) {
	int x = 100;
	int y = 70;
	printf("not swap: x=%d, y=%d\n", x, y);
	swapa(x, y);
	printf("swap(Call-by-value) : x = %d, y=%d\n", x, y); //��ȭ x
	swapb(&x, &y);
	printf("swap(Call-by-reference) : x = %d, y=%d\n", x, y); //��ȭ o
	SwapRef(x, y);
}

int main(void) {
	//POINTEREX();
	//PointWArray();
	exSwap(); //call_by_value, call_by_reference ����
	return 0;
}