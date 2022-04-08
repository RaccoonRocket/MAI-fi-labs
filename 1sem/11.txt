#include <stdio.h>

int main(void)
{
    int true_words = 0, state = 0;
    char symbol, last_symbol = ' ';
    while ((symbol = getchar()) != EOF) {
        if ((symbol >= '0' && symbol <= '9') || symbol == '+' || symbol == '-') {
            continue;
        }
        if (symbol >= 'A' && symbol <= 'Z') {
            symbol += 32;
        }
        if (symbol == ' ' || symbol == '\n') {
            if (state == 1) {
                true_words++;
            }
            last_symbol = ' ';
            state = 0;
            continue;
        }
        switch (state) {
            case 0:
                state = 1;
                last_symbol = symbol;
                break;
            case 1:
                if (last_symbol >= symbol) {
                    state = 2;
                } else {
                    last_symbol = symbol;
                }
                break;
            case 2:
                break;
        }
    }
    if (state == 1) {
        true_words++;
    } printf("%d\n", true_words);
    return 0;
}