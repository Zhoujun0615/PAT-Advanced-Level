#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int change(int a[], int n) {
    int res = 0;
	for(int i = 0; i < n; i++) {
	    int temp = a[i];
	    res = res * 10 + temp;
	}
	return res;
}
int a[4];
int main() {
	int N;
    while(scanf("%d", &N) != EOF) {
		int n = N;
		for(int i = 3; i >= 0; i--) {
		    a[i] = n % 10;
		    n /= 10;
		}
		if(N > 0) {
			int ans = -1;
			while(ans != 6174) {
				sort(a, a + 4, cmp);
				int temp1 = change(a, 4);
				sort(a, a + 4);
				int temp2 = change(a, 4);
				ans = temp1 - temp2;
				if(ans == 0) {
				    printf("%04d - %04d = 0000\n", temp1, temp2);
					break;
				}
				else {
				    printf("%04d - %04d = %04d\n", temp1, temp2, ans);
				}
				if(ans == 6174) break;
				for(int i = 3; i >= 0; i--) {
				    a[i] = ans % 10;
				    ans /= 10;
				}
			}
		}
	}
    return 0;
}
