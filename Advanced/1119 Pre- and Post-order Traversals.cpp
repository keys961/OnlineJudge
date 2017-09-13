#include <cstdio>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : left(0), right(0) { this->val = val; }
};

int preOrder[30];
int postOrder[30];
vector<int> inOrder1;
vector<int> inOrder2;

TreeNode* build1(int preStart, int preEnd, int postStart, int postEnd);
TreeNode* build2(int preStart, int preEnd, int postStart, int postEnd);
void traversal(TreeNode* tree, int id);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &preOrder[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &postOrder[i]);

	TreeNode* tree1 = build1(0, n - 1, 0, n - 1);
	TreeNode* tree2 = build2(0, n - 1, 0, n - 1);
	traversal(tree1, 1);
	traversal(tree2, 2);
	if (inOrder1 == inOrder2)
		printf("Yes\n");
	else
		printf("No\n");
	for (int i = 0; i < inOrder1.size() - 1; i++)
		printf("%d ", inOrder1[i]);
	printf("%d\n", inOrder1.back());
	return 0;
}

TreeNode* build1(int preStart, int preEnd, int postStart, int postEnd)
{
	if (preStart > preEnd)
		return nullptr;
	if (preStart == preEnd)
		return new TreeNode(preOrder[preStart]);

	TreeNode* root = new TreeNode(preOrder[preStart]);
	int leftRoot = preOrder[preStart + 1];
	int i = postStart;
	for (; i <= postEnd; i++)
	{
		if (postOrder[i] == leftRoot)
			break;
	}
	int leftNum = i - postStart + 1;
	root->left = build1(preStart + 1, preStart + leftNum, postStart, postStart + leftNum - 1);
	root->right = build1(preStart + leftNum + 1, preEnd, postStart + leftNum, postEnd - 1);
	return root;
}

TreeNode* build2(int preStart, int preEnd, int postStart, int postEnd)
{
	if (postStart > postEnd)
		return nullptr;
	if (postStart == postEnd)
		return new TreeNode(postOrder[postEnd]);

	TreeNode* root = new TreeNode(postOrder[postEnd]);
	int rightRoot = postOrder[postEnd - 1];
	int i;
	for (i = preStart + 1; i <= preEnd; i++)
	{
		if (preOrder[i] == rightRoot)
			break;
	}
	int leftNum = i - preStart - 1;
	root->left = build2(preStart + 1, preStart + leftNum, postStart, postStart + leftNum - 1);
	root->right = build2(preStart + leftNum + 1, preEnd, postStart + leftNum, postEnd - 1);
	return root;
}

void traversal(TreeNode* tree, int id)
{
	if (tree == nullptr)
		return;
	traversal(tree->left, id);
	if (id == 1)
		inOrder1.push_back(tree->val);
	else
		inOrder2.push_back(tree->val);
	traversal(tree->right, id);
}