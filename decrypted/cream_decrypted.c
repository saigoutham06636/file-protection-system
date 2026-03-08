#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter number of processes\n");
    scanf("%d",&n);
    printf("Enter number of resources\n");
    scanf("%d",&m);
    int alloc[n][m],max[n][m],need[n][m],avail[m];
    printf("Enter allocation matrix");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter maximum matrix");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Need matrix is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d",need[i][j]);
        }
        printf("\n");
    }
    printf("Enter available resources\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    int finish[n];
    for(int i=0;i<n;i++)
    {
        finish[i]=0;
    }
    int safeseq[n];
    int work[m];
    for(int i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    int count=0;
    while(count<n)
    {
        int found=0;
        for(int i=0;i<n;i++)
        {
            if(!finish[i])
            {
                int j;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        break;
                    }
                }
                if(j==m)
                {
                    for(int k=0;k<m;k++)
                    {
                        work[k]+=alloc[i][k];
                    }
                    safeseq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(!found)
        {
            printf("System in deadlock");
        }
    }
    printf("System in safe state.Safe seq is\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d->",safeseq[i]);
    }
}
