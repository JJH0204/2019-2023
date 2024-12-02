#include <stdio.h>
#include <stdlib.h> // malloc �Լ��� ���� �߰�
#include <string> //memset �Լ��� ���� �߰�

typedef struct linknode {
	int data;
	struct linknode * pLink;
}LinkedNode;

typedef struct header {
	int Nodecount = 0;
	LinkedNode pHeader;
}LinkedHeaderNode;

LinkedHeaderNode * CreateList();//��� ���� �Լ�
int GetListData(LinkedHeaderNode * pList, int Position);//��� data ��ȯ
void AddLinkedNode(LinkedHeaderNode* pLink, int position, int data);//��� �߰� 
void DelLinkedNode(LinkedHeaderNode* pLink, int position);//��� ����
void DelLinkedList(LinkedHeaderNode * pLink);//����Ʈ ����
void PrintList(LinkedHeaderNode * pLink);//����Ʈ�� ��Ȳ�� ���

int main(void) {
	LinkedHeaderNode * pList = CreateList();
	int value=0;

	AddLinkedNode(pList, 0, 10);
	AddLinkedNode(pList, 1, 20);
	AddLinkedNode(pList, 2, 30);
	AddLinkedNode(pList, 3, 40);
	AddLinkedNode(pList, 4, 50);
	AddLinkedNode(pList, 5, 60);

	PrintList(pList);

	AddLinkedNode(pList, 3, 70);

	PrintList(pList);

	value = GetListData(pList, 4);
	printf("value : %d\n", value);

	DelLinkedNode(pList, 2);
	PrintList(pList);

	DelLinkedList(pList);
	PrintList(pList);

	return 0;
}

//��� ���� �Լ�
LinkedHeaderNode * CreateList() {
	LinkedHeaderNode * pReturn = (LinkedHeaderNode*)malloc(sizeof(LinkedHeaderNode));//malloc �Լ��� ��带 ����
	memset(pReturn, 0, sizeof(LinkedHeaderNode));//������ ��带 �̸� �ʱ�ȭ
	return pReturn; //�Լ��� ȣ��� ��ġ�� ������ ����� ���� �ּҸ� ����
}
//��� data ��ȯ
int GetListData(LinkedHeaderNode * pList, int Position) {
	int i;
	LinkedNode * pSearchFlow = &(pList->pHeader);
	printf("%d��° ����� �ڷḦ ����մϴ�.\n", Position + 1);
	for (i = 0; i <= Position; i++) {
		pSearchFlow = pSearchFlow->pLink;
	}
	return pSearchFlow->data;
}
//��� �߰� 
void AddLinkedNode(LinkedHeaderNode* pLink, int position, int data) {
	LinkedNode * pAddPoint = &(pLink->pHeader);
	LinkedNode * pAddNode = (LinkedNode *)malloc(sizeof(LinkedNode));
	pAddNode->data = data;
	int i = 0;

	if (position > pLink->Nodecount) {
		printf("%d��ġ�� ���� �������� ���մϴ�. ��� ����Ʈ�� �������� ������ �ΰڽ��ϴ�.\n", position);
		for (i = 0; i < pLink->Nodecount; i++) {
			pAddPoint = pAddPoint->pLink;
		}
		pAddPoint->pLink = pAddNode;
		pLink->Nodecount++;
	}
	else {
		printf("%d��ġ�� ã�� ���� �߰��ϰڽ��ϴ�.\n", position);
		for (i = 0; i < position; i++) {
			pAddPoint = pAddPoint->pLink;
		}
		pAddNode->pLink = pAddPoint->pLink;
		pAddPoint->pLink = pAddNode;
		pLink->Nodecount++;
	}
}
//��� ����
void DelLinkedNode(LinkedHeaderNode* pLink, int position) {
	LinkedNode * pDelPoint = &(pLink->pHeader);
	LinkedNode * pPreNode = NULL;
	int i;
	if (position > pLink->Nodecount) {
		printf(" %d ��ġ�� ���� ���� ���� �ʽ��ϴ�. Ȯ���ϰ� ������ּ���.\n", position);
	}
	else {
		printf(" %d ��ġ�� �ڷḦ ���� �մϴ�.\n", position + 1);
		for (i = 0; i <= position; i++) {
			pPreNode = pDelPoint;
			pDelPoint = pDelPoint->pLink;
		}
		pPreNode->pLink = pDelPoint->pLink;
		free(pDelPoint);
		pLink->Nodecount--;
	}
}
//����Ʈ ����
void DelLinkedList(LinkedHeaderNode * pLink) {
	LinkedNode * pDelPoint = &(pLink->pHeader);
	LinkedNode * pPreNode = pDelPoint->pLink;
	printf("����Ʈ�� �����մϴ�.\n");
	while (pPreNode != NULL) {
		pDelPoint = pPreNode;
		pPreNode = pPreNode->pLink;
		free(pDelPoint);
	}
	free(pLink);
}
//����Ʈ�� ��Ȳ�� ���
void PrintList(LinkedHeaderNode * pLink) {
	LinkedNode * pPrintNode = &(pLink->pHeader);
	if (pLink->Nodecount > 0) {
		pPrintNode = pPrintNode->pLink;
		printf("Now List: ");
		while (pPrintNode != NULL) {
			printf("%d ", pPrintNode->data);
			pPrintNode = pPrintNode->pLink;
		}
		printf("\n");
	}
	else {
		printf("���� �����͸� �������� �ʾ� ����Ʈ�� �������� �ʽ��ϴ�.\n");
	}
}