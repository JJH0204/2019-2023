#include <stdio.h>
#include <stdint.h>

int main(void) {
	int8_t num1 = -128;  //8비트 ( 1바이트) 크기의 부호 있는 정수형 변수
	int16_t num2 = 32767; //16비트 ( 2바이트) 크기의 부호 있는 정수형 변수
	int32_t num3 = 2147483647; //32비트 ( 4바이트) 크기의 부호 있는 정수형 변수
	int64_t num4 = 9223372036854775807; //64비트 ( 8바이트) 크기의 부호 있는 정수형 변수

	uint8_t num5 = 255; //8비트 ( 1바이트) 크기의 부호 없는 정수형 변수
	uint16_t num6 = 65535; //16비트 ( 2바이트) 크기의 부호 없는 정수형 변수
	uint32_t num7 = 4294967295; //32비트 ( 4바이트) 크기의 부호 없는 정수형 변수
	uint64_t num8 = 18446744073709551615; //64비트 ( 8바이트) 크기의 부호 없는 정수형 변수

	printf("%d %d %d %lld \n", num1, num2, num3, num4);
	//int8_t, int16_t, int32_t : %d
	//int64_t : %lld;
	printf("%u %u %u %llu ", num5, num6, num7, num8);
	//uint8_t, uint16_t, uint32_t : %u
	//uint64_t : %llu
	return 0;
}