#include <cstdio>
#include <map>
using namespace std;
int main() {
    int M, N, color_num;
	map<int, int> mp;
	freopen("in1054.txt", "r", stdin);
	while(scanf("%d %d", &M, &N) != EOF) {
		int max = 0;
		int max_color_num = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
			    scanf("%d", &color_num);
                mp[color_num]++;
				if(mp[color_num] > max) {
				    max = mp[color_num];
					max_color_num = color_num;
				}
			}
		}
		printf("%d\n", max_color_num);
		mp.clear();
	}
    return 0;
}