#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define GAUS(x) (((x)*(x)+(x))/2) //��ũ�� �Լ� ����

void Meter(void) {
	int meter;
	int mile=0;

	/*meter = 0 * 1609;
	printf("0������ %d�����Դϴ�\n", meter);

	meter = 1 * 1609;
	printf("1������ %d�����Դϴ�\n", meter);
	
	meter = 2 * 1609;
	printf("2������ %d�����Դϴ�\n", meter);*/
	while (mile < 3) {
		meter = mile * 1609;
		printf("%d������ %d�����Դϴ�\n", mile, meter);
		mile++;
	}
}
//1���� n���� ���� ����ϴ� ���α׷�
//n�� ������ ���� �𸣴� ����� ������ ���� ���
//����, �뿡 1���� n���� �ִ´�. �뿡 ��� �ִ� ������ ������ ����Ѵ�.
void counting(void) {
	int sum, count, iN;
	printf("���� �Է�: ");
	scanf("%d", &iN);

	count = 1;
	sum = count++;


	while (count <= iN) {
		sum += count;
		count++;
	}
	printf("���� ���: %d", sum);
	return;
}
// 1���� �ԷµǴ� �� ���� ���� ���� ����ϴ� �ڵ带 �ۼ��ض� 
// ���� ���� �Էµǰ� �� ������ 1���� 1�� �����ϴ� ��� ������ ���ؾ� �Ѵ�.
void Fcounting(void) {
	int iScan, total, count;
	printf("���� �Է�: ");
	scanf("%d", &iScan);
	count = 1;
	total = count++;
	while (count <= iScan)
		total += count++;
	printf("���: %d", total);
	return;
}

//���콺�� ������ Ȱ��
//1+2+3+.....+99+100 = (1+100)*(100/2) = 5050
void GausCounting(void) {
	int iScan, total;
	printf("���� �Է�: ");
	scanf("%d", &iScan);
	//total = (iScan + 1)*(iScan / 2);
	//total=(iScan*iScan)/2 +(iScan/2);
	//total = (iScan*iScan + iScan) / 2;
	total= GAUS(iScan);
	printf("���: %d", total);
	return;
}

//��� = ��ü ���� ��� ���� �Ŀ� �� ���� ������ ���� ���
//����ڷκ��� ���� �Է� �޴´�. (����ڰ� Ư�� Ű�� �Է��ϸ� �Է� �޴� ���� ����
//����ڰ� �������� �Է��� ������ ��� ���ϰ� �� ������ŭ ������.
void average(void) {
	int count=0, iScan=0;
	float total=0.0f;

	printf("-1�� �Է��ϸ� ��� ���\n");
	do {
		total += (float)iScan;
		printf("%d��° �Է�: ", ++count);
		scanf("%d", &iScan);
	} while (iScan!=-1);
	count--;
	total /= count; 
	printf("���: %f", total);
	return;
}

//�ݰ���: �����Ǿ��� ������ �پ��� �ð�
//���ɹ����� ���� 1/10���Ϸ��� �Ǵµ� (���:int year)�� �ɸ��°�?
// -> ������ ���� 10%�� �����ϴµ� �ɸ��� �ð�
//������ �ݰ���: 400�� //(const int halflife)
//������: 100 (float value)
////������ �ִ� ���α׷��� �����غ���,
////�������� ��� �ٲ�� �� ������ Ȯ���ؼ�,
////�������Ǵ� �ڵ���� ���ݾ� �ٲ㳪���鼭 �ڵ�¥��
void HalfLifeMain()
{
	const int halflife = 400;
	float value = 100.0f;
	const float TenPValue = value * 0.1f;
	int LifeYear = 0;

	while (value >= TenPValue) {
		LifeYear += halflife;
		value *= 0.5;
		printf("%d��� ������ �� %f\n", LifeYear, value);
	}
	printf("�ݰ���� ���� ������ ���� 1/10���ϰ� �� �⵵: %d\n������ ��: %f\n", LifeYear, value);
}

//������ 10������ ����ϰ� ���ռ��� 100���� �̻��� �Ǵ� �ð���?
//������ 1�ð����� 2�辿 �����Ѵ�.
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
	printf("���ռ��� 100������ �Ѿ� %d�� �Ǵµ� �ɸ��� �ð�: %d", Germ, Time);
}

//���̸� ������ ������ 1/2�� �پ�鶧,
//���̸����� 1/10���Ϸ� �پ�����, ������ƾ��ϴ°�?
void PaperAreaMain()
{
	float MyPaper ;
	int FoldCount = 0;
	printf("���� ����: ");
	scanf("%f", &MyPaper);
	float Paper = MyPaper;
	while (MyPaper > Paper/10) {
		FoldCount++;
		MyPaper /= 2;
	}
	printf("���� ������ 10���� 1�� �پ��µ� �ʿ��� ���� Ƚ��: %d\n", FoldCount);
	printf("%d�� ������ �� ���� ����: %f", FoldCount, MyPaper);
}

//���� 10������ ����Ͽ� 10�ð����� ���ռ��� ���Ͽ���.
//�̶�, ������ 1�ð� ���� 4���� �����Ѵ�
void BateriaForMain()
{
	int TimeCount;
	int Germ = 10;
	for (TimeCount=0;TimeCount < 10; TimeCount++)
		Germ *= 4;
	printf("%d�ð� �� ���� �� : %d����\n", TimeCount, Germ);
}

//���̸� 10 �������� ������ ���̵Ǵ°�?
//�̶�, ������ ���� 100�̶������.
//(���̸����� �������پ���)
void PaperForMain()
{
	float MyPaper=100;
	int FoldCount;
	int count = 10;
	for (FoldCount = 0; FoldCount < count;FoldCount++)
		MyPaper /= 2;
	
	printf("%d�� ������ �� ���� ����: %f", FoldCount, MyPaper);
}

//�ݰ���: ���ɹ����Ǿ��� 1/2�� �Ǵ� �ð�
//���� ������ ���� 2000���� ������ ������ ����?
//�ݰ���:400��
//���ɹ����Ǿ�: 100
void HalfLifeForMain()
{
	const int halflife = 400;
	float value = 100.0f;
	float HalfValue = value / 2;
	int LifeYear = 0;

	for (;value>HalfValue;LifeYear+=halflife) {
		printf("%d��� ������ �� %f\n", LifeYear, value);
		value /= 2;
	}
	printf("�ݰ���� ���� ������ ���� 1/2 �� �⵵: %d\n������ ��: %f\n", LifeYear, value);
}

//���ٿ����: 
//���ڸ� �����ϸ� �� ���ڰ� �������� ���� ������, down ũ�� up ���߸� ��.
void UpDownGameMain()
{
	srand(time(NULL));
	const int NUMBER = rand()%101+1;
	int UserNum = 0;
	int count=0;
	printf("UP & DOWN GAME~~~~~\n�̰����� 1~100���� ���� �������� �ϳ� ��� ���ߴ� �����Դϴ�.\n���� ���亸�� ������ UP�� ũ�ٸ� DOWN�� ����մϴ�.\n�Է�Ƚ���� ������ ���� ���� �����ϴ�.##############################\n���� �Է��Ͻø� �˴ϴ�.\n");
	while (UserNum != NUMBER) {
		printf("%d��° �Է�: ", count+1);
		scanf("%d", &UserNum);
		if (UserNum != NUMBER) {
			printf("�� Ʋ�Ƚ��ϴ�.~~~\n");
			if (UserNum > NUMBER) {
				printf("DOWN~\n");
			}
			else {
				printf("UP!!\n");
			}
		}
		count++;
	}
	printf("%d���� �õ� ���� ���� %d�� ���߼̽��ϴ�.\n", count, NUMBER);
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