#include <stdio.h>
struct node {
    int data;
	node *lchild, *rchild;
};
int origin[1010], pre1[1010], pre2[1010];
int n, cnt1 = 0, cnt2 = 0;
void insert(node* &root, int x) {
	if(root == NULL) {
	    root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
	}
	else if(root->data > x) {
	    insert(root->lchild, x);
	} else {
	    insert(root->rchild, x);
	}
}

node* Create(int data[]) {
    node* root;
	root = NULL;
	for(int i = 0; i < n; i++) {
	    insert(root, data[i]);
	}
	return root;
}

void preorder1(node* root) {
	if(root == NULL) return;
	pre1[cnt1++] = root->data;
    preorder1(root->lchild);
	preorder1(root->rchild);
}

void preorder2(node* root) {
	if(root == NULL) return;
	pre2[cnt2++] = root->data;
    preorder2(root->rchild);
	preorder2(root->lchild);
}

void Print1(node* root) {
    if(root == NULL) return;
	Print1(root->lchild);
	Print1(root->rchild);
	printf("%d", root->data);
	cnt1++;
	if(cnt1 < n) printf(" ");
	else printf("\n");
}

void Print2(node* root) {
    if(root == NULL) return;
	Print2(root->rchild);
	Print2(root->lchild);
	printf("%d", root->data);
	cnt2++;
	if(cnt2 < n) printf(" ");
	else printf("\n");
}

bool judge(int origin[], int pre[]) {
	for(int i = 0; i < n; i++) {
	    if(pre[i] != origin[i]) return false;
	}
	return true;
}

int main() {
    freopen("in1043.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
		    scanf("%d", &origin[i]);
		}
		node* root = Create(origin);
		preorder1(root);
		preorder2(root);
		if(judge(origin, pre1)) {
		    printf("YES\n");
            cnt1 = 0;
			Print1(root);
		} else if(judge(origin, pre2)) {
		    printf("YES\n");
            cnt2 = 0;
			Print2(root);
		} else {
		    printf("NO\n");
		}
	}
    return 0;
}
//NOTE:若结点已存在，则需将该结点插入对应的右子树相应位置