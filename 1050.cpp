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
//NOTE:��ѡ��g++�ύ����ʱ�����ܽ�str1��strn����Ϊȫ�ֱ�����Ӧ����main�������涨�����
//������ʹ��scanf��ȡ��Ҫһ�ζ�ȡһ�����ַ������������Ϊscanf��ȡ�ַ���ʱ�ÿո���Ϊ�ضϱ�־��