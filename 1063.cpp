#include <stdio.h>
#include <set>
using namespace std;
int main() {
    int N, M, K, num;
	freopen("in1063.txt", "r", stdin);
	set<int> a[55];
	int size[55] = {0};
	while(scanf("%d", &N) != EOF) {
		for(int i = 1; i <= N; i++) {
		    scanf("%d", &M);
			for(int j = 0; j < M; j++) {
			    scanf("%d", &num);
				a[i].insert(num);
			}
			size[i] = a[i].size();
		}
		scanf("%d", &K);
		for(int i = 0; i < K; i++) {
			int n1, n2;
		    scanf("%d %d", &n1, &n2);
			int temp_same = 0;
			int total_num = a[n2].size();
			for(set<int>::iterator it = a[n1].begin(); it != a[n1].end(); it++) {
			    if(a[n2].count(*it) > 0) temp_same++;
				else total_num++;
			}
			//printf("%d %d %d\n", size[n1], size[n2], temp.size());
			double ans = (temp_same * 1.0) / total_num * 100;
			printf("%.1f%%\n", ans);
		}
	}
    return 0;
}
//NOTE: 注意set.insert()的时间复杂度，尽量不要在多个多重嵌套循环使用set的insert操作
//改用find()或者count()的操作
