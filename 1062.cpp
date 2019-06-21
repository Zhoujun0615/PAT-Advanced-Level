#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct student
{
    int id, sum, de_s, cai_s;
	int flag;
}s[100010];
bool cmp(student a, student b)
{
	if(a.flag != b.flag)
		return a.flag < b.flag;
	else if(a.sum != b.sum)
		return a.sum > b.sum;
	else if(a.de_s != b.de_s)
		return a.de_s > b.de_s;
	else
		return a.id < b.id;
}
int main()
{ 
    int n, l, h;
	freopen("in1062.txt", "r", stdin);
	while(scanf("%d %d %d", &n, &l, &h) != EOF)
	{
	    int cnt = 0;
        for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &s[i].id, &s[i].de_s, &s[i].cai_s);
			s[i].sum = s[i].de_s +  s[i].cai_s;
			if(s[i].de_s >= l && s[i].cai_s >= l)
			{
			    printf("%d %d %d\n", s[i].id, s[i].de_s, s[i].cai_s);
				if(s[i].de_s >= h && s[i].cai_s >= h)
					s[i].flag = 1;
				else if(s[i].de_s >= h && s[i].cai_s < h)
					s[i].flag = 2;
				else if(s[i].de_s >= s[i].cai_s)
                    s[i].flag = 3;
				else
					s[i].flag = 4;
				cnt++;
			}
			else
				s[i].flag = 5;//Note:结构体中的变量记得赋初值，否则无法进行比较。
		}
	    sort(s, s + n, cmp);
		printf("%d\n", cnt);
		for(int i = 0; i < cnt; i++)
			printf("%d %d %d\n", s[i].id, s[i].de_s, s[i].cai_s);	
	}
    return 0;
}


/*这种方法代码量较大，不够简洁
struct student
{
    int id, d_socre, c_socre, t_socre;
}s1[100005], s2[100005], s3[100005], s4[100005];
bool cmp(student a, student b)
{
	if(a.t_socre != b.t_socre)
		return a.t_socre > b.t_socre;
	else if(a.d_socre != b.d_socre)
		return a.d_socre > b.d_socre;
	else
		return a.id < b.id;

}
int main()
{
    int  n, l, h;
	student temp;
	freopen("in1062.txt", "r", stdin);
	while(scanf("%d %d %d", &n, &l, &h) != EOF)
	{
		int num[4] = {0};
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &temp.id, &temp.d_socre, &temp.c_socre);
			if(temp.d_socre >= l && temp.c_socre >= l)
			{
				if(temp.d_socre >= h && temp.c_socre >= h)
				{
				    s1[num[0]] = temp;
					s1[num[0]].t_socre = temp.d_socre + temp.c_socre; 
				    num[0]++;
				}
				else if(temp.d_socre >= h && temp.c_socre < h)
				{
				    s2[num[1]] = temp;
					s2[num[1]].t_socre = temp.d_socre + temp.c_socre; 
				    num[1]++;				
				}
				else if(temp.d_socre < h && temp.c_socre < h && temp.d_socre >= temp.c_socre)
				{
				    s3[num[2]] = temp;
					s3[num[2]].t_socre = temp.d_socre + temp.c_socre; 
				    num[2]++;					    
				}
				else
				{
				    s4[num[3]] = temp;
					s4[num[3]].t_socre = temp.d_socre + temp.c_socre; 
				    num[3]++;				    
				}
			}
		}
	    sort(s1, s1 + num[0], cmp);
		sort(s2, s2 + num[1], cmp);
		sort(s3, s3 + num[2], cmp);	
		sort(s4, s4 + num[3], cmp);	
		sum = num[0] + num[1] + num[2] + num[3];
		printf("%d\n", sum);
		for(int i = 0;i < num[0]; i++)
			printf("%d %d %d\n", s1[i].id, s1[i].d_socre, s1[i].c_socre);
		for(int i = 0;i < num[1]; i++)
			printf("%d %d %d\n", s2[i].id, s2[i].d_socre, s2[i].c_socre);
		for(int i = 0;i < num[2]; i++)
			printf("%d %d %d\n", s3[i].id, s3[i].d_socre, s3[i].c_socre);
		for(int i = 0;i < num[3]; i++)
			printf("%d %d %d\n", s4[i].id, s4[i].d_socre, s4[i].c_socre);
	}
	return 0;
} */