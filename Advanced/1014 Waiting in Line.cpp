#include <cstdio>
#include <map>
#include <list>

using namespace std;

struct Customer
{
    int id;
    int consumeTime;
};

map< int, list<Customer> > windows;
Customer customers[1001];
int customerTime[1001];

int checkInLine(int n, int m);
int waitWindow(int n, int& currentTime);
void getFinishTime(int n, int m, int k);

int main(int argc, char const *argv[])
{
    int n, m, k, q, id;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 1; i <= k; i++)
    {
        customers[i].id = i;
        scanf("%d", &customers[i].consumeTime);
    }
    getFinishTime(n, m, k);
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &id);
        if(customerTime[id] - customers[id].consumeTime >= 17 * 60)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", customerTime[id] / 60, customerTime[id] % 60);
    }
    return 0;
}


int checkInLine(int n, int m)
{
    int minSize = m + 1;
    int windowsId = -1;
    for(int i = 0; i < n; i++)
    {
        if(windows[i].size() < m)
        {
            if(windows[i].size() < minSize)
            {
                minSize = windows[i].size();
                windowsId = i;
            }
        }
    }
    return windowsId;
}

int waitWindow(int n, int& currentTime)
{
    int windowId = 0;
    int minWait = 0x7fffffff;
    for(int i = 0; i < n; i++)
    {
        if(windows[i].front().consumeTime < minWait)
        {
            windowId = i;
            minWait = windows[i].front().consumeTime;
        }
    }
    currentTime += minWait;
    for(int i = 0; i < n; i++)
    {
        windows[i].front().consumeTime -= minWait;
        if(windows[i].front().consumeTime == 0)
        {
            customerTime[windows[i].front().id] = currentTime;
            windows[i].pop_front();
        }
    }
    return windowId;
}

void getFinishTime(int n, int m, int k)
{
    int currentTime = 8 * 60;
    int windowId;
    for(int i = 1; i <= k; i++)
    {
        windowId = checkInLine(n, m);
        if(windowId != -1)
            windows[windowId].push_back(customers[i]);
        else
        {
            windowId = waitWindow(n, currentTime);
            windows[windowId].push_back(customers[i]);
        }
    }
    //Last deal
    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        for(auto it = windows[i].begin(); it != windows[i].end(); it++)
        {
            temp += it->consumeTime;
            customerTime[it->id] = currentTime + temp;
        }
    }
}
