#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxnum = 26 * 26 * 26 * 10 + 1;
int getID(char str[]) {
    int res = 0;
	int i;
	for(i = 0; i < 3; i++) {
	    res = res * 26 + str[i] - 'A';
	}
	res = res * 10 + str[i] - '0';
    return res;
}

int main() {
    int N, K, tc_num, c_num;
    vector<int> v[2501];
	char name[5];
	char ans[maxnum][5];
	freopen("in1047.txt", "r", stdin);
	while(scanf("%d %d", &N, &K) != EOF) {
		for(int i = 0; i < N; i++) {
		    scanf("%s %d", name, &tc_num);
			int id = getID(name);
			strcpy(ans[id], name);
			for(int j = 0; j < tc_num; j++) {
				scanf("%d", &c_num);
			    v[c_num].push_back(id);
			}
		}
		for(int i = 1; i <= K; i++) {
		    printf("%d %d\n", i, v[i].size());
			sort(v[i].begin(), v[i].end());
			for(int j = 0; j < v[i].size(); j++) {
			    int temp = v[i][j];
				printf("%s\n", ans[temp]);
			}
			v[i].clear();
		}
	}
    return 0;
}
//NOTE:注意理解题目，看清楚各个参数的边界值！！！本题中课程数最大为K， 而不是5！