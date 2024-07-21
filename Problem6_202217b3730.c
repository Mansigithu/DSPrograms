#include <stdio.h>
#include <conio.h>

void main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

     // Clear the console screen (non-standard; use system("cls") on Windows or system("clear") on Unix-based systems)

    for (i = 0; i < 10; i++) {
        a[i] = 0; // Arrival times
        b[i] = 0; // Burst times
        w[i] = 0; // Waiting times
        g[i] = 0; // Completion times
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > 10 || n <= 0) {
        printf("Invalid number of processes. Must be between 1 and 10.\n");
        return;
    }

    printf("Enter the burst times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("Enter the arrival times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    g[0] = b[0]; // The completion time of the first process
    for (i = 1; i < n; i++) {
        g[i] = g[i - 1] + b[i];
    }

    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i] - b[i]; // Waiting time
        t[i] = g[i] - a[i];        // Turnaround time
        awt += w[i];
        att += t[i];
    }

    awt = awt / n; // Average waiting time
    att = att / n; // Average turnaround time

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", i + 1, w[i], t[i]);
    }

    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);

    getch(); // Wait for a key press (non-standard; use getchar() or similar)
}
