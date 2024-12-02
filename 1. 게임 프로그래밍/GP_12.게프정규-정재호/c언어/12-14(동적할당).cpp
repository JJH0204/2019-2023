#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	int number;
	char name[10];
	float score;
};
void MallocFUNC(void) {
	int * score;
	int size = 0;
	int i;
	void* pMalloc = NULL;
	printf("할당할 배열의 크기를 입력하세요\n");
	scanf("%d", &size);
	pMalloc = malloc(size * sizeof(int));
	score = (int*)pMalloc; //int형 변수를 size크기 만큼 할당 (int형 배열 동적할당) 
	//size 값을 100을 넣는다면 400byte만큼의 크기가 메모리에 동적으로 할당함
	if (score == NULL) {
		printf("메모리 동적 할당 오류\n");
		return ;
	}
	for (i = 0; i < size; i++) {
		score[i] = i + 1;
	}
	for (i = 0; i < size; i++) {
		printf("%2d. %2d\n", i + 1, *(score+i)); //포인터 연산으로 배열에 접근하기 위해 malloc 사용시 반환형을 정해줘야함
		//(int*)로 반환한 덕에 4byte 값을 읽어 다음으로 넘어갈수 있음 (캐스팅이라고 함)
	}

	free(score); //동적 할당된 메모리 할당 해제
}

void StructMalloc(void) {
	int size=0;
	student* ArrStudent = NULL;
	student* pStudent = NULL;
	printf("할당할 배열의 크기를 입력하세요\n");
	scanf("%d", &size);
	
	ArrStudent = (student*)malloc(size * sizeof(student));
	pStudent = (student*)malloc(sizeof(student));

	for (int i = 0; i < size; i++) {
		scanf("%d", &pStudent->number);
		scanf("%s", &pStudent->name);
		scanf("%f", &pStudent->score);

		strcpy(pStudent->name , (ArrStudent + i)->name);
		(ArrStudent + i)->score = pStudent->score;
		(ArrStudent + i)->number = pStudent->number;
	}

	for (int i = 0; i < size; i++) {
		printf("%d %s %f\n", (ArrStudent + i)->number, (ArrStudent + i)->name, (ArrStudent + i)->score);
	}

	free(pStudent);
}

//정적할당<-----------------------------------------------------> 동적할당(runtime)
//코딩-> 빌드{컴파일(바이너리화)-> 링크(라이브러리사용)} -> 실행파일
//정적 할당이란 컴파일러가 변수의 생성과 삭제시기를 지정. 빌드 과정에서 생성, 삭제지점 확정
//동적할당은 프로그래머가 변수의 생성과 삭제시기를 지정. 런타임에서 생성, 삭제 가능
//변수의 이름은 코딩하면서 컴파일러가 확정함 동적할당된 메모리는 이름이 없음으로 주소값으로만 접근이 가능하다

//자료형*, 자료형&
//매개변수로 동적할당된 메모리를 받을때는 참조자 & 를 사용할 수 없다.
//포인터 변수가 반드시 필요한 이유

void cppdynamic(void) {
	//c++ 문법
	student* pStudent = new student;
	student* ArrStudent = new student[100];

	delete pStudent;
	delete[] ArrStudent;// 동적 할당된 배열의 삭제 방법
}


int main(void) {
//	MallocFUNC();
//	StructMalloc();
	return 0;
}