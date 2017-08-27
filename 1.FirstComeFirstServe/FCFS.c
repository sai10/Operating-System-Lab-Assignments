
#include<stdio.h>
struct process{
int pid,at,bt,ct,tat,wt;
};
void main()
{
    int n,i,j,temp_time=0;
    printf("Enter the number of the process:");
    scanf("%d",&n);
    struct process p[n] , temp , q[n];
    printf("Enter the arrival time and burst time of the process:\n");
    for(i=0;i<n;i++)
    {
        printf("PROCESS %d:",i+1);
        p[i].pid=i+1;
        scanf("%d%d",&p[i].at,&p[i].bt);
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if( p[i].at > p[j].at )
            {
              temp = p[i];
              p[i] = p[j];
              p[j] = temp;
            }
        }
    }

    /*for(i=0;i<n;i++)
        printf("process %d : %d %d \n",p[i].pid,p[i].at,p[i].bt);*/


        temp_time = p[0].at;
        for(i=0;i<n;i++)
        {
                temp_time = temp_time+p[i].bt;
                p[i].ct = temp_time ;
                p[i].tat=p[i].ct - p[i].at;
                p[i].wt =p[i].tat-p[i].bt;
        }

        for(i=0;i<n;i++)
            printf("process %d : %d %d %d %d %d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}
