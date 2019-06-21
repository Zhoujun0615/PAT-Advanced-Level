#include <stdio.h>
const int maxn = 100010;
struct Node {
    int data;
	int next;
}node[maxn];
int main() {
    int K, L, begin, data, address, next;
	freopen("in1074.txt", "r", stdin);
	while(scanf("%d %d %d", &begin, &L, &K) != EOF) {
		for(int i = 0; i < L; i++) {
		    scanf("%d %d %d", &address, &data, &next);
			node[address].data = data;
			node[address].next = next;
		}
		int len = 0;
		int cur = begin;
		while(cur != -1) {
		    len++;
			cur = node[cur].next;
		}
		int time = len / K;
		int p = begin;
		for(int i = 1; i <= time; i++) {
		    int pre = -1;
			int now = p;
			for(int j = 0; j < K; j++) {
                int temp;
				temp = node[p].next;
				node[p].next = pre;
				pre = p;
				p = temp;
				//printf("node[p].data = %d\n", node[p].data);
			}
			if(len - (i + 1) * K >= 0) {
			    int temp1 = p;
			    for(int j = 0; j < K - 1; j++) {
				    temp1 = node[temp1].next;
			    }
			    node[now].next = temp1;			
			} else {
			    node[now].next = p;
				//printf("now = %d\n", now);
			}
			if(i == 1) begin = pre;
		}
		int pos = begin;
		while(pos != -1) {
			printf("%05d %d ", pos, node[pos]);
			if(node[pos].next != -1)
				printf("%05d\n", node[pos].next);
			else printf("-1\n");
			pos = node[pos].next;
		}
	}
    return 0;
}
//NOTE:1 做静态链表的题目时，一定要考虑题目给出的数据中可能出现不在链表上的无效数据
//     2 因此，需要在读入数据后，重新从开始计算链表长度
//     3 对于需要分组且最后一组的处理不一样的题目应该优先将分组数明确，然后再在每一组内计算
//     4 链表中的最后一个结点的next应该为-1，需要特殊处理！