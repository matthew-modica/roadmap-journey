#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    struct stat *st;
    struct dirent *entry;
    char *path;

    int opt;
    while ((opt = getopt(argc, argv, "la") != -1)) {
        switch (opt) {
            case 'l':
                break;
            case 'a':
                break;
          default :
                break;
        }
    }

    path = argv[optind];
    return 0;
}
