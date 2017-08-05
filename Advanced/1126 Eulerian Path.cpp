#include <cstdio>

using namespace std;

int graph[501][501] = {0};
int degree[501] = {0};
bool visited[501] = {false};

bool hasEulerCircuit(int n);
bool hasEulerPath(int n);
bool isConnect(int n, int vertex);

int main(int argc, char const *argv[])
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
        degree[a]++;
        degree[b]++;
    }
    printf("%d", degree[1]);
    for(int i = 2; i <= n; i++)
        printf(" %d", degree[i]);
    printf("\n");
    if(!isConnect(n, 1))//First must be connected
    	printf("Non-Eulerian\n");
    else if(hasEulerCircuit(n))
        printf("Eulerian\n");
    else if(hasEulerPath(n))
        printf("Semi-Eulerian\n");
    else
        printf("Non-Eulerian\n");
    return 0;
}

bool hasEulerCircuit(int n)
{
    for(int i = 1; i <= n; i++)
        if(degree[i] % 2)
            return false;
    return true;
}

bool hasEulerPath(int n)
{
    int oddCount = 0;
    for(int i = 1; i <= n; i++)
        if(degree[i] % 2)
            oddCount++;
    if(oddCount == 2)
        return true;
    else
        return false;
}

bool isConnect(int n, int vertex)
{
	visited[vertex] = true;
    for(int i = 1; i <= n; i++)
    {
    	if(!visited[i] && graph[vertex][i])
    		isConnect(n, i);
    }
    for(int i = 1; i <= n; i++)
    	if(!visited[i])
    		return false;
    return true;
}	
