#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void list_files_on_desktop(const char *desktop_path) 
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(desktop_path);
    if (dir == NULL) 
    {
        printf("opendir");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen("demo_file.txt", "w");
    if (output_file == NULL) 
    {
        printf("fopen");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        if (entry->d_type == DT_REG) 
        {
            fprintf(output_file, "%s\n", entry->d_name);
        }
    }

    closedir(dir);
    fclose(output_file);
    printf("File names written to demo_file.txt\n");
}

int main() 
{
    const char *desktop_path = "/home/kali/Desktop";  // Replace with your actual desktop path
    list_files_on_desktop(desktop_path);

    return 0;
}
