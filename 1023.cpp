#include <stdio.h>
#include <string.h>
struct bign {
    int d[25];
	int len;
	bign() {
	    len = 0;
	    memset(d, 0, sizeof(d));
	}
};

bign change(char str[]) {
    bign res;
	res.len = strlen(str);
	for(int i = 0; i < res.len; i++) {
		res.d[i] = str[res.len - 1 - i] - '0';
	}
	return res;
}

bign add(bign a, bign b) {
    bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		if(temp >= 10) {
			c.d[c.len++] = temp % 10;
			carry = temp / 10;
		} else {
			c.d[c.len++] = temp;
			carry = 0;
		}
	}
	if(carry != 0) c.d[c.len++] = carry;
    return c;
}

void Print(bign a) {
	for(int i = a.len - 1; i >= 0; i--) {
	    printf("%d", a.d[i]);
	}
	printf("\n");
}

bool Judge(bign a, bign b) {
	int hashTable[10] = {0};
	for(int i = 0; i < a.len; i++) {
	    hashTable[a.d[i]]++;
	}
	for(int i = 0; i < b.len; i++) {
		hashTable[b.d[i]]--;
	    if(hashTable[b.d[i]] < 0) return false;
	}
	return true;
}

int main() {
    char str[25];
	while(scanf("%s", str) != EOF) {
	    bign temp = change(str);
		bign ans = add(temp, temp);
		if(Judge(temp, ans)) {
		    printf("Yes\n");
		} else {
		    printf("No\n");
		}
		Print(ans);
	}
    return 0;
}
//NOTE:注意理解题意，题目要求只能是原有数字的重新排列，每个数字出现的次数也要相同！