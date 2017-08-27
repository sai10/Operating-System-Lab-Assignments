#include<stdio.h>

struct process{
    int pid,at,bt,t_bt,ct,tat,wt,flag;
};

void main()
{
    int n,i,j,k=0,l,temp_time=0,count=0,flag=0,qt,temp_qt,var_t;

    printf("Enter the time quantum:");
    scanf("%d",&qt);

    temp_qt = qt;

    printf("Enter the number of the process:");
    scanf("%d",&n);

    struct process p[n] , temp , q[n] , m[100];

    printf("Enter the arrival time and burst time of the process:\n");
    for(i=0;i<n;i++)
    {
        printf("PROCESS %d:",i+1);
        p[i].pid=i+1;
        p[i].flag=0;
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].t_bt=p[i].bt;
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

    k=0;
    while(1)
    {
        temp.bt = 100;
        flag = 0;
        var_t = 0;
        for(i=0;i<n;i++)
        {
               if(p[i].at<=temp_time && p[i].bt<temp.bt && p[i].flag==0)
               {
                   flag=1;
                   temp = p[i];
               }
               if(p[i].at>temp_time)
                    break;
        }

        if(flag==1)
        {
            //printf(" %d ",temp.pid);
            m[k] = temp;
            k++;
            for(i=0;i<n;i++)
            {
                if(p[i].pid == temp.pid && p[i].bt>0)
                   {
                       if(p[i].bt >= qt)
                            p[i].bt = p[i].bt - qt;
                       else
                       {
                             var_t = p[i].bt;
                             p[i].bt = 0 ;
                       }
                        //printf("%d %d\n\n",p[i].pid,p[i].bt);
                   }
                if(p[i].pid == temp.pid && p[i].bt == 0)
                {
                        p[i].flag=1;
                        if(var_t==0)
                            p[i].ct = temp_time+qt;
                        else
                            p[i].ct = temp_time+var_t;
                        p[i].tat = p[i].ct - p[i].at;
                        p[i].wt = p[i].tat - p[i].bt;
                        count++;
                }
            }
        }
        if(count==n)
            break;
        if(flag==1 && var_t==0)
            temp_time+=qt;
        else if(flag==1 && var_t!=0)
            temp_time+=var_t;
        else
            temp_time++;
    }

    printf("\nGANTT CHART IS AS FOLLOWS:\n\n");
    for(i=0;i<k;i++)
        printf("  %d ",m[i].pid);

      // printf("\n\n");
      // for(i=0;i<n;i++)
      //      printf("process %d : %d %d \n",p[i].pid,p[i].at,p[i].bt);
    printf("\n\n");
    printf("PID  AT  BT  CT  TAT  WT\n");

    for(i=0;i<n;i++)
        printf("  %d :%d   %d   %d   %d   %d\n",p[i].pid,p[i].at,p[i].t_bt,p[i].ct,p[i].tat,p[i].wt);
}

