#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxv = 2010;
const int INF = 1000000000;
int n, k, numPerson = 0;
int vis[maxv], weight[maxv];
int G[maxv][maxv];
map<string, int> strToint;
map<int, string> intTostr;
map<string, int> Gang;
void DFS(int nowVisit, int &head, int &num, int &totalValue) {
    vis[nowVisit] = 1;
    num++;
	if(weight[nowVisit] > weight[head]) {
	    head = nowVisit;
	}
	for(int i = 0; i < numPerson; i++) {
		if(G[nowVisit][i] > 0) {
		    totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if(vis[i] == 0)
				DFS(i, head, num, totalValue);		
		}
	}
}

void DFSTrave() {
    for(int i = 0; i < maxv; i++) vis[i] = 0;
	for(int i = 0; i < numPerson; i++) {
	    int head, num, totalValue;
		head = i;
		num = totalValue = 0;
	    DFS(i, head, num, totalValue);
		if(num > 2 && totalValue > k) {
		    Gang[intTostr[head]] = num;
		}
	}
}

int change(string str) {
	if(strToint.find(str) != strToint.end()) {
	    return strToint[str];
	} else {
	    strToint[str] = numPerson;
		intTostr[numPerson] = str;
	    return numPerson++;
	}
}

int main() {
    freopen("in1034.txt", "r", stdin);
	int w;
	string str1, str2;
	while(cin >> n >> k) {
		for(int i = 0; i < maxv; i++)
			weight[i] = 0;
		for(int i = 0; i < n; i++) {
		    cin >> str1 >> str2 >> w;
			int id1 = change(str1);
			int id2 = change(str2);
			weight[id1] += w;
			weight[id2] += w;
			G[id1][id2] = w;
			G[id2][id1] = w;
		}
	    DFSTrave();
		cout << Gang.size() << endl;
		for(map<string, int>::iterator it = Gang.begin(); it != Gang.end(); it++) {
		    cout << it->first << " " << it->second << endl;
		}
		strToint.clear();
		intTostr.clear();
		Gang.clear();
	}
    return 0;
}
//NOTE:���ǵ�
//1���ַ����������Լ����ֵ��ַ�����ת������Ϥ����ô�ڶ�ȡ�Ĺ����д���ͼ���ڽӾ�����
//2��ÿһ��DFS���Ա�����һ����ͨͼ����һ��DFS�������������ò����õ�ÿ����ͨͼ�еĽ����
//3����������weight�����¼ÿ������Ȩֵ���Ա���ÿ��DFS�����бȽϵó�ͷĿ
//4��map����ز�����map����ֵ�Զ��������������
