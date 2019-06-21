#include <iostream>
#include <cstdio>
#include <math.h>
#include <stack>
#include <string>
using namespace std;
const int maxn = 100001;
int table[maxn] = {0};
int b_num = sqrt(maxn * 1.0) + 1;
int num = sqrt(maxn * 1.0);
int block[1000] = {0};
string str;
int n;
int search(int cnt) {
    int res;
	int sum = 0;
	int k = 0;
	for(int i = 0; i < b_num; i++) {
		if(sum + block[i] >= cnt) {
            k = i;
			break;
		} else {
		    sum += block[i];
		}
	}
	for(int j = 0; j < num; j++) {
	    sum += table[j + k * num];
		if(sum >= cnt) {
		    res = j + k * num;
			break;
		}
	}
    return res;
}
void insert(int x) {
    table[x]++;
	block[x / num]++;
}
void del(int x) {
    table[x]--;
    block[x / num]--;
}
int main() {
    stack<int> s;
	freopen("in1057.txt", "r", stdin);
	//cout << b_num << endl;
	while(cin >> n) {
		cin.ignore();
		for(int i = 0; i < n; i++) {
		    getline(cin, str);
			if(str == "Pop") {
				if(!s.empty()) {
				    cout << s.top() << endl;
					del(s.top());
					s.pop();
				} else {
				    cout << "Invalid" << endl;
				}
			} else if(str == "PeekMedian") {
			    int mid;
				if(s.empty()) cout << "Invalid" << endl;
				else {
				    if(s.size() % 2 == 0) {
				        mid = s.size() / 2;
				    } else {
				        mid = (s.size() + 1) / 2;
				    }
					//cout << "mid = " << mid << endl;
				    cout << search(mid) << endl;				
				}
			} else {
			    int temp = 0;
				for(int j = 5; j < str.length(); j++) {
				    temp = temp * 10 + str[j] - '0';
				}
			    insert(temp);
				s.push(temp);
			}
		}
	}
    return 0;
}
//NOTE:利用分块思想，将N个数分为sqrt(N) + 1块，每一块sqrt(N)个元素0到sqrt(N) - 1
//     第i块第一个元素即为i*sqrt(N);