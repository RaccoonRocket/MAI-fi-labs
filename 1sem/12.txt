#include <stdio.h>

int main(void)
{
    long long num, one, unone, a, n = 1;
    while (scanf("%lli", &num) != EOF) {
        n = 1;
        if (num == 0) {
            printf("%lli\n", num);
            continue;
        }
        a = num;
        unone = a % 10;
        while (a != 0) {
            a /= 10;
            n *= 10;
        }
        n /= 10;
        one = num / n;
        num %= n;
        num += unone * n;
        num /= 10;
        num *= 10;
        num += one;
        printf("%lli\n", num);
    }
    return 0;
}