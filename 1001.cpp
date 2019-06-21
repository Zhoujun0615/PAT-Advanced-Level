#include <stdio.h>
int main()
{
    int a, b, sum, pos, cnt;
	pos = 0;
	char ans[10];
    scanf("%d %d", &a, &b);
	sum = a + b;
	if(sum < 0)
	{
		printf("-");
		sum = - sum;
	}
	do
	{
	    ans[pos] = sum % 10 + '0';
		pos++;
		sum /= 10;
	}while(sum != 0);
    for(int i = pos - 1; i >= 0; i--)
	{
        printf("%c", ans[i]);
		if(i > 0 && i % 3 == 0)
			printf(",");
	}
    return 0;
}