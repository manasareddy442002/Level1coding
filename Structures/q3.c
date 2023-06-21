#include <stdio.h>

// Structure to represent time
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateDifference(struct Time t1, struct Time t2) {
    struct Time diff;
    int totalSeconds1, totalSeconds2, diffSeconds;

    // Convert time periods to seconds
    totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate difference in seconds
    diffSeconds = totalSeconds2 - totalSeconds1;

    // Convert difference back to hours, minutes, and seconds
    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;

    return diff;
}

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter start time (hours: minutes: seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Enter end time (hours: minutes: seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    difference = calculateDifference(startTime, endTime);

    printf("\nTime difference: %d hours:%d minutes:%d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
