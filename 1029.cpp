#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 200010;
const int INF = 0x7fffffff;
/*
int a[maxn], b[maxn], ans[maxn];
void merge(int La, int Lb) {
    int i, j, index;
	i = j = index = 0;
	while(i < La && j < Lb) {
		if(a[i] <= b[j]) {
		    ans[index++] = a[i++];
		}
		else
			ans[index++] = a[j++];
	}
	while(i < La) ans[index++] = a[i++];
	while(j < Lb) ans[index++] = a[j++];
}
*/
int main() {
    int La, Lb, temp;
	int a[maxn];
	freopen("in1029.txt", "r", stdin);
	while(scanf("%d", &La) != EOF) {
		for(int i = 0; i < La; i++) {
		    scanf("%d", &a[i]);
		}
		a[La] = INF;//当第二个数组更长时，可以继续读入第二个数组，并比较
		scanf("%d", &Lb);
        int mid = (La + Lb - 1) / 2;
		int cnt, pos, flag;
		cnt = pos = flag = 0;
		for(int i = 0; i < Lb; i++) {
		    scanf("%d", &temp);
			while(a[pos] < temp) {
 			    if(cnt == mid) {
					if(flag == 0) {
						printf("%d\n", a[pos]);
					    flag = 1;
					}
			    }
			    pos++;
				cnt++;
			}
			if(cnt == mid) {
				if(flag == 0){
					printf("%d\n", temp);
				    flag = 1;
				}
			}
			cnt++;
		}
		if(flag == 0) {
			while(cnt < La) {//当第一个数组更长时，则只需在第一个数组剩余部分中查找
			    if(cnt == mid)
					printf("%d\n", a[pos]);
				cnt++;
				pos++;
			}
		}
	}
    return 0;
}
//NOTE:本题的难点在于合理使用内存，故采取two pointers的思想，开一个数组，然后读取第二个数组
//逐个进行比较，然后将相应数组下标右移
//注：1.两个序列的长度不同，注意边界的比较问题
//    2.题目中的long int指的就是int的意思