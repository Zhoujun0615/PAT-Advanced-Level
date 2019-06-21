#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct segment
{
    char str[10];
	int len;
}se[10010];
string str1;
bool cmp(segment a, segment b)
{
	return strcmp(a.str, b.str) < 0;
}
int main()
{
    int N, i;
	freopen("in1038.txt", "r", stdin);
	while(scanf("%d", &N) != EOF)
	{
		cin.ignore();
		int cnt, pos, length;
		pos = cnt = length = 0;
		getline(cin, str1);
		int l = str1.length();
		while(pos < l)
		{
			char ch = str1[pos];
			if(ch != ' ')
			{
				se[cnt].str[length] = ch;
				length++;
                pos++;
			}
			else
			{
				for(i = length; i < 9; i++)
					se[cnt].str[i] = '9';
				se[cnt].str[i] = '\0';
				se[cnt].len = length;
				pos++;
				cnt++;
				length = 0;
			}
		}
		printf("cnt = %d\n", cnt);
		sort(se, se + cnt, cmp);
		for(i = 0; i < cnt; i++)
		{
			for(int j = 0; j < se[i].len; j++)
			{
			    if(i == 0 && j == 0 && se[i].str[j] == '0')
					continue;
				cout << se[i].str[j];
			}
		}	
	}
    return 0;
}