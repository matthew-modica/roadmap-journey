#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <getopt.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    struct dirent *entry;
    struct stat entry_stats;
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

    path = (optind < argc) ? argv[optind] : "."; // Use current directory if none specified
    DIR *dir = opendir(path);
    while ((entry = readdir(dir)) != NULL) {
        if (!include_dotfiles && entry->d_name[0] == '.') {
            continue;
        }

        if (per_line) {
            if (stat(entry->d_name, &entry_stats) == -1) {
                perror("Error populating stats\n");
            } 
            printf("%li ", entry_stats.st_size);
            printf("%s\n", entry->d_name);
        } else {
            printf("%s ", entry->d_name);    
        }
    }
    if (!per_line) {
        printf("\n");
    }

    return 0;
}
