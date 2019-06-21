#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn], isRoot[maxn];
int n, cnt;
bool cmp(int a, int b) {
    return a > b;
}
void init() {
	for(int i = 1; i <= n; i++) {
	    father[i] = i;
		isRoot[i] = 0;
	}
}

int findFather(int x) {
    int a = x;
	while(x != father[x]) {
	    x = father[x];
	}
	while(a != father[a]) {
	    int z = a;
		a = father[a];
	    father[z] = x;
	}
    return x;
}

int main() {
    freopen("in1107.txt", "r", stdin);
	int h_num, temp;
	while(scanf("%d", &n) != EOF) {
		init();
		int hobby[maxn] = {0};
		for(int i = 1; i <= n; i++) {
		    scanf("%d:", &h_num);
		    for(int j = 0; j < h_num; j++) {
		        scanf("%d", &temp);
				//printf("temp = %d\n", temp);
				if(hobby[temp] == 0) {
				    hobby[temp] = i;
				} else {
				    int faA = findFather(i);
					int faB = findFather(hobby[temp]);
					if(faA != faB)
					    father[faA] = faB;
				}
				//printf("i = %d, father[i] = %d\n", i, father[i]);
		    }		
		}
		for(int i = 1; i <= n; i++) {
			isRoot[findFather(i)]++;
		}
		cnt = 0;
		for(int i = 1; i <= n; i++) {
		    if(isRoot[i] != 0) cnt++;
		}
		sort(isRoot + 1, isRoot + n + 1, cmp);
		printf("%d\n", cnt);
		for(int i = 1; i <= cnt; i++) {
		    printf("%d", isRoot[i]);
			if(i <= cnt - 1) printf(" ");
			else printf("\n");
		}
	}
    return 0;
}
//Note:1、注意数组的初始化问题，以及合并不同并查集的实现，还有在并查集中寻找不同集合的根结点的方法