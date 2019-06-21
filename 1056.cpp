#include <stdio.h>
#include <queue>
using namespace std;
struct mice {
	int weight;
	int r;
};
mice m[1005];
int main() {
    int Np, Ng, order;
	freopen("in1056.txt", "r", stdin);
	while(scanf("%d %d", &Np, &Ng) != EOF) {
		queue<int> q;
		for(int i = 0; i < Np; i++) {
		    scanf("%d", &m[i].weight);
		}
		for(int i = 0; i < Np; i++) {
		    scanf("%d", &order);
			q.push(order);
		}
		int temp = Np;
		int group;
		//printf("temp = %d, Ng = %d\n", temp, Ng);
		while(q.size() != 1) {
		    if(temp % Ng == 0) group = temp / Ng;
			else group = temp / Ng + 1;
			//printf("group = %d\n", group);
			for(int i = 0; i < group; i++) {
				int k = q.front();
				int cnt = 0;
				while(cnt < Ng && (i * Ng + cnt < temp)) {
					int front = q.front();
					//printf("front = %d\n", front);
					if(m[front].weight > m[k].weight) k = front;
					m[front].r = group + 1;
                    q.pop();
					cnt++;
				}
				//printf("k = %d\n", k);
				q.push(k);
			}
			temp = group;	
		}
		m[q.front()].r = 1;
		for(int i = 0; i < Np; i++) {
		    printf("%d", m[i].r);
			if(i < Np - 1) printf(" ");
		}
		printf("\n");
	}
    return 0;
}
//Note:1 ע�������Ŀ����˼���ڶ��и������Ǹ�ֻ�����λ�����й�ϵ������6������weight = 25�����ڵ�0λ��
//     2 ÿ�ν���������ÿ��Ngֻ�ֳ�group�飬Ȼ���ٴ�ÿ����ѡ�����ֵ�һֻ�����������������
//     3 ����֮��ÿ����̭�������������Ϊgroup���������ʣ�µ���ֻ���ڵ�һ��