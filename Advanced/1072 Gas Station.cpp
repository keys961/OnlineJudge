#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define INFINITE 0x7fffffff

bool visited[2011] = {false};//G1-G10, 1-1000 if full
int dist[2011];
int graph[2011][2011] = {0};

int bestId = 0;
double minDist, avgDist;

int getId(char* id, int m);
void input(int n, int m, int k);
void init(int n, int m, int stationId);
void solve(int n, int m, int k, int ds);
void dijkstra(int n, int m);

int main(int argc, char const *argv[])
{
    int n, m, k, ds;//Houses, Stations, Roads, Service-range
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    minDist = -1;
    avgDist = INFINITE;
    input(n, m, k);
    solve(n, m, k, ds);
    if(bestId == 0)
        printf("No Solution\n");
    else
        printf("G%d\n%.1f %.1f\n", bestId, minDist, avgDist);
    return 0;
}

int getId(char* id, int m)
{
    if(strlen(id) == 2)
        return id[1] - '0';
    else
        return id[0] - '0' + m;
}

void input(int n, int m, int k)
{
    char p1[3];
    char p2[3];
    int distance;
    for(int i = 1; i <= m + n; i++)
    	for(int j = 1; j <= m + n; j++)
    		graph[i][j] = INFINITE;
    for(int i = 0; i < k; i++)
    {
        scanf("%s %s %d", p1, p2, &distance);
        graph[getId(p1, m)][getId(p2, m)] =
        	graph[getId(p2, m)][getId(p1, m)] = distance;
    }
}

void init(int n, int m, int stationId)
{
    for(int i = 1; i <= m + n; i++)
    {
        visited[i] = false;
        dist[i] = (i == stationId ? 0 : INFINITE);
    }
}

void solve(int n, int m, int k, int ds)
{
    int i, j;
    double totalDist;
    double mDist;
    for(i = 1; i <= m; i++)
    {
        totalDist = 0.0;
        mDist = ds + 1;
        init(n, m, i);
        dijkstra(n, m);
        for(j = m + 1; j <= n + m; j++)
        {
            if(dist[j] > ds)
                break;
            totalDist += dist[j];
            if(dist[j] < mDist)
                mDist = dist[j];
        }
        if(j == n + m + 1)
        {
            if(mDist > minDist)
            {
                minDist = mDist;
                avgDist = totalDist / (n * 1.0);
                bestId = i;
            }
            else if(mDist == minDist && totalDist / (n * 1.0) < avgDist)
            {
                avgDist = totalDist / (n * 1.0);
                bestId = i;
            }
        }
    }
}

void dijkstra(int n, int m)
{
    int minVertex;
    int minDist;

    for(; ;)
    {
        minVertex = -1;
        minDist = INFINITE;
        for(int i = 1; i <= m + n; i++)
        {
            if(!visited[i] && dist[i] < minDist)
            {
                minVertex = i;
                minDist = dist[i];
            }
        }
        if(minVertex == -1)
            break;
        visited[minVertex] = true;
        for(int i = 1; i <= m + n; i++)
        {
            if(!visited[i] && graph[minVertex][i] != INFINITE &&
               graph[minVertex][i] + dist[minVertex] < dist[i])
                dist[i] = graph[minVertex][i] + dist[minVertex];
        }
    }
}