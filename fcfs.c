#include <stdio.h>
#include <stdlib.h>


int main() {
    int at[20],bt[20],tat[20],wt[20],i,n;

    float WAITavg=0,TATavg=0;


    printf("\nEnter the no. of processes: ");
    scanf("%d", &n);
    int sum=0;
    for(i=0;i<n;i++) {
        printf("\nEnter arrival time, burst time for process %d : ",(i+1));
        scanf("%d %d", &at[i], &bt[i]);
        
        
        
        tat[i]=(sum+bt[i])-at[i];
        TATavg+=tat[i];
        wt[i]=tat[i]-bt[i];
        WAITavg+=wt[i];
        sum+=bt[i];

        // tat[i]=bt[i]-at[i];
    }

    for(int i=0;i<n;i++) {
        printf("\n TurnAround Time for process %d : %d", (i+1), tat[i]);
    }
    for(int i=0;i<n;i++) {
        printf("\n Wait Time for process %d : %d", (i+1), wt[i]);
    }
    printf("\n Average Turn Around Time: %f", TATavg/n);
    printf("\n Average Wait Time: %f", WAITavg/n);

    return 0;
}