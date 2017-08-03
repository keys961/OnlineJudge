#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>

using namespace std;

struct Node
{
    int val;
    int next;
    bool valid;
};

Node linkedList[100000];
bool visited[100000] = {false};
bool exist[100000] = {false};
vector<int> addrSeq;

void input(int n);
void traversal(int startAddr);
void remove(int startAddr);
void print(int n);

int main(int argc, char const *argv[])
{
    int startAddr, n;
    scanf("%d %d", &startAddr, &n);
    input(n);
    traversal(startAddr);
    remove(startAddr);
    print(n);
    return 0;
}

void input(int n)
{
    Node node;
    int addr;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &addr, &node.val, &node.next);
        node.valid = true;
        linkedList[addr] = node;
    }
    for(int i = 0; i < 100000; i++)
    {
        visited[i] = exist[i] = false;
    }
}

void traversal(int startAddr)
{
    int addr = startAddr;
    while(addr != -1)
    {
        addrSeq.push_back(addr);
        if(!exist[abs(linkedList[addr].val)])
            exist[abs(linkedList[addr].val)] = true;
        else
            linkedList[addr].valid = false;
        addr = linkedList[addr].next;
    }
}

void remove(int startAddr)
{
    int addr = startAddr;
    int ptr = linkedList[addr].next;
    int prePtr = addr;
    int preRemoved = -1;//Pre removed
    while(ptr != -1)
    {
        if(!linkedList[ptr].valid)//delete
        {
            linkedList[prePtr].next = linkedList[ptr].next;
            linkedList[ptr].next = -1;
            if(preRemoved != -1)
                linkedList[preRemoved].next = ptr;
            preRemoved = ptr;
            ptr = linkedList[prePtr].next;
        }
        else
        {
            prePtr = ptr;
            ptr = linkedList[ptr].next;
        }
    }
}

void print(int n)
{
    int addr;
    for(int i = 0; i < n; i++)
    {
        addr = addrSeq[i];
        if(visited[addr])
            continue;
        while(addr != -1)
        {
            printf("%05d %d ", addr, linkedList[addr].val);
            if(linkedList[addr].next != -1)
                printf("%05d\n", linkedList[addr].next);
            else
                printf("-1\n");
            visited[addr] = true;
            addr = linkedList[addr].next;
        }
    }
}