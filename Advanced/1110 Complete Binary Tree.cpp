//Thoughts: Use CBT parent * 2 = LChild, preorder
//to get index, compare the N

//Or use the level order traversal to judge
//Maybe complicated

//Notice the string -> int convertion

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int left;
	int index;
	int right;
}TreeNode;

TreeNode tree[20];

void input(int n);
int getRoot(int n);
void preOder(int root, int index);
int isCBT(int n);
int convert(char* index);

int main()
{
	int n, root, lastIndex;
	scanf("%d", &n);
	input(n);
	root = getRoot(n);
	preOder(root, 1);
	lastIndex = isCBT(n);
	if(lastIndex == -1)
		printf("NO %d\n", root);
	else
		printf("YES %d\n", lastIndex);
	return 0;
}

void input(int n)
{
	char LEFT[3], RIGHT[3];
	int left, right;
	for(int i = 0; i < n; i++)
	{
		scanf("%s %s", LEFT, RIGHT);
        left = convert(LEFT);
        right = convert(RIGHT);
        tree[i].left = left;
        tree[i].right = right;
	}
}

int getRoot(int n)
{
	int visited[20] = {0,};
	for(int i = 0; i < n; i++)
	{
		if(tree[i].left != -1)
			visited[tree[i].left] = 1;
		if(tree[i].right != -1)
			visited[tree[i].right] = 1;
	}

	for(int i = 0; i < n; i++)
		if(visited[i] == 0)
			return i;
	return -1; //Cannot find
}

void preOder(int root, int index)
{
	if(root == -1)
		return;
	tree[root].index = index;
	preOder(tree[root].left, 2 * index);
	preOder(tree[root].right, 2 * index + 1);
}

int isCBT(int n)
{
	int last = 0, maxIndex = 0;
	for(int i = 0; i < n; i++)
	{
		if(tree[i].index > n)
			return -1;
		if(tree[i].index > maxIndex)
        {
			last = i;
			maxIndex = tree[i].index;
        }
	}
	return last;
}

int convert(char* index)
{
    int result = 0;
    int i = 0;
    if(index[0] == '-')
        return -1;
    else
        while(index[i])
        {
            result = result * 10 + index[i] - '0';
            i++;
        }
    return result;
}


#include <cstdio>
#include <cstring>

using namespace std;

struct Node
{
    int left;
    int right;
};

bool isRoot[2000] = {false};
Node tree[2000];
int queue[2000] = {0};

int input(int n);
int check(int n, int root);

int main(int argc, char const *argv[])
{
    int n, root;
    scanf("%d", &n);
    getchar();
    root = input(n);
    if(check(n, root) == -1)
        printf("NO %d\n", root);
    else
        printf("YES %d\n", queue[n - 1]);
    return 0;
}

//Another Solution
// int input(int n)
// {
//     char left[3], right[3];
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%s %s", left, right);
//         if(left[0] != '-')
//         {
//             for(int j = 0; j < strlen(left); j++)
//                 tree[i].left = tree[i].left * 10 + left[j] - '0';
//             isRoot[tree[i].left] = true;
//         }
//         else
//             tree[i].left = -1;
//         if(right[0] != '-')
//         {
//             for(int j = 0; j < strlen(right); j++)
//                 tree[i].right = tree[i].right * 10 + right[j] - '0';
//             isRoot[tree[i].right] = true;
//         }
//         else
//             tree[i].right = -1;
//     }
//     for(int i = 0; i < n; i++)
//         if(!isRoot[i])
//             return i;
// }

// int check(int n, int root)
// {
//     int front = -1, back = -1;
//     int currentNode;
//     queue[++front] = root;
//     while(front != back)
//     {
//         currentNode = queue[++back];
//         if(currentNode == -1)
//             continue;
//         queue[++front] = tree[currentNode].left;
//         queue[++front] = tree[currentNode].right;
//     }
//     for(int i = 0; i < n; i++)
//         if(queue[i] == -1)
//             return -1;
//     return queue[n - 1];
// }