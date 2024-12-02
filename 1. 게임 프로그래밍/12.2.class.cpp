#include <iostream>
#include <string>
using namespace std;
//1.����: �ӵ��� ���� ���Ƿ� ������ ���� �ٲܼ�����.
//�׷��� �ڵ忡���� �����ϴ�. 
//�̸� �ȵǰ��Ϸ��� ��� �ؾ��ϴ°�?
//1.1. C++ ���� -> ������ ���信 ���� ����
//1.2. ���� �����Ϸ����ϴ°���? �ӵ�, C++ Ŭ������ ������� 
//     -> C++ ������� ���� ->private�� ����Ѵ�.
//1.3. ��ü���̰�, ���� �ؾ��Ұ��� �������� ǥ�������ؾ��Ѵ�.
//1.4. ��ü������ ����: ������ ����� ���� �߸� ����ߴٸ� �˷��޶��� �ǹ̴�.

//2. ��� ������ ����̺꿡 �����ϱ�
//3. 12.ex.String���� �ϼ��ؿ���

class BlackBox {
public:
	BlackBox(int x) {};
};


//ĸ��ȭ: ��Ÿ�� ����� �Ӽ��� ������ ������ �Լ��� ��� Ŭ������ ��Ÿ���°�.
//����: ��Ÿ�� ����� �Ӽ��� �����ϸ� �ȵǴ¶� ����Ѵ�.

//�߻�ȭ: �����ذ��� ���� ����� �ʿ��� �Ӽ��� ���߸���.
//�ڵ���- �Ӽ�: �ӵ�,����,��� ����: �����ϴ�, �����ϴ�
//Ŭ����: ��ü�� ����� ���赵�� �ش�ȴ�.
//Ŭ������ �����ϴ°͸����δ� �޸𸮸� ���������ʴ´�.
class Car
{
//public:
//����������: Ŭ������ ����� ������ �����ϴ� ��. public, private, protected
//private: //������ ��: �� Ŭ�����ȿ����� ��밡���� ���� ��Ÿ��
	       //������ �ϸ� �⺻�� private�̴�. ����ü�� �⺻�� public�̴�.
	
	//�������: �Ϲ��� private�� ����Ѵ�.
	//�ֽŹ��������Ϸ��� �̷��� ������ �����ϹǷ� �ʱ�ȭ����� ��������ʾƵ��ȴ�.
	//const int MAX_SPEED = 100;
	//int &m_refGrear = m_nGear;
	//�����ڳ� �������� ���� ��ü�� ��������� �Ұ���������.
	BlackBox m_cBlackBox = BlackBox(10);
	int m_nSpeed = 0;
	int m_nGear = 0;
	string m_strColor;
	//�����ɹ�����/�Լ�: ��ü�� ��ΰ�������. 
	//��ü�� ��������� ��������� ���ٰ����Ѱ�.
	static int m_nCount;
public:
	static int GetCount()
	{
		//��ü�� ���������ʾ����Ƿ�, ����Ҽ�����.
		//m_nSpeed = 100; 
		return m_nCount;
	}
	//����Լ�: �Ϲ������� public�� ����Ѵ�.
public: //������ ��: �� Ŭ������ �ƴ� �ٸ� ��� ��밡���Ѱ�.
	//ȣ�������ʾƵ� �����ɶ� ȣ��ȴ�.
	//��ȯ���� ����. Ŭ������� ����.
	//Car()//�⺻ ������: ��ü�� �����ɶ� �Լ�
	//{
	//	cout << "Car()" << endl;
	//	m_nSpeed = 0;
	//	m_nGear = 0;
	//}
	//�Ű������� �ִ� ������: �Լ��̹Ƿ� ������. �����ε�����.
	/*Car(string color)
	{
		cout << "Car(" << color << ")" << endl;
		m_strColor = color;
		m_nSpeed = 0;
		m_nGear = 0;
	}*/
	//Car(Car& car)
	//{
	//	cout <<  "copy car[" << this << "]" << endl;
	//	//���ڿ���ü�� �����Ҵ�� �޸𸮰� �ƴϹǷ� �޸𸮺��簡 �Ұ����ϴ�.
	//	//memcpy(this, &car, sizeof(car));
	//	m_strColor = car.m_strColor;
	//	m_nSpeed = car.m_nSpeed;
	//	m_nGear = car.m_nGear;
	//}
	
	//�Ҹ��ڴ� �����Ϸ������� �ڵ����� ȣ��ɶ��� �����Ƿ�, ���� ���� ����������.
	//�Ҹ���: ��ü�� �ı��ɶ� ȣ��Ǵ� �Լ�. ���ϰ�X,~Ŭ������
	//�Ҹ��ڰ� private�̸�,
	//���������϶��� ������ �Ұ���������.
	//���������϶��� ������ �Ұ���������.
	~Car()
	{
		cout << "~Car[" << this << "]" << endl;
		m_nCount--;
	}
	//~Car(int data)
	//����Ʈ�Ű������� ��밡���ϴ�.
	//�׷��Ƿ� ����Ʈ�����ڸ� ��ó�����ϴ�.
	//�����ڰ� private�̶�� �޸𸮸� ����� ���Եȴ�.
	//�׷��Ƿ�, Ư���� ���(�̱���)�� �ƴ϶�� public�� ����Ѵ�.
	Car(string color = "gray", int speed = 0, int gear = 0)
	{
		//this: ��ü�� �޸��ּҰ�
		cout << "Car["<<this<<"](" << color << ")" << endl;
		m_strColor = color;
		m_nSpeed = 0;
		m_nGear = 0;
		m_nCount++;
	}

	//Setter: ���е� ��������� ���� �����ϴ� ��. public�̿����Ѵ�.
	//������ ���������� �㰡�� �ʿ��Ѱ͵鿡 �����.
	void SetColor(string color) 
	{
		m_strColor = color;
	}
	//Getter: ���е� ��������� ���� �������� ��. public�̿����Ѵ�.
	//������ �Ұ��������� Ȯ���� �ʿ��ѰͿ� �����.
	int GetSpeed() const
	{
		return m_nSpeed;
	}
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
	void Display() const
	{
		cout << "Color:" << m_strColor << endl;
		cout << "Gear:" << m_nGear << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Count:" << m_nCount << endl;
	}
};

void SwapCarVal(Car a, Car b)
{
	cout <<"Val("<< &a << ","<< &b<<")";
	Car temp = a;
	a = b;
	b = temp;
}

void SwapCarRef(Car& a, Car& b)
{
	cout << "Ref(" << &a << "," << &b << ")";
	Car temp = a;
	a = b;
	b = temp;
}
//���� ��ȯ�� ���� ��ȯ�� �׽�Ʈ�ϰ�,
//�׽�Ʈ�� ����� �� ��������ʴ��� �����ϱ�.
//����ÿ� �����Ѱ��� �ش�Ǵ� �� ���Ͽ� �����ϱ�.
void SwapCarTestMain()
{
	Car cCarA("red");
	Car cCarB("blue");

	cout << "1.A,B:" << &cCarA << "," << &cCarB << endl;
	cCarA.Display();
	cCarB.Display();
	SwapCarVal(cCarA, cCarB);
	cout << "2.A,B:" << &cCarA << "," << &cCarB << endl;
	cCarA.Display();
	cCarB.Display();
	SwapCarRef(cCarA, cCarB);
	cout << "3.A,B:" << &cCarA << "," << &cCarB << endl;
	cCarA.Display();
	cCarB.Display();
}
//static�������: ��� ��ü�� �����ϴ� ����
//�����ɹ������� ��簴ü�� �����ؾ��ϹǷ�,
//���α׷��� ����Ǵµ��� �����Ҽ��ִ� ���������� �ʿ��ϴ�.
//�׷��Ƿ�, ���������� Ŭ������ ������ �ϰ�,
//��������ó�� ���Ǹ� �ؾ߸� ����� �����ϴ�.
int Car::m_nCount = 0;

void StaticMemberMain()
{
	//Car::m_nCount = 199;
	cout << "1:"<< Car::GetCount() << endl;
	Car arrCar[3];
	cout << "2:" << arrCar[1].GetCount() << endl;
	Car* pCar = new Car();
	cout << "3:" << pCar->GetCount() << endl;
	delete pCar;
	cout << "4:" << Car::GetCount() << endl;
}

//1.�ڵ����� ������ ���Ѵ�.
//(�ӵ�,���� �⺻���� �����Ǿ���)
//1.1.�����߿� ������ �ٲܼ��־����. (���󺯼� ���ڿ�, �Է�)
//2.���忡�� ���� �ֹ��� �������� �ڵ����� �����Ѵ�.
//2.1.���赵�� ���� �ڵ����� �����Ѵ�.(��ü�� �����Ѵ�)
//2.2.�ֹ��� �������� �ڵ����� ������ ���Ѵ�.
//2.3.�ӵ�,���� �⺻���� (0���� �ʱ�ȭ)
//3.����� �ڵ����� ���� �����Ѵ�.
//3.1.�����д��� ��� �ӵ��� ������Ų��.
//3.2.�극��ũ�� ��� �ӵ��� ���ҽ�Ų��.
void CarBasic()
{
	string strColor; //������ �غ�
	cout << "Color:"; 
	cin >> strColor; //�������� ������ üũ
	//Car cCar; //�ڵ��� ���� //����Ʈ�������� ȣ��
	Car cCar("green"); //�Ű������� �ִ� �������� ȣ��
	cCar.Display();
	//cCar.m_nSpeed = 0;//����� �ӵ��� ���� �ʱⰪ�� �����ϴ�.
	//cCar.m_nGear = 0;
	cCar.Display();
	cCar.SetColor(strColor);//cCar.m_strColor = strColor; //�ڵ��� ����
	cCar.Display();
	//cCar.m_nSpeed = 200; //�ڵ����� �ӵ��� ���ڱ� 200�̵Ǵ°��� �Ұ����ϴ�.
	//�ֹ��� �ڵ����� �ý��Ѵ�.(ǥ��X)
	cCar.Accelerator(); //�����д��� ��´�.
	cCar.Accelerator(); //�����д��� ��´�.
	cCar.Accelerator(); //�����д��� ��´�.
	cCar.Accelerator(); //�����д��� ��´�.
	cCar.Display(); //Ȯ���� �Ϸ�Ǿ����� �����Ѵ�.
	cCar.Break();
	cCar.Break();
	cCar.Break();
	cCar.Break();
	cCar.Display();

	Car arrCar[10];
	arrCar[4].SetColor("red");
}

void ClassDynamicMain()
{
	//Car* pCar = new Car();
	Car* pCar = new Car("red",0,0);
	pCar->SetColor("blue");
	pCar->Accelerator();
	pCar->Display();
	delete pCar;

	Car* arrCar = new Car[10];
	delete[] arrCar;
}

void ClassTestMain()
{
	Car cCarA;
	Car cCarB();//�Լ��� ����
	Car cCarC("blue", 0, 0);
	//Car cCarD = Car("red", 0, 0);//�ӽð�ü�� �����Ȱ��� �����.
	Car cCarD = cCarA;//����������� ȣ��

	cCarA.Display();
	//cCarB.Display();
	cCarC.Display();
	cCarD.Display();
}



void main()
{
	//CarBasic();
	//ClassTestMain();
	//SwapCarTestMain();
	StaticMemberMain();
	cout << Car::GetCount() << endl;
}