#include <cstdio>
#include <queue>

using namespace std;

int network[1001][1001] = {0,};
bool visited[1001] = {false};

void buildGraph(int n);//Build reversly
void query(int n, int l, int k);
int getForwardNum(int n, int l, int id);

int main(int argc, char const *argv[])
{
    int n, l, k;
    scanf("%d %d", &n, &l);
    buildGraph(n);
    scanf("%d", &k);
    query(n, l, k);
    return 0;
}

void buildGraph(int n)
{
    int m, id;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &id);
            network[id][i] = 1;
        }
    }
}

void query(int n, int l, int k)
{
    int id;
    for(int i = 0; i < k; ++i)
    {
        scanf("%d", &id);
        printf("%d\n", getForwardNum(n, l, id));
    }
}

int getForwardNum(int n, int l, int id)
{
    for(int i = 0; i <= n; i++)
        visited[i] = false;
    visited[id] = true;
    int level = 0, count = 0;
    int currentUser, lastUser = id;
    queue<int> followers;
    followers.push(id);
    while(!followers.empty() && level < l)
    {
        currentUser = followers.front();
        followers.pop();
        for(int i = 1; i <= n; i++)
        {
            if(network[currentUser][i] && !visited[i])
            {
                followers.push(i);
                visited[i] = true;
                count++;
            }
        }
        if(currentUser == lastUser)
        {
            level++;
            lastUser = followers.back();
        }
    }
    return count;
}