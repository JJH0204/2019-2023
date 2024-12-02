#include <stdio.h>
#include <stdlib.h>

//구조체 선언 : (설계도)
struct student {
	//구조체에 소속된 변수(멤버)
	int number;
	char name[10];
	double grade;
};
//call-by-value
void swapStudentInfo(student a, student b) {
	student temp = {};
	temp = a;
	a = b;
	b = temp;
}
//call-by-reference
void SwapStudentInfo(student* a, student* b) {
	student temp = {};
	temp = *a;
	*a = *b;
	*b = temp;
}
//참조자call-by-reference
void SwapStudentInfoREF(student& a, student& b) { //c++의 참조자를 활용
	student temp = {};
	temp = a;
	a = b;
	b = temp;
}

void swapstruct(void) {
	struct student stArr[3] = { {19, "jung", 3.0}, {17, "ho", 2.8}, {18, "jae", 4.0} };
	int i;
	printf("ArrayStruct\n");
	for (i = 0; i < 3; i++) {
		printf("%d\n", stArr[i].number);
		printf("%s\n", stArr[i].name);
		printf("%lf\n", stArr[i].grade);
		printf("\n");
	}

	printf("swapStudentInfo\n");
	swapStudentInfo(stArr[0], stArr[1]);
	for (i = 0; i < 3; i++) {
		printf("%d\n", stArr[i].number);
		printf("%s\n", stArr[i].name);
		printf("%lf\n", stArr[i].grade);
		printf("\n");
	}
	printf("SwapStudentInfo\n");
	SwapStudentInfo(&stArr[0], &stArr[1]);
	for (i = 0; i < 3; i++) {
		printf("%d\n", stArr[i].number);
		printf("%s\n", stArr[i].name);
		printf("%lf\n", stArr[i].grade);
		printf("\n");
	}
	printf("SwapStudentInfoREF\n");
	SwapStudentInfoREF(stArr[0], stArr[1]);
	for (i = 0; i < 3; i++) {
		printf("%d\n", stArr[i].number);
		printf("%s\n", stArr[i].name);
		printf("%lf\n", stArr[i].grade);
		printf("\n");
	}
}
void Pstruct(void) {
	//구조체 변수 선언(구조체 활용)
	//구조체 변수도 변수, 변수가 가능한 모든것이 가능 (배열, 지역변수, 전역변수, 포인터 변수)
	//값에 의한 호출, 참조에 의한 호출
	struct student s;

	struct student* stPtr = &s; //(c++에서 struct 를 제외 할 수 있다.)

	printf("학번을 입력하세요: ");
	scanf("%d", &s.number);
	printf("이름을 입력하세요: ");
	scanf("%s", s.name);
	printf("학점을 입력하세요(실수): ");
	scanf("%lf", &s.grade);

	printf("ScanStruct\n");
	printf("학번: %d\n", s.number);
	printf("이름: %s\n", s.name);
	printf("학점: %lf\n", s.grade);
	printf("\n");

	printf("PointStruct\n");
	printf("%d \n", stPtr->number);
	printf("%s \n", stPtr->name);
	printf("%lf \n", stPtr->grade);
	printf("\n");
}

int main(void) {
	
	Pstruct();
	swapstruct();
}