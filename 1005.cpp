#include <stdio.h>
#include <string.h>
int main()
{
    char str[110];
	char change[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int ans[10];
	scanf("%s", str);
	int len = strlen(str);
	int sum = 0;
	for(int i = 0; i < len; i++)
	{
	    sum += str[i] - '0';
	}
	int pos = 0;
	do
	{
	    ans[pos] = sum % 10;
	    sum /= 10;
	    pos++;
	}while(sum);
	for(int i = pos - 1; i >= 0; i--)
	{
	    printf("%s", change[ans[i]]);
		if(i > 0)
			printf(" ");
	}
    return 0;
}