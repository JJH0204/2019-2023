#include <iostream> 
#include <string>
using namespace std;
//���ӽ����̽�: �Լ��� ���������� �����ϰ� ������ ��.
namespace A {
	int g_nData = 10;

	void PrintData()
	{
		std::cout << "Data:" << g_nData << std::endl;
	}
}

using namespace A;

namespace B {
	int g_nData = 20;

	void PrintData()
	{
		cout << "Data:" << g_nData << endl;
	}
}

using namespace B;
//�Լ��� �����ε�: ���� �̸��� �Լ��� 
//�ٸ�Ÿ���� �Ű������� ������ �ٸ��� ����
//��, ���ϰ��� �ٸ����� �����ε��Ҽ�����.
//int Add(int a, int b, int c) { return a + b + c; };
//int Add(int a, int b){ int c = 0; return a + b + c; };
//int Add(int a) { int b = 0, c = 0; return a + b + c; };
//int Add(){ int a = 0, b = 0 ,c = 0; return a + b + c; };
int Add(int a = 0, int b = 0, int c = 0) { return a + b + c; };
//float Add(int a = 0, int b = 0, int c = 0) { return a + b + c; }; //�����ε��Ұ�
float Add(float a = 0, float b = 0, float c = 0) { return a + b + c; };
//����Ʈ�Ű�����: �Ű������� �⺻���� �־��ִ� ��.
//�ڿ������� ���ʴ�� ���ڸ� ä���־���Ѵ�.

void StringMain()
{
	string strFullName;
	string strLastName = "k";
	string strFirstName = "hg";
	//���ڿ��� �ѱ������� �̸��� �����,
	strFullName = strLastName + strFirstName;
	//�ش� Ǯ���ӿ��� ���� ��ġ�� ã�ƶ�.
	int nIdx = strFullName.find(strLastName);//�ش繮���� ��ġ�� ã�´�.
	cout << strLastName << " Find:" <<"["<<nIdx<<"]"<< strFullName[nIdx] << endl;
	//���ڿ���ü�� �迭ó�� ����� �����ϴ�.
	for (int i = 0; i < strFullName.size(); i++)
		cout << strFullName[i];
	cout << endl;
}

//�ܾ� ���� ���߱� ����
//A:_ _ _ _
//Q:A
//A:_ A _ _
//
void HangmanGameMain()
{

}
//�ڵ���- �Ӽ�: �ӵ�,����,��� ����: �����ϴ�, �����ϴ�
//Ŭ����: ��ü�� ����� ���赵�� �ش�ȴ�.
//Ŭ������ �����ϴ°͸����δ� �޸𸮸� ���������ʴ´�.
class Car
{
public:
	//�������
	int m_nSpeed;
	string m_strColor;
	int m_nGear;
	//�극��ũ�� ������ �ӵ��� Ȯ���ϱ����� �ӵ��� �����Ѵ�. //�Ϲ���X
	//����Լ�
	void Accelerator()
	{
		m_nSpeed++;
		//return m_nSpeed;
	}
	void Break()
	{
		m_nSpeed--;
		//return m_nSpeed;
	}
};

void CarMain()
{
	//Ŭ������ ����Ҷ� ��ü(�ν��Ͻ�)�� �����Ѵ�.
	//(== Ŭ������ ����Ҷ� �޸𸮸� �����Ѵ�.)
	Car cCar;
	cCar.m_strColor = "Blue";
	cCar.m_nSpeed = 0;
	cCar.m_nGear = 0;

	cCar.Accelerator();
	cout << "Accel:"<< cCar.m_nSpeed << endl;
	cCar.Accelerator();
	cout << "Accel:" << cCar.m_nSpeed << endl;
	cCar.Accelerator();
	cout << "Speed:" << cCar.m_nSpeed << endl;
	cCar.Break();
	cout <<"Break:"<< cCar.m_nSpeed << endl;
	cCar.Break();
	cout << "Break:" << cCar.m_nSpeed << endl;
}

void main()
{
	//StringMain();
	CarMain();
	//A::PrintData(); //10
	//B::PrintData(); //20���ڳ� ���
	////cout << Add()<< endl; //����Ʈ�Ű������� Ÿ���� �ָ���.
	//cout << Add(10) << endl;
	//cout << Add(10, 20) << endl;
	//cout << Add(10, 20, 30) << endl;
}

