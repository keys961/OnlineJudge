#include <cstdio>

using namespace std;

int preorder[30];
int postorder[30];

int inorder1[30];//Pick only 2 possible solution
int inorder2[30];

void input(int n);

void buildTreeFromPre(int preLeft, int preRight, int postLeft, int inLeft);
void buildTreeFromPost(int postLeft, int postRight, int preRight, int inRight);
bool check(int n);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    input(n);
    buildTreeFromPre(0, n - 1, 0, 0);
    buildTreeFromPost(0, n - 1, n - 1, n - 1);
    if(check(n))
        printf("Yes\n");
    else
        printf("No\n");
    for(int i = 0; i < n - 1; i++)
        printf("%d ", inorder1[i]);
    printf("%d\n", inorder1[n - 1]);
    return 0;
}

void input(int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);
}

void buildTreeFromPre(int preLeft, int preRight, int postLeft, int inLeft)
{
    //base
    if(preLeft > preRight)
        return;
    if(preLeft == preRight)
    {
        inorder1[inLeft] = preorder[preLeft];
        return;
    }

    int rootIndex = preLeft;
    int leftNum = 0;
    for(; preorder[rootIndex + 1] != postorder[postLeft + leftNum]; leftNum++);
    inorder1[inLeft + leftNum + 1] = preorder[rootIndex];
    buildTreeFromPre(preLeft + 1, preLeft + 1 + leftNum, postLeft, inLeft);
    buildTreeFromPre(preLeft + 2 + leftNum, preRight, 1 + leftNum + postLeft, inLeft + leftNum + 2);
}

void buildTreeFromPost(int postLeft, int postRight, int preRight, int inRight)
{
    if(postLeft > postRight)
        return;
    if(postLeft == postRight)
    {
        inorder2[inRight] = postorder[postLeft];
        return;
    }

    int rootIndex = postRight;
    int rightNum = 0;
    for(; postorder[postRight - 1] != preorder[preRight - rightNum]; rightNum++);
    inorder2[inRight - rightNum - 1] = postorder[rootIndex];
    buildTreeFromPost(postLeft, postRight - 2 - rightNum, preRight - 1 - rightNum, inRight - rightNum - 2);
    buildTreeFromPost(postRight - 1 - rightNum, postRight - 1, preRight, inRight);
}

bool check(int n)
{
    for(int i = 0; i < n; i++)
    {
        if(inorder1[i] != inorder2[i])
            return false;
    }
    return true;
}