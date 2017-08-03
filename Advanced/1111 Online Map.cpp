#include <cstdio>
#include <vector>
#include <algorithm>

#define INFINITE 0x7ffffff

using namespace std;

int distMap[500][500] = {0};
int timeMap[500][500] = {0};

bool visited[500];
int dist[500];//Distance
int times[500];//Time cost
int ways[500];//Number of edges  --- TO GET A PATH WITH MINIMUM EDGES/VERTICES

int path[500];

vector<int> minDistPath;
vector<int> minTimePath;

void dijkstra(int n, int src, int dst, int& minDist, int& minTime);
void getPath(int dst, int flag);

int main(int argc, char const *argv[])
{
    int n, m, src, dst;
    int v1, v2, oneway, len, t;
    int minDist, minTime;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d %d", &v1, &v2, &oneway, &len, &t);
        distMap[v1][v2] = len;
        timeMap[v1][v2] = t;
        if(oneway == 0)
        {
            distMap[v2][v1] = len;
            timeMap[v2][v1] = t;
        }
    }
    scanf("%d %d", &src, &dst);
    dijkstra(n, src, dst, minDist, minTime);
    if(minDistPath == minTimePath)
    {
        printf("Distance = %d; Time = %d: %d", minDist, minTime, minDistPath[0]);
        for(int i = 1; i < minDistPath.size(); i++)
            printf(" -> %d", minDistPath[i]);
        printf("\n");
    }
    else
    {
        printf("Distance = %d: %d", minDist, minDistPath[0]);
        for(int i = 1; i < minDistPath.size(); i++)
            printf(" -> %d", minDistPath[i]);
        printf("\n");
        printf("Time = %d: %d", minTime, minTimePath[0]);
        for(int i = 1; i < minTimePath.size(); i++)
            printf(" -> %d", minTimePath[i]);
        printf("\n");
    }
    return 0;
}

void dijkstra(int n, int src, int dst, int& minDist, int& minTime)
{
    int minVertex, minVal;
    //Get min dist
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        dist[i] = INFINITE;
        times[i] = INFINITE;
        path[i] = -1;
    }
    dist[src] = times[src] = 0;
    while(true)//For min dist
    {
        minVertex = -1;
        minVal = INFINITE;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < minVal)
            {
                minVal = dist[i];
                minVertex = i;
            }
        }
        if(minVertex == -1)
            break;
        visited[minVertex] = true;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && distMap[minVertex][i] != 0)
            {
                if(dist[minVertex] + distMap[minVertex][i] < dist[i])
                {
                    dist[i] = dist[minVertex] + distMap[minVertex][i];
                    times[i] = times[minVertex] + timeMap[minVertex][i];
                    path[i] = minVertex;
                }
                else if(dist[minVertex] + distMap[minVertex][i] == dist[i]
                        && times[minVertex] + timeMap[minVertex][i] < times[i])
                {
                    times[i] = times[minVertex] + timeMap[minVertex][i];
                    path[i] = minVertex;
                }
            }

        }
    }
    minDist = dist[dst];
    getPath(dst, 0);
    //Get min time
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        ways[i] = INFINITE;
        times[i] = INFINITE;
        path[i] = -1;
    }
    times[src] = ways[src] = 0;
    while(true)//For min time
    {
        minVertex = -1;
        minVal = INFINITE;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && times[i] < minVal)
            {
                minVal = times[i];
                minVertex = i;
            }
        }
        if(minVertex == -1)
            break;
        visited[minVertex] = true;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && timeMap[minVertex][i] != 0)
            {
                if(times[minVertex] + timeMap[minVertex][i] < times[i])
                {
                    ways[i] = ways[minVertex] + 1;
                    times[i] = times[minVertex] + timeMap[minVertex][i];
                    path[i] = minVertex;
                }
                else if(times[minVertex] + timeMap[minVertex][i] == times[i]
                        && ways[minVertex] + 1 < ways[i])
                {
                    ways[i] = ways[minVertex] + 1;
                    path[i] = minVertex;
                }
            }

        }
    }
    minTime = times[dst];
    getPath(dst, 1);
}

void getPath(int dst, int flag)//0:dist, 1:time
{
    while(dst != -1)
    {
        if(flag == 0)
            minDistPath.push_back(dst);
        else
            minTimePath.push_back(dst);
        dst = path[dst];
    }
    if(flag == 1)
        reverse(minTimePath.begin(), minTimePath.end());
    else
        reverse(minDistPath.begin(), minDistPath.end());
}