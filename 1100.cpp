#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    int N;
	string p1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string p2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	map<string, int> mp1;
	map<string, int> mp2;
	for(int i = 0; i < 13; i++) {
	    mp1[p1[i]] = i;
		mp2[p2[i]] = i;
	}
	while(cin >> N) {
		cin.ignore();
		string str;
		string str1;
	    string str2;
		for(int i = 0; i < N; i++) {
		    getline(cin, str);
			if(str[0] >= '0' && str[0] <= '9') {
				int num = 0;
				for(int j = 0; j < str.length(); j++) {
					num = num * 10 + str[j] - '0';
				}
			    int pos2 = num / 13;
				int pos1 = num % 13;
				if(num > 12 && pos1 != 0) {
					cout << p2[pos2] << " ";
				    cout << p1[pos1] << endl;				
				}
				else if(num > 12 && pos1 == 0)
					cout << p2[pos2] << endl;
				else cout << p1[pos1] << endl;

			} else {
				int ans, flag;
				flag = 0;
				str1 = str.substr(0, 3);
				if(str.length() > 3)
				    str2 = str.substr(4, 3);
				else
					str2 = "tret";
				for(int i = 0; i < 13; i++) {
					if(p1[i] == str1) flag = 1;
				}
				if(!flag)
			        ans = mp2[str1] * 13 + mp1[str2];
				else
					ans = mp1[str1]; 
				cout << ans << endl;
			}
		}
	}
    return 0;
}
//NOTE：由于此题的数据量较小，可以考虑先将所有结果打印制表，然后根据输入直接在表中查询可能会便捷一点。