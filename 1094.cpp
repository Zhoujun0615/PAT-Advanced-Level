#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100;
struct node {
    int layer;
	vector<int> child;
}Node[maxn];
int n, m, level = 0, largest = 0;
int ans[101] ={0};
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

void BFS(int root) {
	queue<int> q;
	int p;
	Node[root].layer = 1;
	q.push(root);
	while(!q.empty ()){
	    p = q.front();
		int Level = Node[p].layer;
		ans[Level]++;
		q.pop();
		for(int i = 0; i < Node[p].child.size(); i++) {
		    int child_id = Node[p].child[i];
			Node[child_id].layer = Node[p].layer + 1;
			q.push(child_id);//勿忘将该结点的所有子女加入到队列中
		}
	}
}

void getLevel() {
	for(int i = 1; i <= n; i++) {
		//printf("ans[i] = %d\n", ans[i]);
		if(ans[i] > largest) {
		    largest = ans[i];
            level = i;
		}    
	}
}

int main() {
    freopen("in1094.txt", "r", stdin);
	while(scanf("%d %d", &n, &m) != EOF) {
	    Create();
		BFS(1);
		getLevel();
		printf("%d %d\n", largest, level);
	}
    return 0;
}