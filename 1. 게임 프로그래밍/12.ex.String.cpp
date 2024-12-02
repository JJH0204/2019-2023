#include <iostream>
#include <string.h>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���

//���ڿ� ���� ����(����)
//���ڿ���ü�� 2���̻� �ʿ��ϴ�.
//strA������ ���ڿ��� �����ϰ�,
//strB�� �����Ҷ� strA�� �����Ѵ�.
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
	strB.insert(strB.begin()+1, 'A');//B���ڿ��� �����Ͽ����Ƿ� ���� ����Ǿ����.
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
		//���������: ��ü�� ����ɶ� �Ҹ��� �Լ�.
		//�����ڿ� ���� �Ű������� �ڱ��ڽ��� �����ڸ� �޴´�.
		//�⺻������ �޸� ī�ǰ� �Ͼ�Ƿ�, �����Ҵ���������.
		//���� �ٸ���ü�� ��������� ������ �����Ҵ��� �����ؾ��Ѵ�.
		//1. ��������ÿ� ������ ��ü�� �����Ҵ��� �Ѵ�.
		//2. �����Ұ�ü�� �����Ҵ�� �޸𸮿� �����Ҵ���� ���ڿ��� �����Ѵ�.
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
			//����� ���ڿ��� ���� ������ ���� ��ȯ�ϰ�
			//�ٸ��� ������ ��ȯ�Ѵ�.
			return false;
		}
		
		void insert(int idx, const char ch)
		{
			char* pTemp = new char[strlen(m_strString)+2];//������ �ӽù��ڿ��� �غ��Ѵ�.
			strcpy(pTemp, m_strString); //�ӽù��ڿ��� ������ ���ڿ��� �����Ѵ�.
			std::cout << "1.insert:" << pTemp << std::endl;
			strcpy(pTemp+idx+1, m_strString+idx); //������ ��ġ���� 1ĭ���� ���� ���ڿ��� �޺κ��� �����Ѵ�.
			std::cout << "2.insert:" <<pTemp << std::endl;
			pTemp[idx] = ch; //������ ��ġ�� �Է��� ���ڸ� �ִ´�.
			std::cout << "3.insert:" << pTemp << std::endl;
			delete[] m_strString; //������ �Ҵ�� �޸𸮸� �����ϰ�
			std::cout << "Delete preMemory:" << (int)m_strString << std::endl;
			m_strString = pTemp; //���� �Ҵ�� �޸𸮷� ��ü�Ѵ�.
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
	_CrtSetBreakAlloc(193); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 
	//���Լ��� ���� ����� ������ Ŀ���ҹ��ڿ�Ŭ������ ������.
	StringMain();
	Custom::StringMain();
}