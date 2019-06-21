#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
const int maxn = 10005;
char str1[maxn], str2[maxn];
int main()
{
    freopen("in1050.txt", "r", stdin);
	while(cin.getline(str1, maxn) != NULL)
	{
		int hashTable[128] = {0};
		cout<<str1<<endl;
		int len1 = strlen(str1);
		cin.getline(str1, maxn);
		cout<<str2<<endl;
		int len2 = strlen(str2);
		for(int i = 0; i < len2; i++)
		{
		    hashTable[str2[i]] = 1;
		}
		for(int i = 0; i < len1; i++)
		{
		    if(hashTable[str1[i]] != 1)
				printf("%c", str1[i]);
		}
		printf("\n");	
	}
    return 0;
}
//NOTE:当选择g++提交程序时，不能将str1，strn定义为全局变量，应该在main函数里面定义才行
//不建议使用scanf读取需要一次读取一整行字符串的情况，因为scanf读取字符串时用空格作为截断标志的