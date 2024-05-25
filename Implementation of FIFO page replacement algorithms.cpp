#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

// Function prototypes
void fifoPageReplacement(int pages[], int n, int frames);

int main() {
    int pages[MAX_FRAMES];
    int n, frames;

    // Input number of frames and page reference string
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    printf("Enter the number of page references: ");
    scanf("%d", &n);
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Perform FIFO page replacement algorithm
    fifoPageReplacement(pages, n, frames);

    return 0;
}

// FIFO page replacement algorithm
void fifoPageReplacement(int pages[], int n, int frames) {
    int page_faults = 0;
    int frame_queue[MAX_FRAMES] = {0};
    bool is_page_present[MAX_FRAMES] = {false};
    int rear = -1;

    printf("\nFIFO Page Replacement Algorithm:\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool is_page_fault = true;

        // Check if page is already present in frame
        for (int j = 0; j < frames; j++) {
            if (frame_queue[j] == page) {
                is_page_fault = false;
                break;
            }
        }

        // If page fault occurs
        if (is_page_fault) {
            page_faults++;

            // If frame is not full
            if (rear < frames - 1) {
                rear++;
            } else {
                // Remove the first page in the frame queue
                for (int j = 0; j < frames - 1; j++) {
                    frame_queue[j] = frame_queue[j + 1];
                }
            }

            // Add new page to frame queue
            frame_queue[rear] = page;

            // Print current state of frame queue
            printf("Page %d inserted into frame: ", page);
            for (int j = 0; j <= rear; j++) {
                printf("%d ", frame_queue[j]);
            }
            printf("\n");
        }
    }

    printf("\nTotal page faults: %d\n", page_faults);
}

