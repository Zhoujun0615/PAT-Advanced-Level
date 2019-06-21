#include <stdio.h>
const int maxn = 100010;
int main()
{
    freopen("in1067.txt", "r", stdin);
	int a[maxn];
	int N, num, i;
	while(scanf("%d", &N) != EOF)
	{
	    int flag = 0;
		for(i = 0; i < N; i++)
		{
		    scanf("%d", &num);
			a[num] = i;
		}
		int pos;
		int cnt = 0;
		int k = 1;
		while(flag != 1)
		{
			pos = a[0];
			if(a[pos] != pos)
			{
				int temp = a[pos];
				a[pos] = a[0];
                a[0] = temp;
				cnt++;
			}
			else
			{
				while(k < N)
			    {
			        if(a[k] != k)
				    {
			            int temp = a[k];
			            a[k] = a[0];
				        a[0] = temp;
				        cnt++;
					    break;
				    }
				    k++;
			   }
			   if(k == N)
			        flag = 1;
			}
		}
		printf("%d\n", cnt);
	}
    return 0;
}
//NOTE:注意理解题意，尽量减小重复比较，缩小算法的时间复杂度。