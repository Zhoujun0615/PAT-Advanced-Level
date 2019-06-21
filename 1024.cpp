#include <stdio.h>
#include <string.h>
struct bign {
    int d[1005];
	int len;
	bign() {
	    len = 0;
		memset(d, 0, sizeof(d));
	}
};
bign change(char str[]) {
    bign c;
	c.len = strlen(str);
	for(int i = 0; i < c.len; i++) {
		c.d[i] = str[c.len - 1 - i] - '0';
	}
    return c;
}

bign reverse(bign a) {
	bign b;
	b.len = a.len;
	for(int i = 0; i < a.len; i++) {
        b.d[i] = a.d[a.len - 1 - i];
	}
    return b;
}

bign add(bign a, bign b) {
	bign res;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++) {
	    int temp = a.d[i] + b.d[i] + carry;
		if(temp >= 10) {
			res.d[res.len++] = temp % 10;
			carry = temp / 10;
		} else {
		    res.d[res.len++] = temp;
			carry = 0;
		}
	}
	if(carry != 0) res.d[res.len++] = carry;
    return res;
}

bool judge(bign a) {
	for(int i = 0; i < a.len / 2; i++) {
	    if(a.d[i] != a.d[a.len - 1 - i]) return false;
	}
	return true;
}

void Print(bign a) {
	for(int i = a.len - 1; i >= 0; i--) {
	    printf("%d", a.d[i]);
	}
    printf("\n");
}

int main() {
    char str[20];
	int k;
	while(scanf("%s %d", str, &k) != EOF) {
	    int step = 0;
		bign temp1 = change(str);
		if(judge(temp1)) {
		    Print(temp1);
			printf("%d\n", step);
		} else {
			bign ans = temp1;
			for(step = 1; step <= k; step++) {
			    bign temp2 = reverse(ans);
				//Print(temp2);
			    ans = add(ans, temp2);
				//Print(ans);
				if(judge(ans)) {
		            Print(ans);
			        printf("%d\n", step);
					break;
				}
			}
			if(step > k) {
				Print(ans);
			    printf("%d\n", k);
			}		
		}
	}
    return 0;
}