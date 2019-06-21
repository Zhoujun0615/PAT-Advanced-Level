#include <stdio.h>
#include <math.h>

const int maxn = 100005;
struct factor {
    int x, cnt;
}fac[10];
bool isPrime(int n) {
    if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
	    if(n % sqr == 0) return false;
	}
	return true;
}
int prime[maxn];
int pNum = 0;
void Find_Prime() {
	for(int i = 1; i < maxn; i++) {
		if(isPrime(i)) {
		    prime[pNum++] = i;
		}
	}
}
int main() {
    int N;
	while(scanf("%d", &N) != EOF) {
		printf("%d=", N);
		if(N == 1) printf("%d\n", N);
		else {
	        int sqr = (int)sqrt(1.0 * N);
			int num = 0;
			Find_Prime();
			for(int i = 0; i < pNum && prime[i] <= sqr; i++) {
				if(N % prime[i] == 0) {
					fac[num].x = prime[i];
					fac[num].cnt = 0;
					while(N % prime[i] == 0) {
						fac[num].cnt++;
						 N /= prime[i];
					}
					num++;
				}
				if(N == 1) break;
			}
			if(N != 1) {
				fac[num].cnt = 1;
				fac[num].x = N;
				num++;
			}
			for(int i = 0; i < num; i++){
				printf("%d", fac[i].x);
				if(fac[i].cnt > 1) printf("^%d", fac[i].cnt);
				if(i < num - 1) printf("*");
			}
		    printf("\n");
		}
	}
    return 0;
}
//NOTE:1、在程序开头勿忘调用打印输出素数表函数Find_Prime()
//     2、若n=1，则需特判输出，因为素数表中最小数为2
//     3、记得处理大于sqrt(N)的质因数！