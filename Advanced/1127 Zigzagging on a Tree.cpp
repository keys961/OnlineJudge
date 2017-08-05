#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

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

int inOrder[30];
int postOrder[30];

TreeNode* buildTree(TreeNode* root, int inBegin, int inEnd, int postBegin, int postEnd);
void zigzag(TreeNode* root);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &inOrder[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &postOrder[i]);
    TreeNode* root = nullptr;
    root = buildTree(root, 0, n - 1, 0, n - 1);
    zigzag(root);
    return 0;
}

TreeNode* buildTree(TreeNode* root, int inBegin, int inEnd, int postBegin, int postEnd)
{
    if(inBegin > inEnd)
        return nullptr;
    if(inBegin == inEnd)
        return (root = new TreeNode(inOrder[inBegin]));
    int leftNum = 0;
    root = new TreeNode(postOrder[postEnd]);
    for(; leftNum + inBegin <= inEnd; leftNum++)
        if(inOrder[leftNum + inBegin] == root->val)
            break;
    root->left = buildTree(root->left, inBegin, inBegin + leftNum - 1,
                           postBegin, postBegin + leftNum - 1);
    root->right = buildTree(root->right, inBegin + leftNum + 1, inEnd,
                            postBegin + leftNum, postEnd - 1);
    return root;
}

void zigzag(TreeNode* root)
{
    int count = 0;
    TreeNode* currentNode, *lastNode = root;
    queue<TreeNode*> q;
    vector<int> v;
    vector<int> levelCount;
    q.push(root);
    while(!q.empty())
    {
        currentNode = q.front();
        v.push_back(currentNode->val);
        q.pop();
        count++;
        if(currentNode->left)
            q.push(currentNode->left);
        if(currentNode->right)
            q.push(currentNode->right);
        if(currentNode == lastNode)
        {
            levelCount.push_back(count);
            count = 0;
            lastNode = q.back();
        }
    }
    int startPtr = 0;
    for(int i = 0; i < levelCount.size(); i++)
    {
        if(i % 2 == 0)//Reverse
            reverse(v.begin() + startPtr, v.begin() + startPtr + levelCount[i]);
        startPtr += levelCount[i];
    }
    printf("%d", v[0]);
    for(int i = 1; i < v.size(); i++)
        printf(" %d", v[i]);
    printf("\n");
}