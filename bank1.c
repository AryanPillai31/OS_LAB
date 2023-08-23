#include <stdio.h>

#include <string.h>

void main()
{
    int alloc[10][10], max[10][10];
    int avail[10], work[10], total[10];
    int need[10][10];
    int i, j, k, n, m;
    int count = 0, c = 0;
    char finish[10];

    printf("Enter the number of processes and resources:");
    scanf("%d %d", &n, &m);

    // Initializing the 'finish' array to 'n'
    for (i = 0; i < n; i++)
        finish[i] = 'n';

    // Input the maximum resource claim matrix
    printf("Enter the claim matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input the resource allocation matrix
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input the total resources
    printf("Resource vector:");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);

    // Calculating available resources
    for (i = 0; i < m; i++)
    {
        avail[i] = 0;
        for (j = 0; j < n; j++)
            avail[i] += alloc[j][i];
    }

    // Calculating work vector
    for (i = 0; i < m; i++)
        work[i] = total[i] - avail[i];

    // Calculating the need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Safety algorithm starts here
A:
    for (i = 0; i < n; i++)
    {
        c = 0;
        for (j = 0; j < m; j++)
        {
            if ((need[i][j] <= work[j]) && (finish[i] == 'n'))
                c++;
        }
        if (c == m)
        {
            printf("All the resources can be allocated to Process %d", i + 1);
            printf("\n\nAvailable resources are:");
            for (k = 0; k < m; k++)
            {
                work[k] += alloc[i][k];
                printf("%4d", work[k]);
            }
            printf("\n");
            finish[i] = 'y';
            printf("\nProcess %d executed?: %c \n", i + 1, finish[i]);
            count++;
        }
    }

    // Checking if all processes are executed, else continue the algorithm
    if (count != n)
        goto A;
    else
        printf("\nSystem is in safe mode");

    printf("\nThe given state is safe state");
}
