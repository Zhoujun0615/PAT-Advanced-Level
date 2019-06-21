#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 100;
struct node {
    int data, lchild, rchild;
}Node[maxn];
int n, index;
int origin[maxn];
void Create() {
    int left, right;
	for(int i = 0; i < n; i++) {
	    scanf("%d %d", &left, &right);
		Node[i].lchild = left;
		Node[i].rchild = right;
	}
	for(int i = 0; i < n; i++) {
	    scanf("%d", &origin[i]);
	}
    sort(origin, origin + n);
}

void inorder(int root) {
    if(root == -1) return;
	inorder(Node[root].lchild);
	Node[root].data = origin[index++];
	inorder(Node[root].rchild);
}

void Print(int root) {
	if(root == -1) return;
    int p;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
	    p = q.front();
        q.pop();
		index++;
		printf("%d", Node[p].data);
		if(index < n) printf(" ");
		else printf("\n");
		if(Node[p].lchild != -1)
			q.push(Node[p].lchild);
		if(Node[p].rchild != -1)
			q.push(Node[p].rchild);
	}
}

int main() {
    freopen("in1099.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
		index = 0;
	    Create();
		inorder(0);
		index = 0;
		Print(0);
	}
    return 0;
}