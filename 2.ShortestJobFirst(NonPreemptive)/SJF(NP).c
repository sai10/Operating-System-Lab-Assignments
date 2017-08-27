#include<stdio.h>

struct process{
int pid,at,bt,ct,tat,wt,flag,finale;
};

void main()
{
    int n,i,j,k=0,m=0,l,temp_time=0,count=0;
    printf("Enter the number of the process:");
    scanf("%d",&n);
    struct process p[n] , temp , q[n];
    printf("Enter the arrival time and burst time of the process:\n");
    for(i=0;i<n;i++)
    {
        printf("PROCESS %d:",i+1);
        p[i].pid=i+1;
        p[i].flag=0;
        p[i].finale=0;
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

        i=0;
        temp_time = p[0].at ;

        while(1)
        {
            k=0;
            m=0;
            if(i==temp_time)
            {
                    for(j=0;j<n;j++)
                    {
                       if(p[j].at<=temp_time && p[j].finale==0)
                       {
                           q[k] = p[j];
                           k++;
                       }
                    }
                    for(l=0;l<k;l++)
                    {
                        for(j=l;j<k;j++)
                        {
                            if( q[l].bt > q[j].bt )
                            {
                              temp = q[l];
                              q[l] = q[j];
                              q[j] = temp;
                            }
                        }
                    }

                    q[0].finale =1;

                   for(j=0;j<n;j++)
                    {
                       if(p[j].at<=temp_time && p[j].finale==0)
                       {
                        p[j] = q[m];
                        m++;
                       }
                    }
                    temp_time = temp_time + q[0].bt;
                    for(j=0;j<n;j++)
                    {
                        if(p[j].finale==1 && p[j].flag==0)
                        {
                            p[j].flag=1;
                            p[j].ct = temp_time;
                            p[j].tat = p[j].ct - p[j].at;
                            p[j].wt = p[j].tat - p[j].bt;
                        }
                    }
                    count++;
            }
            i++;
            if(count == n)
                break;
        }

       printf("\n\n");
       /*for(i=0;i<n;i++)
            printf("process %d : %d %d \n",p[i].pid,p[i].at,p[i].bt);*/
       for(i=0;i<n;i++)
            printf("process %d : %d %d %d %d %d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}

