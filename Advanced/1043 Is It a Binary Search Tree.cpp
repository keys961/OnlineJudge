#include <cstdio>
#include <stack>

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

int preOrder[1000];
int postOrder[1000], ptr = 0;

TreeNode* insert(TreeNode* root, int val);
TreeNode* insertRev(TreeNode* root, int val);
bool checkPreOrder(TreeNode* root);
void postOrderTraversal(TreeNode* root);

void print(int n)
{
	for (int i = 0; i < n - 1; i++)
		printf("%d ", postOrder[i]);
	printf("%d\n", postOrder[n - 1]);
}

int main()
{
	int n, val;
	TreeNode* root = nullptr, *rootRev = nullptr;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		preOrder[i] = val;
		root = insert(root, val);
		rootRev = insertRev(rootRev, val);
	}


	if (checkPreOrder(root))
	{
		printf("YES\n");
		postOrderTraversal(root);
		print(n);
	}
	else if (checkPreOrder(rootRev))
	{
		printf("YES\n");
		postOrderTraversal(rootRev);
		print(n);
	}
	else
		printf("NO\n");

	return 0;
}

TreeNode * insert(TreeNode * root, int val)
{
	if(root == nullptr)
		return new TreeNode(val);

	if (val < root->val)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);
	return root;
}

TreeNode * insertRev(TreeNode * root, int val)
{
	if (root == nullptr)
		return new TreeNode(val);

	if (val < root->val)
		root->right = insertRev(root->right, val);
	else
		root->left = insertRev(root->left, val);
	return root;
}

bool checkPreOrder(TreeNode* root)
{
	TreeNode* temp = root;
	stack<TreeNode*> s;
	int i = 0;
	while (!s.empty() || temp)
	{
		while (temp)
		{
			s.push(temp);
			if (preOrder[i++] != temp->val)
				return false;
			temp = temp->left;
		}
		temp = s.top();
		s.pop();
		temp = temp->right;
	}
	return true;
}

void postOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	postOrder[ptr++] = root->val;
}