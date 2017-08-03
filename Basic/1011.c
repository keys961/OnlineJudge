#include<stdio.h>
int main()
{
  long a,b,c;
  int i;
  int repeat;
  scanf("%d",&repeat);
  for(i=1;i<=repeat;i++)
  {
    scanf("%ld %ld %ld",&a,&b,&c);
    if(a+b>c)
      printf("Case #%d: true\n",i);
    else
      printf("Case #%d: false\n",i);
  }
  return 0;
}