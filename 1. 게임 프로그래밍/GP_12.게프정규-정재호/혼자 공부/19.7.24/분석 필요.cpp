#include <stdio.h>
#include <stdlib.h>       //srand
#include <time.h>     //time

//#define _MAX 6
const int nMAX = 6;

void BubbleSort(int* nArr, int nArrSize);

int main()
{
	//���� ���� �� �ʱ�ȭ �κ�
	srand((unsigned)time(NULL));              //srand�� �ʱ�ȭ

	int nLottoNum[nMAX] = { 0, };               //������ �ζ� ��ȣ�� ������ ����
	bool bCheckExistOfNum[45] = { false, };     //������ ��ȣ�� �ߺ����� üũ�� ����(�ε���)

	//��ȣ ���� �κ�
	for (int i = 0; i < nMAX; )                    //��ȣ�� 6�� ������ ������ ����.
	{
		int nTemp = rand() % 45;                  //0~44 ������ ��ȣ�� �����Ѵ�.

		if (bCheckExistOfNum[nTemp] == false)  //�ߺ� ���� �Ǵ�
		{
			bCheckExistOfNum[nTemp] = true;     //��ȣ�� �ߺ� �������� �ʰ� ���� ���θ� true�� �Ѵ�.
			nLottoNum[i] = nTemp + 1;             //+1�� �����ָ� ������ 0~44�̴�.
			++i;                                //���� ������ for������ ���� �ʰ� ���⼭ �Ѵ�.
		}
	}

	//���� ����
	BubbleSort(nLottoNum, sizeof(nLottoNum) / sizeof(int));

	//��� �κ�
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
			if (nArr[j] > nArr[j + 1])    //���� �������� ���� ����, ���� ���� ����
			{//�� ��ȯ �κ�
				int temp = nArr[j];
				nArr[j] = nArr[j + 1];
				nArr[j + 1] = temp;
			}
		}
	}
}
