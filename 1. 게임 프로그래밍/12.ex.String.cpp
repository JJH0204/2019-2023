#include <iostream>
#include <string.h>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더

//문자열 생성 복사(대입)
//문자열객체를 2개이상 필요하다.
//strA생성시 문자열을 지정하고,
//strB를 생성할때 strA를 복사한다.
void StringMain()
{
	std::string strA("Data");
	std::string strB = strA;
	std::cout << strA.c_str() << std::endl;
	std::cout << strB.c_str() << std::endl;
	if (strA == strB)
		std::cout << strA.c_str() << "==" << strB.c_str() << std::endl;
	else
		std::cout << strA.c_str() << "!=" << strB.c_str() << std::endl;
	strB.insert(strB.begin()+1, 'A');//B문자열만 변경하였으므로 값이 변경되어야함.
	std::cout << strA.c_str() <<"," <<strB.c_str() << std::endl;
}

namespace Custom {
	class string {
		char* m_strString;
	public:
		string(const char str[])
		{
			int nSize = strlen(str)+1;
			m_strString = new char[nSize];
			memcpy(m_strString, str, nSize);
			std::cout << "string:" << (int)m_strString << std::endl;
		}
		//복사생성자: 객체가 복사될때 불리는 함수.
		//생성자와 같고 매개변수가 자기자신의 참조자를 받는다.
		//기본적으로 메모리 카피가 일어나므로, 동적할당했을때는.
		//서로 다른객체로 만들기위해 별로의 동적할당을 수행해야한다.
		//1. 복사생성시에 복사할 객체에 동적할당을 한다.
		//2. 복사할객체의 동적할당된 메모리에 복사할대상의 문자열을 복사한다.
		string(string& str)
		{
			//m_strString = str.m_strString; //
			int nSize = strlen(str.m_strString) + 1;
			this->m_strString = new char[nSize];
			strcpy(this->m_strString, str.m_strString);
			std::cout << "string copy:" << (int)m_strString << std::endl;
		}

		~string()
		{
			delete[] m_strString;
		}

		bool operator ==(string& str)
		{
			//저장된 문자열의 값이 같을때 참을 반환하고
			//다르면 거짓을 반환한다.
			return false;
		}
		
		void insert(int idx, const char ch)
		{
			char* pTemp = new char[strlen(m_strString)+2];//복사할 임시문자열을 준비한다.
			strcpy(pTemp, m_strString); //임시문자열에 복사할 문자열을 복사한다.
			std::cout << "1.insert:" << pTemp << std::endl;
			strcpy(pTemp+idx+1, m_strString+idx); //선택한 위치에서 1칸띄우고 원래 문자열의 뒷부분을 복사한다.
			std::cout << "2.insert:" <<pTemp << std::endl;
			pTemp[idx] = ch; //선택한 위치에 입력할 문자를 넣는다.
			std::cout << "3.insert:" << pTemp << std::endl;
			delete[] m_strString; //기존에 할당된 메모리를 삭제하고
			std::cout << "Delete preMemory:" << (int)m_strString << std::endl;
			m_strString = pTemp; //현재 할당된 메모리로 교체한다.
			std::cout << "Swap Memory:" << (int)m_strString << std::endl;
		}

		const char* c_str()
		{
			return m_strString;
		}
	};

	void StringMain()
	{
		string strA("Data");
		string strB = strA;
		std::cout << strA.c_str() << std::endl;
		std::cout << strB.c_str() << std::endl;
		if (strA == strB)
			std::cout << strA.c_str() << "==" << strB.c_str() << std::endl;
		else
			std::cout << strA.c_str() << "!=" << strB.c_str() << std::endl;
		strB.insert(1, 'A');
		std::cout << strA.c_str() << "," << strB.c_str() << std::endl;
	}
}

void main()
{
	_CrtSetBreakAlloc(193); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 
	//두함수가 같은 결과를 내도록 커스텀문자열클래스를 만들어보자.
	StringMain();
	Custom::StringMain();
}