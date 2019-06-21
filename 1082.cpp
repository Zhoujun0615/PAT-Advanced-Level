#include <stdio.h>
int main()
{
    long long N;
	int pos = 0;
	char p1[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	char p2[5][10] ={"ling", "Shi", "Bai", "Qian", "Wan"};
	int ans[10] = {0};
	scanf("%lld", &N);
	if(N < 0)
	{
	    printf("Fu ");
		N = - N;
	}
	if(N == 0)
		printf("ling");
	else
	{
	    while(N)
		{
		    ans[pos] = N % 10;
		    pos++;
			N /= 10;
		}
		int flag = 0;
		for(int i = pos - 1; i >= 0; i--)
		{
			if(ans[i])
			{
			    if(i % 4 > 0)
				{
					if(i > 2)
					    printf("%s %s ", p1[ans[i]], p2[i % 4]);
					else
                        printf("%s %s ", p1[ans[i]], p2[i % 4]);
					flag = 1;
				}    
				else
					printf("%s", p1[ans[i]]);

			}
			else if(ans[i] == 0)
			{
			    if(flag && i % 4 > 1)
				{
				    printf("%s ", p1[ans[i]]);
					flag = 0;
				}
			}
			if(i == 8)
			{
			    printf(" Yi ");
				flag = 1;
			}
                
			else if(i == 4)
			{
			    printf(" Wan ");
				flag = 1;
			}
				
		}
	}
    return 0;
}