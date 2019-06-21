#include <stdio.h>
#include <stack>
using namespace std;
int a[1005];
int main() {
    int M, N, K;
	freopen("in1051.txt", "r", stdin);
	while(scanf("%d %d %d", &M, &N, &K) != EOF) {
		for(int i = 0; i < K; i++) {
			stack<int> st;
			for(int j = 1; j <= N; j++) {
			    scanf("%d", &a[j]);
			}
			int now = 1;
			int front = 1;
			int flag = 1;
			while(now <= N && flag) {
				while(now <= N && now <= a[front]) {
					st.push(now);
					if(st.size() > M) {
					    flag = 0;
						break;
					}
					now++;
				}
				//printf("flag = %d, now = %d\n", flag, now);
				if(flag) {
					while(!st.empty() && front <= N) {
                        //printf("st.top() = %d, front = %d, a[front] = %d\n", st.top(), front, a[front]);
						if(st.top() == a[front]) {
						    front++;
							st.pop();
						}
						else if(st.top() > a[front]) {
						    flag = 0;
							break;
						}
						else break;
					}
				}
				else break;
			}
			if(flag) printf("YES\n");
			else printf("NO\n");
		}	
	}
    return 0;
}
//NOTE:每次循环应该先清空栈或者重新定义一个栈再使用，否则容易出错。
//     每次出栈前应该要判断栈不空！