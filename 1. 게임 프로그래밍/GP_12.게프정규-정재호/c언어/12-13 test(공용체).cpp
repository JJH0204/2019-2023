#include <stdio.h>
union ip_address {
	//멤버의 메모리를 공유 ( 공용체 )
	
	unsigned long laddr;
	unsigned char saddr[4];
};
//다이렉트 x 행렬 또는 패킷에 많이 사용
int main(void) {
	union ip_address addr; // c++에서 union 또한 생략할 수 있다.
	addr.saddr[0] = 1;
	addr.saddr[1] = 0;
	addr.saddr[2] = 0;
	addr.saddr[3] = 127;

	printf("%x\n", addr.laddr);

	return 0;
}