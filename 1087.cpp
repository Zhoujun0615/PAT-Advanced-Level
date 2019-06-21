#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
const int maxv = 210;
const int INF = 0x3fffffff;
int d[maxv], vis[maxv], num[maxv], happy[maxv];
int G[maxv][maxv];
map<string, int> strToint;
map<int, string> intTostr;
int n, k, s, ed;
int numCity = 0;
int max_h = -1, max_av_h = -1;
vector<int> pre[maxv];
vector<int> Path, tempPath;

void Dijkstra(int s) {
    fill(d, d + maxv, INF);
	fill(vis, vis + maxv, 0);
	fill(num, num + maxv, 0);
	d[s] = 0;
	num[s] = 1;
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
				    pre[v].clear();
				    pre[v].push_back(u);
			    } else if(d[u] + G[u][v] == d[v]) {
			        num[v] += num[u];
				    pre[v].push_back(u);
			    }
		    }
	    }
	}
}

void DFS(int v) {
	if(v == s) {
	    tempPath.push_back(v);
		int h = 0, av_h = 0;
		int num = tempPath.size() - 1;
		for(int i = num - 1; i >= 0; i--) {
			int id = tempPath[i];    //这里应该用happy[tempPath[i]]，而不是happy[i]；
		    h += happy[id];
		}
		av_h = h / num;
		if(h > max_h) {
		    max_h = h;
		    max_av_h = av_h;
			Path = tempPath;
		} else if(h == max_h) {
			if(av_h > max_av_h) {
			    max_av_h = av_h;
				Path = tempPath;
			}
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

int change(string str) {
	if(strToint.find(str) != strToint.end()) {
	    return strToint[str];
	} else {
	    strToint[str] = numCity;
		intTostr[numCity] = str;
        return numCity++;
	}
}

int main() {
    int u, v, w;
	string str;
	string city1, city2;
	freopen("in1087.txt", "r", stdin);
	while(cin >> n >> k >> str) {
		fill(G[0], G[0] + maxv * maxv, INF);
	    s = change(str);
		for(int i = 1; i < n; i++) {
		    cin >> str >> w;
			int id = change(str);
			happy[id] = w;
		}
		ed = strToint["ROM"];
		for(int i = 0; i < k; i++) {
		    cin >> city1 >> city2 >> w;
			u = change(city1);
			v = change(city2);
			//cout << u << v << w <<endl;
			G[u][v] = w;
			G[v][u] = w;
		}
		Dijkstra(s);
		DFS(ed);
		cout << num[ed] << " " << d[ed] << " " << max_h << " " << max_av_h << endl;
		for(int i = Path.size() - 1; i >= 0; i--) {
		    int temp = Path[i];
			cout << intTostr[temp];
			if(i > 0) cout << "->";
			else cout << endl;
		}
	}
    return 0;
}
//NOTE：1、注意用map将字符串转化为数字，以及将数字转化为字符串的写法
//Dijkstra + DFS