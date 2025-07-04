#include <stdio.h>

// Function to solve Tower of Hanoi problem
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    tower_of_hanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

// Main function
int main() {
    int n = 3;  // Number of disks
    printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');  // A = source, C = destination, B = auxiliary
    return 0;
}
