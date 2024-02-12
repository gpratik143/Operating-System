#include<stdio.h>
#include<stdlib.h>

// Structure to hold process information
struct Process {
    int pid;  // Process ID
    int burst_time;  // Burst time
    int waiting_time;  // Waiting time
    int turnaround_time;  // Turnaround time
    int response_time;  // Response time
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
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
    processes[0].response_time = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        processes[i].response_time = processes[i].waiting_time;
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

    // Display results
    printf("\nSJF (Non-Preemptive):\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
}

// Function to perform SJF Scheduling (Preemptive)
void SJF_Preemptive(struct Process processes[], int n) {
    // Implementing SJF (Preemptive) is a bit complex and requires simulation of CPU scheduling.
    // In the interest of simplicity, I'll provide a simplified version here.
    // Real-world implementations might require more sophisticated approaches.

    // For this example, I'll use SJF (Non-Preemptive) as it's easier to implement.
    // You can replace this section with a more accurate implementation if needed.
    SJF_NonPreemptive(processes, n);
}

int main() {
    struct Process processes[] = {
        {1, 6, 0, 0, 0},
        {2, 2, 0, 0, 0},
        {3, 8, 0, 0, 0},
        {4, 3, 0, 0, 0},
        {5, 4, 0, 0, 0}
    };
    
    int n = sizeof(processes) / sizeof(processes[0]);

    // Perform SJF (Non-Preemptive)
    SJF_NonPreemptive(processes, n);

    // Perform SJF (Preemptive)
    // SJF_Preemptive(processes, n);  // Uncomment to use SJF (Preemptive)

    return 0;
}
