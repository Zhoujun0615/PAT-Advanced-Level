#include <stdio.h>
const int maxn = 100005;
double a[maxn];
int main() {
    freopen("in1104.txt", "r", stdin);
    int N;
	while(scanf("%d", &N) != EOF) {
		double sum = 0.0;
		for(int i = 0; i < N; i++) {
		    scanf("%lf", &a[i]);
			sum += a[i] * (i + 1) * (N - i);
		}
		printf("%.2f\n", sum);
	}
    return 0;
}
//NOTE:���������������ʱӦע�⽫����������ǰ�棬�Ա���������⡣