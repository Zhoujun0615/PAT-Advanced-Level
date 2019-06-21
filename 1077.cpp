#include <stdio.h>
#include <string.h>
int main()
{
    freopen("in1077.txt", "r", stdin);
	int N, min_pos, flag;
	min_pos = 256;
	flag = 0;
	char first[260], str[260];
	scanf("%d", &N);
	getchar();
	gets(first);
	int len_f = strlen(first);
	for(int i = 0; i < N - 1; i++)
	{
		gets(str);
		int len_s = strlen(str);
		int pos = 0;
		for(int j = 0; j < len_f && j < len_s; j++)
		{
			if(first[len_f - 1 - j] == str[len_s - 1 - j])
			{
			    pos++;
				flag = 1;

			}
		    else
			{
			    if(j == 0 &&(first[len_f - 1 - j] != str[len_s - 1 - j]))
					flag = 0;
			    break;
			}
	
		}
        if(flag)
		{
	        if(min_pos > pos)
			{
		        min_pos = pos;
			}
					
		}
		else if(flag == 0)
		{
			printf("nai");
			break;
		}	
	}
    if(flag)
	{
	    for(int i = min_pos; i > 0; i--)
			printf("%c", first[len_f - i]);
	}
    return 0;
}