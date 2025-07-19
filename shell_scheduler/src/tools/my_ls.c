#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
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

    return 0;
}