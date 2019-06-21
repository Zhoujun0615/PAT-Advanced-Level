#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>
using namespace std;
struct record
{
    char name[10];
	int h, m, s;
	bool status;
}r[10010];
bool cmp(record a, record b)
{
	if(strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;
	else if(a.h != b.h)
		return a.h < b.h;
	else if(a.m != b.m)
		return a.m < b.m;
	else
		return a.s < b.s;
}
int compute_time(int in, int out)
{
    int time = 0;
	time = (r[out].h - r[in].h) * 3600 + (r[out].m - r[in].m) * 60 + (r[out].s - r[in].s);
    return time;
}
map<string, int> staytime;
bool judge(int in, int out, int hh, int mm, int ss)
{
	int  diff1, diff2;
	diff1 = (hh - r[in].h) * 3600 + (mm - r[in].m) * 60 + (ss - r[in].s);
	diff2 = (r[out].h - hh) * 3600 + (r[out].m - mm) * 60 + (r[out].s - ss);
	if(diff1 >= 0 && diff2 > 0)
		return true;
	else
		return false;
}
int main()
{
    int N, K;
	char line[5];
	freopen("in1095.txt", "r", stdin);
	while(scanf("%d %d", &N, &K) != EOF)
	{
	    for(int i = 0; i < N; i++)
		{
			scanf("%s %d:%d:%d", r[i].name, &r[i].h, &r[i].m, &r[i].s);
 			scanf("%s", line);
		    if(strcmp(line, "in") == 0)
				r[i].status = true;
			else
				r[i].status = false;
		}
	    sort(r, r + N, cmp);
        for(int i = 0; i < N; i++)
		{
			printf("%s %02d:%02d:%02d %d i = %d\n", r[i].name, r[i].h, r[i].m, r[i].s, r[i].status, i);
		
		}
		int hh, mm, ss, longestime;
		longestime = 0;
		for(int i = 0; i < K; i++)
		{
			scanf("%d:%d:%d", &hh, &mm, &ss);
		    int in, out, next, sum;
		    in = sum = 0;
		    while(in < N)
		   {
		        int needCount = 0;
			    next = in;
			    while(next < N && strcmp(r[in].name, r[next].name) == 0)
			    {
				    if(needCount == 0 && r[next].status == true)
					    needCount = 1;
				    else if(needCount == 1 && r[next].status == false)
					    needCount = 2;
				    next++;
			    }
			    if(needCount < 2)
				{
				    in = next;
					continue;
				}
				while(in < next)
				{
					while(in < next - 1 && !(r[in].status == true && r[in + 1].status == false))
					{
					    in++;
					}
					out = in + 1;
					if(out == next)
					{
					    in = next;
					    break;
					}
					if(judge(in, out, hh, mm, ss))
					{
					    int time = compute_time(in, out);
						sum++;
						if(staytime.count(r[in].name) == 0)
						{
							staytime[r[i].name] = 0;
						}
						staytime[r[i].name] += time;
						if(longestime < staytime[r[i].name])
							longestime = staytime[r[i].name];
						//printf("in = %d, out = %d\n", in, out);
					}
					in = out + 1;
				}
			}
			printf("%d\n", sum);
	    }
		map<string, int>::iterator it;
		for(it = staytime.begin(); it != staytime.end(); it++)
		{
			printf("%s %d\n", it->first.c_str(), it->second);
			if(it->second == longestime)
				printf("%s ", it->first.c_str());
		}
		printf("%02d:%02d:%02d\n", longestime / 3600, longestime % 3600 / 60, longestime % 60);
		
	}
    return 0;
}