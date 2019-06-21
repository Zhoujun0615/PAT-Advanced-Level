#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
	int stu_num, course_num;
	string str;
	str.resize(5);
	map<string, vector<int> > mp;
	freopen("in1039.txt", "r", stdin);
	while(scanf("%d %d", &N, &K) != EOF) {
		for(int i = 1; i <= K; i++) {
		    scanf("%d %d", &course_num, &stu_num);
			for(int j = 0; j < stu_num; j++) {
			    scanf("%s", &str[0]);
				mp[str].push_back(course_num);
			}
		}
		for(int i = 0; i < N; i++) {
		    scanf("%s", &str[0]);
			printf("%s", str.c_str());
			printf(" %d", mp[str].size());
			sort(mp[str].begin(), mp[str].end());
			for(vector<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
			    printf(" %d", *(it));
			}
			printf("\n");
			mp[str].clear();
		}	
	}
    return 0;
}
//NOTE:这种做法会导致超时，应该想办法把字符串转化为数字，然后再用vector来做；