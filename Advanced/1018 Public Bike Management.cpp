#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define Infinate 100000000

using namespace std;

struct Path
{
    int stack[501];
    int top;
};

int stationGraph[501][501];
int currentState[501] = {0,}; //Bike number
int length = 0, minLength = Infinate;
int carry = 0, minCarry = Infinate;
int back = 0, minBack = Infinate;
int flag = 0;
int visited[501] = {1,};
struct Path path, minPath;

void Init(int N);
void Input(int N, int M);
void FindWay(int currentStation, int previousStation, int N, int Sp, int Cmax); //Use DFS
void PrintPath();
//DFS
int main()
{
    int Cmax, N, Sp, M;
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    Init(N);
    Input(N, M);
    FindWay(0, 0, N, Sp, Cmax);
    printf("%d ", minCarry);
    PrintPath();
    printf(" %d\n", minBack);
    return 0;
}

void Init(int N)
{
    path.top = -1;
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
            stationGraph[i][j] = 0;
    }
}

void Input(int N, int M)
{
    int Si, Sj, weight;
    for(int i = 1; i <= N; i++)
        scanf("%d", &currentState[i]);
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &Si, &Sj, &weight);
        stationGraph[Si][Sj] = stationGraph[Sj][Si] = weight;
    }
}

void FindWay(int currentStation, int previousStation, int N, int Sp, int Cmax)
{
    int i;
    int lastLength = length, lastCarry = carry, lastBack = back; //Store previous info to trace back
    //Calculate
    visited[currentStation] = 1;
    length += stationGraph[previousStation][currentStation];
    path.stack[++path.top] = currentStation;
    if(currentStation != 0)
    {
        if(currentState[currentStation] >= Cmax / 2) //Back
            back += currentState[currentStation] - Cmax / 2;
        else //carry
        {
            if(back >= Cmax / 2 - currentState[currentStation])
                back -= Cmax / 2 - currentState[currentStation];
            else
            {

                carry += Cmax / 2 - currentState[currentStation] - back;
                back = 0;
            }
        }
    }
    //Base case
    if(currentStation == Sp)
    {
        if(length < minLength)
        {
            minLength = length;
            minCarry = carry;
            minBack = back;
            minPath = path;
        }
        else if(length == minLength)
        {
            if(minCarry > carry || ((minCarry == carry) && (minBack > back)))
            {
                minCarry = carry;
                minBack = back;
                minPath = path;
            }
        }
    }
    //Recursion
    else
    {
        for(i = 1; i <= N; i++)
        {
            if(visited[i] == 0 && stationGraph[currentStation][i] > 0)
                FindWay(i, currentStation, N, Sp, Cmax);
        }
    }
    //Return
    visited[currentStation] = 0;
    length = lastLength;
    carry = lastCarry;
    back = lastBack;
    path.top--;
}

void PrintPath()
{
    for(int i = 0; i < minPath.top; i++)
        printf("%d->", minPath.stack[i]);
    printf("%d", minPath.stack[minPath.top]);
}

// Dijkstra

// int cityMap[501][501];
// int currentBikes[501];

// bool visited[501];

// int remain[501]; //Take back
// int send[501]; //Take there
// int dist[501];
// int path[501];

// vector<int> res;
// int bikeSend, bikeBack;

// void solve(int cmax, int n, int sp);

// int main()
// {
// 	int cmax, n, sp, m;
// 	scanf("%d %d %d %d", &cmax, &n, &sp, &m);
// 	for (int i = 1; i <= n; i++)
// 	{
// 		scanf("%d", &currentBikes[i]);
// 		visited[i] = false;
// 		remain[i] = send[i] = dist[i] = 0x7fffffff;
// 		path[i] = -1;
// 	}
// 	for (int i = 0; i < m; i++)
// 	{
// 		int c1, c2, weight;
// 		scanf("%d %d %d", &c1, &c2, &weight);
// 		cityMap[c1][c2] = cityMap[c2][c1] = weight;
// 	}

// 	solve(cmax, n, sp);

// 	printf("%d 0", bikeSend);
// 	for (int i = 0; i < res.size(); i++)
// 		printf("->%d", res[i]);
// 	printf(" %d\n", bikeBack);

//     return 0;
// }

// void solve(int cmax, int n, int sp)
// {
// 	dist[0] = remain[0] = send[0] = 0;
// 	while (true)
// 	{
// 		int minDist = 0x7fffffff;
// 		int minSite = -1;
// 		for (int i = 0; i <= n; i++)
// 		{
// 			if (!visited[i])
// 			{
// 				if (dist[i] < minDist)
// 				{
// 					minDist = dist[i];
// 					minSite = i;
// 				}
// 			}
// 		}

// 		if (minSite == -1 || minSite == sp)
// 			break;

// 		visited[minSite] = true;

// 		for (int i = 1; i <= n; i++)
// 		{
// 			if (!visited[i] && cityMap[minSite][i])
// 			{
// 				if (dist[i] > cityMap[minSite][i] + dist[minSite])
// 				{
// 					dist[i] = cityMap[minSite][i] + dist[minSite];
// 					path[i] = minSite;

// 					int diff = cmax / 2 - currentBikes[i];
// 					if (diff > 0) // Not enough
// 					{
// 						remain[i] = remain[minSite] - diff;
// 						if (remain[i] < 0) //Remain not enough
// 						{
// 							send[i] = send[minSite] + diff - remain[minSite];
// 							remain[i] = 0;
// 						}
// 						else
// 							send[i] = send[minSite];
// 					}
// 					else
// 					{
// 						remain[i] = remain[minSite] - diff;
// 						send[i] = send[minSite];
// 					}
// 				}
// 				else if (dist[i] == cityMap[minSite][i] + dist[minSite])
// 				{
// 					int diff = cmax / 2 - currentBikes[i];
// 					int tempSend, tempRemain;
// 					if (diff > 0) // Not enough
// 					{
// 						tempRemain = remain[minSite] - diff;
// 						if (tempRemain < 0) //Remain not enough
// 						{
// 							tempSend = send[minSite] + diff - remain[minSite];
// 							tempRemain = 0;
// 						}
// 						else
// 							tempSend = send[minSite];
// 					}
// 					else
// 					{
// 						tempRemain = remain[minSite] - diff;
// 						tempSend = send[minSite];
// 					}

// 					if (tempSend < send[i] || (tempSend == send[i] && tempRemain < remain[i]))
// 					{
// 						path[i] = minSite;
// 						send[i] = tempSend;
// 						remain[i] = tempRemain;
// 					}
// 				}
// 			}
// 		}
// 	}

// 	bikeSend = send[sp];
// 	bikeBack = remain[sp];

// 	while (sp != 0)
// 	{
// 		res.push_back(sp);
// 		sp = path[sp];
// 	}

// 	reverse(res.begin(), res.end());
// }