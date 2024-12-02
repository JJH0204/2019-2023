#include <stdio.h>
#include <limits.h>

int main(void) {
	char num1 = CHAR_MAX + 1;
	short num2 = SHRT_MAX + 1; 
	int num3 = INT_MAX + 1; 
	long long num4 = LLONG_MAX + 1;
	
	unsigned char num5 = UCHAR_MAX + 1;
	unsigned int num6 = UINT_MAX + 1; 
	unsigned long num7 = ULONG_MAX + 1;
	
	printf("%d %d %d %lld \n", num1, num2, num3, num4);

	printf("%u %u %lu", num5, num6, num7);
	//unsigned char, unsigned short, unsigned int : %u
	//unsigned long : %lu
	//unsigned long long : %llu

	return 0;
}