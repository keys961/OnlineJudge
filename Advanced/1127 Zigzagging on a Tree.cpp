#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : left(0), right(0) { this->val = val; }
};

int inOrder[30];
int postOrder[30];

TreeNode* buildTree(int inStart, int inEnd, int postStart, int postEnd);
vector<int> traversal(TreeNode* root);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &inOrder[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &postOrder[i]);
	TreeNode* root = buildTree(0, n - 1, 0, n - 1);
	vector<int> res = traversal(root);
	for (int i = 0; i < res.size() - 1; i++)
		printf("%d ", res[i]);
	printf("%d\n", res.back());
	return 0;
}

TreeNode* buildTree(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd)
		return nullptr;
	if (inStart == inEnd)
		return new TreeNode(inOrder[inStart]);

	TreeNode* root = new TreeNode(postOrder[postEnd]);
	int leftNum = 0;
	for (int i = inStart; i <= inEnd; i++)
	{
		if (inOrder[i] == root->val)
		{
			leftNum = i - inStart;
			break;
		}
	}
	root->left = buildTree(inStart, inStart + leftNum - 1, postStart, postStart + leftNum - 1);
	root->right = buildTree(inStart + leftNum + 1, inEnd, postStart + leftNum, postEnd - 1);
	return root;
}

vector<int> traversal(TreeNode* root)
{
	vector<int> res;
	vector<int> levelCount;

	queue<TreeNode*> q;
	TreeNode* last = root;
	int count = 0;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		res.push_back(temp->val);
		count++;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);

		if (temp == last)
		{
			levelCount.push_back(count);
			count = 0;
			if(!q.empty())
				last = q.back();
		}
	}
	int startIndex = 0;
	for (int i = 0; i < levelCount.size(); i++)
	{
		if (i % 2 == 0)
			reverse(res.begin() + startIndex, res.begin() + startIndex + levelCount[i]);
		startIndex += levelCount[i];
	}
	return res;
}