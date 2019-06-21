#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, p, max_sum;
int flag;
vector<int> temp, ans, fac;
int power(int x) {
	int res = 1;
	for(int i = 0; i < p; i++) {
	    res *= x;
	}
    return res;
}

void init() {
    int i = 0;
	int temp = 0;
	while(temp <= n) {
	    fac.push_back(temp);
		temp = power(++i);
	}
}
void DFS(int index, int nowK, int sum, int facSum) {
	if(facSum == n && nowK == k) {
		if(sum > max_sum) {
		    max_sum = sum;
			ans = temp;
		}
	    return;
	}
	if(nowK > k || facSum > n) return;
	if(index >= 1) {
	    temp.push_back(index);
	    //选index
	    DFS(index, nowK + 1, sum + index, fac[index] + facSum);
	    temp.pop_back();
	    //不选index
	    DFS(index - 1, nowK, sum, facSum);	
	}
}

int main() {
	freopen("in1103.txt", "r", stdin);
	while(scanf("%d %d %d", &n, &k, &p) != EOF) {
		max_sum = -1;
		ans.clear();
		fac.clear();
		init();
	    DFS(fac.size() - 1, 0, 0, 0);
		if(max_sum == -1) printf("Impossible\n");
		else {

			printf("%d = ", n);
			for(int i = 0; i < ans.size(); i++) {
			    printf("%d^%d", ans[i], p);
				if(i < ans.size() - 1) printf(" + ");
			}
			printf("\n");	
		}
	}
    return 0;
}
//NOTE:1.多点测试时，每次使用vector时，别忘了先清空它。
//     2.时间复杂度大时，可以考虑先预处理数据，简化思路或计算步骤！