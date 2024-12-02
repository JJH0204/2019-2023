#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	node * Nptr = NULL;
};

struct StartNode {
	unsigned int d_count = 0;
	node * Nptr = NULL;
};

node * NewData(int data) {
	node * ptr = NULL;
	ptr = (node*)malloc(sizeof(node));
	ptr->data = data;
	return ptr;
}
void Addnode(StartNode * sNode, int data) {
	static node * scanpoint = NULL;
	if (sNode->Nptr == NULL) {
		sNode->Nptr = NewData(data);
		scanpoint = sNode->Nptr;
	}
	else {
		scanpoint->Nptr = NewData(data);
		scanpoint = scanpoint->Nptr;
	}
	sNode->d_count++;
}
void PrintLinkData(StartNode * sNode) {
	node * printpoint = sNode->Nptr;
	int count = 1;
	while (printpoint != NULL) {
		printf("%d. %d\n", count, printpoint->data);
		printpoint = printpoint->Nptr;
		count++;
	}
}
void FreeNode(StartNode * sNode) {
	node* delpoint = NULL;
	node* nextnode = sNode->Nptr;
	while (nextnode != NULL) {
		delpoint = nextnode;
		nextnode = delpoint->Nptr;
		free(delpoint);
	}
	free(nextnode);
}
int main(void) {
	StartNode s_node;
	int Scan_data = 0;
	while(true) {
		scanf("%d", &Scan_data);
		if (Scan_data == -1) {
			break;
		}
		Addnode(&s_node, Scan_data);
		printf("s_node.count: %d\n", s_node.d_count);
	}
	PrintLinkData(&s_node);
	FreeNode(&s_node);
}