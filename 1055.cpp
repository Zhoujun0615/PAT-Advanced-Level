#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct person
{
    char name[10];
	int age, worth;
}p[100010];
bool cmp(person a, person b)
{
	if(a.worth != b.worth)
		return a.worth > b.worth;
	else if(a.age != b.age)
		return a.age < b.age;
	else
		return strcmp(a.name, b.name) < 0;
}
int main()
{
    int N, K, M, flag;
	freopen("in1055.txt", "r", stdin);
	while(scanf("%d %d", &N, &K) != EOF)
	{
	    for(int i = 0; i < N; i++)
			scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
	    sort(p, p + N, cmp);
		for(int i = 1; i <= K; i++)
		{
		    int Amin, Amax;
			flag = 0;
			int cnt = 1;
			scanf("%d %d %d", &M, &Amin, &Amax);
			printf("Case #%d:\n", i);
            for(int j = 0; j < N; j++)
			{
				if(p[j].age >= Amin && p[j].age <= Amax)
				{
					printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
				    flag = 1;
					cnt++;
				}
				if(cnt > M)
				    break;
			}
			if(flag == 0)
				printf("None\n");
		}
	}
    return 0;
}
//NOTE:可以考虑只将每个年龄的前100名加入待查询数组。