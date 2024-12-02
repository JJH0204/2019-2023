#include <stdio.h>

/* //���� ���� ����
���� �ӵ��� 1�ʿ� 30�� km �̵�
�¾�� ���� ������ �Ÿ��� �� 1�� 4960��km
���� �¾翡�� �������� ���µ� �󸶳� �ɸ���?>\
*/
//����: data ����
//������ ����: �Ǽ���, ������
//������: int, short, char, long
//�Ǽ���: float, double
//�����⸦ ���� ��� �������� ���Ϸ��� int������ 
//�Ǽ��� ���ϱ� ���ؼ��� float������
//������ ��Ȯ�� �������� �ƴҰ��� ����� ��ҿ� ������ ������ �Ǽ��� �Ѵ�.
void space() {

	unsigned int Sun = 149600000; //�������� �¾���� �Ÿ�
	int KM = 300000; //1�ʿ� �̵��ϴ� �Ÿ�
	int sec = Sun / KM;
	printf("���� �¾翡�� �������� ���µ� �ɸ��� �ð�: %d �� %d ��\n", sec / 60, sec % 60);
	return;
}

//�߰� ������ ����
void Increase() {
	int x=1, y=1;
	int nextX = ++x, nextY = y++;
	printf("x: %d y: %d \n", x, y);
	printf("nextX: %d nextY: %d", nextX, nextY);
	return;
}

//����� ����ȯ
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
	//�Ǽ��� ����Ҷ��� ���ʸ� �Ǽ��� �Ǽ��� �ȴ�. 
	//�Ǽ����� ���������� ��ȯ�ϸ� �Ҽ��� ���ڸ��� ©����.
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
//���迬����
void Relation() {
	int x, y;
	printf("�ΰ��� ������ �Է��Ͻÿ�\n");
	scanf("%d %d", &x, &y);

	printf("x==y ���: %d \n", x == y);
	printf("x!=y ���: %d \n", x != y);
	printf("x>y ���: %d \n", x > y);
	printf("x<y ���: %d \n", x < y);
	printf("x<=y ���: %d \n", x <= y);
	printf("x>=y ���: %d \n", x >= y);

	return;
}
//��: 1
//����: 0
//�����ñⰣ�� �����ֿ���, �������� �Է¹޾�, �Դ� ������ �´��� Ȯ��
//������, ���ְ���, Ʋ���� ���ֺҰ�
//������ �Ⱓ 3���̻�, �������� ������ 40�� �̻�,  ������ �� �� 3���̻��ϰ�� ��
void LantHouse() {
	int noHouse;
	int Family;
	int olderYear;
	
	printf("�����ñⰣ: ");
	scanf("%d", &noHouse);
	printf("�����ֿ���: ");
	scanf("%d", &olderYear);
	printf("������: ");
	scanf("%d", &Family);
	
	if((noHouse >= 3) && (Family >= 3) && (olderYear >= 40)) printf("���ְ���");
	else printf("���ֺҰ�");
	
	return;
}
void BitOper() {
	int z=9, x=10;
	printf("z=%d, x=%d\n", z, x);
	printf("��Ʈ AND: %08X\n��Ʈ OR: %08X\n��Ʈ XOR: %08X\nz�� ��Ʈ NOT: %08X\n",z&x, z|x, z^x, ~z);
	return;
}

void Shiftoper() {
	int x = 4;
	printf("Data: %#08x\n", x);
	printf("��Ʈ << = %#08x\n", x << 1);
	printf("��Ʈ >> = %#08x\n", x >> 1);

	return;
}

void Color() {
	unsigned int color = 0x00389999;
	unsigned int result;

	printf("�ȼ��� ���� : %#08x \n", color);
	result = color & 0x00ff0000; //ff ������ ����ڴٴ� �ǹ�
	printf("����ũ ���� �� : %#08x \n", result);
	result = result >> 16;
	printf("���� ����� : %#08x \n", result);
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