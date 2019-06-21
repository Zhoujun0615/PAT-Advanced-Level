#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int weight;
	vector<int> child;
}Node[100];
bool cmp(int a, int b) {
    return Node[a].weight > Node[b].weight;
}
int n, m, s;
int table[100] = {0};
int path[100];
int Create() {
	int root = -1;
	for(int i = 0; i < n; i++) {
	    scanf("%d", &Node[i].weight);
	}
	for(int i = 0; i < m; i++) {
	    int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		for(int j = 0; j < temp2; j++) {
			int childNum;
			scanf("%d", &childNum);
				table[childNum] = 1;
		    Node[temp1].child.push_back(childNum);
		}
		sort(Node[temp1].child.begin(), Node[temp1].child.end(), cmp);
	}
	for(int i = 0; i < n; i++) {
	    if(table[i] == 0) root = i;
	}
    return root;
}

void PreOrder(int root, int nodeNum, int sum) {
    sum += Node[root].weight;
	//printf("sum = %d, root = %d, Node[root].child.size() = %d\n", sum, root, Node[root].child.size());
	path[nodeNum++] = Node[root].weight;
	if(sum > s ) {
		return;
	} else if(sum == s && Node[root].child.size() == 0) {//ֻ�е���Ҷ�ڵ���sum == sʱ�������
		for(int i = 0; i < nodeNum; i++) {
		    printf("%d", path[i]);
			if(i < nodeNum - 1) printf(" ");
		}
		printf("\n");
		return;
	} else {
		for(int i = 0; i < Node[root].child.size(); i++) {
		    PreOrder(Node[root].child[i], nodeNum, sum);
		}
	}
}

int main() {
    freopen("in1053.txt", "r", stdin);
	while(scanf("%d %d %d", &n, &m, &s) != EOF) {
	    int root = Create();
		int sum = 0;
		//printf("root = %d\n", root);
		PreOrder(root, 0, sum);
	}
    return 0;
}
//NOTE�������ȸ�����ʵ������һ����ȱ����������Ĳ���Ҫ���ú�
//      ������Ӧ������һ��nodeNum��sum��sum������¼��ǰ�Ľ��Ȩֵ֮�ͣ�nodeNum��������¼
//      ·���ϵĽ���Ȩֵ��·�������е��±�