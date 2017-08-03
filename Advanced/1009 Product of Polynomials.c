#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode *PolyNodePtr;
struct polyNode
{
	double cofficient;
	int exponent;
	PolyNodePtr next;
};

PolyNodePtr input(int N);
PolyNodePtr multiply(PolyNodePtr polyA, PolyNodePtr polyB);
void output(PolyNodePtr answer);
int getCount(PolyNodePtr answer);

int main()
{
	int N1, N2;
	scanf("%d", &N1);
	PolyNodePtr polyA = input(N1);
	scanf("%d", &N2);
	PolyNodePtr polyB = input(N2);
	PolyNodePtr answer = multiply(polyA, polyB);

	printf("%d", getCount(answer));
	output(answer);

	return 0;
}

PolyNodePtr input(int N)
{
	PolyNodePtr head = (PolyNodePtr)malloc(sizeof(struct polyNode));
	head->next = NULL;

	PolyNodePtr current = head, new;
	int exponent;
	double cofficient;

	for(int i = 0; i < N; i++)
	{
		new = (PolyNodePtr)malloc(sizeof(struct polyNode));
		new->next = NULL;
		current->next = new;
		current = current->next;

		scanf("%d %lf", &exponent, &cofficient);
		current->exponent = exponent;
		current->cofficient = cofficient;
	}

	return head;
}

PolyNodePtr multiply(PolyNodePtr polyA, PolyNodePtr polyB)
{
	int exponent;
	double cofficient;
	PolyNodePtr answerHead = (PolyNodePtr)malloc(sizeof(struct polyNode));
	answerHead->next = NULL;
	PolyNodePtr current = answerHead, new;
	//Do first
	PolyNodePtr ptrA = polyA->next, ptrB = polyB->next;
	while(ptrA && ptrB)
	{
		new = (PolyNodePtr)malloc(sizeof(struct polyNode));
		new->next = NULL;
		current->next = new;
		current = current->next;

		current->exponent = ptrA->exponent + ptrB->exponent;
		current->cofficient = ptrA->cofficient * ptrB->cofficient;

		ptrB = ptrB->next;
	}
	//Do rest
	ptrA = ptrA->next; ptrB = polyB->next;
	while(ptrA)
	{
		current = answerHead->next;
		exponent = ptrA->exponent + ptrB->exponent;
		cofficient = ptrA->cofficient * ptrB->cofficient;
		while(current->next)
		{
			if(current->next->exponent <= exponent)
				break;
			current = current->next;
		}
		while(ptrB)
		{
			//current = answerHead->next;
			exponent = ptrA->exponent + ptrB->exponent;
			cofficient = ptrA->cofficient * ptrB->cofficient;

			while(current->next)
			{
				if(current->next->exponent <= exponent)
					break;
				current = current->next;
			}

			if(current->next && current->next->exponent == exponent)
				current->next->cofficient += cofficient;
			else
			{
				new = (PolyNodePtr)malloc(sizeof(struct polyNode));
				new->next = current->next;
				current->next = new;
				new->cofficient = cofficient;
				new->exponent = exponent;
			}
			ptrB = ptrB->next;
		}
		ptrA = ptrA->next;
		ptrB = polyB->next;
	}
	return answerHead;
}

int getCount(PolyNodePtr answer)
{
	int count = 0;

	PolyNodePtr temp = answer->next;
	while(temp)
	{
		if(temp->cofficient != 0)
			count++;
		temp = temp->next;
	}

	return count;
}

void output(PolyNodePtr answer)
{
	PolyNodePtr temp = answer->next;

	while(temp)
	{
		if(temp->cofficient != 0)
			printf(" %d %.1f", temp->exponent, temp->cofficient);
        temp = temp->next;
	}
	printf("\n");

}
