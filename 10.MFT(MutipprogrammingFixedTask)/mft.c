#include<stdio.h>

void main()
{
	int mem,f_mem,part,proc,i,int_frag,ext_frag,count=0;
	
	printf("Enter the Memory size:");
	scanf("%d",&mem);
	
	printf("Enter the fixed memory size:");
	scanf("%d",&f_mem);
	
	part = mem/f_mem;
	
	printf("Enter the number of process:");
	scanf("%d",&proc);

	int p[proc];

	printf("Enter the size of each process:\n");
	for(i=0;i<proc;i++)
		scanf("%d",&p[i]);
	printf("PROCESS ID     MEMORY-REQUIRED   ALLOCATED  INTERNAL-FRAGMENTATION\n");
	printf("___________    _______________   _________  ______________________\n");

	for(i=0;i<part;i++)
	{
		int_frag = f_mem - p[i];
		if((int_frag)>=0)
			printf("     %d    		  %d     	YES  		   %d\n",i+1,p[i],int_frag);
		else
			printf("     %d      		  %d      NO   		   --\n",i+1,p[i]);
	}	
	
	ext_frag = mem - part*f_mem;
	printf("\n\nEXTERNAL FRAGMENTATION IS: %d\n\n",ext_frag);
	
}
