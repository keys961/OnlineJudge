//Dijkstra
#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

char hashtable[203][4] = { 0, };

int cityMap[203][203];
int happiness[203];

bool visited[203];
int dist[203];
int path[203];
int happy[203];
int wayCount[203];
int cityCount[203];

list<int> route;

int hashcode(char* city)
{
	int initVal = city[0] + city[1] + city[2] - 3 * 'A';
	while (strcmp(hashtable[initVal], "") != 0 && strcmp(city, hashtable[initVal]) != 0)
		initVal = (initVal + 1) % 203;
	strcpy(hashtable[initVal], city);
	return initVal;
}

char* toString(int cityCode)
{
	return hashtable[cityCode];
}

void solve(int startCity, int endCity);

int main()
{
	int n, k, h, d;
	char city[4];
	scanf("%d %d %s", &n, &k, city);
	char c1[4], c2[4];
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%s %d", c1, &h);
		happiness[hashcode(c1)] = h;
	}

	for (int i = 0; i < k; i++)
	{
		scanf("%s %s %d", c1, c2, &d);
		int code1 = hashcode(c1);
		int code2 = hashcode(c2);
		cityMap[code1][code2] = cityMap[code2][code1] = d;
	}

	int startCity = hashcode(city);
	int endCity = hashcode("ROM");
	solve(startCity, endCity);

	printf("%d %d %d %d\n", wayCount[endCity], dist[endCity], happy[endCity], happy[endCity] / cityCount[endCity]);
	auto it = route.begin();
	printf("%s", toString(*(it++)));
	for(; it != route.end(); it++)
		printf("->%s", toString(*it));
	printf("\n");
	return 0;
}

void solve(int startCity, int endCity)
{
	for (int i = 0; i < 203; i++)
	{
		dist[i] = 0x7fffffff;
		happy[i] = wayCount[i] = cityCount[i] = 0;
		visited[i] = false;
		path[i] = -1;
	}

	dist[startCity] = 0;
	wayCount[startCity] = 1;
	cityCount[startCity] = 0;
	happy[startCity] = happiness[startCity];

	while (true)
	{
		int minCity = -1;
		int minDist = 0x7fffffff;

		for (int i = 0; i < 203; i++)
		{
			if (!visited[i] && minDist > dist[i])
			{
				minCity = i;
				minDist = dist[i];
			}
		}

		if (minCity == -1)
			break;

		visited[minCity] = true;
		
		for (int i = 0; i < 203; i++)
		{
			if (!visited[i] && cityMap[minCity][i])
			{
				if (dist[i] > dist[minCity] + cityMap[minCity][i])
				{
					dist[i] = dist[minCity] + cityMap[minCity][i];
					path[i] = minCity;
					happy[i] = happy[minCity] + happiness[i];
					wayCount[i] = wayCount[minCity];
					cityCount[i] = cityCount[minCity] + 1;
				}
				else if (dist[i] == dist[minCity] + cityMap[minCity][i])
				{
					wayCount[i] += wayCount[minCity];
					if (happy[i] < happy[minCity] + happiness[i])
					{
						path[i] = minCity;
						happy[i] = happy[minCity] + happiness[i];
						cityCount[i] = cityCount[minCity] + 1;
					}
					else if (happy[i] == happy[minCity] + happiness[i])
					{
						if (cityCount[i] > cityCount[minCity] + 1)
						{
							path[i] = minCity;
							cityCount[i] = cityCount[minCity] + 1;
						}
					}
				}
			}
		}
	}

	while (endCity != -1)
	{
		route.push_front(endCity);
		endCity = path[endCity];
	}
}


// DFS
// #include <cstdio>
// #include <vector>
// #include <cstring>

// using namespace std;

// char hashtable[203][4] = {0,};// n = 203

// int graph[203][203] = {0, };
// int happiness[203] = {0};
// bool visited[203] = {false, };

// int routineCount = 0;
// int maxHappiness = 0;
// int leastCost = 0x7fffffff;
// vector<int> bestPath;

// int hashTo(char* city);
// void input(int n, int k);
// void getRoutine(int cityId, int cost, int happy, vector<int> tempPath);

// int main(int argc, char const *argv[])
// {
//     int n, k, cityId;
//     char startCity[4];
//     vector<int> tempPath;
//     scanf("%d %d %s", &n, &k, startCity);
//     input(n, k);
//     cityId = hashTo(startCity);
//     visited[cityId] = true;
//     getRoutine(cityId, 0, 0, tempPath);
//     printf("%d %d %d %d\n", routineCount, leastCost, maxHappiness, maxHappiness / (bestPath.size() - 1));
//     printf("%s", hashtable[bestPath[0]]);
//     for(int i = 1; i < bestPath.size(); i++)
//         printf("->%s", hashtable[bestPath[i]]);
//     printf("\n");
//     return 0;
// }

// int hashTo(char* city)
// {
//     int initVal = city[0] + city[1] + city[2] - 3 * 'A';
//     while(strcmp(hashtable[initVal], "") != 0 && strcmp(city, hashtable[initVal]) != 0)
//         initVal = (initVal + 1) % 203;
//     strcpy(hashtable[initVal], city);
//     return initVal;
// }

// void input(int n, int k)
// {
//     char city1[4], city2[4];
//     int val;
//     for(int i = 0; i < n - 1; i++)
//     {
//         scanf("%s %d", city1, &val);
//         happiness[hashTo(city1)] = val;
//     }
//     for(int i = 0; i < k; i++)
//     {
//         scanf("%s %s %d", city1, city2, &val);
//         int id1 = hashTo(city1), id2 = hashTo(city2);
//         graph[id1][id2] = graph[id2][id1] = val;
//     }
// }

// void getRoutine(int cityId, int cost, int happy, vector<int> tempPath)
// {
//     tempPath.push_back(cityId);
//     if(strcmp("ROM", hashtable[cityId]) == 0)
//     {
//         if(cost < leastCost)
//         {
//             bestPath = tempPath;
//             leastCost = cost;
//             routineCount = 1;
//             maxHappiness = happy;
//         }
//         else if(cost == leastCost)
//         {
//             routineCount++;
//             if(happy > maxHappiness ||
//                (happy == maxHappiness && 
//                 happy * 1.0 / tempPath.size()
//                  > maxHappiness * 1.0 / bestPath.size()))
//             {
//                 bestPath = tempPath;
//                 maxHappiness = happy;
//             }
//         }
//         return;
//     }
//     if(cost >= leastCost)
//         return;
//     //DFS
//     for(int i = 0; i < 203; i++)
//     {
//         if(graph[cityId][i] && !visited[i])
//         {
//             visited[i] = true;
//             getRoutine(i, cost + graph[cityId][i], happy + happiness[i], tempPath);
//             visited[i] = false;
//         }
//     }
// }