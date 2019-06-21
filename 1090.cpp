#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
const int maxn = 100001;
struct node {
    int layer;
	vector<int> child;
}Node[maxn];
int n;
double p, r;
int Create() {
    int root;
	int parent_num;
	for(int i = 0; i < n; i++) {
	    scanf("%d", &parent_num);
		if(parent_num != -1) Node[parent_num].child.push_back(i);
		//printf("parent_num = %d\n", parent_num);
		if(parent_num == -1) root = i;
	}
    return root;
}

int getMaxlevel(int root) {
	int max = 0;
	int p;
	queue<int> q;
	Node[root].layer = 1;
	q.push(root);
	while(!q.empty()) {
	    p = q.front();
		if(Node[p].layer > max) max = Node[p].layer;
		q.pop();
		for(int i = 0; i < Node[p].child.size(); i++) {
		    int child_num = Node[p].child[i];
			Node[child_num].layer = Node[p].layer + 1;
		    q.push(child_num);
		}
	}
    return max;
}

int countMax(int root, int max) {
    int cnt = 0;
	int p;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
	    p = q.front();
		if(Node[p].layer == max) cnt++;
		q.pop();
		for(int i = 0; i < Node[p].child.size(); i++) {
		    int child_num = Node[p].child[i];
		    q.push(child_num);
		}
	}
    return cnt;
}
int main() {
    freopen("in1090.txt", "r", stdin);
	while(scanf("%d %lf %lf", &n, &p, &r) != EOF) {
	    int root = Create();
        int max_L = getMaxlevel(root);
		int cnt = countMax(root, max_L);
		double ans = p * pow(1.0 + r * 0.01, 1.0 * (max_L - 1));
		printf("%.2f %d\n", ans, cnt);
	}
	return 0;
}
//NOTE:理解题意，也可以用DFS做