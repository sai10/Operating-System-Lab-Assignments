#include<stdio.h>

struct partition{
	int size,flag;
};

void main()
{
	int proc,part,i,j,k,mem,sum=0,count=0,final_mem,int_frag=0,ext_frag,temp;
	
	printf("Enter the size of memory:");
	scanf("%d",&mem); 
	
	printf("Enter the number of partitions:");
	scanf("%d",&part);

	struct partition v_mem[part];
	
	printf("Enter the size of each partitions:");
	for(i=0;i<part;i++)
	{
		scanf("%d",&v_mem[i].size);
		v_mem[i].flag = 0;
		sum = sum + v_mem[i].size;
		if(sum<=mem)
		{
			count++;
			final_mem = sum;
		} 
		else
		{
			sum = final_mem;
			printf("\n\nMEMORY OVERFLOW\n\n");
			break;
		}
	}

	
	printf("Enter the number of process:");
	scanf("%d",&proc);

	int p[proc];

	printf("Enter the size of each process:");
	for(i=0;i<proc;i++)
		scanf("%d",&p[i]);
	
	printf("PROCESS ID     MEMORY-REQUIRED   ALLOCATED  INTERNAL-FRAGMENTATION\n");
	printf("___________    _______________   _________  ______________________\n");

	for(i=0;i<proc;i++)
	{
		k=-1;
		int_frag = 0;
		for(j=0;j<count;j++)
		{
			temp = v_mem[j].size - p[i] ;
			if(int_frag < temp && temp>=0  && v_mem[j].flag==0)
			{
				int_frag = temp;
				k=j;
			}	
		}
		if(k!=-1)
			v_mem[k].flag=1;
		if(int_frag>=0 && k!=-1)
			printf("     %d    		  %d     	YES  		   %d\n",i+1,p[i],int_frag);
		else
			printf("     %d    		  %d     	 NO  		   UNALLOCATED\n",i+1,p[i]);
	}	
	
}
