#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
const int maxn = 35;
int n;
int post[maxn], in[maxn];
struct BTNode {
    int data;
	BTNode *lchild, *rchild;
};
BTNode* Create(int post[], int in[], int postL, int postR, int inL, int inR) {
	if(postL > postR) return NULL;
    BTNode *root = new BTNode;
	root->data = post[postR];
	root->lchild = root->rchild = NULL;
	int k;
	for(int i = inL; i <= inR; i++) {//NOTE:这里应该为 i <= inR 而不是i < inR
		if(post[postR] == in[i]) {
		    k = i;
			break;
		}
	}
	int leftNum = k - inL;
	root->rchild = Create(post, in, postL + leftNum, postR - 1, k + 1, inR);
	root->lchild = Create(post, in, postL, postL + leftNum - 1, inL, k - 1);
	return root;
}

void Level_Print(BTNode* root) {
	if(root != NULL) {
		BTNode* p;
	    queue<BTNode*> q;
		q.push(root);
		int cnt = 0;
		while(!q.empty()) {
		    p = q.front();
			printf("%d", p->data);
			cnt++;
			q.pop();
			if(cnt < n) printf(" ");
			if(p->lchild != NULL) {
			    q.push(p->lchild);
			}
			if(p->rchild != NULL) {
			    q.push(p->rchild);
			}
		}
	}
}

int main() {
    freopen("in1020.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
		    scanf("%d", &post[i]);
		}
		for(int i = 0; i < n; i++) {
		    scanf("%d", &in[i]);
		}
	    BTNode* root = Create(post, in, 0, n - 1, 0, n - 1);
	    Level_Print(root);
		printf("\n");
	}
    return 0;
}
