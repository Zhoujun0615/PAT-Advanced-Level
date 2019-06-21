#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
const int maxv = 1010;
int inq[maxv];
int n, l, k, query;
struct node {
    int v;
	int layer;
};
vector<node> Adj[maxv];
void BFS(int u, int &sum) {
    queue<node> q;
	node begin;
	begin.v = u;
	begin.layer = 0;
	inq[begin.v] = 1;
	q.push(begin);
	while(!q.empty()) {
	    node top = q.front();
		q.pop();
		int v = top.v;
		int layer = top.layer;
		if(layer > 0 && layer <= l) {
		    sum++;
		}
		for(int i = 0; i < Adj[v].size(); i++) {
		    node next = Adj[v][i];
			next.layer = layer + 1;
			if(!inq[next.v]) {
				q.push(next);
				inq[next.v] = 1;
			}
		}
	}
}

int main() {
    freopen("in1076.txt", "r", stdin);
	while(scanf("%d %d", &n, &l) != EOF) {
		for(int i = 1; i <= n; i++) {
		   int follow_num, follow;
		   scanf("%d", &follow_num);
		   for(int j = 0; j < follow_num; j++) {
		       scanf("%d", &follow);
			   node temp;
			   temp.layer = 0;
			   temp.v = i;
			   Adj[follow].push_back(temp);
		   }
		}
		scanf("%d", &k);
		for(int i = 0; i < k; i++) {
		    memset(inq, 0, sizeof(inq));
		    scanf("%d", &query);
			int sum = 0;
			BFS(query, sum);
			printf("%d\n", sum);
		}
	}
    return 0;
}
//NOTE:邻接表表示的图的存储和BFS，以及结点层号的设置