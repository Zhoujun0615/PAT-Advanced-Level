#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
struct Fraction {
    LL up, down;
}F1, F2;
char op[4] = {'+', '-', '*', '/'};

LL gcd(LL a, LL b) {
    if(b == 0) return a;
	else return gcd(b, a % b);
}

Fraction reduction(Fraction result) {
	if(result.down < 0) {
		result.down = - result.down;
		result.up = - result.up;
	}
	if(result.up == 0) {
		result.down = 1;
	} else {
		LL d = gcd(abs(result.up), abs(result.down));
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

Fraction minu(Fraction f1, Fraction f2) {
    Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction mutil(Fraction f1, Fraction f2) {
    Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
	result.up = f1.up * f2.down;
	result.down = f2.up * f1.down;
	return reduction(result);
}

void showResult(Fraction r) {
    r = reduction(r);
	if(r.down == 1) {
		if(r.up >= 0) printf("%lld", r.up);
		else printf("(%lld)", r.up);
	}
	else if(abs(r.up) > r.down) {
		if(r.up < 0) {
			printf("(%lld %lld/%lld)", r.up / r.down, abs(r.up) % r.down, r.down);
		} else {
		    printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
		}
	} else {
		if(r.up < 0) {
			printf("(%lld/%lld)", r.up, r.down);
		} else {
		    printf("%lld/%lld", r.up, r.down);
		}	
	}
}

int main() {
	freopen("in1088.txt", "r", stdin);
	while(scanf("%lld/%lld %lld/%lld", &F1.up, &F1.down, &F2.up, &F2.down) != EOF) {
		for(int i = 0; i < 4; i++) {
		    Fraction res;
			res.up = 0; res.down = 1;
			showResult(F1);
			printf(" %c ", op[i]);
			showResult(F2);
			switch(i) {
				case 0:
					res = add(F1, F2);
					printf(" = ");
					showResult(res);
			        break;
				case 1:
			        res = minu(F1, F2);
					printf(" = ");
					showResult(res);
			        break;
				case 2:
			        res = mutil(F1, F2);
					printf(" = ");
					showResult(res);
			        break;
				case 3:
					if(F2.up != 0) {
			            res = divide(F1, F2);
					    printf(" = ");
					    showResult(res);
					} else {
					    printf(" = Inf");
					}
			        break;
			}
			printf("\n");
		}
	}
    return 0;
}
//NOTE: 两个分数做除法运算时，要先判断除数是否为0，若不为0才可以进行除法运算。