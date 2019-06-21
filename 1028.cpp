#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct student
{
    int id;
	char name[10];
	int grade;
}stu[100010];
int c;
bool cmp(student a, student b)
{
    if(c == 1)
	{
		return a.id < b.id;
	}
	else if(c == 2)
	{
		if(strcmp(a.name, b.name) != 0)
			return strcmp(a.name, b.name) < 0;
		else
			return a.id < b.id;
	}
	else
	{
		if(a.grade != b.grade)
			return a.grade < b.grade;
		else
			return a.id < b.id;
	}
}
int main()
{
    int N, C;
	freopen("in1028.txt", "r", stdin);
	while(scanf("%d %d", &N, &C) != EOF)
	{
	    c = C;
		for(int i = 0; i < N; i++)
		{
			scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
		}
	    sort(stu, stu + N, cmp);
		for(int i = 0; i < N; i++)
			printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
    return 0;
}