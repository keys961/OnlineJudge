#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Customer
{
	int arrivingTime; //Second
	int processsingTime; //Min
	Customer(int a, int p)
	{
		arrivingTime = a;
		processsingTime = p;
	}
	bool operator < (const Customer& a)
	{
		return this->arrivingTime < a.arrivingTime;
	}
};

vector<Customer> customers;
int windows[101];

double solve(int n, int k);
int findWindow(int k);

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
		windows[i] = 8 * 3600;
	for (int i = 0; i < n; i++)
	{
		int h, m, s, p;
		scanf("%d:%d:%d %d", &h, &m, &s, &p);
		//if (p > 60)
			//p = 60;
		if (h * 3600 + m * 60 + s <= 17 * 3600)
			customers.push_back(Customer(h * 3600 + m * 60 + s, p * 60));
	}
	sort(customers.begin(), customers.end());
	printf("%.1f", solve(customers.size(), k));
    return 0;
}

double solve(int n, int k)
{
	double totalTime = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int site = findWindow(k);
		if (site == -1)
			break;
		count++;
		double tempTime = (windows[site] - customers[i].arrivingTime);
		if (tempTime < 0)
			tempTime = 0;
		totalTime += tempTime * 1.0 / 60;
		windows[site] = max(windows[site], customers[i].arrivingTime)
			+ customers[i].processsingTime;
	}
	//if (count == 0)
		//return 0.0;
	return totalTime / (count);
}

int findWindow(int k)
{
	int minVal = 0x7fffffff;
	int site = -1;

	for (int i = 0; i < k; i++)
	{
		if (windows[i] < minVal)
		{
			minVal = windows[i];
			site = i;
		}
	}
	return site;
}