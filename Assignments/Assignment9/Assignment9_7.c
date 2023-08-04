//WAP which is used to pring home directory and login user name.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>

int main() {
    // Get the home directory
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) 
    {
        printf("Error getting home directory");
        return 1;
    }
    printf("Home directory: %s\n", home_dir);

    // Get the login user name
    struct passwd *user_info = getpwuid(getuid());
    if (user_info == NULL) 
    {
        printf("Error getting user info");
        return 1;
    }
    printf("Login user name: %s\n", user_info->pw_name);

    return 0;
}
