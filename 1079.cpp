#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
const int maxn = 100001;
struct node {
    int flag, p_num;
	vector<int> child;
}Node[maxn];
int n;
double p, r, sum;
void Create() {
	int child_num;
	for(int i = 0; i < n; i++) {
	    scanf("%d", &child_num);
		int temp;
		if(child_num == 0) {
		    Node[i].flag = 1;
			scanf("%d", &temp);
			Node[i].p_num = temp;
		} else {
			Node[i].flag = 0;
		    for(int j = 0; j < child_num; j++) {
		        scanf("%d", &temp);
				Node[i].child.push_back(temp);
		    }		
		}	
	}
}

void DFS(int index, int depth) {
	if(Node[index].flag == 1) {
		sum += Node[index].p_num * pow(1 + r, depth);
		return;
	} else {
		for(int i = 0; i < Node[index].child.size(); i++) {
		    DFS(Node[index].child[i], depth + 1);
		}
	}
}

int main() {
    freopen("in1079.txt", "r", stdin);
	while(scanf("%d %lf %lf", &n, &p, &r) != EOF) {
	    Create();
	    sum = 0.0;
		r /= 100;
	    DFS(0,0);
		sum *= p;
		printf("%.1f\n", sum);
	}
    return 0;
}
//NOTE:DFS结合全局变量求解。