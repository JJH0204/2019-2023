#include <stdio.h>
#include <limits.h>

int main(void) {
	//각 자료형의 최솟값 저장
	char num1 = CHAR_MIN;
	short num2 = SHRT_MIN;
	int num3 = INT_MIN;
	long num4 = LONG_MIN;
	long long num5 = LLONG_MIN;

	printf("%d %d %d %ld %lld", num1, num2, num3, num4, num5);
	//char, short, int : %d 
	//long : %ld
	//long long : %lld

	return 0;
}