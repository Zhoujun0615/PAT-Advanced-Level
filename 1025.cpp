#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct student
{
    char id[15];
	int loc_n, loc_r;
	int fin_r, socre;
}s[30005];
bool cmp(student a, student b)
{
	if(a.socre != b.socre)
		return a.socre > b.socre;
	else
		return strcmp(a.id, b.id) < 0;
}
int main()
{
    freopen("in1025.txt", "r", stdin);
	int N, K, sum, i, j;
	while(scanf("%d", &N) != EOF)
	{
	    sum = 0;
		for(i = 1; i <= N; i++)
		{
		    scanf("%d", &K);
			for(j = 0; j < K; j++)
			{
				scanf("%s %d", s[sum].id, &s[sum].socre);
				s[sum].loc_n = i;
				sum++;
			}
			sort(s + sum - K, s + sum, cmp);
			int r = 1;
			for(j = 0; j < K; j++)
			{
				if(j > 0 && s[j + sum - K].socre != s[j + sum - K - 1].socre)
					r = j + 1;
				s[j + sum - K].loc_r = r;
			}
		}
	    sort(s, s + sum, cmp);
		int r = 1;
		for(i = 0; i < sum; i++)
		{
			if(i > 0 && s[i].socre != s[i - 1].socre)
				r = i + 1;
			s[i].fin_r = r;
		}
        printf("%d\n", sum);
	    for(i = 0; i < sum; i++)
	    {
		    printf("%s %d %d %d\n", s[i].id, s[i].fin_r, s[i].loc_n, s[i].loc_r);
	    }
	}
    return 0;
}