#include <stdio.h>

int main(void)
{
    long long tests, size_max, size;
    scanf("%lli %lli", &tests, &size_max);
    long long mtx[size_max][size_max];
    for (int q = tests; q >= 1; q--) {
        scanf("%lli", &size);
        if (size == 0) {
            continue;
        }
        for (long long a = 0; a < size; a++) {
            for (long long b = 0; b < size; b++) {
                scanf("%lli", &mtx[a][b]);
            }
        }
        long long i = 1, j = 0, l = 0, k = 0;
        printf("%lli ", mtx[0][0]);
        for (long long c = 1; c < size * size; c++) {
            if (l < size - 1) {
                l++;
                i = l;
                j = 0;
            } else {
                k++;
                j = k;
                i = l;
            }
            while ((i >= 0) && (j < size)) {
                printf("%lli ", mtx[i][j]);
                i--;
                j++;
            }
        }
        printf("\n");
    }
    return 0;
}