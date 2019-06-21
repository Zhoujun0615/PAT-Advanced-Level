#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
const int maxv = 1020;
const int INF = 0x3fffffff;

int d[maxv], vis[maxv];
int n, m, k, ds;
double min_dis = -1.0, minAvg_dis = INF * 1.0;
set<int> ans;
struct node {
    int v, dis;
	node(int _v, int _dis) {
	    v = _v;
		dis = _dis;
	}
};
vector<node> Adj[maxv];

int change(char str[]) {
    int res = 0;
	int len = strlen(str);
	if(str[0] >= '0' && str[0] <= '9') {
		for(int i = 0; i < len; i++) {
		    res = res * 10 + str[i] - '0';
		}
	} else {
		for(int i = 1; i < len; i++) {
		    res = res * 10 + str[i] - '0';
		}
		res += n;
	}
    return res;
}

void Dijkstra(int s) {
    fill(d, d + maxv, INF);
	fill(vis, vis + maxv, 0);
	d[s] = 0;
	for(int i = 1; i <= n + m; i++) {
	    int u = -1, MIN = INF;
		for(int j = 1; j <= n + m; j++) {
			if(!vis[j] && d[j] < MIN) {
			    u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = 1;
		for(int j = 0; j < Adj[u].size(); j++) {
		    int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if(!vis[v] && d[u] + dis < d[v]) {
                d[v] = d[u] + dis;
			}
		}
	}
}

double getAvg(int d[]) {
    double res = 0.0;
	for(int i = 1; i <= n; i++) {
		//printf("d[%d] = %d\n", i, d[i]);
		res += (d[i] * 1.0) / n;
	}
    return res;
}

double getMin(int d[]) {
    double res = 1.0 * INF;
	for(int i = 1; i <= n; i++) {
	    if(d[i] > ds) return -1.0;
		if(d[i] < res) res = d[i];
	}
    return res;
}
int main() {
    freopen("in1072.txt", "r", stdin);
	char str1[5], str2[5];
	while(scanf("%d %d %d %d", &n, &m, &k, &ds) != EOF) {
		for(int i = 0; i < k; i++) {
		    int dis;
			scanf("%s %s %d", str1, str2, &dis);
			int u = change(str1);
			int v = change(str2);
            //printf("u = %d, v = %d\n", u, v);
			Adj[u].push_back(node(v, dis));
			Adj[v].push_back(node(u, dis));
		}
		for(int i = n + 1; i <= (m + n); i++) {
		    Dijkstra(i);
			double fin_min = getMin(d);
			double avg = getAvg(d);
			if(fin_min == -1) continue;
			if(fin_min > min_dis) {
			    ans.clear();
				ans.insert(i);
				min_dis = fin_min;
				minAvg_dis = avg;
				//printf("fin_min = %.1f, sum = %.1f\n", fin_min, sum);
			} else if(fin_min == min_dis) {
				if(avg < minAvg_dis) {
				    minAvg_dis = avg;
			        ans.clear();
				    ans.insert(i);
				} else if(avg == minAvg_dis) {
				    ans.insert(i);
				}
			}
			//printf("fin_min = %.1f, sum = %.1f\n", fin_min, sum);
		}
		if(ans.size() == 0) {
		    printf("No Solution\n");
		} else {
			set<int>::iterator it = ans.begin();
		    int gs = *it;
			printf("G%d\n", gs - n);
			printf("%.1f %.1f\n", min_dis, minAvg_dis);
		}
	}
    return 0;
}
//NOTE:
//1、字符串转化为数字不够熟练
//2、思维不够灵活，还有要多看题目，理解透了题意再做题。