#include <cstdio>
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

	friend bool operator< (const Item& a, const Item& b)
	{
		if (a.freq == b.freq)
			return a.id < b.id;
		return a.freq > b.freq;
	}
};

int frequency[50001];
set<Item> items;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	set<Item>::iterator it;

	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		if (i != 0)
		{
			printf("%d:", val);
			it = items.begin();
			for (int j = 0; j < k && it != items.end(); j++)
			{
				if (it->freq == 0)
					break;
				printf(" %d", it->id);
				it++;
			}
			printf("\n");
		}
		
		Item item(val, frequency[val]);
		
		if ((it = items.find(item)) != items.end())
			items.erase(it);
		frequency[val]++;
		item.freq++;
		items.insert(item);

	}

	return 0;
}