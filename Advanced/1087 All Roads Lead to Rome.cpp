#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char hashtable[203][4] = {0,};// n = 203

int graph[203][203] = {0, };
int happiness[203] = {0};
bool visited[203] = {false, };

int routineCount = 0;
int maxHappiness = 0;
int leastCost = 0x7fffffff;
vector<int> bestPath;

int hashTo(char* city);
void input(int n, int k);
void getRoutine(int cityId, int cost, int happy, vector<int> tempPath);

int main(int argc, char const *argv[])
{
    int n, k, cityId;
    char startCity[4];
    vector<int> tempPath;
    scanf("%d %d %s", &n, &k, startCity);
    input(n, k);
    cityId = hashTo(startCity);
    visited[cityId] = true;
    getRoutine(cityId, 0, 0, tempPath);
    printf("%d %d %d %d\n", routineCount, leastCost, maxHappiness, maxHappiness / (bestPath.size() - 1));
    printf("%s", hashtable[bestPath[0]]);
    for(int i = 1; i < bestPath.size(); i++)
        printf("->%s", hashtable[bestPath[i]]);
    printf("\n");
    return 0;
}

int hashTo(char* city)
{
    int initVal = city[0] + city[1] + city[2] - 3 * 'A';
    while(strcmp(hashtable[initVal], "") != 0 && strcmp(city, hashtable[initVal]) != 0)
        initVal = (initVal + 1) % 203;
    strcpy(hashtable[initVal], city);
    return initVal;
}

void input(int n, int k)
{
    char city1[4], city2[4];
    int val;
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%s %d", city1, &val);
        happiness[hashTo(city1)] = val;
    }
    for(int i = 0; i < k; i++)
    {
        scanf("%s %s %d", city1, city2, &val);
        int id1 = hashTo(city1), id2 = hashTo(city2);
        graph[id1][id2] = graph[id2][id1] = val;
    }
}

void getRoutine(int cityId, int cost, int happy, vector<int> tempPath)
{
    tempPath.push_back(cityId);
    if(strcmp("ROM", hashtable[cityId]) == 0)
    {
        if(cost < leastCost)
        {
            bestPath = tempPath;
            leastCost = cost;
            routineCount = 1;
            maxHappiness = happy;
        }
        else if(cost == leastCost)
        {
            routineCount++;
            if(happy > maxHappiness ||
               (happy == maxHappiness && 
                happy * 1.0 / tempPath.size()
                 > maxHappiness * 1.0 / bestPath.size()))
            {
                bestPath = tempPath;
                maxHappiness = happy;
            }
        }
        return;
    }
    if(cost >= leastCost)
        return;
    //DFS
    for(int i = 0; i < 203; i++)
    {
        if(graph[cityId][i] && !visited[i])
        {
            visited[i] = true;
            getRoutine(i, cost + graph[cityId][i], happy + happiness[i], tempPath);
            visited[i] = false;
        }
    }
}