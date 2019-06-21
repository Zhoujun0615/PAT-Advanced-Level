#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    string str;
	map<string, int> mp;
	freopen("in1071.txt", "r", stdin);
	while(getline(cin, str)) {
		string temp;
		for(int i = 0; i < str.length(); i++) {
		    if(str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
			if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
			    temp += str[i];
				//cout << temp;
			} else {
				//cout << " ";
				if(temp.size() > 0){
				    if(mp.find(temp) != mp.end()) mp[temp]++;
				    else mp[temp] = 1;
				    //cout << temp << mp[temp] << endl;
				}
				temp.clear();
			}
		}
		if(temp.size() > 0){
		    if(mp.find(temp) != mp.end()) mp[temp]++;
			else mp[temp] = 1;
		}//注意最后一个单词的处理
		map<string, int>::iterator it = mp.begin();
		string ans;
		int max = 0;
		for(; it != mp.end(); it++) {
			if(it->second > max) {
				max = it->second;
				ans = it->first;
			}
		}
		cout << ans << " " << max << endl;
		mp.clear();
	}
    return 0;
}
//NOTE: 注意理解题意，有可能最后是以有效字母结束的，故循环外还应判断temp的长度是否大于0