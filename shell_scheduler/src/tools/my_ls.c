#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <getopt.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    struct stat *st;
    struct dirent *entry;
    char *path;
    int per_line = false;

    int opt;
    while ((opt = getopt(argc, argv, "la") != -1)) {
        switch (opt) {
            case 'l':
                per_line = true;
                break;
            case 'a':
                break;
          default :
                break;
        }
    }

    path = argv[optind];
    DIR *dir = opendir(path);
    while ((entry = readdir(dir)) != NULL) {
        if (per_line) {
            printf("%s\n", entry->d_name);
        }
    }

    return 0;
}
