#include <stdio.h>
int main(void) {
	char arr[19][19];
	int a, b, c; 
	int x, y; 
	int count;
	for (a = 0; a < 19; a++) {
		for (b = 0; b < 19; b++) {
			scanf("%d", &arr[a][b]);
		}
	}
	scanf("%d", &count);
	for (c = 0; c < count; c++) {
		scanf("%d  %d", &x, &y);
		for (a = 0; a < 19; a++) {
			arr[y-1][a] = !arr[y-1][a];
		}
		for (b = 0; b < 19; b++) {
			arr[b][x-1] = !arr[b][x-1];
		}
	}

	for (a = 0; a < 19; a++) {
		for (b = 0; b < 19; b++) {
			printf("%d ", arr[a][b]);
		}
		printf("\n");
	}

	return 0;
}