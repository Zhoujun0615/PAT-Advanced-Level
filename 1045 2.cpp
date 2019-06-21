#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10010;
const int maxm = 210;
char A[maxm], B[maxn];
int n, m, l;
int dp[maxm][maxn];

int main() {
    freopen("in1045.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
	    scanf("%d", &m);
		for(int i = 1; i <= m; i++) {
		    scanf("%d", &A[i]);
		}
		scanf("%d", &l);
		for(int i = 1; i <= l; i++) {
		    scanf("%d", &B[i]);
		}
		//边界条件别搞错
		for(int i = 0; i <= m; i++) {
		    dp[i][0] = 0;
		}
		for(int j = 0; j <= l; j++) {
		    dp[0][j] = 0;    
		}
		//状态转移方程
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= l; j++) {
				if(A[i] == B[j]) {    //此处应为A[i]与B[j]相比！！
				    dp[i][j] = dp[i][j - 1] + 1;
				} else {
				    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				//printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
			}
		}
	    printf("%d\n", dp[m][l]);
	}
    return 0;
}