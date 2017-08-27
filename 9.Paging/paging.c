#include<stdio.h>
int main()
{
	int ms, ps, nop, np, pages, i, j, x, y, pa, offset;
	int s[10], fno[10][20];
	printf("Enter the memory size \n");
	scanf("%d",&ms);
	printf("Enter the page size \n");
	scanf("%d",&ps);
	nop = ms/ps;
	printf("The no. of pages available in memory are: %d\n",nop);
	printf("Enter number of processes \n");
	scanf("%d",&np);
	pages = nop;
	for(i=1;i<=np;i++)
	{
		printf("Enter no. of pages required for p[%d]\n",i);
		scanf("%d",&s[i]);
		if(s[i] > pages)
		{
			printf("Memory is Full\n");
			break;
		}
	pages = pages - s[i];
	printf("Enter pagetable for p[%d]\n",i);
	for(j=0;j<s[i];j++)
		scanf("%d",&fno[i][j]);
	}

	printf("Enter Logical Address to find Physical Address -\n");
	printf("Enter process no. and pagenumber and offset -\n");
	scanf("%d %d %d",&x,&y, &offset);

	if(x>np || y>=s[i] || offset>=ps)
		printf("\nInvalid Process or Page Number or offset \n");

	else
	{
		pa=fno[x][y]*ps+offset;
		printf("The Physical Address - %d",pa);
	}
}
