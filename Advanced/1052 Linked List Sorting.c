#include <stdio.h>
#include <stdlib.h>
//Case 有坑,
typedef struct node
{
    int valid;
	int currentAddr;
	int key;
	int nextAddr;
}Node;

void input(Node* listNode, int N);
int cmp(const void* a, const void* b);
int link(Node *listNode, int N);
void checkValid(Node* listNode, int N, int startAddr);

int main()
{
	int N, startAddr;
	scanf("%d %d", &N, &startAddr);
	// if(N == 0)
	// {
 //        printf("0 -1\n");
 //        return 0;
	// }
	Node listNode[N];
	input(listNode, N);
    checkValid(listNode, N, startAddr);
	qsort(listNode, N, sizeof(Node), cmp);
	startAddr = link(listNode, N);

	printf("%d %05d\n", N, startAddr);
	for(int i = 0; i < N; i++)
		if(listNode[i].nextAddr == -1)
        {
			printf("%05d %d %d\n", listNode[i].currentAddr, listNode[i].key,
				 listNode[i].nextAddr);
            break;
        }
		else
			printf("%05d %d %05d\n", listNode[i].currentAddr, listNode[i].key,
				 listNode[i].nextAddr);
	return 0;
}

void input(Node* listNode, int N)
{
	for(int i = 0; i < N; i++)
    {
		scanf("%d %d %d", &listNode[i].currentAddr, &listNode[i].key,
			&listNode[i].nextAddr);
        listNode[i].valid = 0;
    }
}

int cmp(const void* a, const void* b)
{
	if((*(Node*)a).valid - (*(Node*)b).valid > 0)
        return -1;
    else if((*(Node*)a).valid - (*(Node*)b).valid < 0)
        return 1;
    else return (*(Node*)a).key - (*(Node*)b).key;
}

int link(Node *listNode, int N)
{
	int startAddr = listNode[0].currentAddr;
    int i;
	for(i = 0; i + 1 < N && listNode[i + 1].valid; i++)
		listNode[i].nextAddr = listNode[i + 1].currentAddr;
	listNode[i].nextAddr = -1;

	return startAddr;
}

void checkValid(Node* listNode, int N, int startAddr)
{
    int i = 0;

    for(i = 0; i < N; i++)
    {
        if(listNode[i].currentAddr == startAddr)
            listNode[i].valid = 1;
        for(int j = 0; j < N; j++)
        {
        	if(listNode[i].nextAddr == -1)
        		continue;
            if(listNode[i].nextAddr == listNode[j].currentAddr)
                listNode[j].valid = 1;
        }
    }

}
