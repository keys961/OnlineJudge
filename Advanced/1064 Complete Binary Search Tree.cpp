#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int tree[1001] = {0};
int sequence[1001];

void buildTree(int left, int right, int node);
int getLeftNodeNum(int n);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &sequence[i]);
	sort(sequence, sequence + n);
	buildTree(0, n - 1, 1);
	for(int i = 1; i < n; i++)
		printf("%d ", tree[i]);
	printf("%d\n", tree[n]);
	return 0;
}

void buildTree(int left, int right, int node)
{
	if(right < left)
		return;
	if(right == left)
	{
		tree[node] = sequence[left];
		return;
	}
	int num = right - left + 1;
	int leftNum = getLeftNodeNum(num);
	int root = left + leftNum;
	tree[node] = sequence[root];
	buildTree(left, left + leftNum - 1, 2 * node);
	buildTree(left + leftNum + 1, right, 2 * node + 1);
}

int getLeftNodeNum(int n)
{
	int height = 0; //def: only a root: height = 1
	int baseNum = 0;
	int lastLeft; //if the tree is full
	int leftNum;
	int num = n;
	if(n == 1)
		return 0;
	while(num)
	{
		height ++;
		num /= 2;
	}
	baseNum = pow(2, height - 1) - 1;
	lastLeft = pow(2, height - 2);
	if(n - baseNum >= lastLeft)
		leftNum = baseNum;
	else
		leftNum = pow(2, height - 2) - 1 + (n - baseNum);
	return leftNum;
}