#include <cstdio>
#include <string>

using namespace std;

int getE(char * p)
{ 
 	int e = 0;
 
 	if (p[0] != '0')
  		for (int i = 0; p[i] != 0 && p[i] != '.'; i++)
   			e++;
 	else if(p[1] == '.')
  		for (int i = 2; p[i + 1] != 0 && p[i] == '0'; i++)
   			e--;
 	else
 	{
	  	int j = 0;
	  	while (p[j] == '0') j++;
	  	for (; p[j] != 0 && p[j] != '.'; j++)
	    	e++;
	}
 
 	return e;
}

string getB(char *p, int n,int e)
{ 
 	string ret = "";
 	int idx = 0;
 	if (e > 0)
 	{
  		int i = 0;
  		while (p[i] == '0')i++;
  		for (; p[i] != 0 && idx <n; i++)
  		{
	   		if (p[i] == '.')continue;
	   		ret += p[i];
	   		idx++;
	 	}
	}
	else 
	{
	  	int i = 0;
	  	if (p[i + 1] == 0)
	  	{
	   		ret = "0";
	   		while (ret.size() < n)
	    		ret += '0';
	   	}
	   	return ret;
	 }
	 while (p[i] != '.')i++;
	 ++i;
	 while (p[i] == '0')i++;  //0.000x的问题
	 for (; p[i] != 0 && idx < n; i++)
	 {
	   	ret += p[i];
	   	idx++;
	 }
	 
	 while (ret.size() < n)
	  	ret += '0';
	 return ret;
}

int main()
{
	 int N;
	 char A[101];
	 char B[101];
	 scanf("%d %s %s", &N, A, B);
	 string A2;
	 string B2;
	 int Ae = getE(A);
	 int Be = getE(B);
	 A2 = getB(A, N,Ae);
	 B2 = getB(B, N,Be);
	 if (N == 0)
	 	 printf("YES 0.*10^0\n");
	 
	 else if (Ae == Be && A2 == B2)
	  	printf("YES 0.%s*10^%d\n", A2.c_str(), Ae);
	 
	 else
	  	printf("NO 0.%s*10^%d 0.%s*10^%d\n", A2.c_str(), Ae, B2.c_str(), Be);
	 
	 return 0;
}