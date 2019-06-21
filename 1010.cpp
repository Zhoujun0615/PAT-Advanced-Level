#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long LL;
LL Map[256];
LL Inf = (1LL << 63) - 1;
void init()
{
    for(char c ='0'; c <= '9'; c++)
		Map[c] = c - '0';
    for(char c = 'a'; c <= 'z'; c++)
		Map[c] = c - 'a' + 10;
}
LL exchange(char s[], LL radix, LL maxnum)
{
    LL res = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
	{
	    res = res * radix + Map[s[i]];
        if(res < 0 || res > maxnum)
			return -1;
	}
	return res;
}
int findLargestDigit(char N2[])
{
    int len = strlen(N2);
	int res = -1;
	for(int i = 0; i < len; i++)
	{
	    if(Map[N2[i]] > res)
			res = Map[N2[i]];
	}
	return res + 1;
}
int cmp(char N2[], LL radix, LL maxnum)
{
    int len = strlen(N2);
	LL temp = exchange(N2, radix, maxnum);
	if(temp < 0)
		return 1;
	else if(temp > maxnum)
		return 1;
	else if(temp == maxnum)
		return 0;
	else
		return -1;
}
LL BinarySearch(char N2[], LL left, LL right, LL maxnum)
{
    LL mid;
	while(left <= right)
	{
	    mid = (left + right) / 2;
	    int flag = cmp(N2, mid, maxnum);
	    if(flag == 0)
			return mid;
		else if(flag == -1)
			left = mid + 1;
		else
			right = mid - 1;
	}
    return -1;
}
int main()
{
    char N1[15], N2[15], temp[15];
	int tag;
	LL radix;
	freopen("in1010.txt", "r", stdin);
	init();
	while(scanf("%s %s %d %lld", N1, N2, &tag, &radix) != EOF)
	{
        if(tag == 2)
		{
		    strcpy(temp, N1);
			strcpy(N1, N2);
			strcpy(N2, temp);
		}
		LL maxnum = exchange(N1, radix, Inf);
        LL left = findLargestDigit(N2);
		LL right = max(left, maxnum) + 1;
		LL ans = BinarySearch(N2, left, right, maxnum);
		if(ans == -1)
			printf("Impossible\n");
		else
			printf("%lld\n", ans);
	}
    return 0;
}
//Note:
//1.本题中radix有可能非常大，而不仅仅是0-36；
//2.由于radix可能非常大，故应该使用long long 表示，并用二分法查找合适的最小进制