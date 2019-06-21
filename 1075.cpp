#include <cstdio>
#include <algorithm>
using namespace std;
struct student
{
	int s[5] = {0};
	int tijiao[5] = {0};
	int p_num;
	int t_grade, r, id, ac;
}u[100010];
bool cmp(user a, user b)
{
	if(a.t_grade != b.t_grade)
		return a.t_grade > b.t_grade;
	else if(a.ac != b.ac)
		return a.ac > b.ac;
	else 
		return a.id < b.id; 
}
int p[5] = {0};
int main()
{
    int N, K, M;
	int id, num, socre;
	while(scanf("%d %d %d", &N, &K, &M) != EOF)
	{
	    for(int i = 0; i < K; i++)
			scanf("%d", &p[i]);
		for(int i = 0; i < M; i++)
		{
			u[id].ac = 0;
			u[id].t_grade = 0;
			scanf("%d %d %d", &id, &num, &socre);
			u[id].id = id;
			u[id].tijiao[num - 1]++;
			if(u[id].s[num - 1] < socre)
			{
			    s[num - 1] = socre;
				u[id].t_grade += s[num - 1];
			}
			if(u[id].s[num - 1] == p[num - 1])
				u[id].ac++;
		}
		sort(u + 1, u + N + 1, cmp);
		int r = 1;
		for(int i = 1; i < N + 1; i++)
		{
		    if(u[i].)
		
		
		}
	
	
	
	}





    return 0;
}