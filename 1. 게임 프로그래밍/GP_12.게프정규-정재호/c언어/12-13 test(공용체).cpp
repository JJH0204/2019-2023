#include <stdio.h>
union ip_address {
	//����� �޸𸮸� ���� ( ����ü )
	
	unsigned long laddr;
	unsigned char saddr[4];
};
//���̷�Ʈ x ��� �Ǵ� ��Ŷ�� ���� ���
int main(void) {
	union ip_address addr; // c++���� union ���� ������ �� �ִ�.
	addr.saddr[0] = 1;
	addr.saddr[1] = 0;
	addr.saddr[2] = 0;
	addr.saddr[3] = 127;

	printf("%x\n", addr.laddr);

	return 0;
}