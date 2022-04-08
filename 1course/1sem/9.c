#include <stdio.h>

#define MAX_STEP 50
#define first_area 25
#define second_area 100

int minn(int a, int b, int c)
{
    return ((a + b) < (a + c)) ? (a + b) : (a + c);
}
int maxx(int a, int b, int c)
{
    int e;
    e = (a * b > a * c) ? (a * b) : (a * c);
    e = (e > b * c) ? e : (b * c);
    return e;
}
int signn(int a)
{
    if (a < 0) {
        a = -1;
    } if (a > 0) {
        a = 1;
    }
    return a;
}
int area(int a, int b)
{
    int c;
    c = ((a - 10) * (a - 10) + (b - 10) * (b - 10));
    return first_area < c && c <= second_area;
}
int change_i(int i, int j, int l, int k)
{
    int f;
    f = minn(i, j, l) * ++k;
    if (f < 0) {
        return (30 - (-1 * f % 30)) % 30;
    } else {
        return f % 30;
    }
}
int change_j(int i, int j, int l, int k)
{
    int e, f;
    e = l * signn(j);
    if (e < 0) {
        e = (20 - (-1 * e % 20)) % 20;
    } else {
        e %= 20;
    }
    f = k * signn(i);
    if (f < 0) {
        f = (10 - (-1 * f % 10)) % 10;
    } else {
        f %= 10;
    }
    return j + e + f;
}
int change_l(int i, int j, int l)
{
    int e;
    e = maxx(i, j, l);
    if (e < 0) {
        return (30 - (-1 * e % 30)) % 30;
    } else {
        return e % 30;
    }
}

int main(void)
{
    int i, j, l, k = 0, ip, jp, lp;
    scanf("%d %d %d", &i, &j, &l);
    for (int q = 0; q < MAX_STEP; ++q) {
        if (area(i, j)) {
            break;
        }
        ip = change_i(i, j, l, k);
        jp = change_j(i, j, l, k);
        lp = change_l(i, j, l);
        i = ip;
        j = jp;
        l = lp;
        k++;
    }
    printf("%s\n", area(i, j) ? "Yes" : "No");
    printf("%d %d %d %d\n", i, j, l, k);
    return 0;
}
