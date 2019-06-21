#include <stdio.h>
const int maxn = 10005;
int hashTable[maxn] = {0};
int ans[maxn] = {0};
int main()
{
    int N, num;
	while(scanf("%d", &N) != EOF)
	{
	    for(int i = 1; i <= N; i++)
		{
		    scanf("%d", &num);
			ans[i] = num;
			hashTable[num]++;
		}
		int flag = 0;
		for(int i = 0; i < N; i++)
		{
		    if(hashTable[ans[i]] == 1)
			{
			    printf("%d\n", ans[i]);
				flag = 1;
			    break;
			}
		}
		if(!flag)
		    printf("None\n");
	}
    return 0;
}