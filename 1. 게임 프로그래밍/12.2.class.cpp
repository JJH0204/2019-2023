#include <iostream>
#include <string>
using namespace std;
//1.숙제: 속도와 기어는 임의로 변수의 값을 바꿀수없다.
//그러나 코드에서는 가능하다. 
//이를 안되게하려면 어떻게 해야하는가?
//1.1. C++ 은닉 -> 은닉의 개념에 대한 설명
//1.2. 내가 은닉하려고하는것은? 속도, C++ 클래스의 멤버변수 
//     -> C++ 멤버변수 은닉 ->private을 사용한다.
//1.3. 구체적이고, 내가 해야할것을 전문용어로 표현가능해야한다.
//1.4. 객체지향형 은닉: 은닉할 대상을 내가 잘못 사용했다면 알려달라라는 의미다.

//2. 배운 내용을 드라이브에 정리하기
//3. 12.ex.String예제 완성해오기

class BlackBox {
public:
	BlackBox(int x) {};
};


//캡슐화: 나타낼 대상의 속성과 동작을 변수와 함수로 묶어서 클래스로 나타내는것.
//은닉: 나타낼 대상이 속성이 변경하면 안되는때 사용한다.

//추상화: 문제해결을 위해 대상의 필요한 속성만 간추린다.
//자동차- 속성: 속도,색상,기어 동작: 가속하다, 감속하다
//클래스: 객체를 만드는 설계도에 해당된다.
//클래스를 생성하는것만으로는 메모리를 차지하지않는다.
class Car
{
//public:
//접근제어자: 클래스의 멤버에 접근을 제한하는 것. public, private, protected
//private: //개인의 것: 즉 클래스안에서만 사용가능한 것을 나타냄
	       //생략을 하면 기본이 private이다. 구조체는 기본이 public이다.
	
	//멤버변수: 일반적 private을 사용한다.
	//최신버전컴파일러는 이러한 문법을 지원하므로 초기화목록을 사용하지않아도된다.
	//const int MAX_SPEED = 100;
	//int &m_refGrear = m_nGear;
	//참조자나 상수멤버를 가진 객체는 복사생성이 불가능해진다.
	BlackBox m_cBlackBox = BlackBox(10);
	int m_nSpeed = 0;
	int m_nGear = 0;
	string m_strColor;
	//정적맴버변수/함수: 객체가 모두공유가능. 
	//객체가 생기기전에 만들어지고 접근가능한것.
	static int m_nCount;
public:
	static int GetCount()
	{
		//객체가 생성되지않았으므로, 사용할수없음.
		//m_nSpeed = 100; 
		return m_nCount;
	}
	//멤버함수: 일반적으로 public을 사용한다.
public: //공공의 것: 즉 클래스가 아닌 다른 대상도 사용가능한것.
	//호출하지않아도 생성될때 호출된다.
	//반환값이 없다. 클래스명과 같다.
	//Car()//기본 생성자: 객체가 생성될때 함수
	//{
	//	cout << "Car()" << endl;
	//	m_nSpeed = 0;
	//	m_nGear = 0;
	//}
	//매개변수가 있는 생성자: 함수이므로 가능함. 오버로딩가능.
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
	//	//문자열객체는 정적할당된 메모리가 아니므로 메모리복사가 불가능하다.
	//	//memcpy(this, &car, sizeof(car));
	//	m_strColor = car.m_strColor;
	//	m_nSpeed = car.m_nSpeed;
	//	m_nGear = car.m_nGear;
	//}
	
	//소멸자는 컴파일러에의해 자동으로 호출될때가 있으므로, 임의 값을 넣을수없다.
	//소멸자: 객체가 파괴될때 호출되는 함수. 리턴값X,~클래스명
	//소멸자가 private이면,
	//정적생성일때는 생성이 불가능해진다.
	//동적생성일때는 삭제가 불가능해진다.
	~Car()
	{
		cout << "~Car[" << this << "]" << endl;
		m_nCount--;
	}
	//~Car(int data)
	//디폴트매개변수도 사용가능하다.
	//그러므로 디폴트생성자를 대처가능하다.
	//생성자가 private이라면 메모리를 만들수 없게된다.
	//그러므로, 특수한 경우(싱글톤)가 아니라면 public을 사용한다.
	Car(string color = "gray", int speed = 0, int gear = 0)
	{
		//this: 객체의 메모리주소값
		cout << "Car["<<this<<"](" << color << ")" << endl;
		m_strColor = color;
		m_nSpeed = 0;
		m_nGear = 0;
		m_nCount++;
	}

	//Setter: 은닉된 멤버변수의 값을 설정하는 것. public이여아한다.
	//변경은 가능하지만 허가가 필요한것들에 사용함.
	void SetColor(string color) 
	{
		m_strColor = color;
	}
	//Getter: 은닉된 멤버변수의 값을 가져오는 것. public이여아한다.
	//변경은 불가능하지만 확인이 필요한것에 사용함.
	int GetSpeed() const
	{
		return m_nSpeed;
	}
	//브레이크와 가속은 속도를 확인하기위해 속도를 리턴한다. //일반적X
	//멤버함수
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
//참조 교환과 값의 교환을 테스트하고,
//테스트한 결과가 왜 적용되지않는지 설명하기.
//설명시에 설명한것이 해당되는 용어에 대하여 정리하기.
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
//static멤버변수: 모든 객체가 공유하는 변수
//정적맴버변수는 모든객체가 공유해야하므로,
//프로그램이 실행되는동안 유지할수있는 전역변수가 필요하다.
//그러므로, 전역변수는 클래스에 선언을 하고,
//전역변수처럼 정의를 해야만 사용이 가능하다.
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

//1.자동차의 색상을 정한다.
//(속도,기어는 기본으로 설정되야함)
//1.1.실행중에 색상을 바꿀수있어야함. (색상변수 문자열, 입력)
//2.공장에서 내가 주문한 색상으로 자동차를 생산한다.
//2.1.설계도를 보고 자동차를 생산한다.(객체를 생성한다)
//2.2.주문된 색상으로 자동차의 색상을 정한다.
//2.3.속도,기어는 기본설정 (0으로 초기화)
//3.생산된 자동차를 내가 운전한다.
//3.1.가속패달을 밟아 속도를 증가시킨다.
//3.2.브레이크를 밟아 속도를 감소시킨다.
void CarBasic()
{
	string strColor; //견적서 준비
	cout << "Color:"; 
	cin >> strColor; //견적서에 색상을 체크
	//Car cCar; //자동차 생산 //디폴트생성자의 호출
	Car cCar("green"); //매개변수가 있는 생성자의 호출
	cCar.Display();
	//cCar.m_nSpeed = 0;//생산시 속도와 기어는 초기값이 일정하다.
	//cCar.m_nGear = 0;
	cCar.Display();
	cCar.SetColor(strColor);//cCar.m_strColor = strColor; //자동차 도색
	cCar.Display();
	//cCar.m_nSpeed = 200; //자동차의 속도가 갑자기 200이되는것은 불가능하다.
	//주문한 자동차를 시승한다.(표현X)
	cCar.Accelerator(); //가속패달을 밟는다.
	cCar.Accelerator(); //가속패달을 밟는다.
	cCar.Accelerator(); //가속패달을 밟는다.
	cCar.Accelerator(); //가속패달을 밟는다.
	cCar.Display(); //확인이 완료되었으면 정지한다.
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
	Car cCarB();//함수의 선언
	Car cCarC("blue", 0, 0);
	//Car cCarD = Car("red", 0, 0);//임시객체가 생성된것이 복사됨.
	Car cCarD = cCarA;//복사생성자의 호출

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