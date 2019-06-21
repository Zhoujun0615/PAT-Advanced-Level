#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node {
    int data, address, next;
	int flag;
}node[maxn];
bool cmp(Node a, Node b) {
    if(a.flag == 0 || b.flag == 0) return a.flag > b.flag; 
	else return a.data < b.data;
}
int main() {
    int N, begin, address, next, num;
	freopen("in1052.txt", "r", stdin);
	while(scanf("%d %d", &N, &begin) != EOF) {
		for(int i = 0; i < maxn; i++) {
		    node[i].flag = 0;
		}
		for(int i = 0; i < N; i++) {
		    scanf("%d %d %d", &address, &num, &next);
			node[address].data = num;
			node[address].next = next;
			node[address].address = address;
		}
		int p, cnt;
		p = begin;
		cnt = 0;
		while(p != -1) {
		    node[p].flag = 1;
			cnt++;
			p = node[p].next;
		}
		if(cnt == 0) printf("0 -1\n");
		else {
		    sort(node, node + maxn, cmp);//��Ҫ�����п��ܸ��ǵĵ�ַһ���������
			printf("%d %05d\n", cnt, node[0].address);//�����node[0]Ϊdataֵ��С��Ԫ��
		    for(int i = 0; i < cnt - 1; i++) {
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
				//������Ҫע����ǣ���ʱ��һ�����ĵ�ַӦ�øı�Ϊnode[i + 1]�ĵ�ַ
			}
			printf("%05d %d -1\n", node[cnt - 1].address, node[cnt - 1].data);//���һ��Ԫ�ص�next��ַӦΪ-1
		}		
	}
    return 0;
}