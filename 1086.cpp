#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

const int maxn = 35;
int pre[maxn], in[maxn];
int n, num, cnt;
char str[10];
struct BTNode {
    int data;
	BTNode *lchild, *rchild;
};
BTNode* Create(int pre[], int in[], int preL, int preR, int inL, int inR) {
    if(preL > preR) return NULL;
	BTNode* root = new BTNode;
	root->data = pre[preL];
	root->lchild = root->rchild = NULL;
	int k;
	for(k = inL; k <= inR; k++) {
	    if(in[k] == pre[preL]) break;
	}
    int leftNum = k - inL;
	root->lchild = Create(pre, in, preL + 1, preL + leftNum, inL, k - 1);
	root->rchild = Create(pre, in, preL + leftNum + 1, preR, k + 1, inR);
    return root;
}

void postorder_Print(BTNode* root) {
    if(root == NULL) return;
    postorder_Print(root->lchild);
	postorder_Print(root->rchild);
    printf("%d", root->data);
	cnt++;
	if(cnt < n) printf(" ");
}

int main() {
	freopen("in1086.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
		stack<int> s;
		int pre_pos, in_pos;
		pre_pos = in_pos = 0;
		cnt = 0;
		getchar();
		for(int i = 0; i < 2 * n; i++) {
		    scanf("%s", str);
			//printf("%s\n", str);
			if(strcmp(str, "Push") == 0) {
			   scanf("%d", &num);
			   s.push(num);
			   pre[pre_pos++] = num; 
			   //getchar();
			} else if(strcmp(str, "Pop") == 0) {
				//printf(" %d\n", s.top());
				if(!s.empty()){
			        in[in_pos++] = s.top();
				    s.pop();				
				}
			}
		}
		BTNode* root = Create(pre, in, 0, n - 1, 0, n - 1);
		postorder_Print(root);
	    printf("\n");
	}
    return 0;
}
//NOTE:注意理解题意，入栈序列不一定是从1开始的，有可能直接从m开始
//     因此，应该将入栈序列记录为先序序列，出栈序列记录为中序序列。