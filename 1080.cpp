#include <cstdio>
#include <algorithm>
using namespace std;
struct student
{
    int choice[6];
	int Ge, Gi, t_grade;
	int rank, num;
}stu[40010];
struct school
{
    int quota;
	int id[40010];
	int stuNum;
	int lastAdmit;
}sch[110];
bool cmp(student a, student b)
{
	if(a.t_grade != b.t_grade)
		return a.t_grade > b.t_grade;
	else
		return a.Ge > b.Ge;
}
bool cmpID(int a, int b)
{
	return stu[a].num < stu[b].num;
}
int main()
{
    int N, M, K;
	freopen("in1080.txt", "r", stdin);
    while(scanf("%d %d %d", &N, &M, &K) != EOF)
	{
		for(int i = 0; i < M; i++)
		{
			scanf("%d", &sch[i].quota);
			sch[i].lastAdmit = -1;
			sch[i].stuNum = 0;
		}
		for(int i = 0; i < N; i++)
		{
		    scanf("%d %d", &stu[i].Ge, &stu[i].Gi);
			stu[i].t_grade = stu[i].Ge + stu[i].Gi;
			stu[i].num = i;
			for(int j = 0; j < K; j++)
				scanf("%d", &stu[i].choice[j]);		
		}
		sort(stu, stu + N, cmp);
		int r = 1;
		for(int i = 0; i < N; i++)
		{
			if(stu[i].Ge == stu[i - 1].Ge && stu[i].t_grade == stu[i - 1].t_grade && i > 0)
				stu[i].rank = stu[i - 1].rank;
			else
				stu[i].rank = i + 1;
		}
		for(int i = 0; i < N; i++)
		{
	        for(int j = 0; j < K; j++)
			{
				int cho = stu[i].choice[j];
				int num = sch[cho].stuNum;
				int last = sch[cho].lastAdmit;
				if(sch[cho].quota > num || (last != -1 && stu[i].rank == stu[last].rank))
				{
				       
					sch[cho].stuNum++;
					sch[cho].lastAdmit = i;
					sch[cho].id[num] = i;
					break;
				}
		    }
        }
		for(int i = 0; i < M; i++)
		{
			if(sch[i].stuNum > 0)
			{
				sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
				for(int j = 0; j < sch[i].stuNum; j++)
				{
					printf("%d", stu[sch[i].id[j]].num);
					if(j < sch[i].stuNum - 1)
						printf(" ");
				}
			}
			printf("\n");
		}
	}
    return 0;
}