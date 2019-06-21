#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
int n, cnt = 0, min_depth = maxn;//全局变量若需赋值，则在定义时就应该赋值(初始化)，不能先定义，再初始化。
double p, r;
void Create() {
    int temp, child_num;
	for(int i = 0; i < n; i++) {
	    scanf("%d", &child_num);
		for(int j = 0; j < child_num; j++) {
		    scanf("%d", &temp);
			child[i].push_back(temp);
		}
	}
}

void DFS(int index, int depth) {
	if(child[index].size() == 0) {
		if(depth < min_depth) {
		    cnt = 1;
			min_depth = depth;
		} else if(depth == min_depth) {
		    cnt++;
		}
        return;
	} else {
		for(int i = 0; i < child[index].size(); i++) {
		    DFS(child[index][i], depth + 1);
		}
	}
}

int main() {
    freopen("in1106.txt", "r", stdin);
	while(scanf("%d %lf %lf", &n, &p, &r) != EOF) {
	    double ans = 0.0;
		Create();
		DFS(0, 0);
		r /= 100;
        ans = p * pow(1 + r, min_depth);
		printf("%.4f %d\n", ans, cnt);
	}
    return 0;
}
