#include <stdio.h>

#define NUM_PROCESSES 5
#define TICKETS 10
#define BIGGEST_NUMBER 10000
#define INITIAL_PASS_VALUE 0

struct Process {
    int pass;
    int stride;
    int id;
};

void initializeProcesses(struct Process processes[]) {
    int i;
    for (i = 0; i < NUM_PROCESSES; ++i) {
        processes[i].id = i + 1;
        processes[i].pass = INITIAL_PASS_VALUE;
        processes[i].stride = BIGGEST_NUMBER / TICKETS;
    }
}

int selectProcess(struct Process processes[]) {
    int i, min_pass = BIGGEST_NUMBER, selected_process = -1;
    
    for (i = 0; i < NUM_PROCESSES; ++i) {
        if (processes[i].pass < min_pass) {
            min_pass = processes[i].pass;
            selected_process = i;
        }
    }
    
    processes[selected_process].pass += processes[selected_process].stride;
    
    return selected_process;
}

int main() {
    struct Process processes[NUM_PROCESSES];
    int i;
    
    initializeProcesses(processes);
    
    printf("Selected Process IDs in order of execution:\n");
    for (i = 0; i < NUM_PROCESSES; ++i) {
        int selected_process = selectProcess(processes);
        printf("%d ", processes[selected_process].id);
    }
    
    printf("\n");
    
    return 0;
}
