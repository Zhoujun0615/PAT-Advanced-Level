#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 200010;
const int INF = 0x7fffffff;
/*
int a[maxn], b[maxn], ans[maxn];
void merge(int La, int Lb) {
    int i, j, index;
	i = j = index = 0;
	while(i < La && j < Lb) {
		if(a[i] <= b[j]) {
		    ans[index++] = a[i++];
		}
		else
			ans[index++] = a[j++];
	}
	while(i < La) ans[index++] = a[i++];
	while(j < Lb) ans[index++] = a[j++];
}
*/
int main() {
    int La, Lb, temp;
	int a[maxn];
	freopen("in1029.txt", "r", stdin);
	while(scanf("%d", &La) != EOF) {
		for(int i = 0; i < La; i++) {
		    scanf("%d", &a[i]);
		}
		a[La] = INF;//���ڶ����������ʱ�����Լ�������ڶ������飬���Ƚ�
		scanf("%d", &Lb);
        int mid = (La + Lb - 1) / 2;
		int cnt, pos, flag;
		cnt = pos = flag = 0;
		for(int i = 0; i < Lb; i++) {
		    scanf("%d", &temp);
			while(a[pos] < temp) {
 			    if(cnt == mid) {
					if(flag == 0) {
						printf("%d\n", a[pos]);
					    flag = 1;
					}
			    }
			    pos++;
				cnt++;
			}
			if(cnt == mid) {
				if(flag == 0){
					printf("%d\n", temp);
				    flag = 1;
				}
			}
			cnt++;
		}
		if(flag == 0) {
			while(cnt < La) {//����һ���������ʱ����ֻ���ڵ�һ������ʣ�ಿ���в���
			    if(cnt == mid)
					printf("%d\n", a[pos]);
				cnt++;
				pos++;
			}
		}
	}
    return 0;
}
//NOTE:������ѵ����ں���ʹ���ڴ棬�ʲ�ȡtwo pointers��˼�룬��һ�����飬Ȼ���ȡ�ڶ�������
//������бȽϣ�Ȼ����Ӧ�����±�����
//ע��1.�������еĳ��Ȳ�ͬ��ע��߽�ıȽ�����
//    2.��Ŀ�е�long intָ�ľ���int����˼