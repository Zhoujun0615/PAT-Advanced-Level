#include <stdio.h>
int main()
{
	double coef[1010] = {0.0};
	double ans[2010] = {0.0};
	int k1, k2, e, cnt;
	cnt = 0;
	double c;
	scanf("%d", &k1);
	for(int i = 0; i < k1; i++)
	{
	    scanf("%d %lf", &e, &c);
		coef[e] = c;
	}
	scanf("%d", &k2);
	for(int i = 0; i < k2; i++)
	{
	    scanf("%d %lf", &e, &c);
		for(int j = 1000; j >= 0; j--)
		{
		    if(coef[j] != 0)
			{
			    ans[j + e] += (coef[j] * c);
			}			
		}
	}
	for(int i = 0; i <= 2000; i++)
		if(ans[i] != 0)
			cnt++;
    printf("%d", cnt);
	for(int i = 2000; i >= 0; i--)
		if(ans[i] != 0)
			printf(" %d %.1f", i, ans[i]);
    return 0;
}