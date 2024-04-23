#include <stdio.h>

#define PAGE_SIZE 4096 // Assume page size is 4 KB

// Function prototypes
void findPageAndOffset(int virtualAddress);

int main() {
    int virtualAddress;

    // Input virtual address from user
    printf("Enter the virtual address: ");
    scanf("%d", &virtualAddress);

    // Find page number and offset
    findPageAndOffset(virtualAddress);

    return 0;
}

void findPageAndOffset(int virtualAddress) {
    int pageNumber, offset;

    // Calculate page number and offset
    pageNumber = virtualAddress / PAGE_SIZE;
    offset = virtualAddress % PAGE_SIZE;

    // Output page number and offset
    printf("Page Number: %d\n", pageNumber);
    printf("Offset: %d\n", offset);
}
