#include <iostream>
#include <string>
using namespace std;
string str;
int left_P[100010] = {0};
int right_T[100010] ={0};
int main()
{
	freopen("in1093.txt", "r", stdin);
	while(getline(cin, str))
	{
		long long ans = 0;
		int len = str.length();
		if(str[0] == 'P')
			left_P[0] = 1;
	    for(int i = 1; i < len; i++)
		{
		    if(str[i] == 'P')
				left_P[i] = left_P[i - 1] + 1;
			else
				left_P[i] = left_P[i - 1];
		}
		for(int i = len - 1; i >= 0; i--)
		{
		    if(str[i] == 'T' && i == len - 1)
				right_T[i] = 1;
		    else if(str[i] == 'T' && i < len - 1)
			{
			    right_T[i] = right_T[i + 1] + 1;
			}
			else if(str[i] == 'P')
			{
			    right_T[i] = right_T[i + 1];
			}
			else
			{
			    right_T[i] = right_T[i + 1];
                ans += (left_P[i] * right_T[i]);
			}
		}
		ans = ans % 1000000007;
	    printf("%lld\n", ans);
	}
    return 0;
}