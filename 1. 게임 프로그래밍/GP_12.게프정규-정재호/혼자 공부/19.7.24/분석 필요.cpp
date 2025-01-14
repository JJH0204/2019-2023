#include <stdio.h>
#include <stdlib.h>       //srand
#include <time.h>     //time

//#define _MAX 6
const int nMAX = 6;

void BubbleSort(int* nArr, int nArrSize);

int main()
{
	//변수 생성 및 초기화 부분
	srand((unsigned)time(NULL));              //srand로 초기화

	int nLottoNum[nMAX] = { 0, };               //생성된 로또 번호를 저장할 변수
	bool bCheckExistOfNum[45] = { false, };     //생성된 번호가 중복인지 체크할 변수(인덱스)

	//번호 생성 부분
	for (int i = 0; i < nMAX; )                    //번호가 6개 생성될 때까지 돈다.
	{
		int nTemp = rand() % 45;                  //0~44 범위의 번호를 생성한다.

		if (bCheckExistOfNum[nTemp] == false)  //중복 여부 판단
		{
			bCheckExistOfNum[nTemp] = true;     //번호가 중복 생성되지 않게 존재 여부를 true로 한다.
			nLottoNum[i] = nTemp + 1;             //+1을 안해주면 범위가 0~44이다.
			++i;                                //증감 연산을 for문에서 하지 않고 여기서 한다.
		}
	}

	//버블 정렬
	BubbleSort(nLottoNum, sizeof(nLottoNum) / sizeof(int));

	//출력 부분
	for (int i = 0; i < nMAX; ++i)
	{
		printf("%2d ", nLottoNum[i]);
	}

	return 0;
}

void BubbleSort(int* nArr, int nArrSize)
{
	for (int i = 0; i < nArrSize - 1; i++)
	{
		for (int j = 0; j < nArrSize - (i + 1); j++)
		{
			if (nArr[j] > nArr[j + 1])    //꺽쇠 방향으로 오름 차순, 내름 차순 결정
			{//값 교환 부분
				int temp = nArr[j];
				nArr[j] = nArr[j + 1];
				nArr[j + 1] = temp;
			}
		}
	}
}
