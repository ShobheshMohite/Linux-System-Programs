//WAP which is used to create daemon process.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig) {
    if (sig == SIGTERM) {
        // Handle SIGTERM signal, for example, clean up resources
        exit(EXIT_SUCCESS);
    }
}

int main() {
    pid_t pid, sid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    // If we got a good PID, then we can exit the parent process.
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Change the file mode mask
    umask(0);

    // Create a new session
    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    // Change the current working directory
    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }

    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Install a signal handler for clean shutdown
    signal(SIGTERM, signal_handler);

    // Daemon-specific initialization code here

    // Main daemon loop
    while (1) {
        // Daemon's functionality here
        sleep(1);
    }

    return 0;
}
