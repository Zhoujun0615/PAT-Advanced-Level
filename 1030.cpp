#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxv = 510;
const int INF = 1000000000;

int d[maxv], vis[maxv];
int n, m, s, de;
int u, v, dist, c, optvalue = INF;
int G[maxv][maxv], cost[maxv][maxv];
vector<int> pre[maxv];
vector<int> path, tempPath;
/*
//迪杰斯特拉 + DFS算法求最短路径
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
				    pre[v].clear();
					pre[v].push_back(u);
				} else if(d[u] + G[u][v] == d[v]) {
				    pre[v].push_back(u);
				}
			}
		}
	}
}
*/
//SPFA求最短路径
int inq[maxv], num[maxv];
void SPFA(int s) {
    memset(inq, 0, sizeof(inq));
    memset(num, 0, sizeof(num));
	fill(d, d + maxv, INF);
	//fill(G[0], G[0] + maxv * maxv, INF);
	//fill(cost[0], cost[0] + maxv * maxv, INF);
	d[s] = 0;
	num[s]++;
	inq[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
        int u = q.front();
		q.pop();
		inq[u] = 0;
		for(int v = 0; v < n; v++) {
			if(G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
				    d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
					num[v]++;
					q.push(v);
					inq[v] = 1;
					if(num[v] >= n) return;
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
		int value = 0;
		for(int i = tempPath.size() - 1; i > 0; i--) {
		    int id = tempPath[i], idNext = tempPath[i - 1];
            value += cost[id][idNext];		
		}
		if(value < optvalue) {
		    optvalue = value;
			path = tempPath;
		}
	    tempPath.pop_back();
	    return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++) {
	    DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

void init() {
	for(int i = 0; i < n; i++) {
	    vis[i] = 0;
	}
	fill(G[0], G[0] + maxv * maxv, INF);
	fill(cost[0], cost[0] + maxv * maxv, INF);
}
int main() {
    freopen("in1030.txt", "r", stdin);
	while(scanf("%d %d %d %d", &n, &m, &s, &de) != EOF) {
		init();
		for(int i = 0; i < m; i++) {
		    scanf("%d %d %d %d", &u, &v, &dist, &c);
			G[u][v] = dist;
			G[v][u] = dist;
			cost[u][v] = c;
			cost[v][u] = c;		
		}
	    SPFA(s);
		DFS(de);
		for(int i = path.size() - 1; i >= 0; i--) {
		    printf("%d ", path[i]);
		}
		printf("%d %d\n", d[de], optvalue);
	}
    return 0;
}
//NOTE:Dijkstra + DFS 解决含第二标尺的最短路径
//     若题目中设置了初始化函数，在main函数里千万别忘了先初始化
//     最好是直接在main函数里初始化，而不需要另设置一个函数用来初始化