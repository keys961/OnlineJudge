#include <cstdio>
#include <map>

using namespace std;

struct Node
{
    int val;
    int next;
};

map<int, Node> linkedList;

void input(int n);
int canReverse(int addr, int k);
int  reverse(int startAddr, int k);

int main(int argc, char const *argv[])
{
    int startAddr, n, k;
    scanf("%d %d %d", &startAddr, &n, &k);
    input(n);
    startAddr = reverse(startAddr, k);
    while(startAddr != -1)
    {
        if(linkedList[startAddr].next != -1)
            printf("%05d %d %05d\n", startAddr, linkedList[startAddr].val,
               linkedList[startAddr].next);
        else
            printf("%05d %d -1\n", startAddr, linkedList[startAddr].val);
        startAddr = linkedList[startAddr].next;
    }
    return 0;
}

void input(int n)
{
    int addr, val, next;
    Node flag; flag.val = flag.next = -1;
    linkedList[-1] = flag;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d",&addr, &val, &next);
        linkedList[addr].val = val;
        linkedList[addr].next = next;
    }
}

int canReverse(int addr, int k)//Return head addr
{
    int count = 0;
    while(addr != -1)
    {
        count++;
        if(count >= k)
            return addr;
        addr = linkedList[addr].next;
    }
    return -1;
}

int reverse(int startAddr, int k)
{
    int start = startAddr;
    if(k == 1)
        return start;
    if((start = canReverse(startAddr, k)) == -1)
        start = startAddr;
    int pre = startAddr,
            ptr = linkedList[pre].next,
            next = linkedList[ptr].next;
    while(canReverse(pre, k) != -1)
    {
        int oldhead = pre;
        int nexthead;
        int count = 1;
        for(; count < k; count++)
        {
            linkedList[ptr].next = pre;
            pre = ptr;
            ptr = next;
            next = linkedList[next].next;
        }
        if((nexthead = canReverse(ptr, k)) == -1)
            nexthead = ptr;
        linkedList[oldhead].next = nexthead;
        pre = ptr;
        ptr = next;
        next = linkedList[next].next;
    }
    return start;
}