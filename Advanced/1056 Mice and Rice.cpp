#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Player
{
	int id;
	int weight;
	int score;
	friend bool operator < (const Player& a, const Player& b)
	{
		return a.score < b.score;
	}
};

bool compare(Player& a, Player& b)
{
	return a.score > b.score;
}

Player players[1000];
Player scoreBoard[1000];
int weight[1000];
int ranks[1000];

void getRank(int np, int ng);

int main()
{
	int np, ng;
	scanf("%d %d", &np, &ng);
	for (int i = 0; i < np; i++)
	{
		scanf("%d", &weight[i]);
		scoreBoard[i].id = i;
		players[i].score = 0;
	}
	for (int i = 0; i < np; i++)
		scanf("%d", &players[i].id);

	getRank(np, ng);
	for (int i = 0; i < np - 1; i++)
		printf("%d ", ranks[i]);
	printf("%d\n", ranks[np - 1]);

	return 0;
}

void getRank(int np, int ng)
{
	vector<Player> currentRound;
	vector<Player> nextRound;
	for (int i = 0; i < np; i++)
	{
		players[i].weight = weight[players[i].id];
		currentRound.push_back(players[i]);
	}
	while (currentRound.size() > 1) 
	{
		nextRound.clear();
		for (int i = 0; i < currentRound.size(); i += ng)
		{
			int maxWeight = -1;
			int index = -1;
			for (int j = i; j < i + ng && j < currentRound.size(); j++)
			{
				if (currentRound[j].weight > maxWeight)
				{
					maxWeight = currentRound[j].weight;
					index = j;
				}
			}
			scoreBoard[currentRound[index].id].score++;
			nextRound.push_back(currentRound[index]);
		}
		currentRound = nextRound;
	}

	sort(scoreBoard, scoreBoard + np, compare);
	int current = 0;
	int lastScore = 0x7fffffff;
	for (int i = 0; i < np; i++)
	{
		if (scoreBoard[i].score < lastScore)
		{
			current = i + 1;
			lastScore = scoreBoard[i].score;
		}
		ranks[scoreBoard[i].id] = current;
	}
}