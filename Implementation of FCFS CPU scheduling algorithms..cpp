#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
};

void findWaitingTime(struct Process processes[], int n, int waiting_time[]) {
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = processes[i-1].burst_time + waiting_time[i-1];
    }
}

void findTurnaroundTime(struct Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i];
    }
}

void findAverageTimes(struct Process processes[], int n) {
    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;

    findWaitingTime(processes, n, waiting_time);
    findTurnaroundTime(processes, n, waiting_time, turnaround_time);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    struct Process processes[] = {{1, 5}, {2, 3}, {3, 8}, {4, 6}};
    int n = sizeof(processes) / sizeof(processes[0]);

    findAverageTimes(processes, n);

    return 0;
}







FCFS is the simplest CPU scheduling algorithm, where processes are executed in the order they arrive in the ready queue.
It works on the principle of "first come, first served", meaning the process that arrives first gets executed first.
The CPU scheduler selects the process with the lowest arrival time from the ready queue and executes it until completion.
FCFS is easy to understand and implement, but it may lead to high average waiting times, especially for long processes that arrive first.
It is suitable for batch processing systems where turnaround time is not critical, and there is no need for interactive response times.














