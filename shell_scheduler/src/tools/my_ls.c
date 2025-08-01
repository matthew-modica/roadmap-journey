#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat st;
    char *input_dir;
    if (argc == 1) {
        input_dir = ".";
    } else {
        input_dir = argv[1];
    }

    DIR *dir = opendir(input_dir);

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
       
    /*
     * Do this correctly
     */
    char *option1;
    if (argc == 2) {
        option1 = argv[2];
    }
    stat(entry->d_name, &st);
    return 0;
}
