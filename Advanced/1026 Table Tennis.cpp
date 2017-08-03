#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
//CASE 3
using namespace std;

typedef struct info
{
	int arriveTime;//In second
	int serveTime;//In second
	int playTime;//In minute
	int tag;
}Info;

int tables[101] = {0, };
int tableCount[101] = {0,};
bool isVip[101] = {false,};
vector<Info> ordinaries;
vector<Info> vips;
vector<Info> result;

bool compare(Info a, Info b);
bool compare1(Info a, Info b);
void input(int n);
void solve(int n, int k);
void print(int k);

int main(int argc, char const *argv[])
{
	int N; //Total number of pairs of players
	int K, M;//Number of tables, VIP ~
	int vipnum;
	//Input
	scanf("%d", &N);
	input(N);
	scanf("%d %d", &K, &M);
	for(int i = 0; i < M; i++)
	{
		scanf("%d", &vipnum);
		isVip[vipnum] = true;
	}

	solve(N, K);
	print(K);

	return 0;
}

void input(int n)
{
	Info info;
	int hour, minute, second; //Arriving time
	int P; //Playing time
	int tag;//1: VIP
	for(int i = 0; i < n; i++)
	{
		scanf("%d:%d:%d", &hour, &minute, &second);
		if(hour >= 21)
			continue;
		info.arriveTime = hour * 3600 + minute * 60 + second;
		scanf("%d %d", &P, &tag);
		if(P > 120)
			P = 120;
		info.playTime = P;
		info.tag = tag;
		if(tag == 0)
			ordinaries.push_back(info);
		else
			vips.push_back(info);
	}
}

void solve(int n, int k)
{
	for(int i = 1; i <= k; i++)
		tables[i] = 8 * 3600;
	if(ordinaries.size() > 0)
		sort(ordinaries.begin(), ordinaries.end(), compare);
	if(vips.size() > 0)
		sort(vips.begin(), vips.end(), compare);
	while(ordinaries.size() > 0 || vips.size() > 0)
	{
		int minTime = 0x7fffffff, minVipTime = 0x7fffffff;
		int index, vipIndex;
		for(int j = 1; j <= k; j++)
		{
			if(tables[j] < minTime)
			{
				minTime = tables[j];
				index = j;
			}
			if(tables[j] < minVipTime && isVip[j])
			{
				minVipTime = tables[j];
				vipIndex = j;
			}
		}
		if(tables[index] >= 21 * 3600)
			break;

		Info player;
		//Pick player
		if(vips.size() == 0)
		{
			player = ordinaries.front();
			ordinaries.erase(ordinaries.begin());
		}
		else if(ordinaries.size() == 0)
		{
			player = vips.front();
			vips.erase(vips.begin());
		}	
		else
		{
			if(isVip[index])
			{
				if(vips.front().arriveTime < ordinaries.front().arriveTime
					 || tables[index] >= vips.front().arriveTime)
				{
					player = vips.front();
					vips.erase(vips.begin());
				}
				else
				{
					player = ordinaries.front();
					ordinaries.erase(ordinaries.begin());
				}
			}
			else
			{
				if(vips.front().arriveTime < ordinaries.front().arriveTime)
				{
					player = vips.front();
					vips.erase(vips.begin());
				}
				else
				{
					player = ordinaries.front();
					ordinaries.erase(ordinaries.begin());
				}
			}
		}
		//Get serve time
		if(player.tag == 1 && tables[vipIndex] <= player.arriveTime)
		{
			player.serveTime = player.arriveTime;
			tables[vipIndex] = player.arriveTime + player.playTime * 60;
			tableCount[vipIndex]++;
		}
		else
		{
			if(player.arriveTime >= tables[index])
			{
				player.serveTime = player.arriveTime;
				tables[index] = player.arriveTime + player.playTime * 60;
			}
			else
			{
				player.serveTime = tables[index];
				tables[index] = player.serveTime + player.playTime * 60;
			}
			tableCount[index]++;
		}
		result.push_back(player);
	}
	sort(result.begin(), result.end(), compare1);
}

bool compare(Info a, Info b)
{
	return 
		(a.arriveTime < b.arriveTime);
}

bool compare1(Info a, Info b)
{
	return
		(a.serveTime < b.serveTime);
}

void print(int k)
{
	for(int i = 0; i < result.size(); i++)
	{
		int waitSecond = result[i].serveTime - result[i].arriveTime;
		int waitTime = waitSecond / 60 + 
				(waitSecond % 60 < 30 ? 0 : 1);
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
		result[i].arriveTime / 3600, (result[i].arriveTime % 3600) / 60,
		result[i].arriveTime % 60, 
		result[i].serveTime / 3600, (result[i].serveTime % 3600) / 60,
		result[i].serveTime % 60, waitTime);
	}
	for(int i = 1; i < k; i++)
		printf("%d ", tableCount[i]);
	printf("%d", tableCount[k]);
}