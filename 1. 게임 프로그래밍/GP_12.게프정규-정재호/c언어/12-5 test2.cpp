#include <stdio.h>

void Rect(void) {
	int i;
	for (i = 0; i < 5; i++) {
		if (i % 2 == 1) {
			printf("* * *\n");
		}
		else {
			printf("*****\n");
		}
	}
}

void Rect2(void) {
	int x, y;
	for (y = 0; y < 5; y++) {
		for (x = 0; x < 5; x++) {
			printf("* ");
		}
		printf("\n");
	}
}

void Window(void) {

		int x, y;
		for (y = 0; y < 5; y++) {
			for (x = 0; x < 5; x++) {
				if (x % 2 == 1 && y % 2 == 1) printf("  ");
				else printf("* ");
			}
			printf("\n");
		}

}

void worldChaing(void) {
	char a;
	while (1) {
		printf("INPUT : ");
		scanf("%c", &a);
		printf("OUTPUT: %c", a + 32);
	}
}
//break; continue; 무한 루프

int main(void) {
	//Rect();
	//Rect2();
	//Window();
	worldChaing();
	return 0;
}