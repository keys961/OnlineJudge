#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
//AVL Tree

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> res;//res

int getHeight(TreeNode* node);
TreeNode* insert(TreeNode* root, int val);
TreeNode* leftRotation(TreeNode* node);
TreeNode* rightRotation(TreeNode* node);
bool levelOrder(TreeNode* root);

int main(int argc, char const *argv[])
{
    int n, val;
    TreeNode *tree = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        tree = insert(tree, val);
    }
    bool status = levelOrder(tree);
    printf("%d", res[0]);
    for(int i = 1; i < res.size(); i++)
        printf(" %d", res[i]);
    printf("\n");
    if(status)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

int getHeight(TreeNode* node)
{
    if(node == NULL)
        return -1;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
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
    if(val < root->val)
    {
        root->left = insert(root->left, val);
        if(getHeight(root->left) - getHeight(root->right) == 2)
        {
            if(val < root->left->val)
                root = rightRotation(root);
            else
            {
                root->left = leftRotation(root->left);
                root = rightRotation(root);
            }
        }
    }
    else
    {
        root->right = insert(root->right, val);
        if(getHeight(root->left) - getHeight(root->right) == -2)
        {
            if(val > root->right->val)
                root = leftRotation(root);
            else
            {
                root->right = rightRotation(root->right);
                root = leftRotation(root);
            }
        }
    }
    return root;
}

TreeNode* leftRotation(TreeNode* node)
{
    TreeNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

TreeNode* rightRotation(TreeNode* node)
{
    TreeNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

bool levelOrder(TreeNode* root)
{
    if(root == NULL)
        return true;
    long FLAG = INFINITY;
    vector<long> check;
    TreeNode* currentNode;
    queue<TreeNode*> q;
    q.push(root);
    res.push_back(root->val);
    check.push_back((long)root->val);
    while(!q.empty())
    {
        currentNode = q.front();
        q.pop();
        if(currentNode->left)
        {
            q.push(currentNode->left);
            res.push_back(currentNode->left->val);
            check.push_back((long)currentNode->left->val);
        }
        else
            check.push_back(FLAG);
        if(currentNode->right)
        {
            q.push(currentNode->right);
            res.push_back(currentNode->right->val);
            check.push_back((long)currentNode->right->val);
        }
        else
            check.push_back(FLAG);
    }
    int i, j;
    for(i = 0; i < check.size(); i++)
        if(check[i] == FLAG)
            break;
    for(j = i + 1; j < check.size(); j++)
        if(check[j] < FLAG)
            return false;
    return true;
}