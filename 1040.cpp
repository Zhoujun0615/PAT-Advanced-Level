#include <iostream>
#include <cstring>
#include <string>

using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];    //dp[i][j]表示a[i]到a[j]所表示的字串是否为字符串，是则为1，不是则为0

int main() {
    string a;
	getline(cin, a);
	int len = a.length(); 
	int ans = 1;
	memset(dp, 0, sizeof(dp));
	//初始化长度为1和长度为2的字串是否为回文串
	for(int i = 0; i < len; i++) {
	    dp[i][i] = 1;
		if(i < len - 1) {
			if(a[i] == a[i + 1]) {
			    dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	//从长度为3到len的子串是否为回文串，ans中保存了最长回文子串的长度
	for(int L = 3; L <= len; L++) {
		for(int i = 0; i + L - 1 < len; i++) {
		    int j = i + L - 1;
			if(a[i] == a[j] && dp[i + 1][j - 1] == 1) {
			    dp[i][j] = 1;
				ans = L;
			}
		}
	}
	cout << ans << endl;
	return 0;
}