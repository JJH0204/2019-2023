#include <stdio.h>

void InsertSort()
{
	int arrData[] = {8,1,7,4,2,3,9,5,6};
	int temp;
	int i, j;
	for (j = 0; j < 9; j++) {
		for (i = 1; i < 9; i++) {
			if (arrData[i - 1] > arrData[i]) {
				temp = arrData[i - 1];
				arrData[i - 1] = arrData[i];
				arrData[i] = temp;
			}
		}
	}
	
	printf("Data:");
	for (int i = 0; i < 9; i++)
		printf("%d,", arrData[i]);
	printf("\n");
}

void main()
{
	InsertSort();
}