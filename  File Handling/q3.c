#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_FIELD_SIZE 20
#define MAX_LINE_SIZE 100

// Structure to store log entry data
typedef struct {
    int entryNo;
    char sensorNo[MAX_FIELD_SIZE];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_FIELD_SIZE];
} LogEntry;

// Function to extract each line from the CSV file and store it in an array of structures
int extractLogEntries(LogEntry logEntries[]) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int entryCount = 0;

    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    // Skip the header line
    fgets(line, MAX_LINE_SIZE, file);

    // Read each line from the file and extract the data
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]", &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.timestamp);
        logEntries[entryCount++] = entry;
    }

    fclose(file);

    return entryCount;
}

// Function to display the contents of the array of structures
void displayLogEntries(const LogEntry logEntries[], int entryCount) {
    printf("Log Entries:\n");
    printf("------------------------------------\n");
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    printf("------------------------------------\n");

    for (int i = 0; i < entryCount; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n", logEntries[i].entryNo, logEntries[i].sensorNo,
               logEntries[i].temperature, logEntries[i].humidity, logEntries[i].light, logEntries[i].timestamp);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount;

    // Extract log entries from the CSV file
    entryCount = extractLogEntries(logEntries);

    // Display the log entries
    displayLogEntries(logEntries, entryCount);

    return 0;
}
