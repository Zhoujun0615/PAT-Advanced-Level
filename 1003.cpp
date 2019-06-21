#include <cstdio>
#include <algorithm>
using namespace std;
const int maxv = 510;
const int INF = 1000000000;
int d[maxv], vis[maxv];
int num[maxv], w[maxv], weight[maxv];
int G[maxv][maxv];
int n, m, c1, c2;
void Dijkstra(int s) {
    fill(d, d + maxv, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++) {
	    int u = -1, MIN = INF;
		for(int j = 0; j < n; j++) {
			if(!vis[j] && d[j] < MIN) {
			    u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
	    vis[u] = 1;
		for(int v = 0; v < n; v++) {
			if(!vis[v] && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
				    d[v] = d[u] + G[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				} else if(d[u] + G[u][v] == d[v]) {
				    num[v] += num[u];
					if(w[u] + weight[v] > w[v]) {
					    w[v] = w[u] + weight[v];
					}				
				}
			}
		}
	}
}

void init(int s) {
	for(int i = 0; i < n; i++) {
	    vis[i] = 0;
        num[i] = 0;
		w[i] = 0;
	}
	num[s] = 1;
	w[s] = weight[s];
	fill(G[0], G[0] + maxv * maxv, INF);
}

int main() {
    freopen("in1003.txt", "r", stdin);
	int u, v, l;
	while(scanf("%d %d %d %d", &n, &m, &c1, &c2) != EOF) {
		for(int i = 0; i < n; i++) {
		    scanf("%d", &weight[i]);
		}
		init(c1);
		for(int i = 0; i < m; i++) {
		    scanf("%d %d %d", &u, &v, &l);
			G[u][v] = l;
			G[v][u] = l;
		}
	    Dijkstra(c1);
		printf("%d %d\n", num[c2], w[c2]);
	}
    return 0;
}
//NOTE:数组名和变量名不能相同，否则会报错。
//     应该先读入weight数组后再初始化。