#include <stdio.h>
int main()
{
    int t, flag;
	long long a, b, c;
	long long sum = 0;
	int cnt = 1;
	flag = 0;
    scanf("%d", &t);
	while(t--)
	{
	    scanf("%lld%lld%lld", &a, &b,&c);
		sum = a + b;
		if(a > 0 && b > 0 && sum < 0)
			flag = 1;
		else if(a < 0 && b < 0 && sum >= 0)
			flag = 0;
		else if( sum > c)
			flag = 1;
		else
			flag = 0;
		if(flag)
			printf("Case #%d: true\n", cnt);
		else
			printf("Case #%d: false\n", cnt);
		cnt++;
	}
    return 0;
}