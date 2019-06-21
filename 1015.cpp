#include <stdio.h>
#include <math.h>
bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
	    if(n % i == 0) return false;
	}
	return true;
}

int main() {
    int N, D;
	while(scanf("%d", &N) != EOF) {
		int temp[40];
        int pos = 0;
		if(N < 0) break;
	    scanf("%d", &D);
		int num1 = N;
		do {
		    temp[pos++] = N % D;
			N /= D;
		}while(N != 0);
		int num2 = 0;
		for(int i = 0; i < pos; i++) {
		    num2 = num2 * D + temp[i];
		}
		//printf("num2 = %d\n", num2);
		if(isPrime(num1) && isPrime(num2))
			printf("Yes\n");
		else
			printf("No\n");	
	}
	return 0;
}
//NOTE:�ж�һ�����Ƿ�Ϊ����ʱ����Ҫ�Ƚ������У���������С�ڵ���1���򷵻�false��