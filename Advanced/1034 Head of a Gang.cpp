#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;

int disjointSet[20000];//Disjoint Set
int countMin[20000] = {0}; //Count Minute
map<int, int> result;

int hash(char* name);
char* hashRev(int id);
//Disjoint Set
int find(int id);
void join(int idA, int idB, int minute);
//Solve
void input(int n);
void solve(int k);

int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	input(n);
    solve(k);
	return 0;
}

int hashTo(char* name)
{
    return (name[2] - 'A') + 
        (name[1] - 'A') * 26 + 
        (name[0] - 'A') * 26 * 26;
}

char* hashRev(int id)
{
    char* name = new char[4];
    name[3] = 0;
    int i = 2;
    while(i >= 0)
    {
        name[i--] = id % 26 + 'A';
        id /= 26;
    }
    return name;
}

int find(int id)
{
    while(disjointSet[id] >= 0)
        id = disjointSet[id];
    return id;
}

void join(int idA, int idB, int minute)
{
    int idA2 = find(idA);
    int idB2 = find(idB);
    if(idA2 != idB2)
    {
        if(disjointSet[idA2] < disjointSet[idB2])
        {
            disjointSet[idA2] += disjointSet[idB2];
            disjointSet[idB2] = idA2;
        }
        else
        {
            disjointSet[idB2] += disjointSet[idA2];
            disjointSet[idA2] = idB2;
        }
    }
    countMin[idA] += minute;
    countMin[idB] += minute;
}

void input(int n)
{
    for(int i = 0; i < 20000; i++)
        disjointSet[i] = -1;
    char name1[4] = {0};
    char name2[4] = {0};
    int minute;
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s %d", name1, name2, &minute);
        join(hashTo(name1), hashTo(name2), minute);
    }
}

void solve(int k)
{
    //int count = 0;
    for(int i = 0; i < 20000; i++)
    {
        if(disjointSet[i] < -2)//Find, i is set
        {
            //count++;
            int minute = 0;
            int maxMin = 0;
            int maxId;
            for(int j = 0; j < 20000; j++)
            {
                if(find(j) == i)
                {
                    minute += countMin[j];
                    if(countMin[j] > maxMin)
                    {
                        maxMin = countMin[j];
                        maxId = j;
                    }
                }
            }
            if(minute > 2 * k)
                result[maxId] = -disjointSet[i];
        }
    }
    printf("%d\n", result.size());
    map<int, int>::iterator it = result.begin();
    for(; it != result.end(); it++)
        printf("%s %d\n", hashRev(it->first), it->second);
}