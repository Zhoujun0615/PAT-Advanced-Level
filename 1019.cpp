#include <stdio.h>
int main()
{
    int N, D;
	int pos, flag;
	int ans[35] = {0};
    pos = 0, flag = 1;
	scanf("%d %d", &N, &D);
    while(N)
	{
	    int p = N % D;
		ans[pos] = p;
		pos++;
		N /= D;
	}
	for(int i = 0; i < pos; i++)
	{
	    if(ans[i] != ans[pos - 1 - i])
		{
		    flag = 0;
		    break;
		}
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	for(int i = pos - 1; i >= 0; i--)
	{
	    printf("%d", ans[i]);
	    if(i > 0)
			printf(" ");
	}
    return 0;
}