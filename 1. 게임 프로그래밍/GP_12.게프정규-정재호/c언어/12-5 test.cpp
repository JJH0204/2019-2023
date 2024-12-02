#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define GAUS(x) (((x)*(x)+(x))/2) //메크로 함수 만듬

void Meter(void) {
	int meter;
	int mile=0;

	/*meter = 0 * 1609;
	printf("0마일은 %d미터입니다\n", meter);

	meter = 1 * 1609;
	printf("1마일은 %d미터입니다\n", meter);
	
	meter = 2 * 1609;
	printf("2마일은 %d미터입니다\n", meter);*/
	while (mile < 3) {
		meter = mile * 1609;
		printf("%d마일은 %d미터입니다\n", mile, meter);
		mile++;
	}
}
//1부터 n까지 합을 계산하는 프로그램
//n이 무엇이 될지 모르는 경우라면 다음과 값이 계산
//빈통, 통에 1부터 n까지 넣는다. 통에 들어 있는 동전의 개수를 출력한다.
void counting(void) {
	int sum, count, iN;
	printf("정수 입력: ");
	scanf("%d", &iN);

	count = 1;
	sum = count++;


	while (count <= iN) {
		sum += count;
		count++;
	}
	printf("덧셈 결과: %d", sum);
	return;
}
// 1부터 입력되는 수 까지 값의 합을 출력하는 코드를 작성해라 
// 정수 값이 입력되고 그 값까지 1부터 1씩 증가하는 모든 값들을 더해야 한다.
void Fcounting(void) {
	int iScan, total, count;
	printf("정수 입력: ");
	scanf("%d", &iScan);
	count = 1;
	total = count++;
	while (count <= iScan)
		total += count++;
	printf("결과: %d", total);
	return;
}

//가우스의 정리를 활용
//1+2+3+.....+99+100 = (1+100)*(100/2) = 5050
void GausCounting(void) {
	int iScan, total;
	printf("정수 입력: ");
	scanf("%d", &iScan);
	//total = (iScan + 1)*(iScan / 2);
	//total=(iScan*iScan)/2 +(iScan/2);
	//total = (iScan*iScan + iScan) / 2;
	total= GAUS(iScan);
	printf("결과: %d", total);
	return;
}

//평균 = 전체 값을 모두 더한 후에 그 값의 갯수로 나눈 결과
//사용자로부터 값을 입력 받는다. (사용자가 특정 키를 입력하면 입력 받는 것을 종료
//사용자가 마지막에 입력한 값까지 모두 더하고 그 갯수만큼 나눈다.
void average(void) {
	int count=0, iScan=0;
	float total=0.0f;

	printf("-1를 입력하면 결과 출력\n");
	do {
		total += (float)iScan;
		printf("%d번째 입력: ", ++count);
		scanf("%d", &iScan);
	} while (iScan!=-1);
	count--;
	total /= count; 
	printf("평균: %f", total);
	return;
}

//반감기: 물질의양이 반으로 줄어드는 시간
//방사능물질의 양이 1/10이하량이 되는데 (몇년:int year)이 걸리는가?
// -> 물질의 양이 10%로 감소하는데 걸리는 시간
//물질의 반감기: 400년 //(const int halflife)
//물질량: 100 (float value)
////문제가 있는 프로그램을 실행해보고,
////변수들이 어떻게 바뀌는 지 일일히 확인해서,
////문제가되는 코드들을 조금씩 바꿔나가면서 코드짜기
void HalfLifeMain()
{
	const int halflife = 400;
	float value = 100.0f;
	const float TenPValue = value * 0.1f;
	int LifeYear = 0;

	while (value >= TenPValue) {
		LifeYear += halflife;
		value *= 0.5;
		printf("%d년뒤 물질의 양 %f\n", LifeYear, value);
	}
	printf("반감기로 인해 물질의 양이 1/10이하가 된 년도: %d\n물질의 양: %f\n", LifeYear, value);
}

//세균은 10마리를 배양하고 세균수가 100마리 이상이 되는 시간은?
//세균은 1시간마다 2배씩 증가한다.
void BateriaMain()
{
	int Germ = 10;
	const int MaxGerm = 100;
	const int GermTime = 1;
	int Time = 0;
	while (Germ <= MaxGerm) {
		Time += GermTime;
		Germ *= 2;
	}
	printf("세균수가 100마리를 넘어 %d가 되는데 걸리는 시간: %d", Germ, Time);
}

//종이를 접으면 면적이 1/2로 줄어들때,
//종이면적이 1/10이하로 줄어들려면, 몇번접아야하는가?
void PaperAreaMain()
{
	float MyPaper ;
	int FoldCount = 0;
	printf("종이 면적: ");
	scanf("%f", &MyPaper);
	float Paper = MyPaper;
	while (MyPaper > Paper/10) {
		FoldCount++;
		MyPaper /= 2;
	}
	printf("종이 면적이 10분의 1로 줄어들는데 필요한 접기 횟수: %d\n", FoldCount);
	printf("%d번 접었을 때 종이 면적: %f", FoldCount, MyPaper);
}

//세균 10마리를 배양하여 10시간후의 세균수를 구하여라.
//이때, 세균이 1시간 마다 4배찍 증가한다
void BateriaForMain()
{
	int TimeCount;
	int Germ = 10;
	for (TimeCount=0;TimeCount < 10; TimeCount++)
		Germ *= 4;
	printf("%d시간 후 세균 수 : %d마리\n", TimeCount, Germ);
}

//종이를 10 번접으면 면적이 몇이되는가?
//이때, 종이의 면적 100이라고하자.
//(종이면적은 반으로줄어든다)
void PaperForMain()
{
	float MyPaper=100;
	int FoldCount;
	int count = 10;
	for (FoldCount = 0; FoldCount < count;FoldCount++)
		MyPaper /= 2;
	
	printf("%d번 접었을 때 종이 면적: %f", FoldCount, MyPaper);
}

//반감기: 방사능물질의양이 1/2가 되는 시간
//방사능 물질의 양이 2000년이 지난후 물질의 양은?
//반감기:400년
//방사능물질의양: 100
void HalfLifeForMain()
{
	const int halflife = 400;
	float value = 100.0f;
	float HalfValue = value / 2;
	int LifeYear = 0;

	for (;value>HalfValue;LifeYear+=halflife) {
		printf("%d년뒤 물질의 양 %f\n", LifeYear, value);
		value /= 2;
	}
	printf("반감기로 인해 물질의 양이 1/2 된 년도: %d\n물질의 양: %f\n", LifeYear, value);
}

//업다운게임: 
//숫자를 제시하면 그 숫자가 정해진수 보다 작으면, down 크면 up 맞추면 끝.
void UpDownGameMain()
{
	srand(time(NULL));
	const int NUMBER = rand()%101+1;
	int UserNum = 0;
	int count=0;
	printf("UP & DOWN GAME~~~~~\n이게임은 1~100까지 수를 랜덤으로 하나 골라 맞추는 게임입니다.\n만약 정답보다 작으면 UP을 크다면 DOWN을 출력합니다.\n입력횟수가 작으면 작을 수록 좋습니다.##############################\n값을 입력하시면 됩니다.\n");
	while (UserNum != NUMBER) {
		printf("%d번째 입력: ", count+1);
		scanf("%d", &UserNum);
		if (UserNum != NUMBER) {
			printf("땡 틀렸습니다.~~~\n");
			if (UserNum > NUMBER) {
				printf("DOWN~\n");
			}
			else {
				printf("UP!!\n");
			}
		}
		count++;
	}
	printf("%d번의 시도 끝에 정답 %d를 맞추셨습니다.\n", count, NUMBER);
	return;
}

int main(void) {
	//Meter();
	//counting();
	//Fcounting();
	//GausCounting();
	//average();
	//HalfLifeMain();
	//BateriaMain();
	//PaperAreaMain();
	//BateriaForMain();
	//PaperForMain();
	//HalfLifeForMain();
	UpDownGameMain();
	return 0;
}