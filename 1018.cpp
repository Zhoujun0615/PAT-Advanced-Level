#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int maxv = 510;
const int INF = 0x3fffffff;

int d[maxv], vis[maxv], weight[maxv];
int cmax, n, sp, m;
int in, out, s = 0;
int optSendvalue = INF, optBackvalue = INF;
int G[maxv][maxv];
vector<int> pre[maxv];
vector<int> Path, tempPath;

void Dijkstra(int s) {
    fill(d, d + maxv, INF);
	fill(vis, vis + maxv, 0);
	d[s] = 0;
	for(int i = 0; i <= n; i++) {
	    int u = -1, MIN = INF;
		for(int j = 0; j <= n; j++) {
			if(!vis[j] && d[j] < MIN) {
			    u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = 1;
		for(int v = 0; v <= n; v++) {
			if(!vis[v] && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
				    d[v] = d[u] + G[u][v];
				    pre[v].clear();
					pre[v].push_back(u);
				} else if(d[u] + G[u][v] == d[v]) {
				    pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v) {
	if(v == s) {
	    tempPath.push_back(v);
		int value_s = 0, value_b = 0;
		for(int i = tempPath.size() - 1; i >= 0; i--) {
			int id = tempPath[i];
		    int temp = cmax / 2 - weight[id];
			if(temp < 0) {
			    value_b -= temp;
			} else {
				if(value_b > temp) {
				    value_b -= temp;
				} else {
				    value_s += (temp - value_b);
					value_b = 0;
				}
			}
		}
		if(value_s < optSendvalue) {
		    optSendvalue = value_s;
			Path = tempPath;
			optBackvalue =  value_b;
		} else if(value_s == optSendvalue && value_b < optBackvalue) {
		    optBackvalue = value_b;
		    Path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	//printf("v = %d, pre[v].size() = %d\n", v, pre[v].size());
	for(int i = 0; i < pre[v].size(); i++) {
	    DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

void Print() {
    printf("%d ", optSendvalue);
	for(int i = Path.size() - 1; i >= 0; i--) {
	    printf("%d", Path[i]);
		if(i > 0) printf("->");
	}
	printf(" %d\n", optBackvalue);
}

int main() {
    freopen("in1018.txt", "r", stdin);
	while(scanf("%d %d %d %d", &cmax, &n, &sp, &m) != EOF) {
	    fill(G[0], G[0] + maxv * maxv, INF);
		weight[0] = cmax / 2;
		for(int i = 1; i <= n; i++) {
		    scanf("%d", &weight[i]);
		}
		for(int i = 0; i < m; i++) {
		    int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			G[u][v] = w;
			G[v][u] = w;
		}
		Dijkstra(s);
		DFS(sp);
		//printf("optSendvalue = %d, optBackvalue = %d\n", optSendvalue, optBackvalue);
	    Print();
	}
    return 0;
}
//NOTE：坑点：
//    1、从起点PBMC出发到问题站点Sp的过程中就要把路径上的所有站点调整为最优状态
//    此后不再调整，不能用下一个站点多余的车来填补前一个车站缺少的车
//    2、Dijkstra + DFS算法还是不够熟练，应该多写几遍。