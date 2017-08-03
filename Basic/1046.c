#include <stdio.h>

int main()
{
  int JiaHan,JiaHua,YiHan,YiHua;
  int repeat,ri;
  int countJia=0,countYi=0;
  scanf("%d",&repeat);
  for(ri=1;ri<=repeat;ri++)
    {
        scanf("%d %d %d %d",&JiaHan,&JiaHua,&YiHan,&YiHua);
        if(JiaHua==(JiaHan+YiHan)&&YiHua!=(JiaHan+YiHan))
            countYi++;
        else if(JiaHua!=(JiaHan+YiHan)&&YiHua==(JiaHan+YiHan))
            countJia++;
    }
    printf("%d %d\n",countJia,countYi);
  return 0;
}