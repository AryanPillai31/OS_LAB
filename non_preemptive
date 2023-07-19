#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int arrivalTime;
    int cpuTime;
    int priority;
    int completedTime;
} Task;

// Non-preemptive OS scheduling function
void scheduleTasks(Task tasks[], int numTasks) {
    int currentTime = 0;
    int completedTasks = 0;

    while (completedTasks < numTasks) {
        int highestPriority = -1;
        int highestPriorityIndex = -1;

        // Find the task with the highest priority that has arrived
        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].arrivalTime <= currentTime && tasks[i].priority > highestPriority) {
                highestPriority = tasks[i].priority;
                highestPriorityIndex = i;
            }
        }

        if (highestPriorityIndex != -1) {
            printf("current running task is %d\n", highestPriorityIndex);
            printf("Running Task with priority : %d\n", tasks[highestPriorityIndex].priority);
            currentTime += tasks[highestPriorityIndex].cpuTime;
            printf("Task %d completed\n", tasks[highestPriorityIndex].priority);
            completedTasks++;
            tasks[highestPriorityIndex].priority = -1; // Mark task as completed
            int completedTime = currentTime;
        } else {
            printf("CPU Idle\n");
            currentTime++;
        }
    }
}

int main() {
    // Sample tasks
    Task tasks[] = {
        {0, 5, 2},
        {1, 3, 1},
        {2, 2, 3}
    };
    int numTasks = sizeof(tasks) / sizeof(tasks[0]);

    scheduleTasks(tasks, numTasks);

    float avgTAT=0;
    // float avgWT=0;
    for(int i=0;i<numTasks;i++) {
        // int waiting = tasks[i].completedTime-tasks[i].arrivalTime-cpuTime[i];
        printf("TAT time for task is: %d\n", tasks[i].completedTime-tasks[i].arrivalTime);
        // printf("WT time for task is: %d\n", waiting);
        avgTAT+=tasks[i].completedTime-tasks[i].arrivalTime;
        // avgWT+=waiting;
        // printf("%d\n",avgWT);
    }

    printf("Average TurnAround Time is: %f\n", avgTAT/numTasks);

    return 0;
}
