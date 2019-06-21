#include <stdio.h>
#include <string.h>
struct NODE {
    char data;
	int next;
}node[100010];//这里需要注意一下，数组的最大容量为地址的最大值。

int main() {
    int first1, first2;
	int len1, len2, address, next_address;
	int N;
	char ch;
	freopen("in1032.txt", "r", stdin);
	while(scanf("%d %d %d", &first1, &first2, &N) != EOF) {
		for(int i = 0; i < N; i++) {
		    scanf("%d %c %d", &address, &ch, &next_address);
			node[address].data = ch;
			node[address].next = next_address;
		}
		int p = first1;
		int q = first2;
		len1 = len2 = 0;
		while(p != -1) {
		    len1++;
			p = node[p].next;
		}
		while(q != -1) {
		    len2++;
			q = node[q].next;
		}
		int ans = -1;
		if(len1 >= len2) {
			for(int i = 0; i < len1 - len2; i++) {
			    first1 = node[first1].next;
			}
		} else {
			for(int i = 0; i < len2 - len1; i++) {
			    first2 = node[first2].next;
			}	
		}
		while(first1 != -1 && first2 != -1) {
			if(node[first1].data == node[first2].data && first1 == first2) {
			    ans = first1;
				break;
			}
			first1 = node[first1].next;
			first2 = node[first2].next;
		}
		if(ans != -1) printf("%05d\n", ans);
		else printf("-1\n");
	}
    return 0;
}
//Note:此题需注意当结点值相同且结点的地址相同时，才可以判定该结点为公共结点。