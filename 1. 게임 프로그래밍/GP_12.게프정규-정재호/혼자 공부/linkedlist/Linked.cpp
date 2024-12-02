#include <stdio.h>
#include <stdlib.h> // malloc 함수를 위해 추가
#include <string> //memset 함수를 위해 추가

typedef struct linknode {
	int data;
	struct linknode * pLink;
}LinkedNode;

typedef struct header {
	int Nodecount = 0;
	LinkedNode pHeader;
}LinkedHeaderNode;

LinkedHeaderNode * CreateList();//노드 생성 함수
int GetListData(LinkedHeaderNode * pList, int Position);//노드 data 반환
void AddLinkedNode(LinkedHeaderNode* pLink, int position, int data);//노드 추가 
void DelLinkedNode(LinkedHeaderNode* pLink, int position);//노드 제거
void DelLinkedList(LinkedHeaderNode * pLink);//리스트 제거
void PrintList(LinkedHeaderNode * pLink);//리스트의 현황을 출력

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

//노드 생성 함수
LinkedHeaderNode * CreateList() {
	LinkedHeaderNode * pReturn = (LinkedHeaderNode*)malloc(sizeof(LinkedHeaderNode));//malloc 함수로 노드를 생성
	memset(pReturn, 0, sizeof(LinkedHeaderNode));//생성된 노드를 미리 초기화
	return pReturn; //함수가 호출된 위치로 생성된 노드의 시작 주소를 전달
}
//노드 data 반환
int GetListData(LinkedHeaderNode * pList, int Position) {
	int i;
	LinkedNode * pSearchFlow = &(pList->pHeader);
	printf("%d번째 저장된 자료를 출력합니다.\n", Position + 1);
	for (i = 0; i <= Position; i++) {
		pSearchFlow = pSearchFlow->pLink;
	}
	return pSearchFlow->data;
}
//노드 추가 
void AddLinkedNode(LinkedHeaderNode* pLink, int position, int data) {
	LinkedNode * pAddPoint = &(pLink->pHeader);
	LinkedNode * pAddNode = (LinkedNode *)malloc(sizeof(LinkedNode));
	pAddNode->data = data;
	int i = 0;

	if (position > pLink->Nodecount) {
		printf("%d위치에 값을 저장하지 못합니다. 대신 리스트의 마지막에 저장해 두겠습니다.\n", position);
		for (i = 0; i < pLink->Nodecount; i++) {
			pAddPoint = pAddPoint->pLink;
		}
		pAddPoint->pLink = pAddNode;
		pLink->Nodecount++;
	}
	else {
		printf("%d위치를 찾아 값을 추가하겠습니다.\n", position);
		for (i = 0; i < position; i++) {
			pAddPoint = pAddPoint->pLink;
		}
		pAddNode->pLink = pAddPoint->pLink;
		pAddPoint->pLink = pAddNode;
		pLink->Nodecount++;
	}
}
//노드 제거
void DelLinkedNode(LinkedHeaderNode* pLink, int position) {
	LinkedNode * pDelPoint = &(pLink->pHeader);
	LinkedNode * pPreNode = NULL;
	int i;
	if (position > pLink->Nodecount) {
		printf(" %d 위치는 아직 존제 하지 않습니다. 확인하고 사용해주세요.\n", position);
	}
	else {
		printf(" %d 위치의 자료를 제거 합니다.\n", position + 1);
		for (i = 0; i <= position; i++) {
			pPreNode = pDelPoint;
			pDelPoint = pDelPoint->pLink;
		}
		pPreNode->pLink = pDelPoint->pLink;
		free(pDelPoint);
		pLink->Nodecount--;
	}
}
//리스트 제거
void DelLinkedList(LinkedHeaderNode * pLink) {
	LinkedNode * pDelPoint = &(pLink->pHeader);
	LinkedNode * pPreNode = pDelPoint->pLink;
	printf("리스트를 정리합니다.\n");
	while (pPreNode != NULL) {
		pDelPoint = pPreNode;
		pPreNode = pPreNode->pLink;
		free(pDelPoint);
	}
	free(pLink);
}
//리스트의 현황을 출력
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
		printf("아직 데이터를 저장하지 않아 리스트가 존제하지 않습니다.\n");
	}
}