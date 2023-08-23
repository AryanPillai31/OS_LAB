#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void main()
{
    int i,j,temp,pid[10],n,burst[10],wt[10],ta[10];
    float avgwt=0,avgta=0;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    printf("enter the process id and it's burst time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
        scanf("%d",&burst[i]);
    }
    //sorting
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(burst[j]>burst[j+1])
            {
                swap(&burst[j],&burst[j+1]);
                swap(&pid[j],&pid[j+1]);
            }
        }
    }
    printf("according shortest job schedule\n");
    for(i=0;i<n;i++)
    {
        printf("processor id %d\t",pid[i]);
        printf("burst time %d\n",burst[i]);
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+burst[i-1];
    }
    for(i=0;i<n;i++)
    {
        ta[i]=wt[i]+burst[i];
    }
    for(i=0;i<n;i++)
    {
        avgwt+=wt[i];
        avgta+=ta[i];
    }
    avgwt=avgwt/n;
    avgta=avgta/n;
    printf("\nAverage waiting time is %f\n",avgwt);
    printf("\nAverage turnaround time is %f\n",avgta);

}