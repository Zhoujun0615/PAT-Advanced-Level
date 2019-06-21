#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct time
{
    int mon, day, hour, min;
};
struct record
{
    char name[20];
	time t;
	char state[20];
}r[1005];
bool cmp(record a, record b)
{
	if(strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;
    else if(a.t.mon != b.t.mon)
		return a.t.mon < b.t.mon;
	else if(a.t.day != b.t.day)
		return a.t.day < b.t.day;
	else if(a.t.hour != b.t.hour)
		return a.t.hour < b.t.hour;
	else
		return a.t.min  < b.t.min;
}
int main()
{
    int N, flag, nprint, hprint, hasprint, s_hasprint, cnt = 0;
	flag = nprint = hprint = hasprint = s_hasprint = 0;
	int rate[24];
	double d_money = 0.0;
	freopen("in1016.txt", "r", stdin);
    for(int i = 0; i < 24; i++)
	    scanf("%d", &rate[i]);	    
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%s %d:%d:%d:%d %s", r[i].name, &r[i].t.mon, &r[i].t.day, &r[i].t.hour, &r[i].t.min, r[i].state); 	    

	}
	sort(r, r + N, cmp);
	double sum_money = 0.0;
	double money = 0.0;
	int sum = 0;
	for(int j = 0; j < 24; j++)
        d_money += rate[j] * 60;
    for(int i = 0; i < N; i++)
	{
		time on, off;
		//printf("r[%d].state[1] = %c\n", i, r[i].state[1]);
		if(r[i].state[1] == 'n')
		{
			on = r[i].t;
		    flag = 1;

		}
		else if(r[i].state[1] == 'f' && flag)
		{
		    //printf("r[%d].state[1] = %c\n", i, r[i].state[1]);
			nprint = 1;
			hprint = 1;
			off = r[i].t;
			flag = 0;
			sum = (off.day - on.day) * 24 * 60 + (off.hour - on.hour) * 60 + (off.min - on.min);
			money = (off.day - on.day) * d_money + rate[on.hour] * (60 - on.min);
			for(int j = on.hour + 1; j < off.hour; j++)
			{
			    money += rate[j] * 60;
			}
			money += rate[off.hour] * off.min;
			if(hprint && !s_hasprint)
			{
			    hasprint++;
				s_hasprint = 1;
				printf("%s %02d\n", r[i].name, r[i].t.mon);
			}
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", on.day, on.hour, on.min, off.day, off.hour, off.min, sum, money / 100);
			sum_money += money;
			money = 0.0;
		}
		if(strcmp(r[i - 1].name, r[i].name) != 0 && i > 0)
		{
			//printf("r[i = %d].namer = %s, r[i - 1 = %d].name = %s, cmp = %d\n",i, r[i].name, i - 1, r[i - 1].name, cmp);
			if(nprint)
			{
				printf("Total amount: $%.2f\n", sum_money / 100);
			    sum_money = 0.0;
			    money = 0;
			    sum = 0;
				hprint = 0;
				nprint = 0;
				s_hasprint = 0;
			}  
		}
	}
	if(hasprint > 0 && nprint)
		printf("Total amount: $%.2f\n", sum_money / 100);
    return 0;
}