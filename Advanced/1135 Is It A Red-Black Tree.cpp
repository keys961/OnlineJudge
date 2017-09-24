#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    bool isRed;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, bool isRes) : val(val), isRed(isRed), left(0), right(0){}
};

vector<int> preOrder1;
vector<int> preOrder2;

vector<TreeNode*> nodes;
vector<int> bhs;

TreeNode* insert(TreeNode* node, int val, bool isRed)
{
    if(node == nullptr)
    {
        node = new TreeNode(val, isRed);
        nodes.push_back(node);
        return node;
    }

    if(val < node->val)
        node->left = insert(node->left, val, isRed);
    else
        node->right = insert(node->right, val, isRed);

    return node;
}

void preOrderTraversal(TreeNode* root)
{
    if(root == nullptr)
        return;

    preOrder2.push_back(root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

bool checkRedNode()
{
    for(int i = 0; i < nodes.size(); i++)
    {
        if(nodes[i]->isRed)
        {
            if(nodes[i]->left && nodes[i]->left->isRed ||
                    nodes[i]->right && nodes[i]->right->isRed)
                return false;
        }
    }
    return true;

}

void getBH(TreeNode* root, int bh)
{
    if(root == nullptr)
    {
        bhs.push_back(bh + 1);
        return;
    }

    if(root->isRed)
    {
        getBH(root->left, bh);
        getBH(root->right, bh);
    }
    else
    {
        getBH(root->left, bh + 1);
        getBH(root->right, bh + 1);
    }
}

bool isRBTree(TreeNode* root);

int main(int argc, char** argv)
{
    int k, n, val;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        TreeNode* root = nullptr;
        cin >> n;
        preOrder1.clear();
        preOrder2.clear();
        bhs.clear();
        nodes.clear();
        for(int j = 0; j < n; j++)
        {
            cin >> val;
            preOrder1.push_back(abs(val));
            if(val < 0)
                root = insert(root, abs(val), true);
            else
                root = insert(root, abs(val), false);
        }
        if(isRBTree(root))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

bool isRBTree(TreeNode* root)
{
    preOrderTraversal(root);
    if(preOrder1 != preOrder2)
        return false;

    if(root->isRed)
        return false;

    if(!checkRedNode())
        return false;

    getBH(root, 0);
    int temp = bhs[0];

    for(int i = 1; i < bhs.size(); i++)
        if(bhs[i] != temp)
            return false;
    return true;

}