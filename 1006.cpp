#include <stdio.h>
struct time{
    int h, m, s;
};
struct person{
    char id[20];
	time in, out;
}temp, first, last;
bool earlier(time t1, time t2);
bool later(time t1, time t2);
bool earlier(time t1, time t2)
{
	if(t1.h != t2.h)
		return t1.h <= t2.h;
	else if(t1.m != t2.m)
		return t1.m <= t2.m;
	else
		return t1.s <= t2.s;
}
bool later(time t1, time t2)
{
	if(t1.h != t2.h)
		return t1.h >= t2.h;
	else if(t1.m != t2.m)
		return t1.m >= t2.m;
	else
		return t1.s >= t2.s;
}
int main()
{
    FILE *fin, *fout;
	fin = fopen("in1006.txt", "rb");
	fout = fopen("out1006.txt", "wb");
	int M;
	first.in.h = 23, first.in.m = 59, first.in.s = 59;
	last.out.h = 0, last.out.m = 0, last.out.s = 0;
	fscanf(fin, "%d", &M);
	while(M--)
	{
		fscanf(fin, "%s%d:%d:%d", temp.id, &temp.in.h, &temp.in.m, &temp.in.s);
		fscanf(fin, "%d:%d:%d", &temp.out.h, &temp.out.m, &temp.out.s);
		if(later(temp.out, last.out))
			last = temp;
	    if(earlier(temp.in, first.in))
			first = temp;
	}
	fprintf(fout, "%s %s", first.id, last.id);
    fclose(fin);
	fclose(fout);
    return 0;
}