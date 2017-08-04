#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int pairing[200000];
set<int> party;

vector<int> res;

void getSingle(int m);

int main(int argc, char const *argv[])
{
    int n, a, b, m;
    for(int i = 0; i < 200000; i++)
        pairing[i] = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        pairing[a] = b;
        pairing[b] = a;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        party.insert(a);
    }
    getSingle(m);
    printf("%d\n", res.size());
    if(res.size() == 0)
    	return 0;
    for(int i = 0; i < res.size() - 1; i++)
        printf("%05d ", res[i]);
    printf("%05d\n", res[res.size() - 1]);
    return 0;
}

void getSingle(int m)
{
    auto it = party.begin();
    for(; it != party.end(); it++)
    {
        if(pairing[*it] == -1 || party.find(pairing[*it]) == party.end())
            res.push_back(*it);
    }
}