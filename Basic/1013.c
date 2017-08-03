#include<stdio.h>
#include<math.h>
int main()
{
int function(int num);
int m,n;
int count=0;
int par=0;
int i=2;
scanf("%d%d",&m,&n);
while(count<n)
{
if(function(i))
{
count++;
   if(count>=m)
{
printf("%d",i);
   par++;
     if(par%10&&count!=n)printf(" ");
   else printf("\n");
}
}
i++;
}
return 0;
}
int function(int num)
{
int i;
if(num==2)return 1;
for(i=2;i<=(int)sqrt(num);i++)
if(num%i==0)return 0;
return 1;
}