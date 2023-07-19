#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i,  bt[10], rbt[10], qt, st = 0, tat[10], wt[10], at[10];
    float atat = 0, awt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of the processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rbt[i] = bt[i];
    }

    printf("Enter the arrival time of the processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &qt);

    while (1) {
        int done = 1;

        for (i = 0; i < n; i++) {
            if (rbt[i] > 0) {
                done = 0;

                if (rbt[i] > qt) {
                    rbt[i] -= qt;
                    st += qt;
                } else {
                    st += rbt[i];
                    wt[i] = st - bt[i] - at[i];
                    rbt[i] = 0;
                    tat[i] = st - at[i];
                }
            }
        }

        if (done)
            break;
    }

    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;

    printf("\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);

    return 0;
}
