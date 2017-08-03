#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<set<int> >S(n);
	for(int i=0;i<n;i++)
	{
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			int a;
			scanf("%d",&a);
			S[i].insert(a);
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		set<int>u;
		set_intersection(S[x-1].begin(),S[x-1].end(),S[y-1].begin(),S[y-1].end(),inserter(u,u.begin()));
		double res=u.size()*100.0/(S[x-1].size()+S[y-1].size()-u.size());
		printf("%.1f\%\n",res);
	}
	return 0;
}

/* JAVA CODE */
/*



import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;


public class Main {
	
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		int N, K;
		
		N = in.nextInt();
		
		LinkedList<HashSet<Integer>> setList = new LinkedList<HashSet<Integer>>();
		for(int i = 0; i < N; i++)
			setList.add(new HashSet<Integer>());
		
		input(setList, N);
		
		K = in.nextInt();
		
		query(setList, K);
		
	}
	
	public static void input(LinkedList<HashSet<Integer>> setList, int N)
	{
		int M;
		for(int i = 0; i < N; i++)
		{
			M = in.nextInt();
			for(int j = 0; j < M; j++)
				setList.get(i).add(in.nextInt());
		}
	}
	
	public static void query(LinkedList<HashSet<Integer>> setList, int K)
	{
		int set1, set2;
		int Nc, Nt;
		HashSet<Integer> union = new HashSet<Integer>(),
				intersection = new HashSet<Integer>();
		
		for(int i = 0; i < K; i++)
		{
			set1 = in.nextInt();
			set2 = in.nextInt();
			union.clear();
			union.addAll(setList.get(set1 - 1));
			union.addAll(setList.get(set2 - 1));
			
			intersection.clear();
			intersection.addAll(setList.get(set1 - 1));
			intersection.retainAll(setList.get(set2 - 1));
			
			Nc = intersection.size();
			Nt = union.size();
			
			System.out.printf("%.1f%%\n", Nc * 1.0 / Nt * 100.0);
		}
	}
}







*/