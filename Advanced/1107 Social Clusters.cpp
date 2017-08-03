#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int disjointSet[1001] = {-1};
map< int, vector<int> > hobbies; //ID -> Hobbies
vector<int> peopleOfClusters;

void input(int n);

int find(int i);
void link(int a, int b);
int solve(int n);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    input(n);
    printf("%d\n", solve(n));
    for(int i = peopleOfClusters.size() - 1; i > 0; i--)
        printf("%d ", peopleOfClusters[i]);
    printf("%d\n", peopleOfClusters[0]);
    return 0;
}

int find(int i)
{
    while(disjointSet[i] >= 0)
        i = disjointSet[i];
    return i;
}

void link(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    if(rootA == rootB)
        return;
    if(disjointSet[rootA] < disjointSet[rootB])
    {
        disjointSet[rootA] += disjointSet[rootB];
        disjointSet[rootB] = rootA;
    }
    else
    {
        disjointSet[rootB] += disjointSet[rootA];
        disjointSet[rootA] = rootB;
    }
}

void input(int n)
{
    for(int i = 0; i <= n; i++)
        disjointSet[i] = -1;
    int hobby, numOfHobbies;
    for(int i = 1; i <= n; i++)//i = id
    {
        scanf("%d:", &numOfHobbies);
        for(int j = 0; j < numOfHobbies; j++)
        {
            scanf("%d", &hobby);
            hobbies[i].push_back(hobby);
        }
        // Link
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < numOfHobbies; j++)
        {
            for(int k = 1; k <= n; k++)//k - opp id
            {
                if(k == i)
                    continue;
                for(int l = 0; l < hobbies[k].size(); l++)
                {
                    if(hobbies[i][j] == hobbies[k][l])
                    {
                        //link
                        link(i, k);
                        break;
                    }
                }
            }
        }
    }
}

int solve(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(disjointSet[i] < 0)
            peopleOfClusters.push_back(-disjointSet[i]);
    }
    sort(peopleOfClusters.begin(), peopleOfClusters.end());
    return peopleOfClusters.size();
}