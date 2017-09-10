#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

vector<int> preOrder;
vector<int> inOrder;
vector<int> postOrder;

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

TreeNode* buildTree(int preStart, int preEnd, int inStart, int inEnd);
void postOrderTraversal(TreeNode* tree);

int main()
{
	int n;
	char command[5];
	int val;
	stack<int> s;
	scanf("%d", &n);
	while (inOrder.size() < n)
	{
		scanf("%s", command);
		if (strcmp(command, "Push") == 0)
		{
			scanf("%d", &val);
			s.push(val);
			preOrder.push_back(val);
		}
		else
		{
			inOrder.push_back(s.top());
			s.pop();
		}
	}

	TreeNode* root = buildTree(0, n - 1, 0, n - 1);
	postOrderTraversal(root);

	for (int i = 0; i < postOrder.size() - 1; i++)
		printf("%d ", postOrder[i]);
	printf("%d\n", postOrder[postOrder.size() - 1]);
	return 0;
}

TreeNode* buildTree(int preStart, int preEnd, int inStart, int inEnd)
{
	if (preStart > preEnd)
		return nullptr;
	if (preStart == preEnd)
		return new TreeNode(preOrder[preStart]);

	TreeNode* root = new TreeNode(preOrder[preStart]);
	int leftNum = 0;
	for (int i = inStart; i <= inEnd; i++)
	{
		if (inOrder[i] == root->val)
			break;
		leftNum++;
	}
	root->left = buildTree(preStart + 1, preStart + leftNum, inStart, inStart + leftNum - 1);
	root->right = buildTree(preStart + leftNum + 1, preEnd, inStart + leftNum + 1, inEnd);
	return root;
}

void postOrderTraversal(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	postOrderTraversal(tree->left);
	postOrderTraversal(tree->right);
	postOrder.push_back(tree->val);
}