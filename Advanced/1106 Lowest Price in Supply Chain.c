#include <stdio.h>
#include <stdlib.h>

typedef struct node *GNode;
struct node
{
	int id;
	GNode next;
};

typedef struct graph
{
	int capacity;
	GNode adjList;
}*Graph;

Graph createGraph(int n);
void input(Graph g);
void getMinPrice(Graph g, double initPrice, double increment);

double minPrice;
int minNum = 0;

int main()
{
	int n;
	double initPrice, increment;
	scanf("%d %lf %lf", &n, &initPrice, &increment);
	Graph g = createGraph(n);
	input(g);
	getMinPrice(g, initPrice, increment);

	printf("%.4f %d\n", minPrice, minNum);
	return 0;
}

Graph createGraph(int n)
{
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->capacity = n;
	g->adjList = (GNode)malloc(sizeof(struct node) * n);
	for(int i = 0; i < n; i++)
	{
		g->adjList[i].id = i;
		g->adjList[i].next = NULL;
	}
	return g;
}

void input(Graph g)
{
	int K, id;
	GNode currentNode, newNode;
	for(int i = 0; i < g->capacity; i++)
	{
		currentNode = &(g->adjList[i]);
		scanf("%d", &K);
		for(int j = 0; j < K; j++)
		{
			scanf("%d", &id);
			newNode = (GNode)malloc(sizeof(struct node));
			newNode->id = id;
			newNode->next = NULL;
			currentNode->next = newNode;
			currentNode = currentNode->next;
		}
	}
}

void getMinPrice(Graph g, double initPrice, double increment)
{
	int queue[100000];
	int front = -1, rear = -1;
	int member, last = 0;
	GNode memberNode;

	queue[++rear] = 0;
	minPrice = initPrice;

	while(front != rear)
	{
		member = queue[++front];
		memberNode = &(g->adjList[member]);

		if(!memberNode->next)
			minNum++;

		while(memberNode->next)
		{
			queue[++rear] = memberNode->next->id;
			memberNode = memberNode->next;
		}

		if(member == last)
		{
			minPrice = member == 0 ? minPrice : minPrice * (1 + increment / 100);
			last = queue[rear];
			if(minNum)
				break;
		}
	}
}