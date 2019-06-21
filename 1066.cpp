#include <stdio.h>
#include <algorithm>
using namespace std;
struct node {
    int data, height;
	node *lchild, *rchild;
};

node* newNode(int v) {
    node* p = new node;
	p->data = v;
	p->height = 1;
	p->lchild = p->rchild = NULL;
    return p;
}

int getHeight(node* root) {
    if(root == NULL) return 0;
	return root->height;
}

int getBF(node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void L(node* &root) {
    node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
    root = temp;
}

void R(node* &root) {
    node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
    updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int v) {
	if(root == NULL) {
	    root = newNode(v);
		return;
	} else if(root->data > v) {
	    insert(root->lchild, v);
	    updateHeight(root);
		if(getBF(root) == 2) {
			if(getBF(root->lchild) == 1) {
			    R(root);
			} else if(getBF(root->lchild) == -1) {
			    L(root->lchild);
				R(root);
			}
		}
	} else {
	    insert(root->rchild, v);
		updateHeight(root);
		if(getBF(root) == -2) {
			if(getBF(root->rchild) == -1) {//右孩子的平衡因子为-1表示的是RR型
			    L(root);
			} else if(getBF(root->rchild) == 1) {//右孩子的平衡因子为1表示的是RL型
			    R(root->rchild);
				L(root);
			}
		}
	}
}

node* create(int data[], int n) {
    node* root = NULL;
	for(int i = 0; i < n; i++) {
	    insert(root, data[i]);
	}
    return root;
}

int main() {
    int n;
	int a[25];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
	    scanf("%d", &a[i]);
	}
	node* root = create(a, n);
    if(root != NULL) printf("%d\n", root->data);
    return 0;
}