#include <stdio.h>
#include <string.h>
int main()
{
    char str[85];
	int row, len, col, i, j;
	scanf("%s", str);
	len = strlen(str);
    row = (len + 2) / 3;
	col = len - 2 * (row - 1);
	printf("len = %d, row = %d, col = %d\n", len, row, col);
    for(i = 0; i < row; i++)
	{
	    for(j = 0; j < col; j++)
		{
			if(i < row - 1)
		    {
		        if(j == 0)
					printf("%c", str[i]);
		        else if(j == col - 1)
					printf("%c", str[len - 1 - i]);
				else
					printf(" ");
		    }
			else
				printf("%c", str[i + j]);
		}
        printf("\n");
	}
    return 0;
}