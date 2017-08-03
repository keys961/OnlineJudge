#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode *Polynomial;
typedef struct polyNode
{
	double Coefficient;
	int Exponent;
	Polynomial next;
}PolyNode;

Polynomial input(int n);
void print(Polynomial result);
Polynomial add(Polynomial a, Polynomial b);

int main()
{
	Polynomial A, B, result;
	int n;
	scanf("%d", &n);
	A = input(n);
	scanf("%d", &n);
	B = input(n);

	result = add(A, B);
	print(result);
	return 0;
}

Polynomial input(int n)
{
	Polynomial head = NULL, polynomial, temp = NULL;
	do
	{
		polynomial = (Polynomial)malloc(sizeof(PolyNode));
		if(temp)
			temp->next = polynomial;
		if(head == NULL)
			head = polynomial;
		temp = polynomial;
		scanf("%d %lf", &polynomial->Exponent, &polynomial->Coefficient);
		n--;
	}while(n);
	polynomial->next = NULL;
	return head;
}

Polynomial add(Polynomial a, Polynomial b)
{
	Polynomial polyA = a;
	Polynomial polyB = b;
	Polynomial result = (Polynomial)malloc(sizeof(struct polyNode));
	Polynomial temp = result, new;
	result->next = NULL;

	while(polyA && polyB)
	{
		if(polyA->Exponent > polyB->Exponent)
		{
			new = (Polynomial)malloc(sizeof(struct polyNode));
			new->Exponent = polyA->Exponent;
			new->Coefficient = polyA->Coefficient;
			new->next = NULL;
			temp->next = new;
			temp = new;
			polyA = polyA->next;
		}
		else if(polyA->Exponent < polyB->Exponent)
		{
			new = (Polynomial)malloc(sizeof(struct polyNode));
			new->Exponent = polyB->Exponent;
			new->Coefficient = polyB->Coefficient;
			new->next = NULL;
			temp->next = new;
			temp = new;
			polyB = polyB->next;
		}
		else
		{
			if(polyA->Coefficient + polyB->Coefficient)
			{
				new = (Polynomial)malloc(sizeof(struct polyNode));
				new->Exponent = polyB->Exponent;
				new->Coefficient = polyA->Coefficient + polyB->Coefficient;
				new->next = NULL;
				temp->next = new;
				temp = new;
			}
			polyB = polyB->next;
			polyA = polyA->next;
		}
	}

	while(polyA)
	{
		new = (Polynomial)malloc(sizeof(struct polyNode));
		new->Exponent = polyA->Exponent;
		new->Coefficient = polyA->Coefficient;
		new->next = NULL;
		temp->next = new;
		temp = new;
		polyA = polyA->next;
	}
	while(polyB)
	{
		new = (Polynomial)malloc(sizeof(struct polyNode));
		new->Exponent = polyB->Exponent;
		new->Coefficient = polyB->Coefficient;
		new->next = NULL;
		temp->next = new;
		temp = new;
		polyB = polyB->next;
	}
	return result;
}

void print(Polynomial result)
{
	result = result->next;
	Polynomial temp = result;
	int count = 0;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
	if(count)
        printf("%d ", count);
    else
    {
        printf("0\n");
        return;
    }
	while(result)
	{
		if(result->next)
			printf("%d %.1f ", result->Exponent, result->Coefficient);
		else
			printf("%d %.1f\n", result->Exponent, result->Coefficient);

        result = result->next;
	}
}
