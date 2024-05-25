#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
};

void sortProcessesByBurstTime(struct Process processes[], int n) {
    struct Process temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (processes[j].burst_time > processes[j+1].burst_time) {
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

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

    sortProcessesByBurstTime(processes, n);
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
    struct Process processes[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};
    int n = sizeof(processes) / sizeof(processes[0]);

    findAverageTimes(processes, n);

    return 0;
}





SJF selects the process with the shortest burst time (execution time) for execution next.
It can be preemptive, where the currently running process can be interrupted if a new process with a shorter burst time arrives.
SJF minimizes average waiting time and turnaround time because it prioritizes shorter jobs.
However, it can lead to starvation for longer processes if shorter processes keep arriving, causing them to wait indefinitely.
SJF is suitable for environments where the burst time of processes is known in advance or can be predicted accurately.