#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int arrivalTime;
    int cpuTime;
    int priority;
} Task;

typedef struct {
    Task task;
    int remainingTime;
} ScheduledTask;

// Priority Queue implementation
typedef struct {
    ScheduledTask* scheduledTasks;
    int size;
} PriorityQueue;

void initializeQueue(PriorityQueue* queue) {
    queue->scheduledTasks = NULL;
    queue->size = 0;
}

void enqueue(PriorityQueue* queue, ScheduledTask task) {
    int i = queue->size - 1;
    while (i >= 0 && queue->scheduledTasks[i].task.priority <= task.task.priority) {
        if (queue->scheduledTasks[i].task.priority == task.task.priority &&
            queue->scheduledTasks[i].remainingTime <= task.remainingTime) {
            break;
        }
        queue->scheduledTasks[i + 1] = queue->scheduledTasks[i];
        i--;
    }
    queue->scheduledTasks[i + 1] = task;
    queue->size++;
}

ScheduledTask dequeue(PriorityQueue* queue) {
    if (queue->size == 0) {
        ScheduledTask emptyTask = {{0, 0, 0}, 0};
        return emptyTask;
    }
    ScheduledTask task = queue->scheduledTasks[0];
    for (int i = 1; i < queue->size; i++) {
        queue->scheduledTasks[i - 1] = queue->scheduledTasks[i];
    }
    queue->size--;
    return task;
}

// Preemptive OS scheduling function
void scheduleTasks(Task tasks[], int numTasks) {
    PriorityQueue queue;
    initializeQueue(&queue);

    int currentTime = 0;
    int completedTasks = 0;

    while (completedTasks < numTasks) {
        // Enqueue arrived tasks
        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].arrivalTime == currentTime) {
                ScheduledTask scheduledTask = {tasks[i], tasks[i].cpuTime};
                enqueue(&queue, scheduledTask);
            }
        }

        if (queue.size > 0) {
            // Dequeue the task with highest priority
            ScheduledTask currentTask = dequeue(&queue);
            printf("Running Task %d\n", currentTask.task.priority);

            // Reduce remaining time and check if task is completed
            currentTask.remainingTime--;
            if (currentTask.remainingTime == 0) {
                printf("Task %d completed\n", currentTask.task.priority);
                completedTasks++;
            } else {
                enqueue(&queue, currentTask);
            }
        } else {
            printf("CPU Idle\n");
        }

        currentTime++;
    }
}

int main() {
    // Sample tasks
    Task tasks[] = {
        {0, 5, 2},
        {1, 3, 1},
        {2, 2, 3},
        {4, 4, 2},
        {5, 1, 1}
    };
    int numTasks = 5;

    scheduleTasks(tasks, numTasks);

    return 0;
}