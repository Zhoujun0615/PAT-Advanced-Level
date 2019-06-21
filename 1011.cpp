#include <stdio.h>
int main()
{
	FILE *fin, *fout;
	fin = fopen("in1011.txt", "rb");
	fout = fopen("out1011.txt", "wb");
	char ans[3] = {'W', 'T', 'L'};
	int i, j, k;
	double res = 1.0;
	double odds[3] = {0.0};
	for(i = 0; i < 3; i++)
	{
		double max = -1.0;
		for(j = 0; j < 3; j++)
		{
		    fscanf(fin, "%lf", &odds[j]);
		    if(odds[j] > max)
			{
			    max = odds[j];
			    k = j;
			}
		}
		fprintf(fout, "%c ", ans[k]);
		res = res * max;
	}
	res = (res * 0.65 - 1) * 2;
	fprintf(fout, "%.2f", res);
	fclose(fin);
	fclose(fout);
    return 0;
}