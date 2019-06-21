#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int layer;
    vector<int> child;
}Node[100];
int n, m;
int ans[100] = {0};
void Create() {
    int num, child_num, temp;
	for(int i = 0; i < m; i++) {
	    scanf("%d %d", &num, &child_num);
		for(int j = 0; j < child_num; j++) {
		    scanf("%d", &temp);
			Node[num].child.push_back(temp);
		}
	}
}

int BFS(int root) {
    int level;
	queue<int> q;
	Node[root].layer = 1;
	q.push(root);
	while(!q.empty()) {
	    int p = q.front();
		q.pop();
		level = Node[p].layer;
		if(Node[p].child.size() == 0) {
		    ans[level]++;
		}
		for(int i = 0; i < Node[p].child.size(); i++) {
		    int child_id = Node[p].child[i];
			Node[child_id].layer = level + 1;
		    q.push(child_id);
		}
	}
	return level;
}

void Print(int level) {
	for(int i = 1; i <= level; i++) {
	    printf("%d", ans[i]);
		if(i < level) printf(" ");
	}
	printf("\n");
}

int main() {
    freopen("in1004.txt", "r", stdin);
	while(scanf("%d %d", &n, &m) != EOF) {
	    Create();
		int Level = BFS(1);
        Print(Level);
	}
    return 0;
}