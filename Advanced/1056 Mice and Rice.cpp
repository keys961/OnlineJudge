#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

struct Programmer
{
	int id;
	int score;
};


Programmer winTree[1000];
int weight[1000] = {0};
int ranks[1000] = {0};

int compare(const void* a, const void* b)
{
	return ((Programmer*)b)->score - ((Programmer*)a)->score;
}

vector<int> play(int np, int ng);//First round
void nextTurn(vector<int> *winId, int ng);
void getRank(int np);

int main(int argc, char const *argv[])
{
	int np, ng;
	scanf("%d %d", &np, &ng);
	for(int i = 0; i < np; i++)
	{
		scanf("%d", &weight[i]);
		winTree[i].id = i;
		winTree[i].score = 0;
	}
	vector<int> winId = play(np, ng);
	nextTurn(&winId, ng);
	qsort(winTree, np, sizeof(Programmer), compare);
	getRank(np);
	for(int i = 0; i < np - 1; i++)
		printf("%d ", ranks[i]);
	printf("%d\n", ranks[np - 1]);
	return 0;
}

vector<int> play(int np, int ng)
{
	int p = np;
	int id;
	vector<int> winId;
	while(p > 0)
	{
		int maxWeight = 0;
		int maxId = -1;
		for(int i = 0; i < ng && p > 0; i++, p--)
		{
			scanf("%d", &id);
			if(weight[id] > maxWeight)
			{
				maxWeight = weight[id];
				maxId = id;
			}
		}
		winTree[maxId].score += 1;
		winId.push_back(maxId);
	}
	return winId;
}

void nextTurn(vector<int> *winId, int ng)
{
	if(winId->size() == 1)
		return;
	int p, g = ng;
	int maxWeight = 0;
	int maxId = -1;
	vector<int> nextTurn;
	while(winId->size() > 1)
	{
		p = winId->size();
		for(int i = 0; i < p && g > 0; i++)
		{
			if(weight[(*winId)[i]] > maxWeight)
			{
				maxWeight = weight[(*winId)[i]];
				maxId = (*winId)[i];
			}
			if(--g == 0 || i + 1 == p)
			{
				g = ng; nextTurn.push_back(maxId);
				winTree[maxId].score += 1;
				maxWeight = 0; maxId = -1;
			}
		}
		*winId = nextTurn;
		nextTurn.clear();
	}
	//winTree[(*winId)[0]].score++;
}

void getRank(int np)
{
	int count = 1;
	int rank = 0;
	int maxScore = 1000;
	for(int i = 0; i < np; i++)
	{
		if(winTree[i].score < maxScore)
		{
			maxScore = winTree[i].score;
			rank += count;
			ranks[winTree[i].id] = rank;
			count = 1;
		}
		else if(winTree[i].score == maxScore)
		{
			ranks[winTree[i].id] = rank;
			count++;
		}
	}
}