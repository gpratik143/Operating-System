#include <stdio.h>

int main() {
    // Define an empty string (character array) to store the copied string
    char destination[100];  // Assuming a maximum length of 100 characters
    
    // Define the source string
    const char source[] = "Hello, World!";
    
    // Copy each character from source to destination until null character is encountered
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    
    // Add null character at the end of destination to terminate the string
    destination[i] = '\0';
    
    // Display the original and copied strings
    printf("Original String: %s\n", source);
    printf("Copied String: %s\n", destination);
    
    return 0;
}
