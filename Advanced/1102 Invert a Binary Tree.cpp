#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int val;
	int left;
	int right;
};

Node tree[10];
bool visited[10];

vector<int> levelOrder;
vector<int> inOrder;

void inOrderTraversal(int root);
void levelOrderTraversal(int root);
void invert(int root);
int findRoot(int n)
{
	for (int i = 0; i < n; i++)
		if (!visited[i])
			return i;
	return -1;
}
void print(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
		printf("%d ", v[i]);
	printf("%d\n", v.back());
}

int main()
{
	int n;
	char left[3], right[3];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", left, right);
		tree[i].val = i;
		if (strcmp(left, "-") == 0)
			tree[i].left = -1;
		else 
		{
			tree[i].left = atoi(left);
			visited[tree[i].left] = true;
		}

		if (strcmp(right, "-") == 0)
			tree[i].right = -1;
		else
		{
			tree[i].right = atoi(right);
			visited[tree[i].right] = true;
		}
	}
	invert(findRoot(n));
	levelOrderTraversal(findRoot(n));
	inOrderTraversal(findRoot(n));
	print(levelOrder);
	print(inOrder);
	return 0;
}

void invert(int root)
{
	if (root == -1)
		return;
	int temp = tree[root].left;
	tree[root].left = tree[root].right;
	tree[root].right = temp;
	invert(tree[root].left);
	invert(tree[root].right);
}

void inOrderTraversal(int root)
{
	if (root == -1)
		return;
	inOrderTraversal(tree[root].left);
	inOrder.push_back(tree[root].val);
	inOrderTraversal(tree[root].right);
}

void levelOrderTraversal(int root)
{
	queue<int> q;
	q.push(root);

	while (!q.empty())
	{
		int temp = q.front();
		levelOrder.push_back(tree[temp].val);
		q.pop();

		if (tree[temp].left != -1)
			q.push(tree[temp].left);
		if (tree[temp].right != -1)
			q.push(tree[temp].right);
	}
}