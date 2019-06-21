#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 10005;
int a[maxn], dp[maxn];
int n, m, l;
int hashTable[maxn];

int main() {
    freopen("in1045.txt", "r", stdin);
	fill(hashTable, hashTable + maxn, -1);
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
	    int temp;
		scanf("%d", &temp);
		hashTable[temp] = i;
		//printf("temp = %d, mp[temp] = %d\n", temp, mp[temp]);
	}
    scanf("%d", &l);
	int cnt = 1;
	for(int i = 1; i <= l; i++) {
	    int temp;
		scanf("%d", &temp);
		if(hashTable[temp] >= 1) {
		    a[cnt++] = temp;
		}
	}
    int ans = -1;
	for(int i = 1; i < cnt; i++) {
	    dp[i] = 1;
		for(int j = 1; j < i; j++) {
			//printf("a[%d] = %d, a[%d] = %d, dp[%d] = %d\n", i, a[i], j, a[j], dp[i]);
			if(hashTable[a[i]] >= hashTable[a[j]] && dp[j] + 1 > dp[i]) {
			    dp[i] = dp[j] + 1;
				//printf("%d ", a[i]);
				//printf("a[%d] = %d, a[%d] = %d, dp[i] = %d\n", i, a[i], j, a[j], dp[i]);
			}
		}
	    ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
//NOTE:
//1、可以考虑先将所给序列转化为一个具有顺序意义的序列，剔除无关元素
//    然后再利用最长不下降序列的算法求解