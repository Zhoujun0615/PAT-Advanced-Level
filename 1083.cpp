#include <stdio.h>
#include <algorithm>
using namespace std;
struct student
{
    char name[15];
	char id[15];
	int grade;
}stu[10010], vaild[10010];
bool cmp(student a, student b)
{
	return a.grade > b.grade;
}
int main()
{
    FILE *fin, *fout;
	fin = fopen("in1083.txt", "rb");
	fout = fopen("out1083.txt", "wb");
	int N, g1, g2, cnt;
	while(fscanf(fin,"%d", &N) != EOF)
	{
	    cnt = 0;
		for(int i = 0; i < N; i++)
			fscanf(fin, "%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
		fscanf(fin,"%d %d", &g1, &g2);
		for(int i = 0; i < N; i++)
		{
			if(stu[i].grade >= g1 && stu[i].grade <= g2)
			{
			    vaild[cnt] = stu[i];
				cnt++;
			}	
		}
		if(!cnt)
			fprintf(fout, "NONE\n");
		else
		{
		    sort(vaild, vaild + cnt, cmp);
			for(int i = 0; i < cnt; i++)
			{
				fprintf(fout, "%s %s\r\n", vaild[i].name, vaild[i].id);
			}
		
		}

	}
	fclose(fin);
	fclose(fout);
    return 0;
}
