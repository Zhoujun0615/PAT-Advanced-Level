#include <iostream>
#include <cstring>
#include <string>

using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];    //dp[i][j]��ʾa[i]��a[j]����ʾ���ִ��Ƿ�Ϊ�ַ���������Ϊ1��������Ϊ0

int main() {
    string a;
	getline(cin, a);
	int len = a.length(); 
	int ans = 1;
	memset(dp, 0, sizeof(dp));
	//��ʼ������Ϊ1�ͳ���Ϊ2���ִ��Ƿ�Ϊ���Ĵ�
	for(int i = 0; i < len; i++) {
	    dp[i][i] = 1;
		if(i < len - 1) {
			if(a[i] == a[i + 1]) {
			    dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	//�ӳ���Ϊ3��len���Ӵ��Ƿ�Ϊ���Ĵ���ans�б�����������Ӵ��ĳ���
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