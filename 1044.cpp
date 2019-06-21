#include <stdio.h>
typedef long long LL;
const int maxn = 100010;
LL sum[maxn];
LL N, M, num;
int BinarySearch2(int i, LL num, LL min_num)
{
    int mid, left, right;
	left = i + 1, right = N;
	while(left <= right)
	{
	    mid = (left + right) / 2;
		if(sum[mid] - sum[i] - num == min_num)
			return mid;
		else if(sum[mid] - sum[i] - num < min_num)
			left = mid + 1;
		else
			right = mid - 1;
	}
    return -1;
}
int BinarySearch1(int i, LL num)
{
    int mid, left, right;
	left = i + 1, right = N;
	while(left < right)
	{
	    mid = (left + right) / 2;
		//printf("left = %d, right = %d, mid = %d\n", left, right, mid);
	    if(sum[mid] - sum[i] >= num)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main()
{
	freopen("in1044.txt", "r", stdin);
	while(scanf("%lld %lld", &N, &M) != EOF)
	{
	    sum[0] = 0;
		for(int i = 1; i <= N; i++)
		{
		    scanf("%lld", &num);
			sum[i] = sum[i - 1] + num;		
		}
		LL min_num = maxn;
		for(int i = 0; i <= N; i++)
		{
 		    int ans = BinarySearch1(i, M);
            LL temp = sum[ans] - sum[i] - M;
            //printf("sum[%d] = %lld, sum[%d] = %lld\n", i, sum[i], ans, sum[ans]);
			if(temp < min_num && temp >= 0)
				min_num = temp;
			//printf("ans = %d, min_num = %lld\n", ans, min_num);
		}
		//printf("min_num = %lld\n", min_num);
		for(int i = 0; i <= N; i++)
		{
		    //printf("sum[%d] = %lld\n", i, sum[i]);
			int begin = i + 1;
			int end = BinarySearch2(i, M, min_num);
            //printf("end = %d\n", end);
			if(begin <= end)
				printf("%d-%d\n", begin, end);
		}
	}
    return 0;
}
//Note:˼·
//1.�Ƚ������ÿ��λ�ô洢Ϊǰ������Ԫ�أ���������֮�ͣ�sum[0] = 0��
//2.��һ�α�����ö����˵㣨0 <= i <= N��,Ȼ���ö��ַ���sum�����[i + 1, N]�в����һ��sum[j] - sum[i] >= M��λ��j
//Ȼ�������λ�õ�sumֵ��M����С��ֵmin_num����ֵ������ڵ���0��
//3.�ڶ��α���������Щ��ֵǡ��Ϊmin_num�ķ��������