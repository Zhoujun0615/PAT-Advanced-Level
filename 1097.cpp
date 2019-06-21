#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1000005;
int table[maxn] = {0};
struct Node {
    int address, data, next;
	int order;
}node[maxn];
bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    int first, N, address, data, next;
	freopen("in1097.txt", "r", stdin);
	while(scanf("%d %d", &first, &N) != EOF) {
		for(int i = 0; i < 100010; i++) {
		    node[i].order = 2 * maxn;
		}
		for(int i = 0; i < N; i++) {
		    scanf("%d %d %d", &address, &data, &next);
			node[address].address = address;
			node[address].data = data;
			node[address].next = next;
		}
		int p = first;
		int cnt1, cnt2;
		cnt1 = cnt2 = 0;
		while(p != -1) {
			int temp = abs(node[p].data);
		    if(temp < maxn)
			{			    
				if(table[temp] == 0) {
                    node[p].order = cnt1;
					table[temp] = 1;
					cnt1++;
				} else {
				    node[p].order = cnt2 + maxn;
					cnt2++;
				}
			}		
			p = node[p].next;
		}
		//printf("cnt1 = %d, cnt2 = %d\n", cnt1, cnt2);
		sort(node, node + 100010, cmp);
		for(int i = 0; i < cnt1 + cnt2; i++) {
		    printf("%05d %d ", node[i].address, node[i].data);
			if(i == cnt1 - 1 || i == cnt1 + cnt2 - 1) {
			    printf("-1\n");
			} else {
			    printf("%05d\n", node[i + 1].address);
			}		
		}			
	}
    return 0;
}
//NOTE:����Ӧ��ע������ܽ�����Ϊ10^5����key�����ֵ������10^4
//     ��ˣ����ܳ���Ӧɾ�����ظ��ڵ������ܳ���10^4�����Գ�ʼʱorderӦ����Ϊ2*maxn
//     Ȼ���ظ������ֵ���ʼorderӦ��Ϊmaxn