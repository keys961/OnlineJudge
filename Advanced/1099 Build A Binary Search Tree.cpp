#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	int val;
	int left;
	int right;
};

Node tree[100];
int sequence[100];

void buildBST(int n);
vector<int> levelOrder(int n);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &tree[i].left, &tree[i].right);
	for (int i = 0; i < n; i++)
		scanf("%d", &sequence[i]);
	sort(sequence, sequence + n);
	buildBST(n);
	vector<int> res = levelOrder(n);
	for (int i = 0; i < res.size() - 1; i++)
		printf("%d ", res[i]);
	printf("%d\n", res.back());
	return 0;
}

void buildBST(int n)
{
	int tempNode = 0;
	int i = 0;
	stack<int> s;
	while (!s.empty() || tempNode != -1)
	{
		while (tempNode != -1)
		{
			s.push(tempNode);
			tempNode = tree[tempNode].left;
		}
		tempNode = s.top();
		tree[tempNode].val = sequence[i++];
		s.pop();
		tempNode = tree[tempNode].right;
	}
}

vector<int> levelOrder(int n)
{
	vector<int> res;
	queue<int> q;
	q.push(0);
	int temp = 0;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		res.push_back(tree[temp].val);
		if (tree[temp].left != -1)
			q.push(tree[temp].left);
		if(tree[temp].right != -1)
			q.push(tree[temp].right);
	}
	return res;
}