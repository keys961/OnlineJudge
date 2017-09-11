#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct Node
{
	int val;
	int nextAddr;
};

Node nodes[100000];

bool visited[10001];
vector<int> duplicationAddrs;

void getDuplication(int startAddr);
void linkDuplication(int startAddr);
void traversal(int startAddr);

int main()
{
	int startAddr, n;
	scanf("%d %d", &startAddr, &n);
	for (int i = 0; i < n; i++)
	{
		int addr, val, next;
		scanf("%d %d %d", &addr, &val, &next);
		nodes[addr].val = val;
		nodes[addr].nextAddr = next;
	}
	getDuplication(startAddr);
	if (!duplicationAddrs.empty())
		linkDuplication(duplicationAddrs[0]);
	traversal(startAddr);
	if (!duplicationAddrs.empty())
		traversal(duplicationAddrs[0]);
	return 0;
}

void getDuplication(int startAddr)
{
	int pre = startAddr;
	int current = nodes[startAddr].nextAddr;
	visited[abs(nodes[pre].val)] = true;
	while (current != -1)
	{
		if (!visited[abs(nodes[current].val)])
		{
			visited[abs(nodes[current].val)] = true;
			pre = current;
			current = nodes[current].nextAddr;
		}
		else
		{
			nodes[pre].nextAddr = nodes[current].nextAddr;
			duplicationAddrs.push_back(current);
			current = nodes[current].nextAddr;
		}
	}
}

void linkDuplication(int startAddr)
{
	int current = startAddr;
	for (int i = 1; i < duplicationAddrs.size(); i++)
	{
		nodes[current].nextAddr = duplicationAddrs[i];
		current = duplicationAddrs[i];
	}
	nodes[current].nextAddr = -1;
}

void traversal(int startAddr)
{
	while (startAddr != -1)
	{
		if(nodes[startAddr].nextAddr != -1)
			printf("%05d %d %05d\n", startAddr, nodes[startAddr].val, nodes[startAddr].nextAddr);
		else
			printf("%05d %d %d\n", startAddr, nodes[startAddr].val, nodes[startAddr].nextAddr);
		startAddr = nodes[startAddr].nextAddr;
	}
}