// Like this question, if dijkstra is complicated, use dfs

#include <iostream>
#include <vector>
#include <cstring>

#define MAX 0x7fffffff

using namespace std;

struct Station
{
    int id;
    int lineId;
    Station(int id, int lineId)
    {
        this->id = id;
        this->lineId = lineId;
    }
};

struct Node
{
    vector<Station> adjStations;
};

struct Segment
{
    int lineId;
    int start, end;
    Segment(int lineId, int start, int end)
    {
        this->lineId = lineId;
        this->start = start;
        this->end = end;
    }
};

struct Answer
{
    vector<Segment> list;
    int length;
    bool operator < (const Answer& a) const
    {
        if(this->length == a.length)
            return list.size() < a.list.size();
        return this->length < a.length;
    }
};

Node subwayMap[10001]; //Graph with lineId, adj list
bool visited[10001];

Answer tempAns, finalAns;

void init()
{
    memset(visited, false, sizeof(visited));
    tempAns.list.clear();
    tempAns.length = 0;
    finalAns.list.clear();
    finalAns.length = MAX;
}

void dfs(int src, int dst);

int main(int argc, char** argv)
{

    int n, m, k;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> m;
        int pre, cur;
        cin >> pre;
        for(int j = 1; j < m; j++)
        {
            cin >> cur;
            subwayMap[pre].adjStations.push_back(Station(cur, i));
            subwayMap[cur].adjStations.push_back(Station(pre, i));
            pre = cur;
        }
    }

    cin >> k;
    for(int i = 0; i < k; i++)
    {
        init();
        int src, dst;
        cin >> src >> dst;
        dfs(src, dst);
        cout << finalAns.length << endl;

        for(int i = 0; i < finalAns.list.size(); i++)
            printf("Take Line#%d from %04d to %04d.\n",
            finalAns.list[i].lineId, finalAns.list[i].start,
            finalAns.list[i].end);
    }
    return 0;
}

void dfs(int src, int dst)
{
    if(src == dst)
    {
        if(tempAns < finalAns)
            finalAns = tempAns;
    }

    if(finalAns < tempAns)
        return;

    for(int i = 0; i < subwayMap[src].adjStations.size(); i++)
    {
        int next = subwayMap[src].adjStations[i].id;
        if(!visited[next])
        {
            Answer temp = tempAns;
            tempAns.length++;
            if(tempAns.list.size() == 0 || subwayMap[src].adjStations[i].lineId !=
                    tempAns.list.back().lineId)
                tempAns.list.push_back(Segment(subwayMap[src].adjStations[i].lineId,
                           src, next));
            else
                tempAns.list.back().end = next;

            visited[next] = true;
            dfs(next, dst);
            //Restore
            visited[next] = false;
            tempAns = temp;
        }
    }
}