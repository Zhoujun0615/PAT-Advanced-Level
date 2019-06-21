#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int fac[100];
int main() {
    int N;
	while(scanf("%d", &N) != EOF) {
		if(N == 1) printf("0\n");
		else {
		    int sqr = (int)sqrt(1.0 * N);
			int num = 0;
			for(int i = 2; i <= sqr; i++) {
				if(N % i == 0) {
				    fac[num++] = i;
					N /= i;
				}
				if(N == 1) break;
			}
			if(N != 1) {
			    fac[num++] = N;
			}
			if(num == 1) {
			    printf("1\n%d\n", N);
			}
			else {
			    int begin, end, min_len;
				min_len = 1000;
			    begin = end = 0;
			    for(int i = 0; i < num - 1; i++) {
					if(fac[i + 1] - fac[i] == 1) {
					    begin = i;
						while(fac[i + 1] - fac[i] == 1) {
						    i++;
							if(i >= num - 1) break;
						}
						end = i;
						if(end - begin + 1 < min_len)
							min_len = end - begin + 1;
					}
			    }
			    printf("%d\n", min_len);
				for(int i = begin; i <= end; i++) {
				    printf("%d", fac[i]);
					if(i < end) printf("*");
				}
				printf("\n");
			}
            
		}
	}
    return 0;
}