#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to display a colored memory usage bar
void print_bar(float percent) {
    int bar_width = 30; // Total width of the bar
    int filled = (percent / 100.0) * bar_width; // Number of filled segments

    char* color;
    // Choose color based on usage percentage
    if (percent < 50.0) {
        color = "\033[1;32m";  // Green for low usage
    } else if (percent < 80.0) {
        color = "\033[1;33m";  // Yellow for moderate usage
    } else {
        color = "\033[1;31m";  // Red for high usage
    }

    printf("[");
    for (int i = 0; i < bar_width; i++) {
        if (i < filled) {
            printf("%s█\033[0m", color); // Print colored filled bar
        } else {
            printf("-"); // Print empty space
        }
    }
    printf("] %.2f%%\n", percent); // Display percentage value
}

int main() {
    while (1) {
        FILE* file;
        char line[256];

        int Mem_Total = 0;
        int Mem_Free = 0;
        int Mem_Available = 0;

        // Open /proc/meminfo to read memory stats
        file = fopen("/proc/meminfo", "r");
        if (file == NULL) {
            perror("Unable to open file: /proc/meminfo");
            return 1;
        }

        // Parse relevant memory information from each line
        while (fgets(line, sizeof(line), file) != NULL) {
            if (strncmp(line, "MemTotal:", 9) == 0) {
                sscanf(line, "MemTotal: %d kb", &Mem_Total);
            }
            if (strncmp(line, "MemFree:", 8) == 0) {
                sscanf(line, "MemFree: %d kb", &Mem_Free);
            }
            if (strncmp(line, "MemAvailable:", 13) == 0) {
                sscanf(line, "MemAvailable: %d kb", &Mem_Available);
            }
        }
        fclose(file); // Close the file after reading

        // Convert memory values from KB to MB
        float Mem_total_mb = Mem_Total / 1024.0;
        float Mem_free_mb = Mem_Free / 1024.0;
        float Mem_available_mb = Mem_Available / 1024.0;

        // Calculate memory usage stats
        float free_percent = (float)Mem_Free / Mem_Total * 100;
        float Mem_used_mb = (Mem_Total - Mem_Available) / 1024.0;
        float used_percent = (float)(Mem_Total - Mem_Free) / Mem_Total * 100;

        // Clear the terminal for live update effect
        system("clear");

        // Display memory usage info
        printf("\033[1;36m Live Memory Monitor \033[0m\n\n");
        printf("\033[1;34m🔹Total Memory:      \033[0m%.2f MB\n", Mem_total_mb);
        printf("\033[1;32m🔹Free Memory:       \033[0m%.2f MB\n", Mem_free_mb);
        printf("\033[1;33m🔹Available Memory:  \033[0m%.2f MB\n", Mem_available_mb);
        printf("\033[1;31m🔹Used Memory:       \033[0m%.2f MB\n", Mem_used_mb);
        printf("\033[1;35m🔹Used Percentage:   \033[0m");
        print_bar(used_percent); // Print colored usage bar

        sleep(1); // Delay for 1 second before refreshing
    }

    return 0;
}
