#include <iostream> 
#include <string>
using namespace std;
//네임스페이스: 함수나 전역변수를 구별하고 나누는 것.
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
//함수의 오버로딩: 같은 이름의 함수로 
//다른타입의 매개변수나 갯수를 다르게 만듦
//단, 리턴값이 다른것은 오버로딩할수없다.
//int Add(int a, int b, int c) { return a + b + c; };
//int Add(int a, int b){ int c = 0; return a + b + c; };
//int Add(int a) { int b = 0, c = 0; return a + b + c; };
//int Add(){ int a = 0, b = 0 ,c = 0; return a + b + c; };
int Add(int a = 0, int b = 0, int c = 0) { return a + b + c; };
//float Add(int a = 0, int b = 0, int c = 0) { return a + b + c; }; //오버로딩불가
float Add(float a = 0, float b = 0, float c = 0) { return a + b + c; };
//디폴트매개변수: 매개변수에 기본값을 넣어주는 것.
//뒤에서부터 차례대로 숫자를 채워넣어야한다.

void StringMain()
{
	string strFullName;
	string strLastName = "k";
	string strFirstName = "hg";
	//문자열을 한국식으로 이름을 만들고,
	strFullName = strLastName + strFirstName;
	//해당 풀네임에서 성의 위치를 찾아라.
	int nIdx = strFullName.find(strLastName);//해당문자의 위치를 찾는다.
	cout << strLastName << " Find:" <<"["<<nIdx<<"]"<< strFullName[nIdx] << endl;
	//문자열객체를 배열처럼 사용이 가능하다.
	for (int i = 0; i < strFullName.size(); i++)
		cout << strFullName[i];
	cout << endl;
}

//단어 글자 맞추기 게임
//A:_ _ _ _
//Q:A
//A:_ A _ _
//
void HangmanGameMain()
{

}
//자동차- 속성: 속도,색상,기어 동작: 가속하다, 감속하다
//클래스: 객체를 만드는 설계도에 해당된다.
//클래스를 생성하는것만으로는 메모리를 차지하지않는다.
class Car
{
public:
	//멤버변수
	int m_nSpeed;
	string m_strColor;
	int m_nGear;
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
};

void CarMain()
{
	//클래스를 사용할때 객체(인스턴스)를 생성한다.
	//(== 클래스를 사용할때 메모리를 생성한다.)
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
	//B::PrintData(); //20코코넛 페달
	////cout << Add()<< endl; //디폴트매개변수의 타입이 애매함.
	//cout << Add(10) << endl;
	//cout << Add(10, 20) << endl;
	//cout << Add(10, 20, 30) << endl;
}

