#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct MoonCake
{
	double amount; //Thousand ton
	double price; //Billion yuan
};

vector<MoonCake> moonCakes;

bool compare(MoonCake a, MoonCake b)
{
	return a.price / a.amount > b.price / b.amount;
}

double getMaxProfit(int N, int D);

int main(int argc, char const *argv[])
{
	int N, D;
	MoonCake m;
	scanf("%d %d", &N, &D);
	for(int i = 0; i < N; i++)
	{
		scanf("%lf", &m.amount);
		moonCakes.push_back(m);
	}
	for(int i = 0; i < N; i++)
		scanf("%lf", &moonCakes[i].price);
	sort(moonCakes.begin(), moonCakes.end(), compare);
	printf("%.2f\n", getMaxProfit(N, D));
	return 0;
}

double getMaxProfit(int N, int D)
{
	double profit = 0.0;
	for(int i = 0; i < N && D > 0; i++)
	{
		if(moonCakes[i].amount <= D)
		{
			profit += moonCakes[i].price;
			D -= moonCakes[i].amount;
		}
		else
		{
			profit += moonCakes[i].price * D / moonCakes[i].amount;
			D = 0;
		}
	}
	return profit;
}