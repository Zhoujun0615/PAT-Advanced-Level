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
//NOTE:�����������洢��ȫ�������Լ����ö����������������������Ϊ��С�������������
//      ��ˣ������Ƚ��������д�С��������Ȼ������������洢�Ķ��������������
//      �����������������е�Ԫ�أ���С��������������������еõ���λ�á�