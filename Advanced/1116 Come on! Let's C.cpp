#include <cstdio>
#include <map>

using namespace std;

bool checked[10000] = {false};
map<int, int> ranking;

void query(int k);
bool isPrime(int n)
{
	if(n == 1)
		return false;
	if(n == 2 || n == 3)
		return true;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	int n, id, k;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &id);
		ranking[id] = i + 1;
	}
	scanf("%d", &k);
	query(k);
	return 0;
}

void query(int k)
{
	int id;
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &id);
		if(ranking.find(id) == ranking.end())
			printf("%04d: Are you kidding?\n", id);
		else if(checked[id] == true)
			printf("%04d: Checked\n", id);
		else if(ranking[id] == 1)
			printf("%04d: Mystery Award\n", id);
		else if(isPrime(ranking[id]) == true)
			printf("%04d: Minion\n", id);
		else
			printf("%04d: Chocolate\n", id);
		checked[id] = true;
	}
}