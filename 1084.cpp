#include <cstdio>
#include <cstring>
int main()
{
    char right[85], wrong[85];
	int hashTable[40] = {0};
	scanf("%s %s", right, wrong);
    int len_w = strlen(wrong);
	for(int i = 0; i < len_w; i++)
	{
	    if(wrong[i] >= 'a' && wrong[i] <= 'z')
		{
		    int pos = wrong[i] - 'a' + 10;
			hashTable[pos] = 1;
		}
		else if(wrong[i] >= 'A' && wrong[i] <= 'Z')
		{
		    int pos = wrong[i] - 'A' + 10;
			hashTable[pos] = 1;    
		}
		else if(wrong[i] >= '0' && wrong[i] <= '9')
		{
		    hashTable[wrong[i] - '0'] = 1;
		}
		else
			hashTable[36] = 1;
	}
	int len_r = strlen(right);
	for(int i = 0; i < len_r; i++)
	{
	    if(right[i] >= 'a' && right[i] <= 'z')
		{
		    int pos = right[i] - 'a' + 10;
			if(hashTable[pos] == 0)
			{
			    hashTable[pos] = 1;
				char ans = right[i] - 'a' + 'A';
			    printf("%c", ans);
			}
		}
		else if(right[i] >= 'A' && right[i] <= 'Z')
		{
		    int pos = right[i] - 'A' + 10;
			if(hashTable[pos] == 0)
			{
			    hashTable[pos] = 1;
				char ans = right[i];
			    printf("%c", ans);
			}   
		}
		else if(right[i] >= '0' && right[i] <= '9')
		{
		    int pos = right[i] - '0';
			if(hashTable[pos] == 0)
			{
			    hashTable[pos] = 1;
				char ans = right[i];
			    printf("%c", ans);
			} 
		}
		else
		{
		    if(hashTable[36] == 0)
			{
			    hashTable[36] = 1;   
			    printf("_");
			}
		}
	}
    return 0;
}