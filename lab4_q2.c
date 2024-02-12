#include<stdio.h>
#include<stdlib.h>

// Structure to hold process information
struct Process {
    int pid;  // Process ID
    int burst_time;  // Burst time
    int arrival_time;  // Arrival time
    int remaining_time; // Remaining burst time
    int waiting_time;  // Waiting time
    int turnaround_time;  // Turnaround time
    int response_time;  // Response time
    int completed; // 0 if not completed, 1 if completed
};

// Function to perform SJF Scheduling (Non-Preemptive)
void SJF_NonPreemptive(struct Process processes[], int n) {
    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time, turnaround time, and response time
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].response_time = processes[i].waiting_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
    }

    // Calculate total waiting time, total turnaround time, and total response time
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
    }

    // Calculate average waiting time, average turnaround time, and average response time
    double avg_waiting_time = (double) total_waiting_time / n;
    double avg_turnaround_time = (double) total_turnaround_time / n;
    double avg_response_time = (double) total_response_time / n;

    // Calculate CPU Utilization
    double cpu_utilization = (double)(current_time - processes[0].arrival_time) / current_time * 100;

    // Display results
    printf("\nSJF (Non-Preemptive):\n");
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time,
               processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
    printf("CPU Utilization: %.2f%%\n", cpu_utilization);
}

// Function to perform SJF Scheduling (Preemptive)
void SJF_Preemptive(struct Process processes[], int n) {
    int current_time = 0;
    int completed = 0;
    while (completed < n) {
        int shortest_job_index = -1;
        int shortest_job_burst = __INT_MAX__;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !processes[i].completed) {
                if (processes[i].burst_time < shortest_job_burst) {
                    shortest_job_burst = processes[i].burst_time;
                    shortest_job_index = i;
                }
            }
        }
        if (shortest_job_index == -1) {
            current_time++;
            continue;
        }
        processes[shortest_job_index].remaining_time--;
        if (processes[shortest_job_index].remaining_time == 0) {
            processes[shortest_job_index].completed = 1;
            completed++;
            processes[shortest_job_index].turnaround_time = current_time + 1 - processes[shortest_job_index].arrival_time;
            processes[shortest_job_index].waiting_time = processes[shortest_job_index].turnaround_time - processes[shortest_job_index].burst_time;
        }
        current_time++;
    }

    // Calculate total waiting time, total turnaround time, and total response time
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
    }

    // Calculate average waiting time, average turnaround time, and average response time
    double avg_waiting_time = (double) total_waiting_time / n;
    double avg_turnaround_time = (double) total_turnaround_time / n;
    double avg_response_time = (double) total_response_time / n;

    // Calculate CPU Utilization
    double cpu_utilization = (double)(current_time - processes[0].arrival_time) / current_time * 100;

    // Display results
    printf("\nSJF (Preemptive):\n");
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time,
               processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
    printf("CPU Utilization: %.2f%%\n", cpu_utilization);
}

int main() {
    struct Process processes[] = {
        {1, 6, 2, 0, 0, 0, 0},
        {2, 2, 5, 0, 0, 0, 0},
        {3, 8, 1, 0, 0, 0, 0},
        {4, 3, 7, 0, 0, 0, 0},
        {5, 4, 4, 0, 0, 0, 0}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    // Perform SJF (Non-Preemptive)
    SJF_NonPreemptive(processes, n);

    // Perform SJF (Preemptive)
    SJF_Preemptive(processes, n);

    return 0;
}
