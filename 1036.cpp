#include <stdio.h>
struct student{
    char name[15];
	char id[15];
	char gender;
	int grade;
}temp, highest_f, lowest_m;
int main()
{
    int N;
	int flag_f, flag_m;
	freopen("in1036.txt", "r", stdin);
	scanf("%d", &N);
	flag_f = flag_m = 0;
	highest_f.grade = -1, lowest_m.grade = 101;
	while(N--)
	{
		scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.grade);
		if(temp.grade > highest_f.grade && temp.gender == 'F')
		{
		     highest_f = temp;
			 flag_f = 1;
		}
			
		if(temp.grade < lowest_m.grade && temp.gender == 'M')
		{
		     lowest_m = temp;
			 flag_m = 1;
		}
	}
	if(flag_f)
		printf("%s %s\n", highest_f.name, highest_f.id);
	else
		printf("Absent\n");
	if(flag_f)
		printf("%s %s\n", lowest_m.name, lowest_m.id);
	else
		printf("Absent\n");
	if(flag_f && flag_m)
	{
	    int diff = highest_f.grade - lowest_m.grade;
        printf("%d\n", diff);
	}
	else
		printf("NA\n");
    return 0;
}