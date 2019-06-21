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
	while(pnum < n) {//���ƴ������ܱ�ʾ��������Ч�ַ�������Чλ�����ַ����е��ַ���������ĩβ����0
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
//NOTE:��ѧ����������Ŀ���Ǵ�С�����λ�����֣�����ǰ��0����Ӧ����ɾ��ǰ��0��Ȼ�������������д���
//1.�������ִ���0����ʱ������������ֵ�λ��(�ӵ�һ�����ֵ�С�����λ��)����Ϊָ����ֵ(>=0)
//2.��������С��0, ��ʱ�������С������0�ĸ���,��Ϊָ����ֵ(������)
//3.ע�⣺ÿ������С����ʱ��Ӧ��Ҫɾ����С���㣬Ȼ������ʣ��Ĳ�����ǰ��0��С������0����Ч����
//  ��������£��ַ�����ֻ��0����ôȥ��ǰ��0����С������0���ַ���ʣ�೤��Ϊ0����Ӧ����ָ������Ϊ0��
//4.�����кϲ�ʱӦע������ʾ����Чλ�����ַ���ʣ����ַ����Ĵ�С��ϵ��������Чλ����Ӧ����ĩβ����0.