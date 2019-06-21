#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxnum = 26 * 26 * 26 * 10 + 1;
vector<int> Select_course[maxnum];
char name[5];
int change(char str[]) {
    int ans = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
		    ans = ans * 26 + str[i] - 'A';
		} else if(str[i] >= '0' && str[i] <= '9') {
		    ans = ans * 10 + str[i] - '0';
		}
	}
    return ans;
}

int main() {
    int N, K;
	int c_num, s_num;
	freopen("in1039.txt", "r", stdin);
	while(scanf("%d %d", &N, &K) != EOF) {
		for(int i = 0; i < K; i++) {
		    scanf("%d %d", &c_num, &s_num);
			for(int j = 0; j < s_num; j++) {
			    scanf("%s", name);
				int temp = change(name);
				Select_course[temp].push_back(c_num);
			}
		}
		int res;
		for(int i = 0; i < N; i++) {
		    scanf("%s", name);
			res = change(name);
			printf("%s", name);
			printf(" %d", Select_course[res].size());
			sort(Select_course[res].begin(), Select_course[res].end());
			for(int j = 0; j < Select_course[res].size(); j++)
				printf(" %d", Select_course[res][j]);
			printf("\n");
			Select_course[res].clear();
		}
	}
	return 0;
}