#include<stdio.h>
struct price{
	int g,s,k;
}p1,p2,sum;
int main(){
	scanf("%d.%d.%d",&p1.g,&p1.s,&p1.k);
	scanf("%d.%d.%d",&p2.g,&p2.s,&p2.k);
	sum.g=p1.g+p2.g;
	sum.s=p1.s+p2.s;
	sum.k=p1.k+p2.k;
	sum.s+=sum.k/29;
	sum.k=sum.k%29;
	sum.g+=sum.s/17;
	sum.s=sum.s%17;
	printf("%d.%d.%d",sum.g,sum.s,sum.k);
	return 0;
}