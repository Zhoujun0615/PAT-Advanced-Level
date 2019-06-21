#include <stdio.h>
#include <algorithm>
using namespace std;
struct Fraction {
    long long up, down; 
}F[110];

int gcd(long long a, long long b) {
    if(b == 0) return a;
	else return gcd(b, a % b);
}

Fraction reduction(Fraction result) {
	if(result.down < 0) {
		result.up = - result.up;
		result.down = result.down;
	}
	if(result.up == 0) {
		result.down = 1;
	} else {
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
    return result;
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

void showResult(Fraction r) {
    r = reduction(r);
	if(r.down == 1) printf("%lld\n", r.up);
	else if(abs(r.up) > r.down) {
		printf("%lld %lld/%lld\n", r.up / r.down, abs(r.up) % r.down, r.down);
	} else {
		printf("%lld/%lld\n", r.up, r.down);
	}
}

int main() {
    Fraction res;
	int N;
	freopen("in1081.txt", "r", stdin);
	while(scanf("%d", &N) != EOF) {
		res.up = 0, res.down = 1;
		for(int i = 0; i < N; i++) {
			scanf("%lld/%lld", &F[i].up, &F[i].down);
			res = add(res, F[i]);
		}
		showResult(res);
	}
    return 0;
}
//NOTE:分数和初始化应该令其分子为 0，分母为1，否则，当输入为0时，res未初始化，会导致错误。