#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;

//此代码使用前，需删除下面两行+后面的system("PAUSE")
ifstream fin("in.txt");
#define cin fin

const int MAX_STU = 26*26*26*10;

int hashName(const char * name){
	return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int i,j,z;
	vector< vector<int> > vec(MAX_STU+1);
	int id,num;
	char name[5];

	for(i=0;i<k;i++)
	{
		scanf("%d %d",&id,&num);
		for(j=0;j<num;j++)
		{
			scanf("%s",name);
			vec[hashName(name)].push_back(id);
		}
	}
	vector<int> tt;
	char queryName[5];
	for(i=0;i<n;i++)
	{
		scanf("%s",queryName);
		tt = vec[hashName(queryName)];
		sort(tt.begin(),tt.end());

		int size = tt.size();
		printf("%s %d",queryName,size);
		for(z=0;z<size-1;z++)
			printf(" %d",tt[z]);
		if(size>0)
			printf(" %d",tt[size-1]);
		printf("\n");
	}

	return 0;
}