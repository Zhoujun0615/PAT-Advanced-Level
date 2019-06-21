#include <stdio.h>
#include <string.h>
const int maxv = 1000;
const int INF = 1000000000;
int vis[maxv];
int n, m, k;
int G[maxv][maxv] = {0};
void DFS(int u, int wrong) {
    vis[u] = 1;
	for(int v = 1; v <= n; v++) {
		if(vis[v] == 0 && G[u][v] > 0 && v != wrong) {
		    DFS(v, wrong);
		}
	}
}

void DFSTrave(int &cnt, int wrong) {
    for(int i = 1; i <= n; i++) vis[i] = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i] && i != wrong) {
		    DFS(i, wrong);
			cnt++;
		}
	}
}

int main() {
    freopen("in1013.txt", "r", stdin);
	while(scanf("%d %d %d", &n, &m, &k) != EOF) {
		for(int i = 1; i <= m; i++) {
		    int num1, num2;
			scanf("%d %d", &num1, &num2);
			G[num1][num2] = 1;
			G[num2][num1] = 1;
		}
		for(int i = 0; i < k; i++) {
			int num;
			scanf("%d", &num);
			int cnt = 0;
			DFSTrave(cnt, num);
			printf("%d\n", cnt - 1);
		}
	}
	return 0;
}
//NOTE:遇到坏点时，可以不同删除坏点引出的边，只需要在DFS过程中跳过该点，或者遇到该点就返回
//每一次DFS完成一个连通图的遍历，将n个连通图合并成一个连通图只需要增加n-1条边即可。