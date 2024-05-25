#include <stdio.h>
#include <stdlib.h>

// Function prototype
void fcfsDiskScheduling(int requests[], int n, int head);

int main() {
    int requests[100], n, head;

    // Input number of requests and request sequence
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    printf("Enter the disk request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Input initial position of disk head
    printf("Enter the initial position of disk head: ");
    scanf("%d", &head);

    // Perform FCFS disk scheduling algorithm
    fcfsDiskScheduling(requests, n, head);

    return 0;
}

// FCFS Disk Scheduling algorithm
void fcfsDiskScheduling(int requests[], int n, int head) {
    int total_head_movement = 0;
    printf("\nFCFS Disk Scheduling:\n");

    // Calculate total head movement
    for (int i = 0; i < n; i++) {
        printf("Move from %d to %d\n", head, requests[i]);
        total_head_movement += abs(head - requests[i]);
        head = requests[i];
    }

    printf("\nTotal head movement: %d\n", total_head_movement);
}








FCFS schedules disk requests in the order they arrive.
It moves the disk arm to the requested track and services the request.
FCFS is easy to implement but can lead to suboptimal performance, especially if requests are spread across the disk.
It suffers from the "SSTF (Shortest Seek Time First) Starvation" problem, where requests that are far away from the disk head may have to wait indefinitely.