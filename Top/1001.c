/*Author: Ye Jintao; ID: 3150102210; No.02*/

#include <stdio.h>
#include <stdlib.h>

#define INFINITY (1<<30)

typedef struct edge
{
 	int city1;
 	int city2;
 	int cost;
 	//int status;
}Highway;

typedef struct keyCity
{
	int city[500];
	int top;
}KeyCity;

KeyCity keyCity; //Note key city

void input(int N, int M,
	Highway* highwayConnected, Highway* highwayDestroyed, int* C, int *D);

//Disjoint Set Operations
int setUnion(int* disjointSet, int a, int b);
int findRoot(int* disjointSet, int a);

int checkConnectedComponent(int* disjointSet, int N);
void findKeyCity(int* disjointSet, int N,
	Highway* highwayConnected, Highway* highwayDestroyed, int numC, int numD);
//Quick Sort
int compare(const void *a, const void *b);
//Heap Sort
// void pDown(Highway* highways, int index, int num);
// void heapSort(Highway* highways, int num);

int main()
{
	int N, M;
	int numC, numD; //Number of connected/unused ways
	int disjointSet[501];//A set to count connected components
	//Highway highways[300000];
    Highway highwayDestroyed[300000]; //Destroyed highways
    Highway highwayConnected[300000]; //Connected highways

	scanf("%d %d", &N, &M);

	keyCity.top = -1;

	input(N, M, highwayConnected, highwayDestroyed, &numC, &numD);
	//Substitute with heap sort XXXXXX
	qsort(highwayDestroyed, numD, sizeof(Highway), compare);//Sorted for min cost of rebuild
	//heapSort(highwayDestroyed, numD); //Heap sort is more slower!!!

	findKeyCity(disjointSet, N, highwayConnected, highwayDestroyed, numC, numD);

	if(keyCity.top == -1)
		printf("0\n");
	else
	{
		for(int i = 0; i < keyCity.top; i++)
			printf("%d ", keyCity.city[i]);
		printf("%d\n", keyCity.city[keyCity.top]);
	}

	return 0;
}

void input(int N, int M,
	Highway* highwayConnected, Highway* highwayDestroyed, int* C, int *D)
{
	*C = *D = 0;
	for(int i = 0; i < M; i++)
	{
		int city1, city2, cost, status; //Union 2 to 1
		scanf("%d %d %d %d", &city1, &city2, &cost, &status);
		if(status == 1)
		{
			//setUnion(disjointSet, city1, city2);
			highwayConnected[*C].city1 = city1;
			highwayConnected[*C].city2 = city2;
			highwayConnected[*C].cost = cost;
			(*C)++;
		}
		else
		{
			highwayDestroyed[*D].city1 = city1;
			highwayDestroyed[*D].city2 = city2;
			highwayDestroyed[*D].cost = cost;
			(*D)++;
		}
	}
}

int setUnion(int* disjointSet, int a, int b)
{
	int rootA = findRoot(disjointSet, a);
	int rootB = findRoot(disjointSet, b);
	if(rootB != rootA)
	{
		disjointSet[rootB] = rootA;
		return 1; //Union success
	}
	return 0; //Union failed
}

int findRoot(int* disjointSet, int a)
{
	if(disjointSet[a] == -1)
		return a;
	//return disjointSet[a] = findRoot(disjointSet, disjointSet[a]);
	return findRoot(disjointSet, disjointSet[a]);
	//DO NOT USE PATH COMPRESSION FOR IT WILL EXCEED TIME LIMIT!!
}

int checkConnectedComponent(int* disjointSet, int N)
{
	int count = 0;
	for(int i = 1; i <= N; i++)
		if(disjointSet[i] == -1)
			count++;
	return count;
}

int compare(const void *a, const void *b)
{
	return (*(Highway*)a).cost - (*(Highway*)a).cost;
}

void findKeyCity(int* disjointSet, int N,
	Highway* highwayConnected, Highway* highwayDestroyed, int numC, int numD)
{
	//int tempSet[501];
	int cost = 0, maxCost = 1;
	int num = 0; //Number of connected components without removed city
	for(int i = 1; i <= N; i++) //Traversal all the cities
	{
		cost = 0;
		num = 0;
		for(int j = 1; j <= N; j++)
			disjointSet[j] = -1;
		for(int j = 0; j < numC; j++) //Rebuild the set without cityi
		{
			if(highwayConnected[j].city1 == i || highwayConnected[j].city2 == i)
				continue;
			else
				setUnion(disjointSet, highwayConnected[j].city1, highwayConnected[j].city2);
		}

		num = checkConnectedComponent(disjointSet, N) - 1;//-1 because we remove i

		for(int j = 0; j < numD; j++) //Repair and calculate the cost
		{
			if(num == 1) //No need to repair
				break;
			else
			{
				if(highwayDestroyed[j].city1 == i || highwayDestroyed[j].city2 == i)
					continue; //i is occupied, adding this road won't change "num"
				else
				{
					//If union success, the number of connected components must -1
					if(setUnion(disjointSet, highwayDestroyed[j].city1, highwayDestroyed[j].city2))
					{
						cost += highwayDestroyed[j].cost;
						num--;
					} //If faild, do nothing
				}
			}
		}

		if(num > 1) //Cannot repair without i, set as the MAX 
			cost = INFINITY;
		if(cost > maxCost)
		{
			maxCost = cost;
			keyCity.top = 0;
			keyCity.city[0] = i;
		}
		else if(cost == maxCost)
			keyCity.city[++keyCity.top] = i;
	}
}


// void pDown(Highway* highways, int i, int num)
// {
// 	Highway temp = highways[i];
// 	int child;
// 	for(; 2 * i + 1 < num; i = child)
// 	{
// 		child = 2 * i + 1;
// 		if(highways[child].cost < highways[child + 1].cost)
// 			child++;
// 		if(temp.cost < highways[child].cost)
// 			highways[i] = highways[child];
// 	}
// 	highways[i] = temp;

// }
// void heapSort(Highway* highways, int num)
// {
// 	int i = num / 2;
// 	Highway temp;
// 	for(; i >= 0; i--) //Build Max heap
// 		pDown(highways, i, num);

// 	for(int j = num - 1; j > 0; j--)
// 	{
// 		temp = highways[j];
// 		highways[j] = highways[i];
// 		highways[i] = temp;
// 		pDown(highways, 0, j);
// 	}

// }
