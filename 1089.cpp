#include <stdio.h>
#include <algorithm>
using namespace std;

int judge(int a[], int b[], int n) {
	for(int i = 0; i < n; i++) {
		if(a[i] != b[i]) {
		    return 0;
		}
	}
	return 1;
}

void merge(int a[], int L1, int R1, int L2, int R2) {
    int temp[110];
	int i, j , index;
	i = L1, j = L2;
	index = 0;
	while(i <= R1 && j <= R2) {
		if(a[i] <= a[j]) {
		    temp[index++] = a[i++];
		}
		else
			temp[index++] = a[j++];
	}
	while(i <= R1) temp[index++] = a[i++];
	while(j <= R2) temp[index++] = a[j++];
	for(i = 0; i < index; i++) {
	    a[L1 + i] = temp[i];
	}
}

int main() {
    int a[110], b[110], c[110];
	int n;
	freopen("in1089.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
		    scanf("%d", &a[i]);
		}
		for(int i = 0; i < n; i++) {
		    scanf("%d", &b[i]);
		}
		for(int i = 0; i < n; i++)
            c[i] = a[i];
		int flag = 0;
		for(int i = 1; i < n; i++) {
		    int temp = a[i];
			int j = i;
			while(j > 0 && temp < a[j - 1]) {
			    a[j] = a[j - 1];
				j--;
			}
			a[j] = temp;
			if(flag == 1) {
				for(int k = 0; k < n; k++) {
				    printf("%d", a[k]);
					if(k < n - 1)
						printf(" ");
				}
				break;
			}
			int is1 = judge(a, b, n);
			if(is1 == 1) {
			    flag = 1;
				printf("Insertion Sort\n");
			}
		}
		if(flag == 0) {
		    printf("Merge Sort\n");
			for(int step = 2; step / 2 <= n; step *= 2) {
				for(int i = 0; i < n; i += step) {
				    int mid = i + step / 2 - 1;
					if(mid < n) {
						merge(c, i, mid, mid + 1, min(i + step - 1, n - 1));
					}
			    }
			    if(flag == 1) {
				     for(int k = 0; k < n; k++) {
				         printf("%d", c[k]);
					 if(k < n - 1)
						 printf(" ");
				     }
				     break;
				}
				int is2 = judge(c, b, n);
				if(is2 == 1) flag = 1;
			}   	
		}
		printf("\n");
	}
    return 0;
}
//Note:要熟练手写各种排序算法，然后进行模拟输出每一步后的排序结果与所给序列进行对比。
//使用min函数之前一定要加上algorithm库
