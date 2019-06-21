#include <cstdio>
#include <cmath>
#include <cstring>
const int maxn = 100010;
int hashTable[maxn];
int H(int key, int Tsize) {
    return key % Tsize;
}

bool isPrime(int n) {
    if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
	    if(n % i == 0) return false;
	}
	return true;
}

int main() {
    int M, N, num, Tsize;
	freopen("in1078.txt", "r", stdin);
	while(scanf("%d %d", &M, &N) != EOF) {
	    if(isPrime(M)) Tsize = M;
		else {
			for(int i = M + 1; i < maxn; i++) {
				if(isPrime(i)) {
				    Tsize = i;
					break;
				}
			}
		}
		memset(hashTable, -1, sizeof(hashTable));
		for(int i = 0; i < N; i++) {
		    scanf("%d", &num);
			int pos = H(num, Tsize);
			if(hashTable[pos] == -1) {
				hashTable[pos] = 1;
			    printf("%d", pos);
			}
			else {
			    int d = 1;
				int flag = 0;
				int next_pos = H(pos + d * d, Tsize);
				while(d < Tsize) {
					if(hashTable[next_pos] == -1) {
					    flag = 1;
						hashTable[next_pos] = 1;
					    printf("%d", next_pos);
						break;
					}
				    d++;
					next_pos = H(pos + d * d, Tsize);
				}
				if(flag == 0) printf("-");
			}
			if(i < N - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
//NOTE: 1��ÿ�ν�Ԫ�ز����ϣ��󣬼ǵñ�Ǹ�λ��Ϊ�Ѳ��룡
//      2������̽����ɢ�з��е������ﵽ��ʱ����˵����Ԫ���޷�����ɢ�б��У����ؽ��к���Ĳ��ҡ�