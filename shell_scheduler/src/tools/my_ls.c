#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <getopt.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    struct dirent *entry;
    char *path;
    bool per_line = false;
    bool include_dotfiles = false;
    
    int opt;
    while ((opt = getopt(argc, argv, "la")) != -1) {
        switch (opt) {
            case 'l':
                per_line = true;
                break;
            case 'a':
                include_dotfiles = true;
                break;
          default :
                break;
        }
    }

    path = (optind < argc) ? argv[optind] : ".";
    DIR *dir = opendir(path);
    while ((entry = readdir(dir)) != NULL) {
        if (!include_dotfiles && entry->d_name[0] == '.') {
            continue;
        }

        if (per_line) {
            printf("%s\n", entry->d_name);
        } else {
            printf("%s ", entry->d_name);    
        }
    }
    printf("\n");

    return 0;
}
