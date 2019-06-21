#include <stdio.h>
int main()
{
    int k1, k2, e, cnt, i;
	double c, temp;
	double coef1[1010] = {0.0};
	double coef2[1010] = {0.0};
	cnt = 0;
	scanf("%d", &k1);
	for(i = 0; i < k1; i++)
	{
	    scanf("%d %lf", &e, &c);
	    coef1[e] = c;
	}
	scanf("%d", &k2);
	for(i = 0; i < k2; i++)
	{
	    scanf("%d %lf", &e, &c);
	    coef2[e] = c;
	}
	for(i = 0; i <= 1000; i++)
	{
		temp = coef1[i] + coef2[i];
		coef1[i] = temp;
	    if(temp != 0)
			cnt++;
	}
	printf("%d", cnt);
	for(i = 1000; i >= 0; i--)
	{
	    if(coef1[i] != 0)
			printf(" %d %.1f", i, coef1[i]);	
	}
    return 0;
}