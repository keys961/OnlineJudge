#include <stdio.h>
#include <stdlib.h>

typedef struct Station
{
	double dis;
	double price;
}Station;

double unit_gas;
int num;

Station sVec[502];

int compare(const void* a, const void* b)
{
	return (*(Station*)a).dis
		- (*(Station*)b).dis;
}

int FindNeatestCheaperStation(int i, double gas, Station* s)
{
	//int num = s.size();
	int min_index = i;
	for(int j = i+1; j < num && s[j].dis-s[i].dis <= gas*unit_gas; ++j)
	{
		if(s[j].price < s[min_index].price)
		{
			min_index = j;
			break;
		}
	}
	return min_index;
}

int GetFastestStation(int i, double gas, Station* s)
{

	int max_index = i;
	for(int j = i+1; j < num && s[j].dis-s[i].dis <= gas*unit_gas; ++j)
	{
		max_index = j;
	}
	return max_index;
}

int main()
{
	double max_gas, total_dis;

	while(scanf("%lf%lf%lf%d",&max_gas,&total_dis,&unit_gas,&num)!=EOF)
	{

		for(int i = 0; i < num; ++i)
			scanf("%lf %lf",&sVec[i].price,&sVec[i].dis);
		//sort station by distance
		qsort(sVec, num, sizeof(Station), compare);
		Station vir;
		vir.dis = total_dis;//add destination as a virtual station in the end
		sVec[num+1] = vir;
		//algorithm core
		if(num==0 || sVec[0].dis > 0)//special case
			printf("The maximum travel distance = 0.00\n");
		num++;
		else//greedy now
		{
			double remain_gas = 0.0;
			double cur_money = 0.0;
			int i;
			for(i = 0; i < num; )
			{
				int index;
				//1. using remain gas find nearest cheaper station
				index = FindNeatestCheaperStation(i, remain_gas, sVec);
				if(index != i)//find a station else
				{//get there
					remain_gas -= (sVec[index].dis-sVec[i].dis)/unit_gas;
					i = index;
					continue;
				}
				//2. using max_gas find nearest cheaper station
				index = FindNeatestCheaperStation(i, max_gas, sVec);
				if(index != i)//find a station else
				{//get there
					cur_money += ((sVec[index].dis-sVec[i].dis)/unit_gas-remain_gas)*sVec[i].price;
					remain_gas = 0.0;
					i = index;
					continue;
				}
				//3. get the max_gas and go as far as possible
				index = GetFastestStation(i, max_gas, sVec);
				if(index != i)
				{//can get some where
					cur_money += (max_gas-remain_gas)*sVec[i].price;
					remain_gas = max_gas-(sVec[index].dis-sVec[i].dis)/unit_gas;
					i = index;
					continue;
				}
				else
				{
					printf("The maximum travel distance = %.2lf\n", sVec[i].dis+max_gas*unit_gas);
					break;
				}
			}//end of greedy
			if(i == num) printf("%.2lf\n", cur_money);
		}

	}
	return 0;
}
