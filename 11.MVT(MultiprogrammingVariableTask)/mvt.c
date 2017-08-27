#include<stdio.h>

void main()
{
	int mem,proc,i,ext_frag,count=0,sum=0,final_mem,rem_mem,j;
	
	printf("Enter the Memory size:");
	scanf("%d",&mem);
	
	rem_mem = mem;

	printf("Enter the number of process:");
	scanf("%d",&proc);

	int p[proc],q[proc];

	printf("Enter the size of each process:\n");
	for(i=0;i<proc;i++)
	{
		scanf("%d",&p[i]);
		sum = sum + p[i];
		if(sum<=mem)
		{
			count++;
			final_mem = sum;
			q[j] = p[i]; 
			j++;
		} 
		else
			sum = final_mem;
	}

	printf("PROCESS ID     MEMORY-REQUIRED   ALLOCATED  REMAINING-MEMORY\n");
	printf("___________    _______________   _________  ________________\n");

	for(i=0;i<count;i++)
	{
		rem_mem = rem_mem - q[i];
		if((rem_mem)>=0)
			printf("     %d    		  %d     	YES  		   %d\n",i+1,q[i],rem_mem);
	}	
	
	ext_frag = mem - final_mem;
	printf("\n\nEXTERNAL FRAGMENTATION IS: %d\n\n",ext_frag);
	
}
