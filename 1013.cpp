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
//NOTE:��������ʱ�����Բ�ͬɾ�����������ıߣ�ֻ��Ҫ��DFS�����������õ㣬���������õ�ͷ���
//ÿһ��DFS���һ����ͨͼ�ı�������n����ͨͼ�ϲ���һ����ͨͼֻ��Ҫ����n-1���߼��ɡ�