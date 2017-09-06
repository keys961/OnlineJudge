#include <cstdio>

using namespace std;

struct Node
{
    char data[11];
    int left;
    int right;
};

Node tree[21];
bool visited[21];

void show(int root);

void showAddPatheness(int node);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s %d %d", tree[i].data, &tree[i].left, &tree[i].right);
        if(tree[i].left != -1)
            visited[tree[i].left] = true;
        if(tree[i].right != -1)
            visited[tree[i].right] = true;
    }
    int root;
    for(int i = 1; i <= n; i++)
        if(!visited[i])
        {
            root = i;
            break;
        }
    show(root);
    return 0;
}

void show(int root)
{
    showAddPatheness(tree[root].left);
    printf("%s", tree[root].data);
    showAddPatheness(tree[root].right);
}

void showAddPatheness(int node)
{
    if(node == -1)
        return;
    if(tree[node].left == -1 && tree[node].right == -1)
    {
        printf("%s", tree[node].data);
        return;
    }
    printf("(");
    showAddPatheness(tree[node].left);
    printf("%s", tree[node].data);
    showAddPatheness(tree[node].right);
    printf(")");
}