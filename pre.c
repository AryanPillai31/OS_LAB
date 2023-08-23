#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int arrivalTime;
    int cpuTime;
    int priority;
} Task;

// Preemptive OS scheduling function
void scheduleTasks(Task tasks[], int numTasks) {
    int completedTasks = 0;

    while (completedTasks < numTasks) {
        int highestPriority = -1;
        int highestPriorityIndex = -1;

        // Find the task with the highest priority that is pending
        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].cpuTime > 0 && tasks[i].priority > highestPriority) {
                highestPriority = tasks[i].priority;
                highestPriorityIndex = i;
            }
        }

        if (highestPriorityIndex != -1) {
            printf("Running Task : %d\n", highestPriorityIndex);
            printf("Running Task with priority : %d\n", tasks[highestPriorityIndex].priority);
            tasks[highestPriorityIndex].cpuTime--;
            if (tasks[highestPriorityIndex].cpuTime == 0) {
                printf("Task %d completed\n", tasks[highestPriorityIndex].priority);
                completedTasks++;
            }
        } else {
            printf("CPU Idle\n");
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

    return 0;
}