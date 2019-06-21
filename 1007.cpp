#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 10005;
int dp_last[maxn], dp_first[maxn], a[maxn];
int n;

int main() {
    freopen("in1007.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
	    for(int i = 0; i < n; i++)
		    scanf("%d", &a[i]);
	}
	//µÝÍÆ±ß½ç
	dp_last[0] = a[0];
	dp_first[0] = 0;
	//×´Ì¬×ªÒÆ
	for(int i = 1; i < n; i++) {
		if(dp_last[i - 1] + a[i] < a[i]) {
		    dp_last[i] = a[i];
			dp_first[i] = i;
		} else {
		    dp_last[i] = dp_last[i - 1] + a[i];
			dp_first[i] = dp_first[i - 1];
		}
	}
    int k = 0;
	for(int i = 0; i < n; i++) {
	    if(dp_last[i] > dp_last[k]) k = i;
	}
	if(dp_last[k] < 0) {
	    printf("0 %d %d\n", a[0], a[n - 1]);
	} else {
	    printf("%d %d %d\n", dp_last[k], a[dp_first[k]], a[k]);
	}
    return 0;
}