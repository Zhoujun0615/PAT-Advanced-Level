#include <cstdio>
#include <algorithm>
using namespace std;
struct student
{
    int grades[4];
	int id;
}stu[2005];
char course[4] = {'A', 'C', 'M', 'E'};
int Rank[1000005][4] = {0};
int curr;//��ǰ���еĳɼ��ȽϵĿ�Ŀ
bool cmp(student a, student b)
{
	return a.grades[curr] > b.grades[curr];
}
int main()
{
	int N, M, r;
	freopen("in1012.txt", "r", stdin);
	while(scanf("%d %d", &N, &M) != EOF)
	{
	    for(int i = 0; i < N; i++)
		{
			scanf("%d %d %d %d", &stu[i].id, &stu[i].grades[1], &stu[i].grades[2],  &stu[i].grades[3]);
			stu[i].grades[0] = stu[i].grades[1] + stu[i].grades[2] + stu[i].grades[3];
		}
	    for(int i = 0; i < 4; i++)
		{
		    curr = i;
			sort(stu, stu + N, cmp);
			r = 1;
			for(int j = 0; j < N; j++)
			{
				if(j > 0 && stu[j].grades[i] != stu[j - 1].grades[i])
					r = j + 1;
				Rank[stu[j].id][i] = r;
			}
		}
		for(int i = 0; i < M; i++)
		{
		    int check_id, best_c, best_r;
			best_c = -1 , best_r = 2010;
			scanf("%d", &check_id);
			for(int j = 0; j < 4; j++)
			{
				if(Rank[check_id][j] != 0)
				{
    				if(Rank[check_id][j] < best_r)
				   {
					best_r = Rank[check_id][j];
					best_c = j;
				   }		
				}
			}
			if(best_c >= 0)
			    printf("%d %c\n", best_r, course[best_c]);
			else
				printf("N/A\n");
		}
	}
    return 0;
}
//NOTE:Ҫ��������Ŀ����˼����Ҫ�������ʱ���ö�ά��������������洢һ����������ע����g++�в�����rank������Ҫ��Rank�ſ���