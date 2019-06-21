#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
long long a[maxn];
int main()
{
    int N, ans;
	long long p;
	freopen("in1085.txt", "r", stdin);
	while(scanf("%d %lld", &N, &p) != EOF)
	{
	    ans = 1;
		for(int i = 0; i < N; i++)
			scanf("%lld", &a[i]);
	    sort(a, a + N);
		int left, right, mid, j;
		long long mul;
		for(int i = 0; i < N; i++)
		{
		    mul = a[i] * p;
			if(a[N - 1] <= mul)
				j = N;
			else
			{
			    left = i + 1, right = N - 1;
				while(left < right)
		        {
		            mid = (left + right) / 2;
			        if(mul < a[mid])
				        right = mid;
			        else
				        left = mid + 1;				
			    }
	            j = left;
		    }
			ans = max(ans, j - i);
		}
		printf("%d\n", ans);	
	}
    return 0;
}
//�߽���ⲻ�������������߼����󣬲���ÿ�ζ�ѡ����С��
//��������:10 3
//          0 1 2 3 4 4 4 4 12 15 
//          6
//��������Ϊ��2 3 4 4 4 4 �����ǣ�1 2 3