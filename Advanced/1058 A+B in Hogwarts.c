#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g, h, i;
    scanf("%d.%d.%d%d.%d.%d", &a, &b, &c, &d, &e, &f);
    i = (c+f)%29;
    f = (c+f)/29;
    h = (b+e+f)%17;
    e = (b+e+f)/17;
    g = a+d+e;
    printf("%d.%d.%d\n", g, h, i);
    return 0;
}