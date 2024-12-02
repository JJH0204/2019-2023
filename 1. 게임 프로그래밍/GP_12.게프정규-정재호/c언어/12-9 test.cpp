#include <stdio.h>
void POINTEREX(void) {
	int * pData = NULL; //포인터변수 주소값을 저장
	int nData = 2000; //data를 저장
	pData = &nData; //data가 저장된 변수의 주소값을 포인터 변수에 저장
	printf("1.\n");
	printf("Data(%p): %d\n", &nData, nData);
	printf("pData(%p): %p -> %d\n", &pData, pData, *pData);
	//*pData 저장된 주소값에 해당하는 메모리에 접근해 data를 반환
	nData = 100;

	printf("2.\n");
	printf("Data(%p): %d\n", &nData, nData);
	printf("pData(%p): %p -> %d\n", &pData, pData, *pData);

	*pData=7000;
	//*pData 저장된 주소값에 해당하는 메모리에 접근해 data를 변환
	printf("3.\n");
	printf("Data(%p): %d\n", &nData, nData);
	printf("pData(%p): %p -> %d\n", &pData, pData, *pData);

	int nData2 = 20;
	pData = &nData2;

	printf("4.\n");
	printf("Data2(%p): %d\n", &nData2, nData2);
	printf("pData(%p): %p -> %d\n", &pData, pData, *pData);
	//pData 변수로 접근하는 변수를 바꿀 수 있다. 다른 변수의 주소를 저장하는 것으로
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
		printf("ptr+%d=%d\n", x, *(ptr + x)); //포인터에서 + 1을 하면 + 자료형 만큼 주소값이 증가 한다.
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
	// 매개변수에 값을 전달하는 것 뿐, 원래 값에 변화를 주지 못함
}

//포인터를 이용한 call-by-reference (흉내)
void swapb(int * x, int * y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	printf("swapb: x=%d, y=%d \n", *x, *y);
	//매개변수에 주소값을 전달해 원래 값을 변경할 수 있도록 함
}

//참조자를 사용(c++ 문법)call-by-reference
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
	printf("swap(Call-by-value) : x = %d, y=%d\n", x, y); //변화 x
	swapb(&x, &y);
	printf("swap(Call-by-reference) : x = %d, y=%d\n", x, y); //변화 o
	SwapRef(x, y);
}

int main(void) {
	//POINTEREX();
	//PointWArray();
	exSwap(); //call_by_value, call_by_reference 예제
	return 0;
}