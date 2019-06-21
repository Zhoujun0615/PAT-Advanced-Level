#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxv = 10010;
int inq[maxv], level[maxv], ans[maxv];
int num = 0, max_h = -1;
int n;
vector<int> Adj[maxv];
int BFS(int u) {
    queue<int> q;
	inq[u] = 1;
	level[u] = 1;
	int L;
	q.push(u);
	while(!q.empty()) {
	    int front = q.front();
		q.pop();
	    L = level[front];
		for(int i = 0; i < Adj[front].size(); i++) {
		    int v = Adj[front][i];
			level[v] = L + 1;
			if(!inq[v]) {
			    q.push(v);
				inq[v] = 1;
			}
		}
	}
	return L;
}

void BFSTrave() {
	for(int i = 1; i <= n; i++) {
	    inq[i] = 0;
		level[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(!inq[i]) {
		   int h = BFS(i);
		   //printf("i = %d, h = %d\n", i, h);
		   if(h > max_h) {
		       num = 1;
			   max_h = h;
			   ans[num] = i;
		   } else if(h == max_h){
		       num++;
			   ans[num] = i;
		   }		   
		}
    	for(int i = 1; i <= n; i++) {
	        inq[i] = 0;
		    level[i] = 0;
	    }
	}
}

int judge() {
    int cnt = 0;
	for(int i = 1; i <= n; i++) {
	    level[i] = 0;
		inq[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(!inq[i]) {
		    int temp = BFS(i);
			cnt++;
		}
	}
    return cnt;
}
int main() {
    freopen("in1021.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; i++) {
		    int num1, num2;
			scanf("%d %d", &num1, &num2);
			Adj[num1].push_back(num2);
			Adj[num2].push_back(num1);
		}   
		int cnt = judge();
		if(cnt > 1) {
		    printf("Error: %d components\n", cnt);
		} else {
			BFSTrave();
			for(int i = 1; i <= num; i++) {
			    printf("%d\n", ans[i]);
			}
		}
		for(int i = 1; i <= n; i++) Adj[i].clear();
	}
    return 0;
}
//NOTE:多点测试时，最后需要清空邻接表。