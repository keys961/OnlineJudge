#include<stdio.h>
#include<string.h>
int reta(char *str)
{
  int k=0,a=0;
  for(k=0;str[k]!='\0';k++)
  {
    if(str[k]!='P' && str[k]!='A' && str[k]!='T')
      return -1;
  }
  a=strspn(str,"A");
  if(str[a]=='P')
     return a;
  else 
     return -1;
}

int retb(char *str,int a)
{
  int b=0;
  char *p;
  p=str+a+1;
  b=strspn(p,"A");
  if(p[b]=='T') 
    return b;
  else
    return -1;
}

int retc(char *str,int a,int b)
{
  int c=0;
  char *p;
  p=str+a+b+2;
  c=strspn(p,"A");
  if(p[c]=='\0') 
    return c;
  else
    return -1;
}

int main(int argc, char *argv[])
{
  int n=0,i=0,j=0,a=0,b=0,c=0,r[10]={0};
  char str[10][100];
  scanf("%d",&n);
  for(i=0;i<n && i<10;i++)
    scanf("%s",str[i]);

  for(i=0;i<n && i<10;i++) 
  {
    a=reta(str[i]);
    if(a!=-1)
      b=retb(str[i],a);
    else
      continue;
    if(b!=-1)
      c=retc(str[i],a,b);
    else
      continue;
    if(b>0 && c==b*a)
      r[i]=1;
   }

  for(i=0;i<n && i<10;i++)
  {
    if(r[i]==0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}