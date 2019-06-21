#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
long long nc[maxn];
long long np[maxn];
bool cmp(long long a, long long b)
{
    return a > b;
}
int main()
{
    int Nc, Np;
	freopen("in1037.txt", "r", stdin);
	while(scanf("%d", &Nc) != EOF)
	{
        int c1, c2, p1, p2;
        long long max = 0;
		for(int i = 0; i < Nc; i++)
		{
		    scanf("%lld", &nc[i]);
		}
		scanf("%d", &Np);
		for(int i = 0; i < Np; i++)
		{
		    scanf("%lld", &np[i]);	
		}
		sort(nc, nc + Nc, cmp);
		sort(np, np + Np, cmp);
		//printf("Nc = %d, Np = %d\n", Nc, Np);
		c1 = p1 = 0;
		c2 = Nc - 1;
		p2 = Np - 1;
	    while(nc[c1] >= 0 && np[p1] >= 0 && c1 <= c2 && p1 <= p2)
		{
            //printf("%lld %lld\n", nc[c1], np[p1]);
			max += (nc[c1] * np[p1]);
			c1++;
			p1++;
		}
		while(nc[c2] < 0 && np[p2] < 0 && c2 >= 0 && p2 >= 0)
		{
		    //printf("%lld %lld\n", nc[c2], np[p2]);
			max += (nc[c2] * np[p2]);
			c2--;
		    p2--;
		}
		printf("%lld\n", max);
	}
    return 0;
}