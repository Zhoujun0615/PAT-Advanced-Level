#include <stdio.h>
const int maxn = 100010;
int dist[maxn] = {0};
int A[maxn];
int ans[10010] = {0};
int main()
{
    int N, M, sum, in, out;
	sum = 0;
	int cnt = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
	    scanf("%d", &A[i]);
		sum += A[i];
		dist[i] = sum;
	}
	scanf("%d", &M);
	while(M--)
	{
		    scanf("%d %d", &in, &out);
			int s_dist = 0;
			if(in > out)
			{
			    int temp = in;
				in = out;
				out = temp;
			}
            s_dist = dist [out - 1] - dist[in - 1];
			if(s_dist > (sum - s_dist))
			{
			    ans[cnt] = sum - s_dist;
			}
			else
				ans[cnt] = s_dist;
			cnt++;		
	}
	for(int i = 0; i < cnt; i++)
		printf("%d\n", ans[i]);
    return 0;
}