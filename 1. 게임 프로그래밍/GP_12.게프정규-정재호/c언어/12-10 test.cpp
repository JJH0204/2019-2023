#include <stdio.h>
#include <string.h>
void stringex(void) {
	/*char str[4];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';*/
	char str[4] = "abc"; //���ڿ� �ʱ�ȭ ���
	int count = 0;
	printf("str: %p \n", str);
	//str = "base";
	printf("%s", str);
	strcpy(str, "def");
	printf("%s\n", str);
	const char * ptr = "yes";
	printf("%s", ptr);
/*	while (1) {
		if (str[count] == '\0') {
			break;
		}
		printf("%c", str[count]);
		count++;
	}*/
}

void srtingLibrary(void) {
	char FullName[100] = {};	//�ʱ�ȭ �ʼ� // �����Ⱚ ��µ�
	char LastName[50] = "Jung";
	char FirstName[50] = "JaeHo";

	strcpy(FullName, FirstName);
	strcat(FullName, "-");
	strcat(FullName, LastName);
	printf("%s\n", FullName);
	printf("len: %d\n", strlen(FullName));

	sprintf(FullName, "%s%s", FirstName, LastName);

	printf("%s\n", FullName);
	printf("len: %d\n", strlen(FullName));

	/*lastnaem == firstname*/// �ּ� ���� ����..
	if (!strcmp(LastName, FirstName)) { //������ 0 (����) �� �������� !(not) ����
		printf("%s==%s\n", LastName, FirstName);
	}
	else {
		printf("%S!=%s\n", LastName, FirstName);
	}
}
//Q: _ _ _ _
//A: g
//Q: g _ _ _
//A: e
//Q: g _ _ e
//A: m
//Q: g _ m e
//A:....
void Men(void) {

}

int main(void) {
	//stringex();
	srtingLibrary();
}