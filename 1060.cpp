#include <iostream>
#include <string>
using namespace std;
int n;
string deal(string a, int &e) {
    string res;
	int pos = 0;
	while(a.length() > 0 && a[0] == '0') {
	    a.erase(a.begin());
	}
	if(a[0] == '.') {
        a.erase(a.begin());
		while(a.length() > 0 && a[0] == '0') {
		    a.erase(a.begin());
			e--;
		} 
	} 
	else {
			while(pos < a.length() && a[pos] != '.') {
			    pos++;
			    e++;
			}
			if(pos < a.length()) a.erase(a.begin() + pos);
	}
	if(a.length() == 0) e = 0;
	int pnum = 0;
	pos = 0;
	while(pnum < n) {//复制处理后的能表示出来的有效字符，若有效位数比字符串中的字符更大，则在末尾补上0
	    if(pos < a.length()) res += a[pos++];
		else res += '0';
		pnum++;
	}
	return res;
}

int main() {
    string str1, str2;
	freopen("in1060.txt", "r", stdin);
	while(cin >> n) {
        cin >> str1 >> str2;
		cout << str1 << " " << str2 << endl;
		int e1, e2;
		e1 = e2 = 0;
        string temp1 = deal(str1, e1);
        string temp2 = deal(str2, e2);
	    if(temp1 == temp2 && e1 == e2) {
            cout << "YES 0." << temp1 << "*10^" << e1 << endl;
	    } else {
            cout << "NO 0." << temp1 << "*10^" << e1 << " 0." << temp2 << "*10^" << e2 << endl;
	    }
    }
    return 0;
}
//NOTE:科学计数法的题目考虑从小数点的位置入手，若有前导0，则应该先删除前导0，然后分两种情况进行处理。
//1.整数部分大于0，此时计算出整数部分的位数(从第一个数字到小数点的位数)，即为指数的值(>=0)
//2.整数部分小于0, 此时计算出从小数点后的0的个数,即为指数的值(负个数)
//3.注意：每当遇到小数点时，应该要删除掉小数点，然后留下剩余的不包含前导0和小数点后的0的有效数字
//  特殊情况下，字符串中只含0，那么去除前导0或者小数点后的0后，字符串剩余长度为0，那应该令指数部分为0；
//4.最后进行合并时应注意能显示的有效位数和字符串剩余的字符数的大小关系，不足有效位数的应该在末尾补上0.