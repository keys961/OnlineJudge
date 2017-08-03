#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <deque>
#define MAXN 100005
//提前建好树 不要重复遍历
using namespace std;

int n;
int root;
double p,r;
int visited[MAXN];
vector<int> v[MAXN];
deque<int> q;

void BFS(int root,int *height,int count[]){
	int endNode;
	int maxlevel=-1;
	q.push_back(root);
	visited[root]=1;
	endNode=q.back();
	while(!q.empty()){
		int index=q.front();
		q.pop_front();
		for(int i=0;i<v[index].size();i++){
			int j=v[index][i];
			if(!visited[j]){
				visited[j]=1;
				q.push_back(j);
			}
		}
		if(index==endNode){
			(*height)++;//height of the tree
			count[*height]=q.size();//reserve the nodes of each level
			endNode=q.back();
		}
	}
}

int main(int argc,char *argv[]){
	int height=0,count[MAXN];
	count[0]=1;
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int index;
		scanf("%d",&index);
		if(index==-1){
			root=i;
		}else{
			v[index].push_back(i);
		}
	}
	BFS(root,&height,count);
	printf("%.2lf %d\n",p*pow((1+r/100.0),height-1),count[height-1]);
	return 0;
}
