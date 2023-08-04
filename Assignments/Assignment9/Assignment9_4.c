//WAP which is used to increase the priority by 5
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    int priority;

    // Get the current priority of the process
    priority = getpriority(PRIO_PROCESS, 0);
    
    if (priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("Current priority of the process: %d\n", priority);

    // Increase the priority by 5
    if (setpriority(PRIO_PROCESS, 0, priority - 5) == -1) {
        perror("Error setting priority");
        return 1;
    }

    // Get the new priority after modification
    priority = getpriority(PRIO_PROCESS, 0);
    
    if (priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("New priority of the process: %d\n", priority);

    return 0;
}
