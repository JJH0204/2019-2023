#include <stdio.h>
//변수 n값이 100보다 크거나 같으면 "large", 
//100보다 작은면 "small"을 출력
//변수를 하나 할당하고 값을 입력 받는다.
//값을 비교하고 결과를 출력한다
void IfElse() {
	int a;
	scanf("%d", &a);
	if (a >= 100) printf("large\n");
	else printf("small\n");
	return;
}
//학점 계산기
void GradeScore() {
	int a;
	printf("당신의 점수를 입력해주세요\n:");
	scanf("%d", &a);

	if (a >= 90) printf("당신의 점수: A\n");
	else if (a >= 80) printf("당신의 점수: B\n");
	else if (a >= 70) printf("당신의 점수: C\n");
	else if (a >= 60) printf("당신의 점수: D\n");
	else if (a >= 50) printf("당신의 점수: E\n");
	else printf("당신의 점수: F\n");

	if (a >= 90) printf("정말 노력하셨군요 이대로만 하시면 과탑은 당신 것입니다!!\n");
	else if (a >= 70) printf("와우 굉장하네요 조금만 더 노력하시면 A에 도전하 실수 있겠어요~\n");
	else if (a >= 50) printf("저런.. 컨디션이 좋지 않았나요? 조금만 더 노력해보죠\n");
	else printf("학점경고 대상자입니다. 당장 공부하러 가세요!!!\n");

	return;
}

//문자를 하나 입력받는데 그것을 대문자와 소문자, 특수문자로 나눠서 종류를 나타내도록 프로그램을 작성해보아라
//아스키 코드 값은 대문자는 65~90까지이고, 소문자는 97~122, 숫자는 48~57 까지 값들이다. 
//나머지 값들은 특수문자로 생각하면 된다.
void Ascii(void) {
	char ch;

	printf("문자를 입력하세요: ");
	scanf("%c", &ch);

	if (ch >= 'A'&&ch <= 'Z') {
		printf("%c는 대문자 입니다.\n", ch);
	}
	else if (ch >= 'a'&&ch <= 'z') {
		printf("%c는 소문자 입니다.\n", ch);
	}
	else if(ch>='0'&&ch<='9'){
		printf("%c는 숫자 입니다.\n", ch);
	}
	else {
		printf("%c는 기타문자 입니다.\n", ch);
	}
	
}


//1. 사용해야하는 변수의 갯수와 타입 정수만 계산한다면 int 실수의 계산과 나눗셈을 해야한다면 실수형 결과값을 저장할 result, 연산data 2개
//2. 입력방식 생각하기 scanf로 연산 문장 받기
//3. 연산자가 다를때 어떻게 처리할까? 연산자를 조건을 나누어 표기

//입력: 5+1
//정답: 6
//입력: 6-2
//정답: 4

//계산기 만들기
void cal(void) {
	char sign;
	float fA, fB;
	printf("식: ");
	scanf("%f%c%f", &fA, &sign, &fB);
	if (sign == '+') {
		printf("정답: %.2f\n", fA + fB);
	}
	else if (sign == '-') {
		printf("정답: %.2f\n", fA - fB);
	}
	else if (sign == '*') {
		printf("정답: %.2f\n", fA * fB);
	}
	else {
		printf("정답: %.2f\n", fA / fB);
	}
	return;
}

//200ml 이상은 large, 200미만 100초과 medium, 100이하 small
void cupsize() {
	int cup;
	printf("컵 사이즈를 입력해주세요: ");
	scanf("%d", &cup);
	if (cup >= 200) {
		printf("large");
	}
	else if (cup > 100) {
		printf("Medium");
	}
	else {
		printf("small");
	}
	return;
}

//계산기 만들기
void calSwtich(void) {
	char sign;
	float fA, fB;
	printf("식: ");
	scanf("%f%c%f", &fA, &sign, &fB);
	switch (sign)
	{
	case '+':
		printf("정답: %.2f\n", fA + fB);
		break;
	case '-':
		printf("정답: %.2f\n", fA - fB);
		break;
	case '*':
		printf("정답: %.2f\n", fA * fB);
		break;
	case '/':
		printf("정답: %.2f\n", fA / fB);
		break;
	}
	return;
}

int main(void) {
	//IfElse();
	//GradeScore();
	//Ascii();
	//cal();
	//cupsize();
	calSwtich();

	return 0;
}