#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

struct Station
{
	int id;
	int lineId; //Key point
	Station(int id, int lineId): id(id), lineId(lineId){}
};

struct Segment 
{
	int lineId;
	int start, end;
	Segment(int lineId, int start, int end) :
		lineId(lineId), start(start), end(end){}
};

map< int, vector<Station> > subwayMap;
bool visited[10001];

vector<Segment> ans;
int ansLen = 0x7fffffff;

void dfs(int src, int dst, vector<Segment> tempAns, int tempLen);//Key point

void init()
{
	memset(visited, false, sizeof(visited));
	ans.clear();
	ansLen = 0x7fffffff;
}

int main()
{
	int n, m, k;
	scanf("%d", &n);
	for (int line = 1; line <= n; line++)
	{
		scanf("%d", &m);
		int v1, v2;
		scanf("%d", &v1);
		for (int i = 1; i < m; i++)
		{
			scanf("%d", &v2);
			subwayMap[v1].push_back(Station(v2, line));
			subwayMap[v2].push_back(Station(v1, line));
			v1 = v2;
		}
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int src, dst;
		scanf("%d %d", &src, &dst);
		init();
		visited[src] = true;
		dfs(src, dst, vector<Segment>(), 0);
		printf("%d\n", ansLen);
		for (int i = 0; i < ans.size(); i++)
			printf("Take Line#%d from %04d to %04d.\n", ans[i].lineId,
				ans[i].start, ans[i].end);
	}

	return 0;
}

void dfs(int src, int dst, vector<Segment> tempAns, int tempLen)
{
	if (src == dst)
	{
		if (tempLen < ansLen)
		{
			ans = tempAns;
			ansLen = tempLen;
		}
		else if (tempLen == ansLen)
		{
			if (tempAns.size() < ans.size())
				ans = tempAns;
		}
	}

	if (tempLen > ansLen || (tempLen == ansLen && tempAns.size() > ans.size()))
		return;

	for (int i = 0; i < subwayMap[src].size(); i++)
	{
		int next = subwayMap[src][i].id;
		if (!visited[next])
		{
			vector<Segment> t = tempAns;
			if (tempAns.size() == 0 || subwayMap[src][i].lineId != tempAns.back().lineId)//Change
				tempAns.push_back(Segment(subwayMap[src][i].lineId, src, next));
			else //Not change
				tempAns[tempAns.size() - 1].end = next;
			visited[next] = true;
			dfs(next, dst, tempAns, tempLen + 1);
			visited[next] = false;
			tempAns = t;
		}
	}
}