#include <stdio.h>
int main() {
    int N;
	int a[110] = {0};
	long long total = 0;
	while(scanf("%d", &N) != EOF) {
		for(int i = 1; i <= N; i++) {
		    scanf("%d", &a[i]);
		}
		for(int i = N; i >= 1; i--) {
		    a[i] = a[i] - a[i - 1];
			if(a[i] < 0) total -= (a[i] * 4);
			else total += (a[i] * 6);
		}
		total += (N * 5);
		printf("%lld\n", total);
	}
    return 0;
}