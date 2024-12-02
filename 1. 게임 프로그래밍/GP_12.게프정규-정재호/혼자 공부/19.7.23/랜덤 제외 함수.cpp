#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	int RandArr[8];
	int idx = 0;
	int count = 0;
	int RandNUM = rand() % 10 + 1;

	RandArr[0] = RandNUM;
	count = 1;

	RandNUM = rand() % 11 + 1;

	for (; count < 8; count++) {
		while (idx<8-1) {
			if (RandNUM == RandArr[idx]) {
				RandNUM = rand() % 11 + 1;
				idx = 0;
			}
			idx++;
		}
		RandArr[count] = RandNUM;
		RandNUM = rand() % 11 + 1;
		idx = 0;
	}

	for (count = 0; count < 8; count++)
		printf("%d ", RandArr[count]);

	return 0;
}