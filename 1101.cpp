#include <stdio.h>
const int maxn = 100010;
const int INF = 0x7fffffff;
int a[maxn], ans[maxn];
int main()
{
    int N;
	freopen("in1101.txt", "r", stdin);
	while(scanf("%d", &N) != EOF) {
		int left_max[maxn];
		int right_min[maxn];
		int cnt = 0;
		left_max[0] = 0;
		if(N >= 1) right_min[N - 1] = INF;
		for(int i = 0; i < N; i++) {
		    scanf("%d", &a[i]);
		}
		for(int i = 1; i < N; i++) {
		    if(left_max[i - 1] < a[i - 1])
				left_max[i] = a[i - 1];
			else
				left_max[i] = left_max[i - 1];
		}
		for(int i = N - 2; i >= 0; i--) {
		    if(right_min[i + 1] > a[i + 1])
				right_min[i] = a[i + 1];
			else
				right_min[i] = right_min[i + 1];		
		}
		for(int i = 0; i < N; i++) {
			if(left_max[i] < a[i] && right_min[i] > a[i]) {
			    ans[cnt] = a[i];
				cnt++;
			}
		}
        printf("%d\n", cnt);
		for(int i = 0; i < cnt; i++) {
		    printf("%d", ans[i]);
			if(i < cnt - 1)
				printf(" ");
		}
		printf("\n");
	}
    return 0;
}
//NOTE:ע��������⣬˼ά����������Ӳ�ס����ܼ�¼ÿһλ��߱���С�ĸ�����
//�ǾͿ��Ǽ�¼ÿһλ��ߵ���������������ĿӦ�ô��ܼ̳е����Գ����������ֵ
//������������