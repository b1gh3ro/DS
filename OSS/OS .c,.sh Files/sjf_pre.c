#include <stdio.h>
#include <limits.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
        proc[i].remaining_time = proc[i].burst_time;
    }

    int time = 0, completed = 0;
    while (completed < n) {
        int idx = -1;
        int min_remaining_time = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0 && proc[i].arrival_time <= time) {
                if (proc[i].remaining_time < min_remaining_time) {
                    min_remaining_time = proc[i].remaining_time;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            proc[idx].remaining_time--;
            if (proc[idx].remaining_time == 0) {
                completed++;
                proc[idx].turnaround_time = time + 1 - proc[idx].arrival_time;
                proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].burst_time;
            }
        }
        time++;
    }

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", proc[i].id, proc[i].arrival_time, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += proc[i].waiting_time;
        avg_turnaround_time += proc[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
