#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESS 100

// Structure to represent a memory block
typedef struct {
    int id;
    int size;
    int allocated;
} Block;

// Structure to represent a process
typedef struct {
    int id;
    int size;
} Process;

// Function prototypes
void firstFit(Block blocks[], int m, Process processes[], int n);
void bestFit(Block blocks[], int m, Process processes[], int n);
void worstFit(Block blocks[], int m, Process processes[], int n);

int main() {
    Block blocks[MAX_BLOCKS];
    Process processes[MAX_PROCESS];
    int m, n;

    // Input memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter details of memory blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ID Size\n", i + 1);
        scanf("%d %d", &blocks[i].id, &blocks[i].size);
        blocks[i].allocated = 0;
    }

    // Input processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter details of processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ID Size\n", i + 1);
        scanf("%d %d", &processes[i].id, &processes[i].size);
    }

    // Perform memory allocation using various algorithms
    firstFit(blocks, m, processes, n);
    bestFit(blocks, m, processes, n);
    worstFit(blocks, m, processes, n);

    return 0;
}

// First Fit memory allocation algorithm
void firstFit(Block blocks[], int m, Process processes[], int n) {
    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocks[j].allocated == 0 && blocks[j].size >= processes[i].size) {
                blocks[j].allocated = 1;
                printf("Process %d allocated to Block %d\n", processes[i].id, blocks[j].id);
                break;
            }
        }
    }
}

// Best Fit memory allocation algorithm
void bestFit(Block blocks[], int m, Process processes[], int n) {
    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j].allocated == 0 && blocks[j].size >= processes[i].size) {
                if (bestIdx == -1 || blocks[j].size < blocks[bestIdx].size) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            blocks[bestIdx].allocated = 1;
            printf("Process %d allocated to Block %d\n", processes[i].id, blocks[bestIdx].id);
        }
    }
}

// Worst Fit memory allocation algorithm
void worstFit(Block blocks[], int m, Process processes[], int n) {
    printf("\nWorst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j].allocated == 0 && blocks[j].size >= processes[i].size) {
                if (worstIdx == -1 || blocks[j].size > blocks[worstIdx].size) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            blocks[worstIdx].allocated = 1;
            printf("Process %d allocated to Block %d\n", processes[i].id, blocks[worstIdx].id);
        }
    }
}






