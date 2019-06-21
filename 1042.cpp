#include <stdio.h>
int main()
{
    int time, i;
	int start[55] = {0};
	int end[55] = {0};
	int change[55] = {0};
	char ans[5] = {'S', 'H', 'C', 'D', 'J'};
	FILE *fin, *fout;
	fin = fopen("in.txt", "rb");
	fout = fopen("out2.txt", "wb");
	fscanf(fin,"%d", &time);
	for(i = 1; i < 55; i++)
	{
	    start[i] = i;
		fscanf(fin,"%d", &change[i]);
	}
	for(i = 0; i < time; i++)
	{
		for(int j = 1; j < 55; j++)
		{
		    end[change[j]] = start[j];
		}
		for(int k = 1; k < 55; k++)
			start[k] = end[k];	
	}
    for(i = 1; i < 55; i++)
	{
	    fprintf(fout,"%c%d", ans[(start[i] - 1) / 13], (start[i] - 1) % 13 + 1);
        if(i < 54)
			fprintf(fout," ");
	}
	fclose(fin);
	fclose(fout);
    return 0;
}