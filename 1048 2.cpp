#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int m[maxn];
int N, M;
int binarySearch(int a[], int i, int num)
{
    int left, right, mid;
	left = i + 1, right = N - 1;
    while(left <= right)
	{
	    mid = (left + right) / 2;
        if(m[mid] == num)
			return mid;
		else if(m[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;	
	}
	return -1;
}
int main()
{
	freopen("in1048.txt", "r", stdin);
	while(scanf("%d %d", &N, &M) != EOF)
	{
	    for(int i = 0; i < N; i++)
		{
		    scanf("%d", &m[i]);
		}
		sort(m, m + N);
		int flag = 0;
		int fin_i = -1;
		int ans;
		for(int i = 0; i < N; i++)
		{
		    int temp = M - m[i];
			ans = binarySearch(m, i, temp);
			if(ans != -1)
			{
                flag = 1;
				fin_i = i;
				break;
			}
		}
		if(flag == 0)
			printf("No Solution\n");
		else
			printf("%d %d\n", m[fin_i], m[ans]);
	}
    return 0;
}