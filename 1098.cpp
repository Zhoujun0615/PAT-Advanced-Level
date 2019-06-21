#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, flag;
int in[maxn], out[maxn], heap[maxn];
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
	while(j <= high) {
		if(j + 1 <= high && heap[j + 1] > heap[j]) {
		    j = j + 1;
		}
		if(heap[j] > heap[i]) {
		    swap(heap[i], heap[j]);
			i = j;
			j = i * 2;
		} else {
		    break;
		}
	}
}

void createHeap() {
	for(int i = n / 2; i >= 1; i--) {
	    downAdjust(i, n);
	}
}

bool judge(int a[], int b[]) {
	for(int i = 1; i <= n; i++) {
	    if(a[i] != b[i]) return false;
	}
	return true;
}

void insertSort() {
	for(int i = 2; i <= n; i++) {
        int temp = in[i];
		int j = i;
		while(j > 1 && in[j] < in[j - 1]) {
		    swap(in[j], in[j - 1]);
			j--;
		}
		temp = in[j];
		if(flag == 1) {
			printf("Insertion Sort\n");
			for(int i = 1; i <= n; i++) {
			    printf("%d", in[i]);
				if(i < n) printf(" ");
			}
			return;
		}
		if(judge(in, out)) flag = 1;
	}
}

void heapSort() {
    createHeap();
	for(int i = n; i > 1; i--) {
	    swap(heap[1], heap[i]);
		downAdjust(1, i - 1);
		if(flag == 1) {
			printf("Heap Sort\n");
			for(int i = 1; i <= n; i++) {
			    printf("%d", heap[i]);
				if(i < n) printf(" ");
			}
			return;
		}
        if(judge(heap, out)) flag = 1;
	}
}

int main() {
    freopen("in1098.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
		flag = 0;
		for(int i = 1; i <= n; i++) {
		    scanf("%d", &in[i]);
			heap[i] = in[i];
		}
		for(int i = 1; i <= n; i++) {
		    scanf("%d", &out[i]);
		}
		insertSort();
		if(!flag) {
		    heapSort();
		}
		printf("\n");
	}
    return 0;
}