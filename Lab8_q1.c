#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_REQUESTS 5

// Structure to represent memory partition
typedef struct {
    int size;
    int allocated;
} Partition;

// Function prototypes
void bestFit(int partitions[], int requests[]);
void firstFit(int partitions[], int requests[]);
void nextFit(int partitions[], int requests[]);
void worstFit(int partitions[], int requests[]);

int main() {
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int requests[MAX_REQUESTS] = {115, 500, 358, 200, 375};

    printf("Best Fit Algorithm:\n");
    bestFit(partitions, requests);

    printf("\nFirst Fit Algorithm:\n");
    firstFit(partitions, requests);

    printf("\nNext Fit Algorithm:\n");
    nextFit(partitions, requests);

    printf("\nWorst Fit Algorithm:\n");
    worstFit(partitions, requests);

    return 0;
}

void bestFit(int partitions[], int requests[]) {
    int i, j, minFragmentation;
    int allocated[MAX_REQUESTS];

    for (i = 0; i < MAX_REQUESTS; i++) {
        minFragmentation = 9999;
        for (j = 0; j < MAX_PARTITIONS; j++) {
            if (!partitions[j] || partitions[j] < requests[i]) // Skip if partition is already allocated or too small
                continue;
            if (partitions[j] - requests[i] < minFragmentation) {
                allocated[i] = j;
                minFragmentation = partitions[j] - requests[i];
            }
        }
        if (minFragmentation != 9999) {
            partitions[allocated[i]] -= requests[i];
            printf("Request %d KB allocated to Partition %d\n", requests[i], allocated[i]);
        } else {
            printf("Request %d KB cannot be allocated\n", requests[i]);
        }
    }
}

void firstFit(int partitions[], int requests[]) {
    int i, j;

    for (i = 0; i < MAX_REQUESTS; i++) {
        for (j = 0; j < MAX_PARTITIONS; j++) {
            if (!partitions[j] || partitions[j] < requests[i]) // Skip if partition is already allocated or too small
                continue;
            partitions[j] -= requests[i];
            printf("Request %d KB allocated to Partition %d\n", requests[i], j);
            break; // Allocation done, move to next request
        }
        if (j == MAX_PARTITIONS) {
            printf("Request %d KB cannot be allocated\n", requests[i]);
        }
    }
}

void nextFit(int partitions[], int requests[]) {
    int i, j, lastAllocated = 0;

    for (i = 0; i < MAX_REQUESTS; i++) {
        for (j = lastAllocated; j < MAX_PARTITIONS; j++) {
            if (!partitions[j] || partitions[j] < requests[i]) // Skip if partition is already allocated or too small
                continue;
            partitions[j] -= requests[i];
            printf("Request %d KB allocated to Partition %d\n", requests[i], j);
            lastAllocated = j; // Update last allocated partition
            break; // Allocation done, move to next request
        }
        if (j == MAX_PARTITIONS) {
            printf("Request %d KB cannot be allocated\n", requests[i]);
        }
    }
}

void worstFit(int partitions[], int requests[]) {
    int i, j, maxFragmentation;
    int allocated[MAX_REQUESTS];

    for (i = 0; i < MAX_REQUESTS; i++) {
        maxFragmentation = -1;
        for (j = 0; j < MAX_PARTITIONS; j++) {
            if (!partitions[j] || partitions[j] < requests[i]) // Skip if partition is already allocated or too small
                continue;
            if (partitions[j] - requests[i] > maxFragmentation) {
                allocated[i] = j;
                maxFragmentation = partitions[j] - requests[i];
            }
        }
        if (maxFragmentation != -1) {
            partitions[allocated[i]] -= requests[i];
            printf("Request %d KB allocated to Partition %d\n", requests[i], allocated[i]);
        } else {
            printf("Request %d KB cannot be allocated\n", requests[i]);
        }
    }
}

