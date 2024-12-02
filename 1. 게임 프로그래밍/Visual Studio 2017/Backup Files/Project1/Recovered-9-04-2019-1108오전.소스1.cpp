/*
파일이름	:	Using_STL_ver.1.0.cpp
파일목적	:	c++의 STL을 연습하기 위한 연습 파일
작성자	:	정재호(jhjy5369@naver.com)
수정날짜	:	2019.09.03
구현과제 
STL을 이용한 vector, list, stack, queue, graph 구현
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
/*
c++ STL 에서 컨테이너는 크게 두 가지 종류가 있다.
배열 처럼 객체들을 순차적으로 보관하는 '스퀀스 컨테이너(sequence container)와 
키를 바탕으로 대응되는 값을 찾아주는 연관 컨테이너(associative container)가 있다.
시퀀스 컨테이너 : vector, list, deque

vector (백터) : 가변길이 배열
- 벡터에는 원소들이 메모리 상에서 실제로 순차적으로 저장되어 있다.
- 임의의 위치에 있는 원소를 접근하는 것을 매우 빠르게 수행할 수 있다. 임의의 위치의 원소에 접근하는 것을 O(1)로 수행할 수 있다.
- 원소를 제거하는 것 또한 O(1)로 수행 할 수 있다.
- 임의의 원소에 접근하는 것은 배열처럼 []를 이용하거나, at함수를 이용하면 된다.
- 맨 뒤에 원소를 추가하는 경우 : push_back
- 맨 뒤에 원소를 제거하는 경우 : pop_back
*/

void STL_vector(void) {
	std::vector<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.push_back(40);

	for (std::vector<int>::size_type i = 0; i < list.size(); i++) {
		printf("List의 %d 번째 원소 : %d \n", i + 1, list[i]);
	}
	return;
}
/*
백터의 문제점
맨 뒤에 원소를 추가하는 작업을 엄밀히 말하면 amortized O(1)이라고 하는데
왜냐하면, vector의 경우 현재 가지고 있는 원소의 개수 보다 더 많은 공간을 미리 할당해 놓는다.
만약 원소의 개수가 5개라면 이보다 더 큰 10개의 메모리를 미리 할당해 둔것이다.
그래서 평소에는 O(1)속도의 작업을 보여주지만 만약에 10개의 메모리를 모두 사용한 경우에는 해당 메모리를 삭제하고 값을 다른 메모리에 옮기는 작업을 수행한다. O(n)속도
그래서 간혹 가다가 한번씩 일어나는 이문제 때문에 평균적으로 O(1)의 속도를 낸다는 의미에서 amortized O(1)이라고 한다.

- amortized : 분할상환

또 맨 뒤에 원소를 추가하는 것은 매우 빠르지만 , 임의의 위치에 원소를 추가하거나 제거하는 것은 O(n)으로 느리다.
특정 자리에 새로운 원소를 추가하거나 뺄 경우 그 뒤에 오는 원소들을 한 칸 씩 이동시켜 주어야 하기 때문이다.
이때 n번의 복사를 진행하기 때문에 만일 맨 뒤가 아닌 위치에 데이터를 추가(제거)하는 작업을 해야할 경우 vector의 사용을 자제해야한다.

임의의 위치에 원소 접근([], at): O(1)
맨 뒤에 원소 추가(제거)(push_back/pop_back) : amortized O(1); ( 평균적으로 O(1), 최악의 경우 O(n) )
임의의 위치에 원소 추가 및 제거 ( insert, erase ) : O(n)

따라서 어떤 작업을 하냐에 따라 속도의 차이가 매우 크기 때문에, C++표준 라이브러리를 사용할 때 컨테이너가 어떤 작업을 위해 사용되는지 이해하고 적절한 컨테이너를 골라야 한다.
*/

void STL_vector2(void) {
	std::vector<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.push_back(40);

	for (std::vector<int>::iterator itr = list.begin(); itr != list.end(); itr++) 
		printf("%d\n", *itr);
	//여기서 itr 변수는 포인터 변수이다. 
	//vector 배열의 인자 주소 값을 저장할 수 있다. 
	//배열에 저장된 값을 출력하려면 포인터 연산을 해야한다.
	std::vector<int>::iterator itr = list.begin() + 2;
	printf("3번째 요소 : %d \n", *itr);
	return;
}
/*
: 반복자는 컨테이너에 원소에 접근할 수 있는 포인터와 같은 객체
벡터의 경우 []를 이용해 정수형 변수로 마치 배열 처럼 임의의 위치에 접근할 수 있지만, 반복자를 사용해서도 동일한 작업을 할 수 있다.
알고리즘 라이브러리의 경우 대부분이 반복자를 인자로 받아서 알고리즘을 수행한다.

반복자는 컨테이너에서 iterator 멤버 타입으로 정의되어 있다.

*/
int main(void) {
	
	//STL_vector();	//백터 자료형 사용
	STL_vector2();	//반복자 활용


	return 0;
}
/*
C++에 대한 추론

C++에서 구조체와 활용 방식이 비슷한 무언가가 있다.(컨테이너라고 하는 것 같다)
그곳에 맴버로 함수와 변수의 자료형을 미리 정의해 둘 수 있다.
정적으로 할당된 컨테이너 형의 변수로 맴버인 함수를 호출할 수 있다.
호출한 함수는 해당 변수를 활용한 연산만 실행 할 수 있다.
*/