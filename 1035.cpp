#include <stdio.h>
#include <string.h>
struct user{
    char name[15];
	char pass[15];
}temp, ans[1005];
int main()
{
    int N, cnt, flag;
	freopen("in1035.txt", "r", stdin);
	cnt = 0;
    scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%s %s", temp.name, temp.pass);
		int len = strlen(temp.pass);
		flag = 0;
		for(int j = 0; j < len; j++)
		{
			char c = temp.pass[j];
			if(c == '0' || c == '1' || c == 'l' || c == 'O')
			{
			    flag = 1;
				if(c == '0')
					temp.pass[j] = '%';
				else if(c == '1')
					temp.pass[j] = '@';
				else if(c == 'l')
					temp.pass[j] = 'L';
				else if(c == 'O')
					temp.pass[j] = 'o';
			}
		}
		ans[cnt] = temp;
		if(flag)
			cnt++;
	}
	if(cnt == 0)
	{
	    if(N > 1)
	        printf("There are %d accounts and no account is modified", N);
	    else
		    printf("There is 1 account and no account is modified");
	}
	else
	{
	    printf("%d\n", cnt);
		for(int i = 0; i < cnt; i++)
			printf("%s %s\n", ans[i].name, ans[i].pass);
	}
    return 0;
}