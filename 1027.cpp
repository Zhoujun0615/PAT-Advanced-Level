#include <stdio.h>
int main()
{
    int r, g, b;
	char d[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    scanf("%d %d %d", &r, &g, &b);
	printf("#%c%c", d[r / 13], d[r % 13]);
    printf("%c%c", d[g / 13], d[g % 13]);
	printf("%c%c", d[b / 13], d[b % 13]);
    return 0;
}