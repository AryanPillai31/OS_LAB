#include <stdio.h>

#define MAX_FRAMES 3

void display(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf("X\t");
        } else {
            printf("%d\t", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, pages[20], frames[MAX_FRAMES], used[MAX_FRAMES], page_faults = 0;

    printf("Enter length of the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;  // Initialize frames as empty
        used[i] = 0;     // Initialize used flags as 0
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        
        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                used[j] = 1; // Mark as recently used
                found = 1;
                break;
            }
        }

        // If not found in frames, find the LRU frame
        if (!found) {
            int lru_index = 0;
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (used[j] < used[lru_index]) {
                    lru_index = j;
                }
            }
            frames[lru_index] = page; // Replace LRU page
            used[lru_index] = 1;      // Mark as recently used
            page_faults++;
        }

        display(frames, MAX_FRAMES);
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
