#include<stdio.h>
#include<stdlib.h>

int arrival[50],cpu[50],turn_around[50],wait[50],n;
float completion=0;

void SJF(){
    int remaining[n];
    int current=0;
    int completed=0;

    for(int i=0;i<n;i++){
        remaining[i]=cpu[i];
    }

    while(completed!=n){
        int shortest=-1;
        int min=1000;

        for(int i=0;i<n;i++){
            if(arrival[i]<=current && remaining[i]>0 && remaining[i]<min){
                shortest=i;
                min=remaining[i];
            }
        }
            if(shortest==-1){
                current++;
                continue;
            }

            current+=remaining[shortest];
            remaining[shortest]=0;
            turn_around[shortest]=current-arrival[shortest];
            wait[shortest]=turn_around[shortest]-cpu[shortest];
            completed++;
    }
    completion=current;
}

void STRF(){
    int remaining[n];
    int current=0;
    int completed=0;

    for(int i=0;i<n;i++){
        remaining[i]=cpu[i];
    }

    while(completed!=n){
        int shortest=-1;
        int min=1000;

        for(int i=0;i<n;i++){
            if(arrival[i]<=current && remaining[i]>0 && remaining[i]<min){
                shortest=i;
                min=remaining[i];
            }
        }
            if(shortest==-1){
                current++;
                continue;
            }

            current++;
            remaining[shortest]--;
            if(remaining[shortest]==0){
            turn_around[shortest]=current-arrival[shortest];
            wait[shortest]=turn_around[shortest]-cpu[shortest];
            completed++;
            }
    }
    completion=current;
}


int main(){
    printf("Enter number of processes\n");
    scanf("%d",&n);
    printf("Enter arrival time and processing time\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&arrival[i],&cpu[i]);
    }

    SJF();
    float avgTAT=0,avgWT=0;
    printf("\nSJF\nProcess     TurnAroundTime      WaitingTime\n");
    for(int i=0;i<n;i++){
        printf("%d      %d      %d\n",i,turn_around[i],wait[i]);
        avgTAT+=turn_around[i];
        avgWT+=wait[i];
    }
    printf("Average Turn Around Time: %f\n",avgTAT/n);
    printf("Average Wait Time: %f\n",avgWT/n);
    printf("Throughput: %f",completion/n);

    
    STRF();
    avgTAT=0,avgWT=0;
    printf("\nSTRF\nProcess   TurnAroundTime    WaitingTime\n");
    for(int i=0;i<n;i++){
        printf("%d      %d      %d\n",i,turn_around[i],wait[i]);
        avgTAT+=turn_around[i];
        avgWT+=wait[i];
    }
    printf("Average Turn Around Time: %f\n",avgTAT/n);
    printf("Average Wait Time: %f\n",avgWT/n);
    printf("Throughput: %f",completion/n);


    return 0;
}