#include<stdio.h>
void main()
{
    int n,a[10][10],indeg[10],flag[10],i,j,k,count=0;
    printf("Enter no of nodes:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
        indeg[i]=0;
        flag[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            indeg[i]=indeg[i]+a[j][i];
        }
    }
    printf("The topoligical sorting is as follows:\n");
    while(count<n)
    {
        for(k=0;k<n;k++)
        {
            if(indeg[k]==0 && flag[k]==0)
            {
                printf("%c ",(k+65));
                flag[k]=1;
            }
            for(i=0;i<n;i++)
            {
                 if(a[i][k])
                {
                    indeg[k]--;
                }
            }
        }
        count++;
    }
}