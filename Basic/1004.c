#include<stdio.h>
struct student
{
char stuname[11];
char stunum[11];
int stuscore;
};

int main()
{
  int i,n,max,min;
  scanf("%d",&n);
  struct student stu[n]; 
  for(i=0;i<n;i++)
    scanf("%s %s %d",stu[i].stuname,stu[i].stunum,&stu[i].stuscore);
  max=0;
  min=0;
  for(i=1;i<n;i++)
  {
    if(stu[i].stuscore > stu[max].stuscore)
      max=i;
    if(stu[i].stuscore < stu[min].stuscore)
      min=i;
  }
  printf("%.10s %.10s\n",stu[max].stuname,stu[max].stunum);
  printf("%.10s %.10s\n",stu[min].stuname,stu[min].stunum);
  return 0;
}