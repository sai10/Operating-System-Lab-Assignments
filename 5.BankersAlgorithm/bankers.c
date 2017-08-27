#include<stdio.h>

void main()
{
    int n,m,i,j,k,y,count=0;

    printf("Enter the number of resources:");
    scanf("%d",&m);

    printf("Enter the number of process:");
    scanf("%d",&n);

    int allo[n][m],max[n][m],need[n][m],avai[m],seq[n],flag[n];


    printf("Enter the AVAILABLE RESOURCES:\n");
    printf("______________________________\n\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avai[i]);
    }

    printf("\nEnter the ALLOCATION MATRIX:\n");
    printf("______________________________\n");
    for(i=0;i<n;i++)
    {
        printf("\nPROCESS %d : ",i);
        for(j=0;j<m;j++)
        {
            scanf("%d",&allo[i][j]);
        }
    }

    for(i=0;i<n;i++)
        flag[i]=0;

    printf("\nEnter the MAX MATRIX:\n");
    printf("_______________________\n");
    for(i=0;i<n;i++)
    {
        printf("\nPROCESS %d : ",i);
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - allo[i][j];
        }
    }
    printf("\n\nNEED MATRIX IS:\n\n");
    printf("___________________\n");
    for(i=0;i<n;i++)
    {
        printf("\nPROCESS %d : ",i);
        for(j=0;j<m;j++)
        {
            printf("%d ",need[i][j]);
        }
    }

    k=0;
    while(1)
    {
        for(i=0;i<n;i++)
        {
            if(flag[i]==0)
            {
                count=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]<=avai[j])
                        count++;
                    else
                        break;
                }
                if(count==m)
                {
                    seq[k]=i;
                    flag[i]=1;
                    k++;
                    for(y=0;y<m;y++)
                        avai[y] += allo[i][y];
                }
            }
        }
        if(k==n)
            break;
    }

    printf("\n\nPROCESS SEQUENCE IS:\n");
    printf("________________________\n\n");
    for(i=0;i<n;i++)
        printf("P%d ",seq[i]);

    printf("\n\n");
}

