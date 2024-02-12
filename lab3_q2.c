
#include<stdio.h>

// Structure to hold process information
struct Process {
    int pid;  // Process ID
    int burst_time;  // Burst time
    int arrival_time;  // Arrival time
    int waiting_time;  // Waiting time
    int turnaround_time;  // Turnaround time
    int response_time;  // Response time
};

// Function to calculate FCFS scheduling
void FCFS(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    
    // Calculate waiting time, turnaround time, and response time
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Update response time
        processes[i].response_time = current_time - processes[i].arrival_time;
        if (processes[i].response_time < 0)
            processes[i].response_time = 0;
        
        // Update waiting time
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        if (processes[i].waiting_time < 0)
            processes[i].waiting_time = 0;
        
        // Update current time
        current_time += processes[i].burst_time;
        
        // Update turnaround time
        processes[i].turnaround_time = current_time - processes[i].arrival_time;
        
        // Accumulate total waiting time, turnaround time, and response time
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
        
        // Print process details
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
    
    // Calculate average waiting time, average turnaround time, and average response time
    double avg_waiting_time = (double) total_waiting_time / n;
    double avg_turnaround_time = (double) total_turnaround_time / n;
    double avg_response_time = (double) total_response_time / n;
    
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
}

int main() {
    struct Process processes[] = {
        {1, 6, 2, 0, 0, 0},
        {2, 2, 5, 0, 0, 0},
        {3, 8, 1, 0, 0, 0},
        {4, 3, 0, 0, 0, 0},
        {5, 4, 4, 0, 0, 0}
    };
    
    int n = sizeof(processes) / sizeof(processes[0]);
    
    FCFS(processes, n);
    
    return 0;
}
