//3. WAP which is used to print priority of process.
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    int priority;

    // Get the priority of the current process (0 for the current process)
    priority = getpriority(PRIO_PROCESS, 0);
    
    if (priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("Priority of the current process: %d\n", priority);

    return 0;
}
