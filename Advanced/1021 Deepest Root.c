#include <stdio.h>
#include <stdlib.h>

//Use adjList and BFS
//If use adjMatrix or DFS, there will be Memory Exceeded!!

int visited[10001];
int dist[10001];
int disjointSet[10001] = {0,};
int height = 0, maxHeightTemp = 0, maxHeight = 0;
int component = 0;

typedef struct graphNode *Node;
struct graphNode
{
	int data;
	Node next;
};

typedef struct graph
{
	Node adjList[10001];
}Graph;

struct Result
{
	int maxHeightNode[10000];
	int top;
};

Graph g;

struct Result result;

void input(int N);
void restore(int N);
void bfs(int i, int N);
void getDeepestRoot(int N);

void setUnion(int a, int b);
int findRoot(int a);
int countComponents(int N);

int main()
{
	int N;
	int component = 0;
	scanf("%d", &N);
	for(int i = 0; i <= N; i++)
        g.adjList[i] = NULL;
	result.top = -1;

	input(N);

	component = countComponents(N);
	if(component > 1)
        printf("Error: %d components\n", component);
    else
    {
        getDeepestRoot(N);
        for(int i = 0; i <= result.top; i++)
			printf("%d\n", result.maxHeightNode[i]);
    }
	return 0;
}

int findRoot(int a)
{
    if(disjointSet[a] == 0)
        return a;
    return disjointSet[a] = findRoot(disjointSet[a]);
}

void setUnion(int a, int b)
{
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA != rootB)
        disjointSet[rootB] = rootA;
}

int countComponents(int N)
{
    int count = 0;
    for(int i = 1; i <= N; i++)
        if(disjointSet[i] == 0)
            count++;
    return count;
}

void restore(int N)
{
	for(int i = 0; i <= N; i++)
	{
		visited[i] = 0;
		dist[i] = 0;
	}
}

void input(int N)
{
	int a, b;
	Node temp;
	for(int i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		setUnion(a, b);
		if(g.adjList[a] == NULL)
		{
			g.adjList[a] = (Node)malloc(sizeof(struct graphNode));
			g.adjList[a]->data = b;
			g.adjList[a]->next = NULL;
		}
		else
		{
			temp = g.adjList[a];
			while(temp->next)
				temp = temp->next;
			temp->next = (Node)malloc(sizeof(struct graphNode));
			temp->next->data = b;
			temp->next->next = NULL;
		}
		if(g.adjList[b] == NULL)
		{
			g.adjList[b] = (Node)malloc(sizeof(struct graphNode));
			g.adjList[b]->data = a;
			g.adjList[b]->next = NULL;
		}
		else
		{
			temp = g.adjList[b];
			while(temp->next)
				temp = temp->next;
			temp->next = (Node)malloc(sizeof(struct graphNode));
			temp->next->data = a;
			temp->next->next = NULL;
		}

	}
}

void bfs(int i, int N)
{
	int queue[10000];
    int temp;
    Node tempNode;
    int front = -1, rear = -1;
    queue[++rear] = i;
    visited[i] = 1;

    while(front != rear)
    {
        temp = queue[++front];
        tempNode = g.adjList[temp];
        while(tempNode)
        {
            if(!visited[tempNode->data])
            {
                queue[++rear] = tempNode->data;
                visited[tempNode->data] = 1;
                height = dist[tempNode->data] = dist[temp] + 1;
                if(height > maxHeightTemp)
                    maxHeightTemp = height;
            }
            tempNode = tempNode->next;
        }
    }
}

void getDeepestRoot(int N)
{
    for(int j = 1; j <= N; j++)
    {
        restore(N);
        maxHeightTemp = 0;
        bfs(j, N);
        if(maxHeightTemp > maxHeight)
        {
            maxHeight = maxHeightTemp;
            result.top = 0;
            result.maxHeightNode[result.top] = j;
        }
        else if(maxHeightTemp == maxHeight)
            result.maxHeightNode[++result.top] = j;
    }
}
