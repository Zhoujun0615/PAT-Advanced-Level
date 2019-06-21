#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int CBT[maxn], origin[maxn];
int n, index = 0;
void inorder(int root) {
    if(root > n) return;
	inorder(root * 2);
	CBT[root] = origin[index++];
    inorder(root * 2 + 1);
}

int main() {
	//freopen("in1064.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
		    scanf("%d", &origin[i]);
		}
		sort(origin, origin + n);
	    inorder(1);
		for(int i = 1; i <= n; i++) {
		    printf("%d", CBT[i]);
			if(i <= n - 1) printf(" ");
		}
		printf("\n");
	}
    return 0;
}
//NOTE:利用数组来存储完全二叉树以及利用二叉搜索树的中序遍历序列为从小到大的有序序列
//      因此，可以先将所给序列从小到大排序，然后利用以数组存储的二叉树的中序遍历
//      将排序后的所给序列中的元素，从小到大，依次填入中序遍历中得到的位置。