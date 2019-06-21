#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void Print(map<string,set<int> >& mp, string& str) {
    cout << str << endl;
	str.erase(0, 3);
	if(mp[str].size() == 0) cout << "Not Found" << endl;
	for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
		printf("%07d\n", *it);
	}
}
int main() {
    int N, M, id;
	char ch;
	string str;
	map<string, set<int> > Title, Author, Key, Pub, Year;
	freopen("in1022.txt", "r", stdin);
	while(cin >> N) {
		for(int i = 0; i < N; i++) {
		    cin >> id;
			cin.ignore();
			getline(cin, str);
			Title[str].insert(id);
			getline(cin, str);
			Author[str].insert(id);
			while(cin >> str) {
			    Key[str].insert(id);
				ch = cin.get();
				if(ch == '\n') break;
			}
			getline(cin, str);
			Pub[str].insert(id);
			getline(cin, str);
			Year[str].insert(id);
		}
		cin >> M;
		cin.ignore();
		for(int i = 0; i < M; i++) {
		    getline(cin, str);
            int type = str[0] - '0';
			if(type == 1) Print(Title, str);
			else if (type == 2) Print(Author, str);
			else if(type == 3) Print(Key, str);
			else if(type == 4) Print(Pub, str);
			else Print(Year, str);
		}
	}
    return 0;
}
//NOTE:注意：有可能作者和关键词是同一个字符串，故应该用不同的map来存储！
//            书的编号是7位整数，故应该输出%07d格式的编号！