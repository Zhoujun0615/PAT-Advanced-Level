#include <stdio.h>
#include <queue>
using namespace std;
const int maxm = 1290;
const int maxn = 130;
const int maxl = 61;
struct node {
    int x, y, z;
}Node;
int m, n, l, t;
int matrix[maxl][maxm][maxn];
bool inq[maxl][maxm][maxn];
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
bool judge(int x, int y, int z) {
	if(z >= l || z < 0 || x >= m || x < 0 || y >= n || y < 0) return false;
	if(matrix[z][x][y] == 0 || inq[z][x][y] == true) return false;
	return true;
}

int BFS(int x, int y, int z) {
   int sum = 0;
   queue<node> q;
   Node.x = x, Node.y = y, Node.z = z;
   inq[z][x][y] = true;
   q.push(Node);
   while(!q.empty()) {
       node top = q.front();
	   q.pop();
	   sum++;
	   for(int i = 0; i < 6; i++) {
	       int newX = top.x + X[i];
		   int newY = top.y + Y[i];
		   int newZ = top.z + Z[i];
		   if(judge(newX, newY, newZ)) {
		       Node.x = newX, Node.y = newY, Node.z = newZ;
			   q.push(Node);
			   inq[newZ][newX][newY] = true;
		   }
	   }
   }
   if(sum >= t) return sum;
   else return 0;
}

int main() {
	freopen("in1091.txt", "r", stdin);
	while(scanf("%d %d %d %d", &m, &n, &l, &t) != EOF) {
		int ans = 0;
		for(int z = 0; z < l; z++) {
			for(int x = 0; x < m; x++) {
				for(int y = 0; y < n; y++) {
				    scanf("%d", &matrix[z][x][y]);
					//printf("%d ", matrix[z][x][y]);
				}
				//printf("\n");
			}
		}
		for(int z = 0; z < l; z++) {
			for(int x = 0; x < m; x++) {
				for(int y = 0; y < n; y++) {
					if(matrix[z][x][y] == 1 && inq[z][x][y] == false) {
					    int temp = BFS(x, y, z);
                        ans += temp;
					}
				}
			}
		}
	    printf("%d\n", ans);
	}
    return 0;
}
//NOTE:1、当出现超时的时候，不妨查看在程序中设置的边界是否超过题目要求太多了
//        尤其是需要三重循环时，边界值不能超过题目要求的太多。
//     2、每次重新在队列中加入新的结点后，需要将该位置的inq设置为真，避免重复入队。