#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Item
{
    int id;
    int freq;

    Item(int id, int freq)
    {
        this->id = id;
        this->freq = freq;
    }

    friend bool operator<(const Item& a, const Item& b)
    {
        if(a.freq == b.freq)
            return a.id < b.id;
        return a.freq > b.freq;
    }
};

int frequency[50001];

int main(int argc, char const *argv[])
{
    int n, k, id;
    scanf("%d %d", &n, &k);
    set<Item> itemList;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &id);
        frequency[id]++;
        set<Item>::iterator it;
        if(i > 0)
        {
            vector<int> res;
            for (it = itemList.begin(); it != itemList.end(); it++)
            {
                if (it->freq == 0)
                    break;
                res.push_back(it->id);
                if (res.size() == k)
                    break;
            }
            if (res.empty())
                continue;
            printf("%d:", id);
            for (int i = 0; i < res.size(); i++)
                printf(" %d", res[i]);
            printf("\n");
        }

        Item item(id, frequency[id] - 1);
        if((it = itemList.find(item)) != itemList.end())
            itemList.erase(it);
        item.freq += 1;
        itemList.insert(item);
    }
    return 0;
}
