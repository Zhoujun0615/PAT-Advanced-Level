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
//NOTE: ע��set.insert()��ʱ�临�Ӷȣ�������Ҫ�ڶ������Ƕ��ѭ��ʹ��set��insert����
//����find()����count()�Ĳ���
