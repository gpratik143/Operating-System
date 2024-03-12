#include <iostream>

#define NUM_PROCESSES 5
#define TICKETS 10
#define BIGGEST_NUMBER 10000
#define INITIAL_PASS_VALUE 0

using namespace std;

struct Process {
    int pass;
    int stride;
    int id;
};

void initializeProcesses(Process processes[]) {
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        processes[i].id = i + 1;
        processes[i].pass = INITIAL_PASS_VALUE;
        processes[i].stride = BIGGEST_NUMBER / TICKETS;
    }
}

int selectProcess(Process processes[]) {
    int min_pass = BIGGEST_NUMBER;
    int selected_process = -1;

    for (int i = 0; i < NUM_PROCESSES; ++i) {
        if (processes[i].pass < min_pass) {
            min_pass = processes[i].pass;
            selected_process = i;
        }
    }

    processes[selected_process].pass += processes[selected_process].stride;

    return selected_process;
}

int main() {
    Process processes[NUM_PROCESSES];

    initializeProcesses(processes);

    cout << "Selected Process IDs in order of execution:\n";
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        int selected_process = selectProcess(processes);
        cout << processes[selected_process].id << " ";
    }

    cout << endl;

    return 0;
}
