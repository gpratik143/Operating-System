#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Process {
    char name;
    int tickets;
    bool executed;
};

int selectProcess(Process processes[], int numProcesses, int totalTickets) {
    int winningTicket = rand() % totalTickets + 1;
    int sum = 0;
    for (int i = 0; i < numProcesses; ++i) {
        sum += processes[i].tickets;
        if (sum >= winningTicket && !processes[i].executed) {
            return i;
        }
    }
    return -1;
}

int main() {
    int numProcesses;

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    Process *processes = new Process[numProcesses];

    int totalTickets = 0;

    // Get ticket distribution for each process
    cout << "Enter ticket distribution for each process:\n";
    for (int i = 0; i < numProcesses; ++i) {
        cout << "Process P" << i + 1 << " tickets: ";
        cin >> processes[i].tickets;
        totalTickets += processes[i].tickets;
        processes[i].name = 'P' + i;
        processes[i].executed = false;
    }

    // Set random seed
    srand(time(nullptr));

    cout << "CPU Allocation to process:\n";
    for (int i = 0; i < numProcesses; ++i) {
        int selectedProcess = selectProcess(processes, numProcesses, totalTickets);
        if (selectedProcess != -1) {
            processes[selectedProcess].executed = true;
            cout << "CPU allocated to P" << selectedProcess + 1 << endl;
        }
    }

    delete[] processes;
    return 0;
}
