#include <stdio.h>
#include <algorithm>
using namespace std;
struct gas_station
{
    double price;
	double dist;
}gs[510], last_gs;
bool cmp(gas_station a, gas_station b)
{
	return a.dist < b.dist;
}
int main()
{
    double C, D, Davg;
	int N, i;
	freopen("in1033.txt", "r", stdin);
	while(scanf("%lf %lf %lf %d", &C, &D, &Davg, &N) != EOF)
	{
		last_gs.dist = 0.0;
		last_gs.price = 20;
		double per_max = C * Davg;
	    for(i = 0; i < N; i++)
		{
			scanf("%lf %lf", &gs[i].price, &gs[i].dist);
		}
		sort(gs, gs + N, cmp);
		double max_dist, sum_money;
		max_dist = sum_money = 0.0;
	    for(i = 0; i < N; i++)
		{
			if(gs[i].dist < D)
			{
			    if(gs[i].price < last_gs.price && gs[i].dist - last_gs.dist <= per_max)
				{
					sum_money += (last_gs.price * (gs[i].dist - last_gs.dist) / Davg);
					max_dist += (gs[i].dist - last_gs.dist);
					last_gs = gs[i];
					printf("%.2f %.2f %.2f %.2f\n", gs[i].price, gs[i].dist, sum_money, max_dist);
				}
				else if(gs[i].dist - last_gs.dist > per_max)
				{
					if(gs[i - 1].dist != last_gs.dist && gs[i - 1].dist - last_gs.dist <= per_max)
					{
					    sum_money += (last_gs.price * (gs[i - 1].dist - last_gs.dist) / Davg);
                        max_dist += (gs[i - 1].dist - last_gs.dist);
						last_gs = gs[i - 1];
						i--;
						printf("%.2f %.2f %.2f %.2f\n", gs[i].price, gs[i].dist, sum_money, max_dist);
					}
				}
			}
		}
		if(D - last_gs.dist > per_max)
		{
			if(gs[i - 2].dist != last_gs.dist && gs[i - 2].dist - last_gs.dist <= per_max)
			{
				sum_money += last_gs.price * (gs[i - 2].dist - last_gs.dist) / Davg;
                max_dist += (gs[i - 2].dist - last_gs.dist);
				last_gs = gs[i - 2];
			}
			else
				printf("The maximum travel distance = %.2f\n", max_dist);
		}
		else
		{
		    sum_money += last_gs.price * (gs[i].dist - last_gs.dist) / Davg;
			printf("%.2f\n", sum_money);	
		}	
	}
    return 0;
}
