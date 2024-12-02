#include <stdio.h>

/* //변수 예제 복습
빛의 속도는 1초에 30만 km 이동
태양과 지구 사이의 거리는 약 1억 4960만km
빛이 태양에서 지구까지 오는데 얼마나 걸릴까?>\
*/
//변수: data 저장
//변수의 종류: 실수형, 정수형
//정수형: int, short, char, long
//실수형: float, double
//나누기를 통해 몫과 나머지를 구하려면 int형으로 
//실수를 구하기 위해서는 float형으로
//나눌때 정확한 정수형이 아닐것을 대비해 평소에 나누기 연산은 실수로 한다.
void space() {

	unsigned int Sun = 149600000; //지구에서 태양까지 거리
	int KM = 300000; //1초에 이동하는 거리
	int sec = Sun / KM;
	printf("빛이 태양에서 지구까지 오는데 걸리는 시간: %d 분 %d 초\n", sec / 60, sec % 60);
	return;
}

//중감 연산자 예제
void Increase() {
	int x=1, y=1;
	int nextX = ++x, nextY = y++;
	printf("x: %d y: %d \n", x, y);
	printf("nextX: %d nextY: %d", nextX, nextY);
	return;
}

//명시적 형변환
void Trans() {
	int nData;
	float fData;
	fData = 5 / 4;	//1
	printf("(i/i)fData: %f\n", fData);
	fData = (float)5 / 4;	//1.25
	printf("(f/i)fData: %f\n", fData);
	fData = 5 / (float)4;	//1.25
	printf("(i/f)fData: %f\n", fData);
	fData = (float)5 / (float)4;	//1.25
	printf("(f/f)fData: %f\n", fData);
	//실수로 계산할때는 한쪽만 실수라도 실수가 된다. 
	//실수형을 정수형으로 변환하면 소숫점 뒷자리가 짤린다.
	nData = 1.3 + 1.8;//3
	printf("(f+f)nData: %d\n", nData);
	nData = (int)1.3 + 1.8;//2
	printf("(i+f)nData: %d\n", nData);
	nData = 1.3 + (int)1.8;//2
	printf("(f+i)nData: %d\n", nData);
	nData = (int)1.3 + (int)1.8;//2
	printf("(i+i)nData: %d\n", nData);

	return;
}
//관계연산자
void Relation() {
	int x, y;
	printf("두개의 정수를 입력하시오\n");
	scanf("%d %d", &x, &y);

	printf("x==y 결과: %d \n", x == y);
	printf("x!=y 결과: %d \n", x != y);
	printf("x>y 결과: %d \n", x > y);
	printf("x<y 결과: %d \n", x < y);
	printf("x<=y 결과: %d \n", x <= y);
	printf("x>=y 결과: %d \n", x >= y);

	return;
}
//참: 1
//거짓: 0
//무주택기간과 가구주연령, 가족수를 입력받아, 입대 조건이 맞는지 확인
//맞으면, 입주가능, 틀리면 입주불가
//무주택 기간 3년이상, 가구주의 연령이 40세 이상,  가족의 수 가 3명이상일경우 참
void LantHouse() {
	int noHouse;
	int Family;
	int olderYear;
	
	printf("무주택기간: ");
	scanf("%d", &noHouse);
	printf("가구주연령: ");
	scanf("%d", &olderYear);
	printf("가족수: ");
	scanf("%d", &Family);
	
	if((noHouse >= 3) && (Family >= 3) && (olderYear >= 40)) printf("입주가능");
	else printf("입주불가");
	
	return;
}
void BitOper() {
	int z=9, x=10;
	printf("z=%d, x=%d\n", z, x);
	printf("비트 AND: %08X\n비트 OR: %08X\n비트 XOR: %08X\nz값 비트 NOT: %08X\n",z&x, z|x, z^x, ~z);
	return;
}

void Shiftoper() {
	int x = 4;
	printf("Data: %#08x\n", x);
	printf("비트 << = %#08x\n", x << 1);
	printf("비트 >> = %#08x\n", x >> 1);

	return;
}

void Color() {
	unsigned int color = 0x00389999;
	unsigned int result;

	printf("픽셀의 색상 : %#08x \n", color);
	result = color & 0x00ff0000; //ff 영역만 남기겠다는 의미
	printf("마스크 연산 후 : %#08x \n", result);
	result = result >> 16;
	printf("최종 결과값 : %#08x \n", result);
	return;
}

int main(void) {
	//space();
	//Increase();
	//Trans();
	//Relation();
	//LantHouse();
	//BitOper();
	//Shiftoper();
	Color();

	return 0;
}