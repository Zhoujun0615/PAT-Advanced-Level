#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
const int maxv = 510;
const int INF = 0x3fffffff;
int d[maxv], weight[maxv], w[maxv], num[maxv];
int n, m, s, ed;
int c1, c2, l;
set<int> pre[maxv];
struct node {
    int v, dis;
	node(int _v, int _dis) {
	    v = _v;
		dis = _dis;
	}
};
vector<node> Adj[maxv];
/*
//贝尔曼算法求含负权值的最短路径算法
bool Bellman(int s) { 
    fill(d, d + maxv, INF);
    fill(w, w + maxv, 0);
	fill(num, num + maxv, 0);
	d[s] = 0;
	w[s] = weight[s];
    num[s] = 1;
	for(int i = 0; i < n - 1; i++) {
	//执行n - 1轮,每轮操作都遍历所有边
		for(int u = 0; u < n; u++) {
			for(int j = 0; j < Adj[u].size(); j++) {
			    int v = Adj[u][j].v;
				int dis = Adj[u][j].dis;
				if(d[u] + dis < d[v]) {
				    d[v] = d[u] + dis;    //松弛操作
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				    pre[v].clear();
					pre[v].insert(u);
				} else if(d[u] + dis == d[v]) {
					if(w[u] + weight[v] > w[v]) {
					    w[v] = w[u] + weight[v];
					}
					pre[v].insert(u);
					num[v] = 0;//重新统计num[v]
					set<int>::iterator it;
					for(it = pre[v].begin(); it != pre[v].end(); it++) {
					    num[v] += num[*it];
					}
				}
			}
		}
	}
	//判断图中是否存在源点可达的负环
	for(int u = 0; u < n; u++) {
		for(int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
		    if(d[u] + dis < d[v])//    如果仍可被松弛
				return false;//    说明图中有从源点可达的负环
		}
	}
    return true;
}
*/
//SPFA(Shortest Path Faster Algorithm)求带负权值的最短路径
int cnt[maxv], inq[maxv];
bool SPFA(int s) {
	memset(cnt, 0, sizeof(cnt));
	memset(inq, 0, sizeof(inq));
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
    fill(d, d + maxv, INF);
    inq[s] = 1;
	d[s] = 0; 
	w[s] = weight[s];
	num[s] = 1;
	cnt[s]++;
	queue<node> q;
	q.push(node(s, 0));
	while(!q.empty()) {
	    node temp = q.front();
		q.pop();
		int u = temp.v;
		inq[u] = 0;
		for(int j = 0; j < Adj[u].size(); j++) {
		    int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if(d[u] + dis < d[v]) {
			    d[v] = d[u] + dis;
				num[v] = num[u];
				w[v] = w[u] + weight[v];
				pre[v].clear();
				pre[v].insert(u);
			    q.push(node(v, dis));
				cnt[v]++;
				inq[v] = 1;
				if(cnt[v] >= n) return false;
			} else if(d[u] + dis == d[v]) {
				if(w[u] + weight[v] > w[v]) {
				    w[v] = w[u] + weight[v];
				}
				//num[v] += num[u];
				num[v] = 0;
				pre[v].insert(u);
				set<int>::iterator it;
				for(it = pre[v].begin(); it != pre[v].end(); it++) {
				    num[v] += num[*it];
				}
			    q.push(node(v, dis));
				cnt[v]++;
				inq[v] = 1;
				if(cnt[v] >= n) return false;
			}
		}
	}
	return true;
}

int main() {
    freopen("in1003.txt", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &s, &ed);
	for(int i = 0; i < n; i++) {
	    scanf("%d", &weight[i]);
	}
	for(int i = 0; i < m; i++) {
	    scanf("%d %d %d", &c1, &c2, &l);
        Adj[c1].push_back(node(c2, l));
		Adj[c2].push_back(node(c1, l));
	}
    if(SPFA(s))
	    printf("%d %d\n", num[ed], w[ed]);
	for(int i = 0; i < n; i++) {
		printf("cnt[%d] = %d\n", i, cnt[i]);
		for(set<int>::iterator it = pre[i].begin(); it != pre[i].end(); it++) {
		    printf("i = %d, pre[i] = %d ", i, *it);
		}
		printf("\n");
	}
    return 0;
}