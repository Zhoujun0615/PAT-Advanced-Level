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
		    sort(node, node + maxn, cmp);//需要将所有可能覆盖的地址一起进行排序
			printf("%d %05d\n", cnt, node[0].address);//排序后node[0]为data值最小的元素
		    for(int i = 0; i < cnt - 1; i++) {
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
				//这里需要注意的是，此时下一个结点的地址应该改变为node[i + 1]的地址
			}
			printf("%05d %d -1\n", node[cnt - 1].address, node[cnt - 1].data);//最后一个元素的next地址应为-1
		}		
	}
    return 0;
}