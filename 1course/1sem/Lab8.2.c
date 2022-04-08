#include <stdio.h> 
int main(void) 
{
	int a;
	long int s = 0;
	scanf("%d", &a);
	for (int i = 0; i <= a; ++i) {
		scanf("%d", &i);
		s += i;
	}
	printf("%ld", s);
}