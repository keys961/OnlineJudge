include <stdio.h>

int main(void)
{
#define CLK_TCK     (100)

    int c1, c2;
    int delta;
    int h, m , s;

    scanf("%d %d", &c1, &c2);

    delta = (c2 - c1) / 100;
    if((c2 - c1) % CLK_TCK >= 50)
        delta += 1;

    h      = delta / 3600;
    delta -= (h * 3600);
    m      = delta / 60;
    delta -= (m * 60);
    s      = delta;

    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}