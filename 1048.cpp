#include <stdio.h>
const int maxn = 100010;
int a[maxn];
int main()
{
    int N, M, min, less, flag;
	freopen("in1048.txt", "r", stdin);
	while(scanf("%d %d", &N, &M) != EOF)
	{
	    int table[maxn] = {0};
		min = 501;
		flag = 0;
		for(int i = 0; i < N; i++)
	   {
	       scanf("%d", &a[i]);
		   table[a[i]]++;
	   }
	   for(int i = 0; i < N; i++)
	   {
           if(a[i] < M)
		   {
		       int diff = M - a[i];
		       less = a[i];
			   table[a[i]]--;
		       if(diff <= a[i])
			       less = diff;
		       if(table[diff])
		       {
		           if(min > less)
				       min = less;
			       flag = 1;
		       }		    
		   }
	   }
	   if(!flag)
		   printf("No Solution\n");
	   else
		   printf("%d %d\n", min, M - min);	
	}
    return 0;
}
//Note:注意题目要求的输出的英文语句的大小写，这种错误不会报成格式错误，比较难找出！