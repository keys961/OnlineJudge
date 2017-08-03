#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

//typedef TreeNode* Tree;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

vector<int> nodeNum;

TreeNode* insert(TreeNode* tree, int val);
void levelTraversal(TreeNode* root);

int main(int argc, char const *argv[])
{
	int n, val;
	TreeNode* tree = NULL;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		tree = insert(tree, val);
	}
	levelTraversal(tree);
	int last = nodeNum[nodeNum.size() - 1];
	int last2 = nodeNum[nodeNum.size() - 2];
	printf("%d + %d = %d\n", last, last2, last + last2);
	return 0;
}

TreeNode* insert(TreeNode* root, int val)
{
	if(root == NULL)
	{
		root = new TreeNode;
		root->val = val;
		root->left = root->right = NULL;
		return root;
	}
	if(val <= root->val)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);
	return root;
}

void levelTraversal(TreeNode* root)
{
	if(root == NULL)
		return;
	int levelNum = 0;
	TreeNode* currentNode, *lastNode;
	lastNode = root;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		currentNode = q.front();
		q.pop();
		levelNum++;
		if(currentNode->left != NULL)
			q.push(currentNode->left);
		if(currentNode->right != NULL)
			q.push(currentNode->right);
		if(currentNode == lastNode)
		{
			nodeNum.push_back(levelNum);
			levelNum = 0;
			lastNode = q.back();
		}
	}
}