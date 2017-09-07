#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val)
	{
		this->val = val; 
		this->left = this->right = nullptr;
	}
};

int postOrder[30];
int inOrder[30];

TreeNode* buildTree(int inStart, int inEnd, int postStart, int postEnd);
void traversal(TreeNode* root);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &postOrder[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &inOrder[i]);
	TreeNode* tree = buildTree(0, n - 1, 0, n - 1);
	traversal(tree);
	return 0;
}

TreeNode* buildTree(int inStart, int inEnd, int postStart, int postEnd)
{
	if (postStart > postEnd)
		return nullptr;
	if (postStart == postEnd)
		return new TreeNode(postOrder[postEnd]);

	TreeNode* root = new TreeNode(postOrder[postEnd]);
	int rightNum = 0;
	for (int i = inEnd; i >= inStart; i--)
	{
		if (inOrder[i] == root->val)
		{
			rightNum = inEnd - i;
			break;
		}
	}

	root->left = buildTree(inStart, inEnd - rightNum - 1, postStart, postEnd - rightNum - 1);
	root->right = buildTree(inEnd - rightNum + 1, inEnd, postEnd - rightNum, postEnd - 1);
	return root;
}

void traversal(TreeNode* root)
{
	vector<int> res;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		res.push_back(temp->val);

		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}

	for (int i = 0; i < res.size() - 1; i++)
		printf("%d ", res[i]);
	printf("%d\n", res[res.size() - 1]);
}